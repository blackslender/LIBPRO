/********************************************************************************
** Form generated from reading UI file 'changepass.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASS_H
#define UI_CHANGEPASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangePass
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtOld;
    QLabel *label_2;
    QLineEdit *txtNew;
    QLabel *label_3;
    QLineEdit *txtRepeat;
    QPushButton *pushButton;

    void setupUi(QWidget *ChangePass)
    {
        if (ChangePass->objectName().isEmpty())
            ChangePass->setObjectName(QStringLiteral("ChangePass"));
        ChangePass->resize(238, 125);
        formLayout = new QFormLayout(ChangePass);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(ChangePass);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtOld = new QLineEdit(ChangePass);
        txtOld->setObjectName(QStringLiteral("txtOld"));
        txtOld->setMaxLength(20);
        txtOld->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(0, QFormLayout::FieldRole, txtOld);

        label_2 = new QLabel(ChangePass);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        txtNew = new QLineEdit(ChangePass);
        txtNew->setObjectName(QStringLiteral("txtNew"));
        txtNew->setMaxLength(20);
        txtNew->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, txtNew);

        label_3 = new QLabel(ChangePass);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        txtRepeat = new QLineEdit(ChangePass);
        txtRepeat->setObjectName(QStringLiteral("txtRepeat"));
        txtRepeat->setMaxLength(20);
        txtRepeat->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::FieldRole, txtRepeat);

        pushButton = new QPushButton(ChangePass);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        formLayout->setWidget(4, QFormLayout::FieldRole, pushButton);


        retranslateUi(ChangePass);

        QMetaObject::connectSlotsByName(ChangePass);
    } // setupUi

    void retranslateUi(QWidget *ChangePass)
    {
        ChangePass->setWindowTitle(QApplication::translate("ChangePass", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("ChangePass", "M\341\272\255t kh\341\272\251u c\305\251:", Q_NULLPTR));
        label_2->setText(QApplication::translate("ChangePass", "M\341\272\255t kh\341\272\251u m\341\273\233i:", Q_NULLPTR));
        label_3->setText(QApplication::translate("ChangePass", "Nh\341\272\255p l\341\272\241i l\341\272\247n n\341\273\257a:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ChangePass", "\304\220\341\273\225i m\341\272\255t kh\341\272\251u", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChangePass: public Ui_ChangePass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASS_H
