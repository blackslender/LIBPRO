#ifndef ADDUSER_H
#define ADDUSER_H

#include <QDialog>
#include <QtSql>
#include "user.h"
#include <QtWidgets>
namespace Ui {
class AddUser;
}

class AddUser : public QDialog
{
    Q_OBJECT

public:
    enum MODE
    {
        ADD,
        EDIT
    };

    explicit AddUser(QSqlDatabase *db,int mode=ADD,int id=0,QWidget *parent = 0);
    ~AddUser();

private slots:
    void on_buttonBox_accepted();

    void on_checkBox_clicked(bool checked);

private:
    QSqlDatabase *db;
    Ui::AddUser *ui;
    int mode;
    USER *user;
    int id;
};

#endif // ADDUSER_H
