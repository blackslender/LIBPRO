/********************************************************************************
** Form generated from reading UI file 'themsachs.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEMSACHS_H
#define UI_THEMSACHS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ThemSachs
{
public:
    QFormLayout *formLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *txtName;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *txtAuthor;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *txtNxb;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *txtType;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *txtGia;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_6;
    QDateEdit *dateNhap;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_6;
    QFormLayout *formLayout;
    QSpinBox *spinSoLuong;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_7;
    QFormLayout *formLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QTextEdit *txtContent;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer;
    QLabel *label_9;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *btnAdd;
    QPushButton *btnExit;

    void setupUi(QDialog *ThemSachs)
    {
        if (ThemSachs->objectName().isEmpty())
            ThemSachs->setObjectName(QStringLiteral("ThemSachs"));
        ThemSachs->resize(401, 516);
        formLayout_3 = new QFormLayout(ThemSachs);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label = new QLabel(ThemSachs);
        label->setObjectName(QStringLiteral("label"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        txtName = new QLineEdit(ThemSachs);
        txtName->setObjectName(QStringLiteral("txtName"));

        horizontalLayout->addWidget(txtName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        formLayout_3->setLayout(0, QFormLayout::FieldRole, horizontalLayout);

        label_2 = new QLabel(ThemSachs);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        txtAuthor = new QLineEdit(ThemSachs);
        txtAuthor->setObjectName(QStringLiteral("txtAuthor"));

        horizontalLayout_2->addWidget(txtAuthor);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        formLayout_3->setLayout(1, QFormLayout::FieldRole, horizontalLayout_2);

        label_8 = new QLabel(ThemSachs);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        txtNxb = new QLineEdit(ThemSachs);
        txtNxb->setObjectName(QStringLiteral("txtNxb"));

        horizontalLayout_3->addWidget(txtNxb);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        formLayout_3->setLayout(2, QFormLayout::FieldRole, horizontalLayout_3);

        label_3 = new QLabel(ThemSachs);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        txtType = new QLineEdit(ThemSachs);
        txtType->setObjectName(QStringLiteral("txtType"));

        horizontalLayout_4->addWidget(txtType);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        formLayout_3->setLayout(3, QFormLayout::FieldRole, horizontalLayout_4);

        label_4 = new QLabel(ThemSachs);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        txtGia = new QLineEdit(ThemSachs);
        txtGia->setObjectName(QStringLiteral("txtGia"));

        horizontalLayout_5->addWidget(txtGia);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        formLayout_3->setLayout(4, QFormLayout::FieldRole, horizontalLayout_5);

        label_5 = new QLabel(ThemSachs);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_3->setWidget(5, QFormLayout::LabelRole, label_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        dateNhap = new QDateEdit(ThemSachs);
        dateNhap->setObjectName(QStringLiteral("dateNhap"));

        horizontalLayout_6->addWidget(dateNhap);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        formLayout_3->setLayout(5, QFormLayout::FieldRole, horizontalLayout_6);

        label_6 = new QLabel(ThemSachs);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_3->setWidget(6, QFormLayout::LabelRole, label_6);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        spinSoLuong = new QSpinBox(ThemSachs);
        spinSoLuong->setObjectName(QStringLiteral("spinSoLuong"));

        formLayout->setWidget(0, QFormLayout::LabelRole, spinSoLuong);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(0, QFormLayout::FieldRole, horizontalSpacer_8);


        formLayout_3->setLayout(6, QFormLayout::FieldRole, formLayout);

        label_7 = new QLabel(ThemSachs);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_3->setWidget(7, QFormLayout::LabelRole, label_7);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        txtContent = new QTextEdit(ThemSachs);
        txtContent->setObjectName(QStringLiteral("txtContent"));

        horizontalLayout_8->addWidget(txtContent);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, horizontalLayout_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(1, QFormLayout::LabelRole, verticalSpacer);


        formLayout_3->setLayout(7, QFormLayout::FieldRole, formLayout_2);

        label_9 = new QLabel(ThemSachs);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_3->setWidget(8, QFormLayout::LabelRole, label_9);

        checkBox = new QCheckBox(ThemSachs);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setChecked(true);

        formLayout_3->setWidget(8, QFormLayout::FieldRole, checkBox);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        btnAdd = new QPushButton(ThemSachs);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));

        horizontalLayout_7->addWidget(btnAdd);

        btnExit = new QPushButton(ThemSachs);
        btnExit->setObjectName(QStringLiteral("btnExit"));

        horizontalLayout_7->addWidget(btnExit);


        formLayout_3->setLayout(10, QFormLayout::FieldRole, horizontalLayout_7);


        retranslateUi(ThemSachs);

        QMetaObject::connectSlotsByName(ThemSachs);
    } // setupUi

    void retranslateUi(QDialog *ThemSachs)
    {
        ThemSachs->setWindowTitle(QApplication::translate("ThemSachs", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ThemSachs", "T\303\252n s\303\241ch", Q_NULLPTR));
        label_2->setText(QApplication::translate("ThemSachs", "T\303\241c gi\341\272\243", Q_NULLPTR));
        label_8->setText(QApplication::translate("ThemSachs", "Nh\303\240 xu\341\272\245t b\341\272\243n", Q_NULLPTR));
        label_3->setText(QApplication::translate("ThemSachs", "Lo\341\272\241i s\303\241ch", Q_NULLPTR));
        label_4->setText(QApplication::translate("ThemSachs", "Gi\303\241 b\303\254a", Q_NULLPTR));
        label_5->setText(QApplication::translate("ThemSachs", "Ng\303\240y nh\341\272\255p:", Q_NULLPTR));
        label_6->setText(QApplication::translate("ThemSachs", "S\341\273\221 l\306\260\341\273\243ng", Q_NULLPTR));
        label_7->setText(QApplication::translate("ThemSachs", "N\341\273\231i dung", Q_NULLPTR));
        label_9->setText(QApplication::translate("ThemSachs", "\304\220\306\260\341\273\243c m\306\260\341\273\243n", Q_NULLPTR));
        checkBox->setText(QApplication::translate("ThemSachs", "C\303\263", Q_NULLPTR));
        btnAdd->setText(QApplication::translate("ThemSachs", "Th\303\252m", Q_NULLPTR));
        btnExit->setText(QApplication::translate("ThemSachs", "Tho\303\241t", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ThemSachs: public Ui_ThemSachs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEMSACHS_H
