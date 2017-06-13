#include "changepass.h"
#include "ui_changepass.h"
#include <QMessageBox>
ChangePass::ChangePass(USER *user, QSqlDatabase *db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangePass)
{
    ui->setupUi(this);
    this->user=user;
    this->db=db;
}

ChangePass::~ChangePass()
{
    delete ui;
}

void ChangePass::on_pushButton_clicked()
{
    QString Old_Pass=ui->txtOld->text();
    QString New_Pass=ui->txtNew->text();
    QString Repeat_Pass=ui->txtRepeat->text();
    if(USER::getHash(Old_Pass)!=user->getPassWord())
    {
        QMessageBox::critical(this,"Lỗi","Mật khẩu nhập vào không đúng");
        return;
    }
    if(New_Pass.length()<6)
    {
        QMessageBox::critical(this,"Lỗi","Mật khẩu phải có ít nhất 6 ký tự");
        return;
    }
    if(New_Pass!=Repeat_Pass)
    {
        QMessageBox::critical(this,"Lỗi","Mật khẩu nhập lại không trùng mật khẩu cũ");
        return;
    }
    user->setPassWord(New_Pass);
    user->Commit();
    if(user->getError()==USER::SUCCESS) QMessageBox::information(this,"OK","Đổi mật khẩu thành công!");
    else QMessageBox::critical(this,"Error","Không thể thay đổi mật khẩu");
}
