#ifndef USER_H
#define USER_H
#define DATABASE (QGuiApplication::applicationDirPath()+"/data.db")
#define ICON (QGuiApplication::applicationDirPath()+"/icon.png")
#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDate>
#define UADMIN   0x0001
#define ULIBMAN  0x0010
#define UREADER  0x0100
#define IsAdmin(role) ((role)&(UADMIN))
#define IsLibMan(role) ((role)&(ULIBMAN))
#define IsReader(role) ((role)&(UREADER))
class USER
{
    private:
    QSqlDatabase *db;
    int UserID;
    QString UserName;
    QString PassWord;
    int Enable;
    int GioiTinh;
    QString FullName;
    QString Address;
    QString BirthDay;
    QString PhoneNumber;
    QString Email;
    int Error;
    int Role;
    public:
    enum GIOITINH
    {
        NAM,
        NU
    };
    enum USER_ERROR
    {
        DISABLE,
        SUCCESS,
        FAILED,
        LOCKED,
        COMMIT_FAILED,
        NOT_LOAD,
        NOT_DELETE
    };

    USER();
    USER(int id,QSqlDatabase *db);
    void setData(QString UserName,QSqlDatabase *db);
    USER(QString UserName,  QSqlDatabase *db);
    void operator=(const USER& usr);
    int getUserID();
    void setUserID(int id);
    QString getUserName();
    void setUserName(QString usr);
    bool getEnable();
    int getGioiTinh();
    void setGioiTinh(int GioiTinh);
    void setDatabase(QSqlDatabase *db);
    void setEnable(bool en);
    void ResetPassWord(QString pass);
    QString getFullName();
    int getError();
    static QString getHash(QString object);
    void setFullName(QString fname);
    QString getAddress();
    void setAdress(QString addr);
    QString getBirthDay();
    void setBirthDay(QString BirthDay);
    QString getEmail();
    void setEmail(QString email);
    int getRole();
    void setRole(int role);
    void setPassWord(QString pass);
    QString getPassWord();
    QString getPhoneNumber();
    void setPhoneNumber(QString phone);
    static int AddUser(USER& user, QSqlDatabase *db);
    static int Delete(int id, QSqlDatabase *db);
    void Commit();
};

#endif // USER_H
