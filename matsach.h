#ifndef MATSACH_H
#define MATSACH_H
#include <QDate>
#include <QSqlDatabase>
class MatSach
{
public:
    MatSach(int User, int Book, QSqlDatabase *db);
    MatSach(int id,QSqlDatabase *db);
    enum MSERROR
    {
        SUCCESS,
        NOT_FOUND,
        OUT_OF_LEND,
        NOT_UPDATED,
        NOT_LOADED,
        NOT_INSERT,
        NOT_FOR_BORROW,
        OUT_OF_BOOKTYPE,
        NOT_ENOUGH_BOOK
    };
private:
    int ID;
    int User;
    int Book;
    QDate NgayMat;
    int SoLuong;
    int LastError;
    QSqlDatabase *db;
public:
    int getID()
    {
        return ID;
    }

    static int getMaxID(QSqlDatabase *db);
    static int Insert(MatSach &ms,QSqlDatabase *db);
    void Commit();
    QDate getNgayMat();
    void setNgayMat(QDate ngaymuon);
    int getSoLuong();
    int getUser();
    void setSoLuong(int sl);
    int getBook();
    int getLastError();
    static bool Delete(int User, int Book,QSqlDatabase *db);
    static bool Delete(int id, QSqlDatabase *db);
};

#endif // MATSACH_H
