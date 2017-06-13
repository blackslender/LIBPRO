#include "changerole.h"
#include "ui_changerole.h"
#include <QMessageBox>
ChangeRole::ChangeRole(USER *user,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeRole)
{
    this->user=user;
    ui->setupUi(this);
    if(IsAdmin(user->getRole())) ui->rAdmin->setVisible(true);
    else ui->rAdmin->setVisible(false);
    if(IsLibMan(user->getRole())) ui->rLib->setVisible(true);
    else ui->rLib->setVisible(false);
    if(IsReader(user->getRole())) ui->rRead->setVisible(true);
    else ui->rRead->setVisible(false);
}

ChangeRole::~ChangeRole()
{
    delete ui;
}

void ChangeRole::on_buttonBox_accepted()
{
    role=0;
    if(ui->rAdmin->isChecked()) role|=UADMIN;
    if(ui->rLib->isChecked())
                role|=ULIBMAN;
    if(ui->rRead->isChecked())
                role|=UREADER;
    emit closeWidget(role);
}
