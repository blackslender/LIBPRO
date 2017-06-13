#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include <QWidget>
#include <QSqlDatabase>
#include <user.h>
#include <QtSql>
namespace Ui {
class Librarian;
}

class Librarian : public QWidget
{
    Q_OBJECT

public:
    explicit Librarian(QSqlDatabase *db, USER *user,QWidget *parent = 0);
    enum BOOKTYPE
    {
        TENSACH,
        TACGIA,
        LOAISACH,
        NXB,
        ID
    };
    enum MUON
    {
        DANG_CHO,
        DA_MUON,
        QUA_HAN
    };

    ~Librarian();

private slots:
    void on_listAction_currentRowChanged(int currentRow);
    void on_ContextMenu(QPoint pos);
    void on_btnSearch_clicked();
    void on_Add();
    void on_Edit();
    void on_Del();
    void on_ContextMenu2(QPoint pos);
    void on_Accept();
    void on_Reject();
    void on_Chitiet();
    void on_Lost();
    void on_FilterMuon_currentIndexChanged(int index);

    void on_btnTim_clicked();

    void on_tableMuon_clicked(const QModelIndex &index);

    void on_btnPay_clicked();

    void on_btnSearchPhat_clicked();

    void on_btnXuly_clicked();

private:
    Ui::Librarian *ui;
    QSqlDatabase *db;
    USER *user;
    void resizeEvent(QResizeEvent *event);
    QSqlQueryModel* Search(QString content, BOOKTYPE type);
    void LoadTableSach();
    void LoadTableMuon(int id);
    void LoadTablePhat(QString content="");

};

#endif // LIBRARIAN_H
