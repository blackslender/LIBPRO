#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QDebug>
#include "reader.h"
LOGIN::LOGIN(QSqlDatabase *db, USER *user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LOGIN)
{
    ui->setupUi(this);
    instances++;
    this->db=db;
    Role=-1;
    this->user=user;
    Load();

}
void LOGIN::Load()
{

    ui->comboBox->addItem("Quản lý hệ thống");
    ui->comboBox->addItem("Quản lý thư viện");
    ui->comboBox->addItem("Độc giả");
}
int LOGIN::instances=0;
LOGIN::~LOGIN()
{
    delete ui;
    instances--;
}

void LOGIN::on_btnLogin_clicked()
{
   user->setData(ui->txtUser->text(),db);
    int res=user->getError();
    QString thongbao;
    if(res!=USER::SUCCESS)
    {
        if(res==USER::FAILED)
        {
            thongbao="Tên đăng nhập hoặc mật khẩu sai!";
        }
        else if(res==USER::LOCKED)
        {
            thongbao="Tài khoản đang bị khóa!";
        }
        QMessageBox::information(this,"Thông báo",thongbao);
        return;
    }
    int role=user->getRole();
    int index=ui->comboBox->currentIndex();
    switch(index)
    {
    case LADMIN:
        if(IsAdmin(role)) Role=UADMIN;
        break;
    case LLIBMAN:
        if(IsLibMan(role)) Role=ULIBMAN;
        break;
    case LUSER:
        if(IsReader(role)) Role=UREADER;
        break;
    }
    if(Role==-1)
    {
        QMessageBox::critical(this,"Lỗi","Tài khoản của bạn chưa được cấp quyền này!");
    }
    else this->close();

}
void LOGIN::closeEvent(QCloseEvent *event)
{
    emit closeWidget(Role);
    QWidget::closeEvent(event);
    this->parentWidget()->close();
}
