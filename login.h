#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "user.h"
#define LADMIN 0
#define LLIBMAN 1
#define LUSER 2
namespace Ui {
class LOGIN;
}

class LOGIN : public QWidget
{
    Q_OBJECT

public:
    explicit LOGIN(QSqlDatabase *db, USER *user,QWidget *parent = 0);
    static int instances;
    ~LOGIN();

private slots:
    void on_btnLogin_clicked();
signals:
    void closeWidget(int  role);
private:
    Ui::LOGIN *ui;
    QSqlDatabase *db;
    USER *user;
    int Role;
    void closeEvent(QCloseEvent *event);
    void Load();
};

#endif // LOGIN_H
