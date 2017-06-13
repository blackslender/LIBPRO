/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QListWidget *listAdmin;
    QStackedWidget *stackedWidget;
    QWidget *page_2;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QLineEdit *txtContent;
    QPushButton *pushButton;
    QTableView *tableUser;
    QWidget *page;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtUser;
    QLabel *label_2;
    QLineEdit *txtPass;
    QLabel *label_3;
    QLineEdit *txtRePass;
    QLabel *label_4;
    QLineEdit *txtPhone;
    QLabel *label_5;
    QLineEdit *txtEmail;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *checkActive;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkAdmin;
    QCheckBox *checkLib;
    QCheckBox *checkRead;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *btnOK;
    QPushButton *btnReset;
    QSpacerItem *horizontalSpacer_8;

    void setupUi(QWidget *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName(QStringLiteral("Admin"));
        Admin->resize(712, 310);
        listAdmin = new QListWidget(Admin);
        listAdmin->setObjectName(QStringLiteral("listAdmin"));
        listAdmin->setGeometry(QRect(10, 30, 111, 192));
        stackedWidget = new QStackedWidget(Admin);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(139, 20, 561, 271));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        gridLayout = new QGridLayout(page_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_8 = new QLabel(page_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 0, 0, 1, 1);

        txtContent = new QLineEdit(page_2);
        txtContent->setObjectName(QStringLiteral("txtContent"));

        gridLayout->addWidget(txtContent, 0, 1, 1, 1);

        pushButton = new QPushButton(page_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);

        tableUser = new QTableView(page_2);
        tableUser->setObjectName(QStringLiteral("tableUser"));

        gridLayout->addWidget(tableUser, 1, 0, 1, 3);

        stackedWidget->addWidget(page_2);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        formLayout = new QFormLayout(page);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtUser = new QLineEdit(page);
        txtUser->setObjectName(QStringLiteral("txtUser"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtUser);

        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        txtPass = new QLineEdit(page);
        txtPass->setObjectName(QStringLiteral("txtPass"));
        txtPass->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, txtPass);

        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        txtRePass = new QLineEdit(page);
        txtRePass->setObjectName(QStringLiteral("txtRePass"));
        txtRePass->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::FieldRole, txtRePass);

        label_4 = new QLabel(page);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        txtPhone = new QLineEdit(page);
        txtPhone->setObjectName(QStringLiteral("txtPhone"));

        formLayout->setWidget(3, QFormLayout::FieldRole, txtPhone);

        label_5 = new QLabel(page);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        txtEmail = new QLineEdit(page);
        txtEmail->setObjectName(QStringLiteral("txtEmail"));

        formLayout->setWidget(4, QFormLayout::FieldRole, txtEmail);

        label_6 = new QLabel(page);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        checkActive = new QCheckBox(page);
        checkActive->setObjectName(QStringLiteral("checkActive"));
        checkActive->setChecked(true);

        horizontalLayout_7->addWidget(checkActive);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);


        formLayout->setLayout(5, QFormLayout::FieldRole, horizontalLayout_7);

        label_7 = new QLabel(page);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkAdmin = new QCheckBox(page);
        checkAdmin->setObjectName(QStringLiteral("checkAdmin"));

        horizontalLayout->addWidget(checkAdmin);

        checkLib = new QCheckBox(page);
        checkLib->setObjectName(QStringLiteral("checkLib"));

        horizontalLayout->addWidget(checkLib);

        checkRead = new QCheckBox(page);
        checkRead->setObjectName(QStringLiteral("checkRead"));
        checkRead->setChecked(true);

        horizontalLayout->addWidget(checkRead);


        formLayout->setLayout(6, QFormLayout::FieldRole, horizontalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);

        btnOK = new QPushButton(page);
        btnOK->setObjectName(QStringLiteral("btnOK"));

        horizontalLayout_8->addWidget(btnOK);

        btnReset = new QPushButton(page);
        btnReset->setObjectName(QStringLiteral("btnReset"));

        horizontalLayout_8->addWidget(btnReset);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);


        formLayout->setLayout(7, QFormLayout::FieldRole, horizontalLayout_8);

        stackedWidget->addWidget(page);

        retranslateUi(Admin);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QWidget *Admin)
    {
        Admin->setWindowTitle(QApplication::translate("Admin", "Form", Q_NULLPTR));
        label_8->setText(QApplication::translate("Admin", "UserName", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Admin", "T\303\254m ki\341\272\277m", Q_NULLPTR));
        label->setText(QApplication::translate("Admin", "T\303\252n \304\221\304\203ng nh\341\272\255p", Q_NULLPTR));
        label_2->setText(QApplication::translate("Admin", "M\341\272\255t kh\341\272\251u", Q_NULLPTR));
        label_3->setText(QApplication::translate("Admin", "Nh\341\272\255p l\341\272\241i m\341\272\255t kh\341\272\251u", Q_NULLPTR));
        label_4->setText(QApplication::translate("Admin", "\304\220i\341\273\207n tho\341\272\241i", Q_NULLPTR));
        label_5->setText(QApplication::translate("Admin", "Email", Q_NULLPTR));
        label_6->setText(QApplication::translate("Admin", "Active", Q_NULLPTR));
        checkActive->setText(QApplication::translate("Admin", "C\303\263", Q_NULLPTR));
        label_7->setText(QApplication::translate("Admin", "Vai tr\303\262", Q_NULLPTR));
        checkAdmin->setText(QApplication::translate("Admin", "Qu\341\272\243n l\303\275 ng\306\260\341\273\235i d\303\271ng", Q_NULLPTR));
        checkLib->setText(QApplication::translate("Admin", "Th\341\273\247 th\306\260", Q_NULLPTR));
        checkRead->setText(QApplication::translate("Admin", "\304\220\341\273\231c gi\341\272\243", Q_NULLPTR));
        btnOK->setText(QApplication::translate("Admin", "OK", Q_NULLPTR));
        btnReset->setText(QApplication::translate("Admin", "Reset", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
