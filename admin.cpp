#include "admin.h"
#include "ui_admin.h"
#include "adduser.h"
#include <QDebug>
Admin::Admin(QSqlDatabase *db, USER *user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    ui->listAdmin->addItem("Sửa thông tin");
    ui->listAdmin->addItem("Thêm người dùng");  
    this->db=db;
    this->user=user;
    ui->tableUser->setEditTriggers(QTableView::NoEditTriggers);
    ui->tableUser->setSelectionBehavior(QTableView::SelectRows);
    ui->tableUser->setSelectionMode(QTableView::SingleSelection);
    ui->tableUser->setContextMenuPolicy(Qt::CustomContextMenu);
    //
    ui->txtPhone->setValidator(new QRegExpValidator(QRegExp("[0-9]{10,11}")));
    ui->txtEmail->setValidator(new QRegExpValidator(QRegExp("[_.a-zA-Z0-9]+@[a-zA-Z]+.[a-zA-Z]+")));

    connect(ui->tableUser,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(on_ContextMenu(QPoint)));
}
void Admin::on_ContextMenu(QPoint pos)
{
    QMenu *menu=new QMenu(ui->tableUser);
    QAction* edit=new QAction("Chỉnh sửa",ui->tableUser);
    QAction* del=new QAction("Xóa",this);
    if(ui->tableUser->currentIndex().row()==-1)
    {
        edit->setEnabled(false);
        del->setEnabled(false);
    }
    connect(edit,SIGNAL(triggered()),this,SLOT(on_Edit()));
    connect(del,SIGNAL(triggered()),this,SLOT(on_Del()));
    menu->addAction(edit);
    menu->addAction(del);
    menu->popup(QCursor::pos());

}
void Admin::on_Del()
{
    QModelIndex index=ui->tableUser->selectionModel()->selectedRows().at(0);
    int id=ui->tableUser->model()->sibling(index.row(),0,index).data().toInt();
    int error=USER::Delete(id,db);
    if(error!=USER::SUCCESS) QMessageBox::critical(this,"Lỗi","User này xóa hổng được");
    else Search();
}
void Admin::on_Edit()
{
    QModelIndex index=ui->tableUser->selectionModel()->selectedRows().at(0);
    int id=ui->tableUser->model()->sibling(index.row(),0,index).data().toInt();
    AddUser *usr=new AddUser(db,AddUser::EDIT,id,this);
    usr->setModal(true);
    usr->exec();
    Search();
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_btnOK_clicked()
{
    USER usr;
    if(ui->txtPhone->text().length()<10)
    {
        QMessageBox::critical(this,"Lỗi","Số điện thoại không đúng");
        return;
    }
    if(ui->txtPass->text()!=ui->txtRePass->text())
    {
        QMessageBox::critical(this,"Lỗi","Mật khẩu không khớp");
        return;
    }
    usr.setUserName(ui->txtUser->text());
    usr.setPassWord(ui->txtPass->text());
    usr.setEnable(ui->checkActive->isChecked());
    usr.setPhoneNumber(ui->txtPhone->text());
    usr.setEmail(ui->txtEmail->text());
    int role=0;
    if(ui->checkAdmin->isChecked()) role|=UADMIN;
    if(ui->checkLib->isChecked()) role|=ULIBMAN;
    if(ui->checkRead->isChecked()) role|=UREADER;
    usr.setRole(role);
    int success=USER::AddUser(usr,db);
    if(success!=USER::SUCCESS)
    {
        QMessageBox::critical(this,"Lỗi","Không tạo được tài khoản");
    }
    else
        QMessageBox::information(this,"Thành công","Tài khoản đã được tạo");
}

void Admin::Search(QString content)
{
    content=content.toLower();
    QSqlRelationalTableModel *model=new QSqlRelationalTableModel(this,*db);
    QString pattern;
    if(content=="") pattern=content;
    else pattern="LOWER(UserName) like '%"+content+"%'";
    model->setTable("USER");
    model->setFilter(pattern);
    model->setRelation(10,QSqlRelation("Role","Role","RoleText"));
    model->setRelation(5,QSqlRelation("Male","ID","Text"));
    model->setHeaderData(0,Qt::Horizontal,"ID");
    model->setHeaderData(1,Qt::Horizontal,"Tên đăng nhập");
    model->setHeaderData(2,Qt::Horizontal,"Mật khẩu");
    model->setHeaderData(3,Qt::Horizontal,"Active");
    model->setHeaderData(4,Qt::Horizontal,"Họ và tên");
    model->setHeaderData(5,Qt::Horizontal,"Giới tính");
    model->setHeaderData(6,Qt::Horizontal,"Địa chỉ");
    model->setHeaderData(7,Qt::Horizontal,"Ngày sinh");
    model->setHeaderData(8,Qt::Horizontal,"Điện thoại");
    model->setHeaderData(9,Qt::Horizontal,"Email");
    model->setHeaderData(10,Qt::Horizontal,"Vai trò");
    model->select();
    ui->tableUser->setModel(model);
    ui->tableUser->hideColumn(2);
    ui->tableUser->resizeColumnsToContents();
    ui->tableUser->show();
}

void Admin::on_btnReset_clicked()
{
    ui->txtUser->clear();
    ui->txtPass->clear();
    ui->txtPhone->clear();
    ui->txtEmail->clear();
    ui->txtRePass->clear();
}

void Admin::on_listAdmin_currentRowChanged(int currentRow)
{
    ui->stackedWidget->setCurrentIndex(currentRow);
    if(currentRow==0) Search();
}

void Admin::resizeEvent(QResizeEvent *event)
{
    QRect rect=ui->stackedWidget->geometry();
    QPoint bot=rect.bottomRight();
    bot.setX(event->size().width()-20);
    bot.setY(event->size().height()-20);
    rect.setBottomRight(bot);
    ui->stackedWidget->setGeometry(rect);
    QWidget::resizeEvent(event);
}
void Admin::on_pushButton_clicked()
{
    Search(ui->txtContent->text());
}
