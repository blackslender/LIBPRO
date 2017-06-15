#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "user.h"
#include "login.h"
#include "reader.h"
#include <QMainWindow>
#include <QMdiArea>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    //attribute
    Ui::MainWindow *ui;
    QSqlDatabase *db;
    QToolBar *toolbar = addToolBar("Thanh công cụ");
    QMdiArea *mdi;
    USER *user;
    bool Logined;
    //method
    void Load();
    void LoginShow();
    void ReaderShow();
    void LoadPhieuMuon();
    void showToolbar();
    void createWindow();
private slots:
    void on_actionLogin();
    void on_actionLogout();
    void on_Widgetclose(int Role);
    void on_LoginChanged(bool);
    void on_actionChangeRole();
    void on_actionViewInfo();
    void on_changePass();
    void on_actionVersion_triggered();

    void on_actionLogout_triggered();

    void on_actionG_p_triggered();

signals:
    void LoginChanged(bool);
};

#endif // MAINWINDOW_H
