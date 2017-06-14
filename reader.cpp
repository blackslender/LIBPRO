#include "reader.h"
#include "ui_reader.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlRelationalTableModel>
#include <QtWidgets>
#include <muonsach.h>
#include "book.h"
#include "phieumuon.h"

READER::READER(QSqlDatabase *db,USER *user,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::READER)
{
    ui->setupUi(this);
    this->db=db;
    this->user=user;
    ui->tableMuon->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableMuon,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(on_ContextMenu(QPoint)));
    FormLoad();
    on_btnSearch_clicked();
}

void READER::resizeEvent(QResizeEvent *event)
{
    QRect rect=ui->stackedWidget->geometry();
    QPoint bot=rect.bottomRight();
    bot.setX(event->size().width()-20);
    bot.setY(event->size().height()-20);
    rect.setBottomRight(bot);
    ui->stackedWidget->setGeometry(rect);
    QWidget::resizeEvent(event);
}
void READER::on_ContextMenu(QPoint pos)
{
    QMenu *menu=new QMenu(ui->tableMuon);
    QAction* info=new QAction("Chi tiết",ui->tableMuon);
    QAction* edit=new QAction("Chỉnh sửa",ui->tableMuon);
    QAction* del=new QAction("Xóa",this);
    if(ui->tableMuon->currentIndex().row()==-1)
    {
        info->setEnabled(false);
        edit->setEnabled(false);
        del->setEnabled(false);
    }
    connect(info,SIGNAL(triggered()),this,SLOT(on_Info()));
    connect(edit,SIGNAL(triggered()),this,SLOT(on_Edit()));
    connect(del,SIGNAL(triggered()),this,SLOT(on_Del()));
    menu->addAction(info);
    menu->addAction(edit);
    menu->addAction(del);
    menu->popup(QCursor::pos());

}
void READER::on_Del()
{
    QModelIndex index=ui->tableMuon->selectionModel()->currentIndex();
    int id=ui->tableMuon->model()->sibling(index.row(),0,index).data().toInt();
    PhieuMuon::Delete(id,db);
    tableMuonLoad();
}
void READER::on_Edit()
{
    QModelIndex index=ui->tableMuon->selectionModel()->currentIndex();
    int id=ui->tableMuon->model()->sibling(index.row(),0,index).data().toInt();
    PhieuMuon phieu(id,db);
    MuonSach *dialog=new MuonSach(user->getUserID(),phieu.getBook(),db,MuonSach::UPDATE,this);
    dialog->setModal(true);
    if(dialog->exec()==MuonSach::Accepted) tableMuonLoad();

}
void READER::on_Info()
{
    QModelIndex index=ui->tableMuon->selectionModel()->currentIndex();
    int id=ui->tableMuon->model()->sibling(index.row(),0,index).data().toInt();
    PhieuMuon phieu(id,db);
    MuonSach *dialog=new MuonSach(user->getUserID(),phieu.getBook(),db,MuonSach::VIEW,this);\
    dialog->setModal(true);
    dialog->exec();
}

void READER::FormLoad()
{
    //
    //List widget
    ui->listWidget->addItem("Tìm kiếm sách");
    ui->listWidget->addItem("Sách chờ duyệt");
    ui->listWidget->addItem("Thông báo");
    //
    //combo Box 1
    ui->FilterBox->addItem("Tên sách");
    ui->FilterBox->addItem("Tác giả");
    ui->FilterBox->addItem("Loại sách");
    ui->FilterBox->addItem("Nhà xuất bản");
    ui->FilterBox->addItem("ID");
    //Combo Box
    ui->Filter2->addItem("Sách đã duyệt");
    ui->Filter2->addItem("Sách mới về");
    ui->Filter2->addItem("Nhắc nhở trả sách");
    ui->Filter2->addItem("Thông báo phạt");
    //
    ui->tableMuon->setEditTriggers(QTableView::NoEditTriggers);
    tableBookLoad();
}
void READER::on_listWidgetChangedIndex(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
    if(index==CHODUYET) tableMuonLoad();
}
QSqlQueryModel* READER::Search(QString content, BOOKTYPE type)
{
    QString pattern="%"+content.toLower()+"%";
    QSqlQuery qr=QSqlQuery(*db);
    QString BookType;
    if(pattern=="") qr.prepare("SELECT * FROM BOOK");
    else
    {
        switch(type)
        {
          case TENSACH: BookType="TenSach"; break;
          case TACGIA: BookType="TacGia";break;
          case LOAISACH: BookType="LoaiSach";break;
          case NXB: BookType="NXB";break;
        case ID: BookType="ID";break;
        }
    QString query("SELECT * FROM BOOK WHERE LOWER(%1) LIKE ?");
    query=query.arg(BookType);
    qr.prepare(query);
    qr.addBindValue(pattern);
    }
    qr.exec();
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery(qr);
    model->setHeaderData(0,Qt::Horizontal,"ID");
    model->setHeaderData(1,Qt::Horizontal,"Tên sách");
    model->setHeaderData(2,Qt::Horizontal,"Tác giả");
    model->setHeaderData(3,Qt::Horizontal,"Ngày nhập");
    model->setHeaderData(4,Qt::Horizontal,"Loại sách");
    model->setHeaderData(5,Qt::Horizontal,"Giá bìa");
    model->setHeaderData(6,Qt::Horizontal,"Số lượng");
    model->setHeaderData(7,Qt::Horizontal,"Nội dung");
    model->setHeaderData(8,Qt::Horizontal,"NXB");
    return model;
}
void READER::tableMuonLoad()
{
    QSqlRelationalTableModel *model=new QSqlRelationalTableModel(this,*db);
    QString pattern="User=%1 AND DaMuon=0";
    pattern=pattern.arg(QString::number(user->getUserID()));
    model->setTable("PHIEUMUON");
    model->setFilter(pattern);
    model->setRelation(2,QSqlRelation("BOOK","ID","TenSach"));
    model->setHeaderData(2,Qt::Horizontal,"Tên sách");
    model->setHeaderData(3,Qt::Horizontal,"Ngày lấy");
    model->setHeaderData(4,Qt::Horizontal,"Ngày trả");
    model->setHeaderData(5,Qt::Horizontal,"Số lượng");
    model->select();
    ui->tableMuon->setModel(model);
    ui->tableMuon->hideColumn(0);
    ui->tableMuon->hideColumn(1);
    ui->tableMuon->hideColumn(6);
    ui->tableMuon->hideColumn(7);
    ui->tableMuon->show();
}

READER::~READER()
{
    delete ui;
}

void READER::on_btnSearch_clicked()
{
    QString content=ui->txtContent->text();
    BOOKTYPE type=(BOOKTYPE)(ui->FilterBox->currentIndex());
    QSqlQueryModel *model=Search(content,type);
    ui->tableBook->setModel(model);
    ui->tableBook->show();
    ui->tableBook->resizeColumnsToContents();

}

void READER::on_listWidget_currentRowChanged(int currentRow)
{
    on_listWidgetChangedIndex(currentRow);
}
void READER::tableBookLoad()
{
    ui->tableBook->setSelectionBehavior(QTableView::SelectRows);
    ui->tableBook->setSelectionMode(QTableView::SingleSelection);
    ui->tableMuon->setSelectionBehavior(QTableView::SelectRows);
    ui->tableMuon->setSelectionMode(QTableView::SingleSelection);
}

void READER::on_tableBook_doubleClicked(const QModelIndex &index)
{
    int idBook=ui->tableBook->model()->sibling(index.row(),0,index).data().toInt();
    MuonSach *dia=new MuonSach(user->getUserID(),idBook,db);
    dia->setModal(true);
    dia->exec();

}

void READER::SachDaDuyet()
{
    QSqlRelationalTableModel *model=new QSqlRelationalTableModel(this,*db);
    model->setTable("PHIEUMUON");
    model->setFilter(QString("User=%1 AND DaMuon=1").arg(user->getUserID()));
    model->setRelation(2,QSqlRelation("BOOK","ID","TenSach"));
    model->setHeaderData(2,Qt::Horizontal,"Tên sách");
    model->setHeaderData(3,Qt::Horizontal,"Ngày mượn");
    model->setHeaderData(4,Qt::Horizontal,"Ngày trả");
    model->setHeaderData(5,Qt::Horizontal,"Số lượng mượn");
    model->select();
    ui->tablenews->setModel(model);
    ui->tablenews->hideColumn(0);
    ui->tablenews->hideColumn(1);
    ui->tablenews->hideColumn(6);
    ui->tablenews->hideColumn(7);
    ui->tablenews->show();
}

void READER::NhacNho()
{
    QSqlRelationalTableModel *model=new QSqlRelationalTableModel(this,*db);
    model->setTable("PHIEUMUON");
    model->setFilter("julianday(date('now'))-julianday(NgayTra)<3");
    model->setRelation(2,QSqlRelation("BOOK","ID","TenSach"));
    model->setHeaderData(2,Qt::Horizontal,"Tên sách");
    model->setHeaderData(3,Qt::Horizontal,"Ngày mượn");
    model->setHeaderData(4,Qt::Horizontal,"Ngày trả");
    model->setHeaderData(5,Qt::Horizontal,"Số lượng mượn");
    model->select();
    ui->tablenews->setModel(model);
    ui->tablenews->hideColumn(0);
    ui->tablenews->hideColumn(1);
    ui->tablenews->hideColumn(6);
    ui->tablenews->hideColumn(7);
    ui->tablenews->show();
}
void READER::Phat()
{
    QSqlRelationalTableModel *model=new QSqlRelationalTableModel(this,*db);
    model->setTable("PHIEUMUON");
    model->setFilter(QString("User=%1 AND Phat=1").arg(user->getUserID()));
    model->setRelation(2,QSqlRelation("BOOK","ID","TenSach"));
    model->setHeaderData(2,Qt::Horizontal,"Tên sách");
    model->setHeaderData(3,Qt::Horizontal,"Ngày mượn");
    model->setHeaderData(4,Qt::Horizontal,"Ngày trả");
    model->setHeaderData(5,Qt::Horizontal,"Số lượng mượn");
    model->select();
    ui->tablenews->setModel(model);
    ui->tablenews->hideColumn(0);
    ui->tablenews->hideColumn(1);
    ui->tablenews->hideColumn(6);
    ui->tablenews->hideColumn(7);
    ui->tablenews->show();
}

void READER::SachMoiVe()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery qr(*db);
    qr.prepare("SELECT * FROM BOOK WHERE julianday(date('now'))-julianday(NgayNhap)<14");
    qr.exec();
    model->setQuery(qr);
    model->setHeaderData(0,Qt::Horizontal,"ID");
    model->setHeaderData(1,Qt::Horizontal,"Tên sách");
    model->setHeaderData(2,Qt::Horizontal,"Tác giả");
    model->setHeaderData(3,Qt::Horizontal,"Ngày nhập");
    model->setHeaderData(4,Qt::Horizontal,"Loại sách");
    model->setHeaderData(5,Qt::Horizontal,"Giá bìa");
    model->setHeaderData(6,Qt::Horizontal,"Số lượng");
    model->setHeaderData(7,Qt::Horizontal,"Nội dung");
    model->setHeaderData(8,Qt::Horizontal,"NXB");
    model->setHeaderData(9,Qt::Horizontal,"Được mượn");
    ui->tablenews->setModel(model);
}

void READER::on_Filter2_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0:
        SachDaDuyet();
        break;
    case 1:
        SachMoiVe();
        break;
    case 2:
        NhacNho();
        break;
    case 3:
        Phat();
        break;
    }
}
