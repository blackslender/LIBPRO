#include "changeinfomation.h"
#include "ui_changeinfomation.h"
#include <QMessageBox>
ChangeInfomation::ChangeInfomation(USER *user,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangeInfomation)
{
    ui->setupUi(this);
    this->user=user;
    FormLoad();
}
void ChangeInfomation::FormLoad()
{
    ui->txtID->setText(QString::number(user->getUserID()));
    ui->txtAddress->setText(user->getAddress());
    ui->txtEmail->setText(user->getEmail());
    ui->txtName->setText(user->getFullName());
    ui->txtPass->setText("password");
    ui->txtPhone->setText(user->getPhoneNumber());
    ui->txtUser->setText(user->getUserName());
    ui->dateBirth->setDate(QDate::fromString(user->getBirthDay(),"yyyy-MM-dd"));
    ui->dateBirth->setDisplayFormat("dd/MM/yyyy");
    ui->dateBirth->setMinimumDate(QDate(1900,1,1));
    ui->dateBirth->setMaximumDate(QDate::currentDate());
}

ChangeInfomation::~ChangeInfomation()
{
    delete ui;
}

void ChangeInfomation::on_btnUpdate_clicked()
{
    user->setAdress(ui->txtAddress->text());
    user->setBirthDay(ui->dateBirth->date().toString("yyyy-MM-dd"));
    user->setFullName(ui->txtName->text());
    user->Commit();
    if(user->getError()==USER::SUCCESS)
    {
        QMessageBox::information(this,"Done","Cập nhật thông tin cá nhân thành công!");
    }
    else QMessageBox::critical(this,"Error","Cập nhật thông tin thất bại!");
}
