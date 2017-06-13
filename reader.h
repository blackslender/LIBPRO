#ifndef READER_H
#define READER_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QSqlRelationalTableModel>
//Dinh nghia hang cho listview
#define TIMSACH 0
#define CHODUYET 1
#define THONGBAO 2
#include <QSqlDatabase>
#include <QMenu>
#include <user.h>
namespace Ui {
class READER;
}

class READER : public QWidget
{
    Q_OBJECT

public:
    explicit READER(QSqlDatabase *db,USER *user,QWidget *parent = 0);
    ~READER();
    enum BOOKTYPE
    {
        TENSACH,
        TACGIA,
        LOAISACH,
        NXB,
        ID
    };

private:
    Ui::READER *ui;
    USER *user;
    QSqlDatabase *db;
    void FormLoad();
    QSqlQueryModel* Search(QString content,BOOKTYPE type);
    void tableBookLoad();
    void tableMuonLoad();
    void SachDaDuyet();
    void SachMoiVe();
    void NhacNho();
    void Phat();
    void resizeEvent(QResizeEvent *event);

private slots:
    void on_listWidgetChangedIndex(int index);
    void on_btnSearch_clicked();
    void on_ContextMenu(QPoint);
    void on_listWidget_currentRowChanged(int currentRow);
    void on_tableBook_doubleClicked(const QModelIndex &index);
    void on_Info();
    void on_Edit();
    void on_Del();
    void on_Filter2_currentIndexChanged(int index);
};

#endif // READER_H
