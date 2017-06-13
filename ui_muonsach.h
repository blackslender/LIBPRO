/********************************************************************************
** Form generated from reading UI file 'muonsach.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUONSACH_H
#define UI_MUONSACH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_MuonSach
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtName;
    QLabel *label_6;
    QLineEdit *txtAuthor;
    QLabel *label_7;
    QLineEdit *txtType;
    QLabel *label_8;
    QLineEdit *txtNum;
    QLabel *label_9;
    QLineEdit *txtCost;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QDateEdit *dateLay;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QDateEdit *dateTra;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *SoLuong;
    QSpacerItem *horizontalSpacer_3;
    QDialogButtonBox *buttonBox;
    QLabel *label_5;

    void setupUi(QDialog *MuonSach)
    {
        if (MuonSach->objectName().isEmpty())
            MuonSach->setObjectName(QStringLiteral("MuonSach"));
        MuonSach->resize(361, 290);
        formLayout = new QFormLayout(MuonSach);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(MuonSach);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        txtName = new QLineEdit(MuonSach);
        txtName->setObjectName(QStringLiteral("txtName"));
        txtName->setEnabled(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, txtName);

        label_6 = new QLabel(MuonSach);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_6);

        txtAuthor = new QLineEdit(MuonSach);
        txtAuthor->setObjectName(QStringLiteral("txtAuthor"));
        txtAuthor->setEnabled(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, txtAuthor);

        label_7 = new QLabel(MuonSach);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_7);

        txtType = new QLineEdit(MuonSach);
        txtType->setObjectName(QStringLiteral("txtType"));
        txtType->setEnabled(false);

        formLayout->setWidget(3, QFormLayout::FieldRole, txtType);

        label_8 = new QLabel(MuonSach);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_8);

        txtNum = new QLineEdit(MuonSach);
        txtNum->setObjectName(QStringLiteral("txtNum"));
        txtNum->setEnabled(false);

        formLayout->setWidget(4, QFormLayout::FieldRole, txtNum);

        label_9 = new QLabel(MuonSach);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_9);

        txtCost = new QLineEdit(MuonSach);
        txtCost->setObjectName(QStringLiteral("txtCost"));
        txtCost->setEnabled(false);

        formLayout->setWidget(5, QFormLayout::FieldRole, txtCost);

        label_2 = new QLabel(MuonSach);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        dateLay = new QDateEdit(MuonSach);
        dateLay->setObjectName(QStringLiteral("dateLay"));

        horizontalLayout->addWidget(dateLay);

        horizontalSpacer = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        formLayout->setLayout(6, QFormLayout::FieldRole, horizontalLayout);

        label_3 = new QLabel(MuonSach);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        dateTra = new QDateEdit(MuonSach);
        dateTra->setObjectName(QStringLiteral("dateTra"));

        horizontalLayout_2->addWidget(dateTra);

        horizontalSpacer_2 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        formLayout->setLayout(7, QFormLayout::FieldRole, horizontalLayout_2);

        label_4 = new QLabel(MuonSach);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        SoLuong = new QSpinBox(MuonSach);
        SoLuong->setObjectName(QStringLiteral("SoLuong"));

        horizontalLayout_3->addWidget(SoLuong);

        horizontalSpacer_3 = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        formLayout->setLayout(8, QFormLayout::FieldRole, horizontalLayout_3);

        buttonBox = new QDialogButtonBox(MuonSach);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(9, QFormLayout::SpanningRole, buttonBox);

        label_5 = new QLabel(MuonSach);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font;
        font.setPointSize(18);
        label_5->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, label_5);


        retranslateUi(MuonSach);
        QObject::connect(buttonBox, SIGNAL(accepted()), MuonSach, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MuonSach, SLOT(reject()));

        QMetaObject::connectSlotsByName(MuonSach);
    } // setupUi

    void retranslateUi(QDialog *MuonSach)
    {
        MuonSach->setWindowTitle(QApplication::translate("MuonSach", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("MuonSach", "T\303\252n s\303\241ch:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MuonSach", "T\303\241c gi\341\272\243:", Q_NULLPTR));
        label_7->setText(QApplication::translate("MuonSach", "Lo\341\272\241i s\303\241ch:", Q_NULLPTR));
        label_8->setText(QApplication::translate("MuonSach", "S\341\273\221 l\306\260\341\273\243ng:", Q_NULLPTR));
        label_9->setText(QApplication::translate("MuonSach", "Gi\303\241 b\303\254a:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MuonSach", "Ng\303\240y l\341\272\245y s\303\241ch:", Q_NULLPTR));
        dateLay->setDisplayFormat(QApplication::translate("MuonSach", "dd/MM/yyyy", Q_NULLPTR));
        label_3->setText(QApplication::translate("MuonSach", "Ng\303\240y h\341\272\271n tr\341\272\243:", Q_NULLPTR));
        dateTra->setDisplayFormat(QApplication::translate("MuonSach", "dd/MM/yyyy", Q_NULLPTR));
        label_4->setText(QApplication::translate("MuonSach", "S\341\273\221 l\306\260\341\273\243ng m\306\260\341\273\243n:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MuonSach", "<font color=\"red\">LIBPRO</font>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MuonSach: public Ui_MuonSach {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUONSACH_H
