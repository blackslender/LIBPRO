#ifndef CHANGEPASS_H
#define CHANGEPASS_H

#include <QWidget>
#include "user.h"
#include <QSqlDatabase>
#include <QSqlQuery>
namespace Ui {
class ChangePass;
}

class ChangePass : public QWidget
{
    Q_OBJECT

public:
    explicit ChangePass(USER *user,QSqlDatabase *db,QWidget *parent = 0);
    ~ChangePass();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ChangePass *ui;
    USER *user;
    QSqlDatabase *db;
};

#endif // CHANGEPASS_H
