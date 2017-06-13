#ifndef CHANGEROLE_H
#define CHANGEROLE_H

#include <QDialog>
#include "user.h"

namespace Ui {
class ChangeRole;
}

class ChangeRole : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeRole(USER *user,QWidget *parent = 0);
    ~ChangeRole();
    int getrole()
    {
        return role;
    }
private slots:
    void on_buttonBox_accepted();
signals:
    void closeWidget(int  role);
private:
    Ui::ChangeRole *ui;
    USER *user;
    int role;

};

#endif // CHANGEROLE_H
