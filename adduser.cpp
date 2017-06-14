#include "adduser.h"
#include "ui_adduser.h"
#include <QtSql>
#include "user.h"
AddUser::AddUser(QSqlDatabase *db, int mode,int id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddUser)
{
    ui->setupUi(this);
    this->db=db;
    this->mode=mode;
    this->id=id;
    user=new USER(id,db);
    ui->txtUser->setText(user->getUserName());
    ui->txtPass->setText(user->getPassWord());
    ui->checkActive->setChecked(user->getEnable());
    ui->txtPhone->setText(user->getPhoneNumber());
    ui->txtEmail->setText(user->getEmail());
    if(IsAdmin(user->getRole())) ui->CheckAdmin->setChecked(true);
    if(IsLibMan(user->getRole())) ui->CheckLib->setChecked(true);
    if(IsReader(user->getRole())) ui->CheckRead->setChecked(true);
}

AddUser::~AddUser()
{
    if(mode==EDIT) delete user;
    delete ui;
}

void AddUser::on_buttonBox_accepted()
{
    user->setUserName(ui->txtUser->text());
    user->setPassWord(ui->txtPass->text());
    user->setEnable(ui->checkActive->isChecked());
    user->setPhoneNumber(ui->txtPhone->text());
    user->setEmail(ui->txtEmail->text());
    int role=0;
    bool enable=ui->checkActive->isChecked();
    user->setEnable(enable);
    if(ui->CheckAdmin->isChecked()) role|=UADMIN;
    if(ui->CheckLib->isChecked()) role|=ULIBMAN;
    if(ui->CheckRead->isChecked()) role|=UREADER;
    user->setRole(role);
    if(ui->txtPass->isEnabled()) user->ResetPassWord(ui->txtPass->text());
    user->Commit();
    if(user->getError()!=USER::COMMIT_FAILED)
    {
        QMessageBox::information(this,"Thành công","Cập nhật thông tin thành công");
    }
    else
    {
        QMessageBox::critical(this,"Lỗi","Cập nhật thất bại");
    }
}

void AddUser::on_checkBox_clicked(bool checked)
{
    ui->txtPass->setEnabled(checked);
}
