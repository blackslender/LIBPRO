#include "book.h"
#include <QVariant>
#include <QtSql>
#include <QDebug>
#include "phieumuon.h"
BOOK::BOOK()
{
    ID=-1;
    TenSach="";
    TacGia="";
    NgayNhap=QDate(01,01,1900);
    LoaiSach="";
    GiaTien=0;
    SoLuong=0;
    NoiDung="";
    NXB="";
    LastError=NOT_LOAD;
    DuocMuon=false;
}
BOOK::BERROR BOOK::Insert(QSqlDatabase *db, BOOK &book)
{
    QSqlQuery qr(*db);
    qr.prepare("INSERT INTO BOOK(ID,TenSach,TacGia,NgayNhap,LoaiSach,GiaTien,SoLuong,NoiDung,NXB,DuocMuon) VALUES(?,?,?,?,?,?,?,?,?,?)");
    int id=BOOK::getMaxID(db)+1;
    qr.addBindValue(id);
    qr.addBindValue(book.getTenSach());
    qr.addBindValue(book.getTacGia());
    qr.addBindValue(book.getNgayNhap().toString("yyyy-MM-dd"));
    qr.addBindValue(book.getLoaiSach());
    qr.addBindValue(book.getGiaTien());
    qr.addBindValue(book.getSoLuong());
    qr.addBindValue(book.getNoiDung());
    qr.addBindValue(book.getNXB());
    qr.addBindValue(book.isDuocMuon());
    if(qr.exec()) return SUCCESS;
    return NOT_INSERT;
}
int BOOK::getMaxID(QSqlDatabase *db)//static method
{
    QSqlQuery qr(*db);
    qr.prepare("SELECT ID FROM BOOK ORDER BY ID DESC LIMIT 1");
    qr.exec();
    int id;
    if(!qr.next()) id=0;
    else id=qr.value("ID").toInt();
    return id;
}

void BOOK::setTacGia(QString str)
{
    TacGia=str;
}

BOOK::BOOK(int id, QSqlDatabase *db)
{
    this->db=db;
    QSqlQuery qr(*db);
    qr.prepare("SELECT * FROM BOOK WHERE ID=?");
    qr.addBindValue(id);
    if(!qr.exec())
    {
        LastError=NOT_OPEN;
        return;
    }
    if(!qr.next())
    {
        LastError=NOT_FOUND;
        return;
    }
    ID=qr.value(0).toInt();
    TenSach=qr.value(1).toString();
    TacGia=qr.value(2).toString();
    NgayNhap=QDate::fromString(qr.value(3).toString(),"yyyy-MM-dd");
    LoaiSach=qr.value(4).toString();
    GiaTien=qr.value(5).toInt();
    SoLuong=qr.value(6).toInt();
    NoiDung=qr.value(7).toString();
    NXB=qr.value(8).toString();
    DuocMuon=qr.value(9).toInt();
    qr.prepare("SELECT COUNT(SoLuong) FROM PHIEUMUON WHERE Book=?");
    qr.addBindValue(id);
    qr.exec();
    qr.next();
    LastError=SUCCESS;
}
int BOOK::getID()
{
    return ID;
}
void BOOK::setDuocMuon(bool res)
{
    this->DuocMuon=res;
}

void BOOK::setID(int id)
{
    ID=id;
}

QString BOOK::getTenSach()
{
    return TenSach;
}

void BOOK::setTenSach(QString tensach)
{
    TenSach=tensach;
}

QDate BOOK::getNgayNhap()
{
    return NgayNhap;
}

void BOOK::setNgayNhap(QDate date)
{
    NgayNhap.setDate(date.year(),date.month(),date.day());
}

QString BOOK::getLoaiSach()
{
    return LoaiSach;
}

void BOOK::setLoaiSach(QString ls)
{
    LoaiSach=ls;
}

int BOOK::getGiaTien()
{
    return GiaTien;
}

void BOOK::setGiaTien(int gia)
{
    GiaTien=gia;
}

int BOOK::getSoLuong()
{
    return SoLuong;
}

void BOOK::setSoLuong(int x)
{
    SoLuong=x;
}


int BOOK::getLastError()
{
    return LastError;
}
BOOK::BERROR BOOK::DeleteBook(int id, QSqlDatabase *db)
{
    QSqlQuery qr(*db);
    qr.prepare("DELETE FROM BOOK WHERE ID=?");
    qr.addBindValue(id);
    if(!qr.exec()) return NOT_DELETE;
    qr.prepare("DELETE FROM PHIEUMUON WHERE ID=?");
    qr.addBindValue(id);
    if(!qr.exec()) return NOT_DELETE;
    return SUCCESS;
}
bool BOOK::isDuocMuon()
{
    return DuocMuon;
}

QString BOOK::getNoiDung()
{
    return NoiDung;
}

void BOOK::setNoiDung(QString nd)
{
    NoiDung=nd;
}

QString BOOK::getNXB()
{
    return NXB;
}
QString BOOK::getTacGia()
{
    return this->TacGia;
}

void BOOK::setNXB(QString nxb)
{
    NXB=nxb;
}
void BOOK::Commit()
{
    if(LastError==SUCCESS)
    {
        QSqlQuery qr(*db);
        qr.prepare("UPDATE BOOK SET NgayNhap=?,LoaiSach=?,GiaTien=?,SoLuong=?,NoiDung=?,NXB=?,DuocMuon=? WHERE ID=?");
        qr.addBindValue(NgayNhap);
        qr.addBindValue(LoaiSach);
        qr.addBindValue(GiaTien);
        qr.addBindValue(SoLuong);
        qr.addBindValue(NoiDung);
        qr.addBindValue(NXB);
        qr.addBindValue(DuocMuon);
        qr.addBindValue(ID);
        if(!qr.exec())
        {
            LastError=NOT_UPDATE;
        }
        else
            LastError=SUCCESS;
    }
}
