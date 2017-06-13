#ifndef BOOK_H
#define BOOK_H
#include <QString>
#include <QDate>
#include <QSqlDatabase>
#include <QSqlQuery>

class BOOK
{
public:
    BOOK();
    BOOK(int id, QSqlDatabase *db);
    enum BERROR
    {
        NOT_LOAD=-1,
        SUCCESS,
        NOT_OPEN,
        NOT_FOUND,
        OUT_OF_LEND,
        NOT_UPDATE,
        NOT_INSERT,
        NOT_DELETE
    };

private:
    QSqlDatabase *db;

    int ID;
    QString TenSach;
    QString TacGia;
    QDate NgayNhap;
    QString LoaiSach;
    int GiaTien;
    int SoLuong;
    QString NoiDung;
    QString NXB;
    int LastError;
    bool DuocMuon;
public:
    int getID();
    void setID(int id);
    QString getTenSach();
    void setTenSach(QString tensach);
    QDate getNgayNhap();
    void setNgayNhap(QDate date);
    QString getLoaiSach();
    QString getTacGia();
    void setTacGia(QString);
    void setLoaiSach(QString);
    static BERROR DeleteBook(int id, QSqlDatabase *db);
    int getGiaTien();
    void setGiaTien(int gia);
    int getSoLuong();
    void setSoLuong(int x);
    QString getNoiDung();
    void setNoiDung(QString nd);
    static BERROR Insert(QSqlDatabase *db, BOOK &book);
    QString getNXB();
    int getLastError();
    void setNXB(QString nxb);
    bool isDuocMuon();
    void setDuocMuon(bool);
    static int getMaxID(QSqlDatabase *db);
    void Commit();
};

#endif // BOOK_H
