#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "changeinfomation.h"
#include <QDebug>
#include "reader.h"
#include "changepass.h"
#include "admin.h"
#include "librarian.h"
#include "phieumuon.h"
#include "changerole.h"
#include <QWidget>
#include <QtWidgets>
#include <QMdiSubWindow>
#include <QLayout>
#include <book.h>
#include "feedback.h"
#include <QDir>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Khoi tao form
    ui->setupUi(this);
    //Load Database
    db=new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    db->setDatabaseName(DIR("data.db"));
    db->open();
    //Tao vung MDI
    mdi=new QMdiArea();
    QImage background(DIR("background.png"));
    mdi->setBackground(background);
    user=new USER();
    //Show toolbar
    showToolbar();
    //Bat dau show form login
    LoginShow();
    Logined=false;
    //ket thuc show form login
    setCentralWidget(mdi);
    //
    this->setWindowTitle("LIBPRO");
    this->setWindowIcon(QIcon(DIR("icon.png")));
    //
    ui->actionLogin->setEnabled(true);
    ui->actionChangeRole->setEnabled(false);
    ui->actionLogout->setEnabled(false);
    ui->actionViewInfo->setEnabled(false);
    ui->actionChangePass->setEnabled(false);
    //
    connect(ui->actionLogin,SIGNAL(triggered()),this,SLOT(on_actionLogin()));
    connect(ui->actionLogout,SIGNAL(triggered()),this,SLOT(on_actionLogout()));
    connect(ui->actionExit,SIGNAL(triggered()),qApp,SLOT(quit()));
    connect(ui->actionChangePass,SIGNAL(triggered()),this,SLOT(on_changePass()));


    connect(this,SIGNAL(LoginChanged(bool)),this,SLOT(on_LoginChanged(bool)));
    connect(ui->actionChangeRole,SIGNAL(triggered()),this,SLOT(on_actionChangeRole()));
    connect(ui->actionViewInfo,SIGNAL(triggered()),this,SLOT(on_actionViewInfo()));
    //
    qDebug()<<DIR("data.db");
}
void MainWindow::Load()
{

}
void MainWindow::on_changePass()
{
    ChangePass *widget=new ChangePass(user,db);
    QMdiSubWindow *wchpass=mdi->addSubWindow(widget);
    wchpass->setWindowTitle("Đổi mật khẩu");
    wchpass->show();
}

void MainWindow::LoginShow()
{
    LOGIN* login=new LOGIN(db,user);
    QMdiSubWindow *wlogin=mdi->addSubWindow(login);
    wlogin->setWindowFlags((wlogin->windowFlags()^Qt::WindowMaximizeButtonHint)^Qt::WindowMinimizeButtonHint);
    wlogin->layout()->setSizeConstraint(QLayout::SetFixedSize);
    wlogin->setWindowTitle("Đăng nhập");
    wlogin->show();
    connect(login,SIGNAL(closeWidget(int)),this,SLOT(on_Widgetclose(int)));
    Logined=false;
}

void MainWindow::on_actionChangeRole()
{
    foreach(QMdiSubWindow *child,mdi->subWindowList()) child->close();
    ChangeRole *role=new ChangeRole(user);
    QMdiSubWindow *wrole=mdi->addSubWindow(role);
    wrole->setWindowFlags((wrole->windowFlags()^Qt::WindowMaximizeButtonHint)^Qt::WindowMinimizeButtonHint);
    wrole->layout()->setSizeConstraint(QLayout::SetFixedSize);
    wrole->setWindowTitle("Doi vai tro");
    wrole->show();
    connect(role,SIGNAL(closeWidget(int)),this,SLOT(on_Widgetclose(int)));
    Logined=false;
}
void MainWindow::ReaderShow()
{
    READER* reader=new READER(db,user);
    QMdiSubWindow *wreader=mdi->addSubWindow(reader);
    wreader->setWindowTitle("Độc giả - "+user->getUserName());
    wreader->setFixedSize(wreader->size());
    wreader->show();
}

void MainWindow::on_Widgetclose(int Role)
{

    bool flag=false;
    if(Role==UADMIN)
    {
        flag=true;
        Admin *ad=new Admin(db,user);
        QMdiSubWindow *wad=mdi->addSubWindow(ad);
        wad->setWindowTitle("Quản lý hệ thống - "+user->getUserName());
        wad->showMaximized();
    }
    else if(Role==ULIBMAN)
    {
        flag=true;
        Librarian *lib=new Librarian(db,user);
        QMdiSubWindow *wlib=mdi->addSubWindow(lib);
        wlib->setWindowTitle("Quản lý thư viện - "+user->getUserName());
        wlib->showMaximized();

    }
    else if(Role== UREADER)
    {
        flag=true;
        READER* reader=new READER(db,user);
        QMdiSubWindow *wreader=mdi->addSubWindow(reader);
        wreader->setWindowTitle("Độc giả "+user->getUserName());
        wreader->showMaximized();
    }
    if(flag!=Logined) emit LoginChanged(flag);
    Logined=flag;
}

void MainWindow::on_LoginChanged(bool bo)
{
    if(bo)
    {
        ui->actionLogin->setEnabled(false);
        ui->actionLogout->setEnabled(true);
        ui->actionViewInfo->setEnabled(true);
        ui->actionChangePass->setEnabled(true);
        ui->actionChangeRole->setEnabled(true);
    }
    else
    {
        ui->actionLogin->setEnabled(true);
        ui->actionLogout->setEnabled(false);
        ui->actionViewInfo->setEnabled(false);
        ui->actionChangePass->setEnabled(false);
        ui->actionChangeRole->setEnabled(false);
    }
}

void MainWindow::on_actionLogout()
{
    delete user;
    user=new USER();
    Logined=false;
    emit LoginChanged(Logined);
    foreach(QMdiSubWindow *child,mdi->subWindowList()) child->close();
    LoginShow();
}

void MainWindow::on_actionViewInfo()
{
    ChangeInfomation *form=new ChangeInfomation(user);
    QMdiSubWindow *wform=mdi->addSubWindow(form);
    wform->show();
}

void MainWindow::on_actionLogin()
{
    if(LOGIN::instances==0)
    {
        //bat dau show form login
        LoginShow();
        //ket thuc show form login
    }
}

void MainWindow::LoadPhieuMuon()
{

}

MainWindow::~MainWindow()
{
    delete ui;
    delete db;
    delete user;
}

void MainWindow::on_actionVersion_triggered()
{
    QMessageBox::information(this,"Thông tin phiên bản","LIBPRO "+VERSION+" \n Nhóm tác giả: \n Lương Tuấn Kiệt - 1611695 \n Nguyễn Văn Tường - 1614028 \n Huỳnh Phúc Nghị - 1612233 \n Vũ Hoàng Văn 1614063");
}

void MainWindow::showToolbar() {
    QPixmap newpix(DIR("new.png"));
    QPixmap logoutpix(DIR("logout.png"));
    QPixmap changerole(DIR("changerole.png"));
   // toolbar->addSeparator();
    toolbar->setIconSize(QSize(18,18));
    QAction *btnNewWindow = toolbar->addAction(QIcon(newpix), "Cửa số LIBPRO mới");
    QAction *btnChangeRole = toolbar->addAction(QIcon(changerole),"Thay đổi tư cách đăng nhập");
    QAction *btnLogOut = toolbar -> addAction(QIcon(logoutpix),"Đăng xuất");
    connect(btnNewWindow, &QAction::triggered, this,&MainWindow::createWindow);
    connect(btnChangeRole,&QAction::triggered,this,&MainWindow::on_actionChangeRole);
    connect(btnLogOut, &QAction::triggered,this,&MainWindow::on_actionLogout);
}

void MainWindow::createWindow() {
    MainWindow* newMainWindow = new MainWindow;
    newMainWindow->show();
}



void MainWindow::on_actionG_p_triggered()
{
    Feedback *wfb = new Feedback;
    QMdiSubWindow *wf=mdi->addSubWindow(wfb);
    wfb->show();
}

void MainWindow::on_actionLogout_triggered() {
    MainWindow::on_actionLogout();
}
