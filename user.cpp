#include "user.h"
#include <QVariant>
#include <QCryptographicHash>
USER::USER()
{
    db=NULL;
    UserID=-1;
    UserName="";
    PassWord="";
    Enable=0;
    FullName="";
    Address="";
    GioiTinh=0;
    BirthDay="";
    PhoneNumber="";
    Email="";
    Error=-10;
    Role=0;
}

USER::USER(QString UserName, QSqlDatabase* db)
{
    setData(UserName,db);
}
int USER::Delete(int id,QSqlDatabase *db)
{
    QSqlQuery qr(*db);
    qr.prepare("DELETE FROM USER WHERE ID=?");
    qr.addBindValue(id);
    if(!qr.exec()) return NOT_DELETE;
    qr.prepare("DELETE FROM PHIEUMUON WHERE ID=?");
    qr.addBindValue(id);
    if(!qr.exec()) return NOT_DELETE;
    return SUCCESS;
}

int USER::AddUser(USER &user, QSqlDatabase *db)
{
    QSqlQuery qr(*db);
    qr.prepare("INSERT INTO USER(UserName,PassWord,Enable,PhoneNumber,Email, Role) VALUES(?,?,?,?,?,?)");
    qr.addBindValue(user.getUserName());
    qr.addBindValue(user.getPassWord());
    qr.addBindValue(user.getEnable());
    qr.addBindValue(user.getPhoneNumber());
    qr.addBindValue(user.getEmail());
    qr.addBindValue(user.getRole());
    if(qr.exec())
        return SUCCESS;
    return FAILED;
}

void USER::setData(QString UserName, QSqlDatabase *db)
{
    QSqlQuery qr=QSqlQuery(*db);
    qr.prepare("SELECT * FROM USER WHERE UserName=? ");
    qr.addBindValue(UserName);
    qr.exec();
    if(!qr.next())
    {
        Error=FAILED;
        return;
    }
    UserID=qr.value(0).toInt();
    this->db=db;
    this->UserName=qr.value(1).toString();
    this->PassWord=qr.value(2).toString();
    Enable=qr.value(3).toInt();
    FullName=qr.value(4).toString();
    GioiTinh=qr.value(5).toInt();
    Address=qr.value(6).toString();
    BirthDay=qr.value(7).toString();
    PhoneNumber=qr.value(8).toString();
    Email=qr.value(9).toString();
    Role=qr.value(10).toInt();
    if(Enable==DISABLE)
    {
        Error= LOCKED;
        return;
    }
    Error=SUCCESS;
}
USER::USER(int id, QSqlDatabase *db)
{
    QSqlQuery qr=QSqlQuery(*db);
    qr.prepare("SELECT * FROM USER WHERE ID=?");
    qr.addBindValue(id);
    qr.exec();
    if(!qr.next())
    {
        Error=FAILED;
        return;
    }
    UserID=qr.value(0).toInt();
    this->db=db;
    this->UserName=qr.value(1).toString();
    this->PassWord=qr.value(2).toString();
    Enable=qr.value(3).toInt();
    FullName=qr.value(4).toString();
    GioiTinh=qr.value(5).toInt();
    Address=qr.value(6).toString();
    BirthDay=qr.value(7).toString();
    PhoneNumber=qr.value(8).toString();
    Email=qr.value(9).toString();
    Role=qr.value(10).toInt();
    if(Enable==DISABLE)
    {
        Error= LOCKED;
        return;
    }
    Error=SUCCESS;
}

int USER::getError()
{
    return Error;
}
void USER::operator=(const USER& usr)
{
    this->UserID=usr.UserID;
    this->UserName=usr.UserName;
    this->PassWord=usr.PassWord;
    this->Enable=usr.Enable;
    this->FullName=usr.FullName;
    this->GioiTinh=usr.GioiTinh;
    this->Address=usr.Address;
    this->BirthDay=usr.BirthDay;
    this->PhoneNumber=usr.PhoneNumber;
    this->Email=usr.Email;
    this->Role=usr.Role;
}
int USER::getUserID()
{
    return UserID;
}
void USER::setUserID(int id)
{
    UserID=id;
}
int USER::getGioiTinh()
{
    return GioiTinh;
}
void USER::setGioiTinh(int GioiTinh)
{
    this->GioiTinh=GioiTinh;
}

QString USER::getUserName()
{
    return UserName;
}
void USER::setUserName(QString usr)
{
    UserName=usr;
}
bool USER::getEnable()
{
    return Enable;
}
void USER::setEnable(bool en)
{
    Enable=en;
}
QString USER::getFullName()
{
    return FullName;
}
void USER::setFullName(QString fname)
{
    FullName=fname;
}
QString USER::getAddress()
{
    return Address;
}
void USER::setAdress(QString addr)
{
    Address=addr;
}
QString USER::getBirthDay()
{
    return BirthDay;
}
void USER::setBirthDay(QString BirthDay)
{
    this->BirthDay=BirthDay;
}
QString USER::getEmail()
{
    return Email;
}
void USER::setEmail(QString email)
{
    Email=email;
}
int USER::getRole()
{
    return Role;
}
void USER::setRole(int role)
{
    Role=role;
}
void USER::setPassWord(QString pass)
{
    PassWord=USER::getHash(pass);
}
QString USER::getPassWord()
{
    return PassWord;
}
QString USER::getPhoneNumber()
{
    return PhoneNumber;
}
void USER::setPhoneNumber(QString phone)
{
    PhoneNumber=phone;
}
QString USER::getHash(QString object)
{
    return QString(QCryptographicHash::hash(object.toUtf8(),QCryptographicHash::Sha224).toHex());
}
void USER::setDatabase(QSqlDatabase *db)
{
    this->db=db;
}
void USER::ResetPassWord(QString pass)
{
    setPassWord(pass);
    QSqlQuery qr(*db);
    qr.prepare("UPDATE USER SET PassWord=? WHERE ID=?");
    qr.addBindValue(PassWord);
    qr.addBindValue(UserID);
    qr.exec();
}

void USER::Commit()
{
    if(Error==NOT_LOAD) return;
    QSqlQuery qr(*db);
    qr.prepare("UPDATE USER SET FullName=?,GioiTinh=?,Address=?,BirthDay=?, Role=?, Enable=? WHERE ID=?");
    qr.addBindValue(FullName);
    qr.addBindValue(GioiTinh);
    qr.addBindValue(Address);
    qr.addBindValue(BirthDay);
    qr.addBindValue(Role);
    qr.addBindValue(Enable);
    qr.addBindValue(UserID);
    if(!qr.exec())
    {
        Error=COMMIT_FAILED;
    }
    else Error=SUCCESS;
}

