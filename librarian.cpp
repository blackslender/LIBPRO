
#include "librarian.h"
#include "ui_librarian.h"
#include "phieumuon.h"
#include "muonsach.h"
#include "themsachs.h"
#include "matsach.h"
#include <QtWidgets>
#include <QtSql>
#include <QInputDialog>
Librarian::Librarian(QSqlDatabase *db, USER *user,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Librarian)
{
    ui->setupUi(this);
    this->db=db;
    this->user=user;
    ui->listAction->addItem("Quản lý sách");
    ui->listAction->addItem("Quản lý mượn/trả");
    ui->listAction->addItem("Xử lý mất sách");
    //
    ui->Filter->addItem("Tên sách");
    ui->Filter->addItem("Tác giả");
    ui->Filter->addItem("Loại sách");
    ui->Filter->addItem("Nhà xuất bản");
    ui->Filter->addItem("ID");
    //
    ui->FilterMuon->addItem("Đang chờ");
    ui->FilterMuon->addItem("Đã mượn");
    ui->FilterMuon->addItem("Quá hạn");
    //
    //
    ui->tableSach->setSelectionMode(QTableView::SingleSelection);
    ui->tableSach->setSelectionBehavior(QTableView::SelectRows);
    //
    ui->tablePhat->setSelectionMode(QTableView::SingleSelection);
    ui->tablePhat->setSelectionBehavior(QTableView::SelectRows);
    //
    ui->tableMuon->setSelectionBehavior(QTableView::SelectRows);
    //

    //create context menu
    ui->tableSach->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableSach,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(on_ContextMenu(QPoint)));
    ui->tableMuon->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableMuon,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(on_ContextMenu2(QPoint)));
}
void Librarian::resizeEvent(QResizeEvent *event)
{
    QRect rect=ui->stackedWidget->geometry();
    QPoint bot=rect.bottomRight();
    bot.setX(event->size().width()-20);
    bot.setY(event->size().height()-20);
    rect.setBottomRight(bot);
    ui->stackedWidget->setGeometry(rect);
    QWidget::resizeEvent(event);
}
void Librarian::LoadTableMuon(int id)
{
    QSqlRelationalTableModel *model=new QSqlRelationalTableModel(this,*db);
    model->setTable("PHIEUMUON");
    QString filter;
    switch(id)
    {
    case DANG_CHO:
        filter="DaMuon=0";
        break;
    case DA_MUON:
        filter="DaMuon=1 AND julianday(NgayTra)-julianday(date('NOW'))>=0";
        break;
    case QUA_HAN:
        filter="julianday(NgayTra)-julianday(date('NOW'))<0 AND DaMuon=1";
        break;

    }
    model->setFilter(filter);
    model->setRelation(1,QSqlRelation("USER","ID","FullName"));
    model->setRelation(2,QSqlRelation("BOOK","ID","TenSach"));
    model->setHeaderData(1,Qt::Horizontal,"Người mượn");
    model->setHeaderData(2,Qt::Horizontal,"Tên sách");
    model->setHeaderData(3,Qt::Horizontal,"Ngày mượn");
    model->setHeaderData(4,Qt::Horizontal,"Ngày trả");
    model->setHeaderData(5,Qt::Horizontal,"Số lượng");
    model->select();
    ui->tableMuon->setModel(model);
    ui->tableMuon->hideColumn(0);
    ui->tableMuon->hideColumn(6);
    ui->tableMuon->hideColumn(7);
    ui->tableMuon->resizeColumnsToContents();
}

Librarian::~Librarian()
{
    delete ui;
}

QSqlQueryModel* Librarian::Search(QString content, BOOKTYPE type)
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
void Librarian::LoadTableSach()
{
    QSqlQueryModel *model=Search(QString(),BOOKTYPE::TENSACH);
    ui->tableSach->setModel(model);
    ui->tableSach->resizeColumnsToContents();
}

void Librarian::on_ContextMenu(QPoint pos)
{
    QMenu *menu=new QMenu(ui->tableSach);
    QAction* add=new QAction("Thêm sách",ui->tableSach);
    QAction* edit=new QAction("Chỉnh sửa",ui->tableSach);
    QAction* del=new QAction("Xóa",ui->tableSach);

    if(ui->tableSach->currentIndex().row()==-1)
    {
        edit->setEnabled(false);
        del->setEnabled(false);
    }

    connect(add,SIGNAL(triggered()),this,SLOT(on_Add()));
    connect(edit,SIGNAL(triggered()),this,SLOT(on_Edit()));
    connect(del,SIGNAL(triggered()),this,SLOT(on_Del()));
    menu->addAction(add);
    menu->addAction(edit);
    menu->addAction(del);
    menu->popup(QCursor::pos());

}
void Librarian::on_Lost()
{
    QModelIndex index=ui->tableMuon->selectionModel()->selectedRows().at(0);
    PhieuMuon phieu(ui->tableMuon->model()->sibling(index.row(),0,index).data().toInt(),db);
    MatSach ms(phieu.getUser(),phieu.getBook(),db);
    bool ok;
    int sl=QInputDialog::getInt(this,"Số lượng mất","So",1,1,phieu.getSoLuong(),1,&ok);
    if(ok)
    {
        ms.setSoLuong(sl);
        ms.setNgayMat(QDate::currentDate());
        ms.Commit();
        if(ms.getLastError()==MatSach::SUCCESS)
        {
            sl=phieu.getSoLuong()-sl;
            if(sl==0) PhieuMuon::Delete(phieu.getID(),db);
            else
            {
                phieu.setSoLuong(sl);
                phieu.Commit();
                LoadTableMuon(DA_MUON);
            }
        }
        else
        {
            QMessageBox::critical(this,"Lỗi","Sách này đã báo mất");
            return;
        }

    }
    else return;
}

void Librarian::on_Add()
{
    ThemSachs sach(db,ThemSachs::ADD,this);
    sach.exec();
    LoadTableSach();
}
void Librarian::on_Edit()
{
    QModelIndex index=ui->tableSach->selectionModel()->selectedRows().at(0);
    int id=ui->tableSach->model()->sibling(index.row(),0,index).data().toInt();
    ThemSachs *sach=new ThemSachs(db,ThemSachs::EDIT,this,id);
    sach->setModal(true);
    sach->exec();
    LoadTableSach();
}
void Librarian::on_Del()
{
    QModelIndex index=ui->tableSach->selectionModel()->selectedRows().at(0);
    int id=ui->tableSach->model()->sibling(index.row(),0,index).data().toInt();
    BOOK::BERROR error=BOOK::DeleteBook(id,db);
    if(error!=BOOK::SUCCESS) QMessageBox::critical(this,"Lỗi","Sách này xóa hổng được");
    else LoadTableSach();
}
void Librarian::on_ContextMenu2(QPoint pos)
{
    QMenu*  menu=new QMenu(ui->tableMuon);
    QAction* accept=new QAction("Chấp nhận yêu cầu",ui->tableMuon);
    QAction* reject=new QAction("Hủy bỏ yêu cầu",ui->tableMuon);
    QAction* chitiet=new QAction("Chi tiết",ui->tableMuon);
    QAction* lost=new QAction("Báo mất sách",ui->tableMuon);
    int count=ui->tableMuon->selectionModel()->selectedRows().count();
    if(ui->FilterMuon->currentIndex()!=DANG_CHO|| count==0)
    {
        accept->setEnabled(false);
        reject->setEnabled(false);
        chitiet->setEnabled(false);
    }
    if(count==1) chitiet->setEnabled(true);
    if(ui->FilterMuon->currentIndex()>0&&count==1) lost->setEnabled(true);
    else lost->setEnabled(false);
    connect(accept,SIGNAL(triggered()),this,SLOT(on_Accept()));
    connect(reject,SIGNAL(triggered()),this,SLOT(on_Reject()));
    connect(chitiet,SIGNAL(triggered()),this,SLOT(on_Chitiet()));
     connect(lost,SIGNAL(triggered()),this,SLOT(on_Lost()));
    menu->addAction(accept);
    menu->addAction(reject);
    menu->addAction(chitiet);
    menu->addAction(lost);
    menu->popup(QCursor::pos());
}
void Librarian::on_Accept()
{
    QModelIndexList list=ui->tableMuon->selectionModel()->selectedRows();
    for(int i=0;i<list.count();++i)
    {
        QModelIndex index=list.at(i);
        PhieuMuon phieu(ui->tableMuon->model()->sibling(index.row(),0,index).data().toInt(),db);
        phieu.setDaMuon(true);
        phieu.Commit();
    }
    LoadTableMuon(DANG_CHO);
}
void Librarian::on_Reject()
{
    QModelIndexList list=ui->tableMuon->selectionModel()->selectedRows();
    for(int i=0;i<list.count();++i)
    {
        QModelIndex index=list.at(i);
        int ID=ui->tableMuon->model()->sibling(index.row(),0,index).data().toInt();
        PhieuMuon::Delete(ID,db);
    }
    LoadTableMuon(DANG_CHO);
}
void Librarian::on_Chitiet()
{
    QModelIndex index=ui->tableMuon->selectionModel()->selectedRows().at(0);
    PhieuMuon phieu(ui->tableMuon->model()->sibling(index.row(),0,index).data().toInt(),db);
    MuonSach *muon=new MuonSach(phieu.getUser(),phieu.getBook(),db,MuonSach::VIEW);
    QString Name=ui->tableMuon->model()->sibling(index.row(),1,index).data().toString();
    muon->setWindowTitle("Người mượn: "+Name);
    muon->show();
}
void Librarian::LoadTablePhat(QString content)
{
    QSqlRelationalTableModel *model=new QSqlRelationalTableModel(this,*db);
    model->setTable("MATSACH");

    model->setRelation(1,QSqlRelation("USER","ID","FullName"));
    model->setRelation(2,QSqlRelation("BOOK","ID","TenSach"));
    QString filter="";
    if(content!="")
    filter="user="+content;
    model->setFilter(filter);
    model->setHeaderData(1,Qt::Horizontal,"Người mượn");
    model->setHeaderData(2,Qt::Horizontal,"Tên sách");
    model->setHeaderData(3,Qt::Horizontal,"Số lượng");
    model->setHeaderData(4,Qt::Horizontal,"Thời gian");
    model->select();
    ui->tablePhat->setModel(model);
    ui->tablePhat->show();
}

void Librarian::on_listAction_currentRowChanged(int currentRow)
{
    ui->stackedWidget->setCurrentIndex(currentRow);
    switch(currentRow)
    {
    case 0:
        LoadTableSach();
        break;
    case 1:
        LoadTableMuon(ui->FilterMuon->currentIndex());
        break;
    case 2:
        LoadTablePhat();
        break;
    }
}

void Librarian::on_btnSearch_clicked()
{
    QString content=ui->txtContent->text();
    BOOKTYPE type=(BOOKTYPE)(ui->Filter->currentIndex());
    QSqlQueryModel *model=Search(content,type);
    ui->tableSach->setModel(model);
    ui->tableSach->show();
    ui->tableSach->resizeColumnsToContents();

}

void Librarian::on_FilterMuon_currentIndexChanged(int index)
{
    LoadTableMuon(index);
    switch(index)
    {
        case DANG_CHO:
        ui->lblID->setVisible(false);
        ui->txtSearch->setVisible(false);
        ui->btnTim->setVisible(false);
        ui->btnPay->setVisible(false);
        break;
    case DA_MUON:
        ui->lblID->setVisible(true);
        ui->txtSearch->setVisible(true);
        ui->btnTim->setVisible(true);
        ui->btnPay->setVisible(true);
        break;
    case QUA_HAN:

        break;
    }
}

void Librarian::on_btnTim_clicked()
{
    int id=ui->txtSearch->text().toInt();
    QSqlQuery qr=QSqlQuery(*db);
    qr.prepare("SELECT * FROM PHIEUMUON WHERE User=? AND DaMuon=1 AND Phat=0");
    qr.addBindValue(id);
    qr.exec();
    QSqlRelationalTableModel *model=new QSqlRelationalTableModel(this,*db);
    model->setTable("PHIEUMUON");
    model->setFilter(QString("User=%1 AND DaMuon=1 AND Phat=0").arg(id));
    model->setRelation(1,QSqlRelation("USER","ID","FullName"));
    model->setRelation(2,QSqlRelation("BOOK","ID","TenSach"));
    model->setHeaderData(1,Qt::Horizontal,"Người mượn");
    model->setHeaderData(2,Qt::Horizontal,"Tên sách");
    model->setHeaderData(3,Qt::Horizontal,"Ngày mượn");
    model->setHeaderData(4,Qt::Horizontal,"Ngày trả");
    model->setHeaderData(5,Qt::Horizontal,"Số lượng");
    model->select();
    ui->tableMuon->setModel(model);
    ui->tableMuon->hideColumn(0);
    ui->tableMuon->hideColumn(6);
    ui->tableMuon->hideColumn(7);

}

void Librarian::on_tableMuon_clicked(const QModelIndex &index)
{
    ui->btnPay->setEnabled(true);
}

void Librarian::on_btnPay_clicked()
{
    if(ui->tableMuon->selectionModel()->selectedRows().count()==1)
    {
        QModelIndex index=ui->tableMuon->selectionModel()->selectedRows().at(0);
        int id=ui->tableMuon->model()->sibling(index.row(),0,index).data().toInt();
        PhieuMuon phieu(id,db);
        int han=phieu.getQuaHan();
        if(han<0)
        {
            int tien=phieu.TIENPHAT*(-han)*phieu.getSoLuong();
            int res=QMessageBox::warning(this,"Thông báo","Mượn sách quá hạn "+QString::number(-han)
                                         +" ngày.\n Phải thanh toán thêm số tiền là: "+QString::number(tien)+" đồng"
                                         ,QMessageBox::Ok|QMessageBox::Cancel);
             if(res==QMessageBox::Ok)
             {
                 PhieuMuon::Delete(id,db);
                 LoadTableMuon(DA_MUON);
             }
        }
        else
        {
            PhieuMuon::Delete(id,db);
            LoadTableMuon(DA_MUON);
        }
    }
}

void Librarian::on_btnSearchPhat_clicked()
{
    LoadTablePhat(ui->txtContentPhat->text());
}

void Librarian::on_btnXuly_clicked()
{
    if(ui->tablePhat->selectionModel()->selectedRows().count()==1)
    {
    QModelIndex index=ui->tablePhat->selectionModel()->selectedRows().at(0);
    int id=ui->tablePhat->model()->sibling(index.row(),0,index).data().toInt();
    MatSach ms(id,db);
    BOOK book(ms.getBook(),db);
    int res=QMessageBox::information(this,"Xu ly mat sach","Truong hop nay phai den gap doi gia sach la:"+QString::number(book.getGiaTien()*2));
    if(res==QMessageBox::Ok)
    {
        MatSach::Delete(id,db);
        book.setSoLuong(book.getSoLuong()-ms.getSoLuong());
        book.Commit();
    }
    }
}
