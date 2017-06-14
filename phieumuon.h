#ifndef PHIEUMUON_H
#define PHIEUMUON_H
#include<QDate>
#include <QSqlDatabase>
#define MAXBOOK 5
#define MAX_BOOK_TYPE 3
class PhieuMuon
{
public:
    PhieuMuon(int User, int Book, QSqlDatabase *db);
    PhieuMuon(int id,QSqlDatabase *db);
    enum PMERROR
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
    QDate NgayMuon;
    QDate NgayTra;
    int SoLuong;
    bool DaMuon;
    int Phat;
    int LastError;
    QSqlDatabase *db;
public:
    const int TIENPHAT=5000;
    int getID()
    {
        return ID;
    }

    static int getMaxID(QSqlDatabase *db);
    static int Insert(int User, int Book, QDate NgayMuon, QDate NgayTra, int SoLuong,QSqlDatabase *db);
    static int BookCount(int user, QSqlDatabase *db);
    static int BooksBorrow(int idBook,QSqlDatabase *db);
    void Commit();
    QDate getNgayMuon();
    void setNgayMuon(QDate ngaymuon);
    QDate getNgayTra();
    void setNgayTra(QDate ngaytra);
    int getSoLuong();
    int getUser();
    void setSoLuong(int sl);
    int getQuaHan();
    int getBook();
    bool getDaMuon();
    void setDaMuon(bool damuon);
    int getLastError();
    static QString ErrortoString(PMERROR err);
    static bool Delete(int User, int Book,QSqlDatabase *db);
    static bool Delete(int id, QSqlDatabase *db);
};

#endif // PHIEUMUON_H
