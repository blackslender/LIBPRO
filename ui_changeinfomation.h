/********************************************************************************
** Form generated from reading UI file 'changeinfomation.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEINFOMATION_H
#define UI_CHANGEINFOMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeInfomation
{
public:
    QFormLayout *formLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *txtID;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *txtUser;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *txtPass;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *txtName;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *txtAddress;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_8;
    QDateEdit *dateBirth;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *txtPhone;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *txtEmail;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnUpdate;
    QLabel *label;

    void setupUi(QWidget *ChangeInfomation)
    {
        if (ChangeInfomation->objectName().isEmpty())
            ChangeInfomation->setObjectName(QStringLiteral("ChangeInfomation"));
        ChangeInfomation->resize(313, 367);
        formLayout = new QFormLayout(ChangeInfomation);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(ChangeInfomation);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        txtID = new QLineEdit(ChangeInfomation);
        txtID->setObjectName(QStringLiteral("txtID"));
        txtID->setEnabled(false);

        horizontalLayout_3->addWidget(txtID);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_3);

        label_3 = new QLabel(ChangeInfomation);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        txtUser = new QLineEdit(ChangeInfomation);
        txtUser->setObjectName(QStringLiteral("txtUser"));
        txtUser->setEnabled(false);

        horizontalLayout_4->addWidget(txtUser);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_4);

        label_4 = new QLabel(ChangeInfomation);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        txtPass = new QLineEdit(ChangeInfomation);
        txtPass->setObjectName(QStringLiteral("txtPass"));
        txtPass->setEnabled(false);
        txtPass->setEchoMode(QLineEdit::Password);

        horizontalLayout_5->addWidget(txtPass);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_5);

        label_5 = new QLabel(ChangeInfomation);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        txtName = new QLineEdit(ChangeInfomation);
        txtName->setObjectName(QStringLiteral("txtName"));

        horizontalLayout_6->addWidget(txtName);


        formLayout->setLayout(5, QFormLayout::FieldRole, horizontalLayout_6);

        label_6 = new QLabel(ChangeInfomation);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        txtAddress = new QLineEdit(ChangeInfomation);
        txtAddress->setObjectName(QStringLiteral("txtAddress"));

        horizontalLayout_7->addWidget(txtAddress);


        formLayout->setLayout(6, QFormLayout::FieldRole, horizontalLayout_7);

        label_7 = new QLabel(ChangeInfomation);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        dateBirth = new QDateEdit(ChangeInfomation);
        dateBirth->setObjectName(QStringLiteral("dateBirth"));

        horizontalLayout_8->addWidget(dateBirth);


        formLayout->setLayout(7, QFormLayout::FieldRole, horizontalLayout_8);

        label_8 = new QLabel(ChangeInfomation);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        txtPhone = new QLineEdit(ChangeInfomation);
        txtPhone->setObjectName(QStringLiteral("txtPhone"));
        txtPhone->setEnabled(false);

        horizontalLayout_9->addWidget(txtPhone);


        formLayout->setLayout(8, QFormLayout::FieldRole, horizontalLayout_9);

        label_9 = new QLabel(ChangeInfomation);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        txtEmail = new QLineEdit(ChangeInfomation);
        txtEmail->setObjectName(QStringLiteral("txtEmail"));
        txtEmail->setEnabled(false);

        horizontalLayout_10->addWidget(txtEmail);


        formLayout->setLayout(9, QFormLayout::FieldRole, horizontalLayout_10);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnUpdate = new QPushButton(ChangeInfomation);
        btnUpdate->setObjectName(QStringLiteral("btnUpdate"));

        horizontalLayout->addWidget(btnUpdate);


        formLayout->setLayout(10, QFormLayout::FieldRole, horizontalLayout);

        label = new QLabel(ChangeInfomation);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);


        retranslateUi(ChangeInfomation);

        QMetaObject::connectSlotsByName(ChangeInfomation);
    } // setupUi

    void retranslateUi(QWidget *ChangeInfomation)
    {
        ChangeInfomation->setWindowTitle(QApplication::translate("ChangeInfomation", "Form", Q_NULLPTR));
        label_2->setText(QApplication::translate("ChangeInfomation", "ID:", Q_NULLPTR));
        label_3->setText(QApplication::translate("ChangeInfomation", "T\303\252n \304\221\304\203ng nh\341\272\255p:", Q_NULLPTR));
        label_4->setText(QApplication::translate("ChangeInfomation", "M\341\272\255t kh\341\272\251u:", Q_NULLPTR));
        label_5->setText(QApplication::translate("ChangeInfomation", "H\341\273\215 v\303\240 t\303\252n:", Q_NULLPTR));
        label_6->setText(QApplication::translate("ChangeInfomation", "\304\220\341\273\213a ch\341\273\211:", Q_NULLPTR));
        label_7->setText(QApplication::translate("ChangeInfomation", "Ng\303\240y sinh:", Q_NULLPTR));
        label_8->setText(QApplication::translate("ChangeInfomation", "S\341\273\221 \304\221i\341\273\207n tho\341\272\241i:", Q_NULLPTR));
        label_9->setText(QApplication::translate("ChangeInfomation", "Email:", Q_NULLPTR));
        btnUpdate->setText(QApplication::translate("ChangeInfomation", "C\341\272\255p nh\341\272\255t", Q_NULLPTR));
        label->setText(QApplication::translate("ChangeInfomation", "<b>Th\303\264ng tin c\303\241 nh\303\242n</b>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChangeInfomation: public Ui_ChangeInfomation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEINFOMATION_H
