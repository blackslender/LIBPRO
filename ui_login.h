/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LOGIN
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *txtUser;
    QLabel *label_2;
    QLineEdit *txtPass;
    QLabel *label_3;
    QComboBox *comboBox;
    QPushButton *btnLogin;

    void setupUi(QWidget *LOGIN)
    {
        if (LOGIN->objectName().isEmpty())
            LOGIN->setObjectName(QStringLiteral("LOGIN"));
        LOGIN->resize(233, 153);
        gridLayout = new QGridLayout(LOGIN);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(LOGIN);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        txtUser = new QLineEdit(LOGIN);
        txtUser->setObjectName(QStringLiteral("txtUser"));

        gridLayout->addWidget(txtUser, 0, 1, 1, 1);

        label_2 = new QLabel(LOGIN);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        txtPass = new QLineEdit(LOGIN);
        txtPass->setObjectName(QStringLiteral("txtPass"));
        txtPass->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(txtPass, 1, 1, 1, 1);

        label_3 = new QLabel(LOGIN);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        comboBox = new QComboBox(LOGIN);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 2, 1, 1, 1);

        btnLogin = new QPushButton(LOGIN);
        btnLogin->setObjectName(QStringLiteral("btnLogin"));

        gridLayout->addWidget(btnLogin, 3, 1, 1, 1);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(txtUser);
        label_2->setBuddy(txtPass);
#endif // QT_NO_SHORTCUT

        retranslateUi(LOGIN);

        QMetaObject::connectSlotsByName(LOGIN);
    } // setupUi

    void retranslateUi(QWidget *LOGIN)
    {
        LOGIN->setWindowTitle(QApplication::translate("LOGIN", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("LOGIN", "&T\303\252n \304\221\304\203ng nh\341\272\255p:", Q_NULLPTR));
        label_2->setText(QApplication::translate("LOGIN", "&M\341\272\255t kh\341\272\251u:", Q_NULLPTR));
        label_3->setText(QApplication::translate("LOGIN", "Vai tr\303\262:", Q_NULLPTR));
        btnLogin->setText(QApplication::translate("LOGIN", "\304\220\304\203ng nh\341\272\255p", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LOGIN: public Ui_LOGIN {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
