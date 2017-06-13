#ifndef ADMIN_H
#define ADMIN_H
#include <QtSql>
#include "user.h"
#include <QWidget>

namespace Ui {
class Admin;
}

class Admin : public QWidget
{
    Q_OBJECT

public:
    explicit Admin(QSqlDatabase *db, USER *user,QWidget *parent = 0);
    ~Admin();

private slots:
    void on_btnOK_clicked();

    void on_btnReset_clicked();

    void on_listAdmin_currentRowChanged(int currentRow);


    void on_pushButton_clicked();

    void on_ContextMenu(QPoint pos);

    void on_Edit();

    void on_Del();
private:
    void Search(QString content="");
    void resizeEvent(QResizeEvent *event);
    Ui::Admin *ui;
    QSqlDatabase *db;
    USER *user;
};

#endif // ADMIN_H
