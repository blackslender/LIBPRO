#include "phieumuon.h"
#include <QSqlQuery>
#include "book.h"
#include <QVariant>
#include <QSqlError>
#include <QDebug>
PhieuMuon::PhieuMuon(int User, int Book,QSqlDatabase *db)
{
    this->User=User;
    this->Book=Book;
    this->db=db;
    QSqlQuery qr(*db);
    qr.prepare("SELECT * FROM PHIEUMUON WHERE User=? AND Book=?");
    qr.addBindValue(User);
    qr.addBindValue(Book);
    qr.exec();
    if(!qr.next())
    {
        LastError=NOT_FOUND;
        return;
    }
    else
    {
        this->ID=qr.value("ID").toInt();
        this->NgayMuon=QDate::fromString(qr.value("NgayMuon").toString(),"yyyy-MM-dd");
        this->NgayTra=QDate::fromString(qr.value("NgayTra").toString(),"yyyy-MM-dd");
        this->SoLuong=qr.value("SoLuong").toInt();
        this->DaMuon=qr.value("DaMuon").toInt();
        this->Phat=qr.value("Phat").toInt();
        LastError=SUCCESS;
    }
}
int PhieuMuon::getQuaHan()
{
    return NgayTra.toJulianDay()-QDate::currentDate().toJulianDay();
}

int PhieuMuon::getUser()
{
    return User;
}

PhieuMuon::PhieuMuon(int id, QSqlDatabase *db)
{
    this->ID=id;
    this->db=db;
    QSqlQuery qr(*db);
    qr.prepare("SELECT * FROM PHIEUMUON WHERE ID=?");
    qr.addBindValue(id);
    qr.exec();
    if(!qr.next())
        {
            LastError=NOT_FOUND;
            return;
        }
        else
        {
            this->User=qr.value("User").toInt();
            this->Book=qr.value("Book").toInt();
            this->NgayMuon=QDate::fromString(qr.value("NgayMuon").toString(),"yyyy-MM-dd");
            this->NgayTra=QDate::fromString(qr.value("NgayTra").toString(),"yyyy-MM-dd");
            this->SoLuong=qr.value("SoLuong").toInt();
            this->DaMuon=qr.value("DaMuon").toInt();
            this->Phat=qr.value("Phat").toInt();
            LastError=SUCCESS;
        }
}

int PhieuMuon::BookCount(int user, QSqlDatabase *db)//static method
{
    QSqlQuery qr(*db);
    qr.prepare("SELECT COUNT(*) FROM PHIEUMUON WHERE User=?");
    qr.addBindValue(user);
    qr.exec();
    qr.next();
    return qr.value(0).toInt();
}

int PhieuMuon::Insert(int User, int Book, QDate NgayMuon, QDate NgayTra, int SoLuong, QSqlDatabase *db)
{
    BOOK book(Book,db);
    if(!book.isDuocMuon()) return NOT_FOR_BORROW;
    if(SoLuong>MAXBOOK) return OUT_OF_LEND;
    int bookcount=PhieuMuon::BookCount(User,db);
    if(bookcount>=MAX_BOOK_TYPE) return OUT_OF_BOOKTYPE;
    if(PhieuMuon::BooksBorrow(Book,db)>book.getSoLuong()) return NOT_ENOUGH_BOOK;
    QSqlQuery qr(*db);
    qr.prepare("INSERT INTO PHIEUMUON(ID, User, Book, NgayMuon,NgayTra,SoLuong)"
               "VALUES(?,?,?,?,?,?)");
    int id=PhieuMuon::getMaxID(db)+1;
    qr.addBindValue(id);
    qr.addBindValue(User);
    qr.addBindValue(Book);
    qr.addBindValue(NgayMuon.toString("yyyy-MM-dd"));
    qr.addBindValue(NgayTra.toString("yyyy-MM-dd"));
    qr.addBindValue(SoLuong);
    if(qr.exec()) return SUCCESS;
    else return NOT_INSERT;
}
int PhieuMuon::BooksBorrow(int idBook, QSqlDatabase *db)
{
    QSqlQuery qr(*db);
    qr.prepare("SELECT SUM(SoLuong) FROM PHIEUMUON WHERE Book=?");
    qr.addBindValue(idBook);
    qr.exec();
    if(qr.next()) return qr.value(0).toInt();
    return 0;
}

int PhieuMuon::getMaxID(QSqlDatabase *db)//static method
{
    QSqlQuery qr(*db);
    qr.prepare("SELECT ID FROM PHIEUMUON ORDER BY ID DESC LIMIT 1");
    qr.exec();
    int id;
    if(!qr.next()) id=0;
    else id=qr.value("ID").toInt();
    return id;
}

void PhieuMuon::Commit()
{
    QSqlQuery qr(*db);
    if(SoLuong>MAXBOOK)
    {
        LastError=OUT_OF_LEND;
        return;
    }
    qr.prepare("UPDATE PHIEUMUON "
               "SET SoLuong=?, NgayMuon=?, NgayTra=?, DaMuon=?, Phat=?"
               "WHERE ID=?"
              );
    qr.addBindValue(SoLuong);
    qr.addBindValue(NgayMuon.toString("yyyy-MM-dd"));
    qr.addBindValue(NgayTra.toString("yyyy-MM-dd"));
    qr.addBindValue(DaMuon);
    qr.addBindValue(Phat);
    qr.addBindValue(this->ID);
    if(!qr.exec()) LastError=NOT_UPDATED;
    else LastError=SUCCESS;
}
bool PhieuMuon::Delete(int User, int Book, QSqlDatabase *db)
{
    QSqlQuery qr(*db);
    qr.prepare("DELETE FROM PHIEUMUON WHERE User=? AND Book=?");
    qr.addBindValue(User);
    qr.addBindValue(Book);
    return qr.exec();
}
bool PhieuMuon::Delete(int id, QSqlDatabase *db)
{
    QSqlQuery qr(*db);
    qr.prepare("DELETE FROM PHIEUMUON WHERE ID=?");
    qr.addBindValue(id);
    return qr.exec();
}
QDate PhieuMuon::getNgayMuon()
{
    return NgayMuon;
}

void PhieuMuon::setNgayMuon(QDate ngaymuon)
{
    this->NgayMuon=ngaymuon;
}

QDate PhieuMuon::getNgayTra()
{
    return NgayTra;
}

void PhieuMuon::setNgayTra(QDate ngaytra)
{
    this->NgayTra=ngaytra;
}

int PhieuMuon::getSoLuong()
{
    return SoLuong;
}

void PhieuMuon::setSoLuong(int sl)
{
    this->SoLuong=sl;
}

bool PhieuMuon::getDaMuon()
{
    return this->DaMuon;
}

void PhieuMuon::setDaMuon(bool damuon)
{
    this->DaMuon=damuon;
}

int PhieuMuon::getLastError()
{
    return LastError;
}
QString PhieuMuon::ErrortoString(PMERROR err)
{
    switch (err) {
    case NOT_FOR_BORROW:
        return QString("Sách không cho mượn");
        break;
    case NOT_FOUND:
        return QString("Không tìm thấy phiếu mượn");
    case OUT_OF_LEND:
        return QString("Vượt quá số lượng mượn tối đa mỗi loại.");
    case NOT_UPDATED:
        return QString("Không thể cập nhật dữ liệu");
    case NOT_LOADED:
        return QString("Không thể load dữ liệu");
    case NOT_INSERT:
        return QString("Không thể thêm phiếu mượn");
    case OUT_OF_BOOKTYPE:
        return QString("Vượt quá số loại sách tối đa được mượn");
    default:
        return QString();
        break;
    }
}
int PhieuMuon::getBook()
{
    return Book;
}
