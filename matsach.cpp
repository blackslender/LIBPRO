#include "matsach.h"
#include <QSqlQuery>
#include <QVariant>
MatSach::MatSach(int User, int Book, QSqlDatabase *db)
{
    this->User=User;
    this->Book=Book;
    this->db=db;
    QSqlQuery qr(*db);
    qr.prepare("SELECT * FROM MATSACH WHERE user=? AND book=?");
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
        this->NgayMat=QDate::fromString(qr.value("thoigian").toString(),"yyyy-MM-dd");
        this->SoLuong=qr.value("soluong").toInt();
        LastError=SUCCESS;
    }
}

MatSach::MatSach(int id,QSqlDatabase *db)
{
    this->ID=id;
    this->db=db;
    QSqlQuery qr(*db);
    qr.prepare("SELECT * FROM MATSACH WHERE ID=?");
    qr.addBindValue(id);
    qr.exec();
    if(!qr.next())
        {
            LastError=NOT_FOUND;
            return;
        }
        else
        {
            this->User=qr.value("user").toInt();
            this->Book=qr.value("book").toInt();
            this->NgayMat=QDate::fromString(qr.value("thoigian").toString(),"yyyy-MM-dd");
            this->SoLuong=qr.value("soluong").toInt();
            LastError=SUCCESS;
        }
}

int MatSach::getMaxID(QSqlDatabase *db)
{
    QSqlQuery qr(*db);
    qr.prepare("SELECT ID FROM MATSACH ORDER BY ID DESC LIMIT 1");
    qr.exec();
    int id;
    if(!qr.next()) id=0;
    else id=qr.value("ID").toInt();
    return id;
}

int MatSach::Insert(MatSach &ms,QSqlDatabase *db)
{
    QSqlQuery qr(*db);
    qr.prepare("INSERT INTO MATSACH(ID, user, book,soluong, thoigian)"
               "VALUES(?,?,?,?,?,?)");
    int id=MatSach::getMaxID(db)+1;
    qr.addBindValue(id);
    qr.addBindValue(ms.getUser());
    qr.addBindValue(ms.getBook());
    qr.addBindValue(ms.getNgayMat().toString("yyyy-MM-dd"));
    qr.addBindValue(ms.getSoLuong());
    if(qr.exec()) return SUCCESS;
    else return NOT_INSERT;
}

void MatSach::Commit()
{
    QSqlQuery qr(*db);
    qr.prepare("UPDATE MATSACH  SET SoLuong=?, NgayMat=? WHERE ID=?"
              );
    qr.addBindValue(SoLuong);
    qr.addBindValue(NgayMat.toString("yyyy-MM-dd"));
    qr.addBindValue(this->ID);
    if(!qr.exec()) LastError=NOT_UPDATED;
    else LastError=SUCCESS;
}

QDate MatSach::getNgayMat()
{
    return NgayMat;
}

void MatSach::setNgayMat(QDate ngaymuon)
{
    NgayMat=ngaymuon;
}

int MatSach::getSoLuong()
{
    return SoLuong;
}

int MatSach::getUser()
{
    return User;
}

void MatSach::setSoLuong(int sl)
{
    SoLuong=sl;
}

int MatSach::getBook()
{
    return Book;
}

int MatSach::getLastError()
{
    return LastError;
}

bool MatSach::Delete(int User, int Book,QSqlDatabase *db)
{
    QSqlQuery qr(*db);
    qr.prepare("DELETE FROM MATSACH WHERE user=? AND book=?");
    qr.addBindValue(User);
    qr.addBindValue(Book);
    return qr.exec();
}

bool MatSach::Delete(int id, QSqlDatabase *db)
{
    QSqlQuery qr(*db);
    qr.prepare("DELETE FROM MATSACH WHERE ID=?");
    qr.addBindValue(id);
    return qr.exec();
}
