#ifndef CHANGEINFOMATION_H
#define CHANGEINFOMATION_H

#include <QWidget>
#include "user.h"
namespace Ui {
class ChangeInfomation;
}

class ChangeInfomation : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeInfomation(USER *user,QWidget *parent = 0);
    ~ChangeInfomation();

private slots:
    void on_btnUpdate_clicked();

private:
    Ui::ChangeInfomation *ui;
    USER *user;
    void FormLoad();
};

#endif // CHANGEINFOMATION_H
