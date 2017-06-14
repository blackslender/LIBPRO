#ifndef THEMSACHS_H
#define THEMSACHS_H

#include <QDialog>
#include "book.h"
#include <QtSql>
namespace Ui {
class ThemSachs;
}

class ThemSachs : public QDialog
{
    Q_OBJECT

public:
    enum MODE
    {
        ADD,
        EDIT
    };

    explicit ThemSachs(QSqlDatabase *db, MODE mode,QWidget *parent = 0, int id=0);
    ~ThemSachs();

private slots:


    void on_btnAdd_clicked();

    void on_btnExit_clicked();

private:
    Ui::ThemSachs *ui;
    void Reset();
    QSqlDatabase *db;
    int id;
    bool Init;
    BOOK *book;
    MODE mode;
};

#endif // THEMSACHS_H
