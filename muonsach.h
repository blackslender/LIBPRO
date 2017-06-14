#ifndef MUONSACH_H
#define MUONSACH_H

#include <QDialog>
#include <QDate>
#include "book.h"
namespace Ui {
class MuonSach;
}

class MuonSach : public QDialog
{
    Q_OBJECT

public:
    enum MODE
    {
        ADDTO,
        UPDATE,
        VIEW
    };

    explicit MuonSach(int user,int id,QSqlDatabase *db, int mode=ADDTO,QWidget *parent = 0);
    ~MuonSach();

private slots:
    void on_buttonBox_accepted();
    void on_DateChanged(QDate Date);

private:
    int user;
    Ui::MuonSach *ui;
    QSqlDatabase *db;
    void DialogLoad(int mode);
    BOOK book;
    int mode;
};







#endif // MUONSACH_H
