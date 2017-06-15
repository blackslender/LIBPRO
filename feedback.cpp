#include "feedback.h"
#include "ui_feedback.h"

Feedback::Feedback(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Feedback)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}

Feedback::~Feedback()
{
    delete ui;
}

void Feedback::on_btnSend_released()
{
    db.setDatabaseName(DATABASE);
    db.open();
    QSqlQuery qr(db);
    qr.prepare("INSERT INTO FEEDBACK VALUES (?)");
    qr.addBindValue(ui->textFeed->toPlainText());
    qr.exec();
    QMessageBox::information(this,"Feedback","Gửi góp ý thành công, cảm ơn bạn đã góp phần xây dựng LIBPRO");
    this->close();
}

void Feedback::on_btnCancel_released()
{
    this->close();
}
