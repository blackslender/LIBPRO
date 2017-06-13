/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLogin;
    QAction *actionLogout;
    QAction *actionExit;
    QAction *actionViewInfo;
    QAction *actionChangePass;
    QAction *actionChangeRole;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuT_i_kho_n;
    QMenu *menuTh_ng_tin;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(842, 541);
        actionLogin = new QAction(MainWindow);
        actionLogin->setObjectName(QStringLiteral("actionLogin"));
        actionLogout = new QAction(MainWindow);
        actionLogout->setObjectName(QStringLiteral("actionLogout"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionViewInfo = new QAction(MainWindow);
        actionViewInfo->setObjectName(QStringLiteral("actionViewInfo"));
        actionChangePass = new QAction(MainWindow);
        actionChangePass->setObjectName(QStringLiteral("actionChangePass"));
        actionChangeRole = new QAction(MainWindow);
        actionChangeRole->setObjectName(QStringLiteral("actionChangeRole"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 842, 21));
        menuT_i_kho_n = new QMenu(menuBar);
        menuT_i_kho_n->setObjectName(QStringLiteral("menuT_i_kho_n"));
        menuTh_ng_tin = new QMenu(menuBar);
        menuTh_ng_tin->setObjectName(QStringLiteral("menuTh_ng_tin"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuT_i_kho_n->menuAction());
        menuBar->addAction(menuTh_ng_tin->menuAction());
        menuT_i_kho_n->addAction(actionLogin);
        menuT_i_kho_n->addAction(actionChangeRole);
        menuT_i_kho_n->addAction(actionLogout);
        menuT_i_kho_n->addSeparator();
        menuT_i_kho_n->addAction(actionExit);
        menuTh_ng_tin->addAction(actionViewInfo);
        menuTh_ng_tin->addAction(actionChangePass);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionLogin->setText(QApplication::translate("MainWindow", "\304\220\304\203ng nh\341\272\255p", Q_NULLPTR));
        actionLogout->setText(QApplication::translate("MainWindow", "\304\220\304\203ng xu\341\272\245t", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Tho\303\241t", Q_NULLPTR));
        actionViewInfo->setText(QApplication::translate("MainWindow", "Xem th\303\264ng tin c\303\241 nh\303\242n", Q_NULLPTR));
        actionChangePass->setText(QApplication::translate("MainWindow", "\304\220\341\273\225i m\341\272\255t kh\341\272\251u", Q_NULLPTR));
        actionChangeRole->setText(QApplication::translate("MainWindow", "\304\220\304\203ng nh\341\272\255p vai tr\303\262 kh\303\241c", Q_NULLPTR));
        menuT_i_kho_n->setTitle(QApplication::translate("MainWindow", "T\303\240i kho\341\272\243n", Q_NULLPTR));
        menuTh_ng_tin->setTitle(QApplication::translate("MainWindow", "Th\303\264ng tin", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
