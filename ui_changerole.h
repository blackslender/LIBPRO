/********************************************************************************
** Form generated from reading UI file 'changerole.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEROLE_H
#define UI_CHANGEROLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_ChangeRole
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *rAdmin;
    QRadioButton *rLib;
    QRadioButton *rRead;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ChangeRole)
    {
        if (ChangeRole->objectName().isEmpty())
            ChangeRole->setObjectName(QStringLiteral("ChangeRole"));
        ChangeRole->resize(193, 189);
        gridLayout_2 = new QGridLayout(ChangeRole);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(ChangeRole);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        rAdmin = new QRadioButton(groupBox);
        rAdmin->setObjectName(QStringLiteral("rAdmin"));
        rAdmin->setChecked(true);

        gridLayout->addWidget(rAdmin, 0, 0, 1, 1);

        rLib = new QRadioButton(groupBox);
        rLib->setObjectName(QStringLiteral("rLib"));

        gridLayout->addWidget(rLib, 1, 0, 1, 1);

        rRead = new QRadioButton(groupBox);
        rRead->setObjectName(QStringLiteral("rRead"));

        gridLayout->addWidget(rRead, 2, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(ChangeRole);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(ChangeRole);
        QObject::connect(buttonBox, SIGNAL(accepted()), ChangeRole, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ChangeRole, SLOT(reject()));

        QMetaObject::connectSlotsByName(ChangeRole);
    } // setupUi

    void retranslateUi(QDialog *ChangeRole)
    {
        ChangeRole->setWindowTitle(QApplication::translate("ChangeRole", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ChangeRole", "Vai tro", Q_NULLPTR));
        rAdmin->setText(QApplication::translate("ChangeRole", "Quan ly nguoi dung", Q_NULLPTR));
        rLib->setText(QApplication::translate("ChangeRole", "Quan ly thu vien", Q_NULLPTR));
        rRead->setText(QApplication::translate("ChangeRole", "Doc gia", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChangeRole: public Ui_ChangeRole {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEROLE_H
