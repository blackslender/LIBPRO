/********************************************************************************
** Form generated from reading UI file 'adduser.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSER_H
#define UI_ADDUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddUser
{
public:
    QFormLayout *formLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *txtUser;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *txtPass;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *txtPhone;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *txtEmail;
    QLabel *label_6;
    QCheckBox *checkActive;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout;
    QCheckBox *CheckAdmin;
    QCheckBox *CheckLib;
    QCheckBox *CheckRead;
    QDialogButtonBox *buttonBox;
    QLabel *label_3;
    QCheckBox *checkBox;

    void setupUi(QDialog *AddUser)
    {
        if (AddUser->objectName().isEmpty())
            AddUser->setObjectName(QStringLiteral("AddUser"));
        AddUser->resize(372, 288);
        formLayout_2 = new QFormLayout(AddUser);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label = new QLabel(AddUser);
        label->setObjectName(QStringLiteral("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        txtUser = new QLineEdit(AddUser);
        txtUser->setObjectName(QStringLiteral("txtUser"));

        horizontalLayout_2->addWidget(txtUser);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, horizontalLayout_2);

        label_2 = new QLabel(AddUser);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        txtPass = new QLineEdit(AddUser);
        txtPass->setObjectName(QStringLiteral("txtPass"));
        txtPass->setEnabled(false);

        horizontalLayout_3->addWidget(txtPass);


        formLayout_2->setLayout(2, QFormLayout::FieldRole, horizontalLayout_3);

        label_4 = new QLabel(AddUser);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        txtPhone = new QLineEdit(AddUser);
        txtPhone->setObjectName(QStringLiteral("txtPhone"));

        horizontalLayout_5->addWidget(txtPhone);


        formLayout_2->setLayout(3, QFormLayout::FieldRole, horizontalLayout_5);

        label_5 = new QLabel(AddUser);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        txtEmail = new QLineEdit(AddUser);
        txtEmail->setObjectName(QStringLiteral("txtEmail"));

        horizontalLayout_6->addWidget(txtEmail);


        formLayout_2->setLayout(4, QFormLayout::FieldRole, horizontalLayout_6);

        label_6 = new QLabel(AddUser);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_6);

        checkActive = new QCheckBox(AddUser);
        checkActive->setObjectName(QStringLiteral("checkActive"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, checkActive);

        label_7 = new QLabel(AddUser);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        CheckAdmin = new QCheckBox(AddUser);
        CheckAdmin->setObjectName(QStringLiteral("CheckAdmin"));

        horizontalLayout->addWidget(CheckAdmin);

        CheckLib = new QCheckBox(AddUser);
        CheckLib->setObjectName(QStringLiteral("CheckLib"));

        horizontalLayout->addWidget(CheckLib);

        CheckRead = new QCheckBox(AddUser);
        CheckRead->setObjectName(QStringLiteral("CheckRead"));

        horizontalLayout->addWidget(CheckRead);


        formLayout_2->setLayout(6, QFormLayout::FieldRole, horizontalLayout);

        buttonBox = new QDialogButtonBox(AddUser);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout_2->setWidget(7, QFormLayout::FieldRole, buttonBox);

        label_3 = new QLabel(AddUser);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_3);

        checkBox = new QCheckBox(AddUser);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, checkBox);


        retranslateUi(AddUser);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddUser, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddUser, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddUser);
    } // setupUi

    void retranslateUi(QDialog *AddUser)
    {
        AddUser->setWindowTitle(QApplication::translate("AddUser", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("AddUser", "T\303\252n \304\221\304\203ng nh\341\272\255p:", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddUser", "M\341\272\255t kh\341\272\251u", Q_NULLPTR));
        label_4->setText(QApplication::translate("AddUser", "S\341\273\221 \304\221i\341\273\207n tho\341\272\241i", Q_NULLPTR));
        label_5->setText(QApplication::translate("AddUser", "Email", Q_NULLPTR));
        label_6->setText(QApplication::translate("AddUser", "Active", Q_NULLPTR));
        checkActive->setText(QApplication::translate("AddUser", "C\303\263", Q_NULLPTR));
        label_7->setText(QApplication::translate("AddUser", "Vai tr\303\262", Q_NULLPTR));
        CheckAdmin->setText(QApplication::translate("AddUser", "Qu\341\272\243n l\303\275", Q_NULLPTR));
        CheckLib->setText(QApplication::translate("AddUser", "Th\341\273\247 th\306\260", Q_NULLPTR));
        CheckRead->setText(QApplication::translate("AddUser", "\304\220\341\273\231c gi\341\272\243", Q_NULLPTR));
        label_3->setText(QApplication::translate("AddUser", "\304\220\341\272\267t l\341\272\241i m\341\272\255t kh\341\272\251u:", Q_NULLPTR));
        checkBox->setText(QApplication::translate("AddUser", "C\303\263", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddUser: public Ui_AddUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSER_H
