/********************************************************************************
** Form generated from reading UI file 'librarian.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBRARIAN_H
#define UI_LIBRARIAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Librarian
{
public:
    QListWidget *listAction;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *txtContent;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *Filter;
    QPushButton *btnSearch;
    QTableView *tableSach;
    QWidget *page_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QComboBox *FilterMuon;
    QGridLayout *gridLayout_2;
    QPushButton *btnTim;
    QLineEdit *txtSearch;
    QLabel *lblID;
    QTableView *tableMuon;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnPay;
    QWidget *page_3;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *txtContentPhat;
    QPushButton *btnSearchPhat;
    QTableView *tablePhat;
    QPushButton *btnXuly;

    void setupUi(QWidget *Librarian)
    {
        if (Librarian->objectName().isEmpty())
            Librarian->setObjectName(QStringLiteral("Librarian"));
        Librarian->resize(540, 310);
        listAction = new QListWidget(Librarian);
        listAction->setObjectName(QStringLiteral("listAction"));
        listAction->setGeometry(QRect(10, 70, 111, 192));
        stackedWidget = new QStackedWidget(Librarian);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(140, 29, 356, 271));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        gridLayout = new QGridLayout(page);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        txtContent = new QLineEdit(page);
        txtContent->setObjectName(QStringLiteral("txtContent"));

        horizontalLayout->addWidget(txtContent);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        Filter = new QComboBox(page);
        Filter->setObjectName(QStringLiteral("Filter"));

        horizontalLayout_2->addWidget(Filter);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);

        btnSearch = new QPushButton(page);
        btnSearch->setObjectName(QStringLiteral("btnSearch"));

        horizontalLayout_3->addWidget(btnSearch);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        tableSach = new QTableView(page);
        tableSach->setObjectName(QStringLiteral("tableSach"));

        gridLayout->addWidget(tableSach, 1, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        gridLayout_3 = new QGridLayout(page_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(118, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        FilterMuon = new QComboBox(page_2);
        FilterMuon->setObjectName(QStringLiteral("FilterMuon"));

        horizontalLayout_4->addWidget(FilterMuon);


        gridLayout_3->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        btnTim = new QPushButton(page_2);
        btnTim->setObjectName(QStringLiteral("btnTim"));

        gridLayout_2->addWidget(btnTim, 0, 2, 1, 1);

        txtSearch = new QLineEdit(page_2);
        txtSearch->setObjectName(QStringLiteral("txtSearch"));

        gridLayout_2->addWidget(txtSearch, 0, 1, 1, 1);

        lblID = new QLabel(page_2);
        lblID->setObjectName(QStringLiteral("lblID"));

        gridLayout_2->addWidget(lblID, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 0, 1, 1);

        tableMuon = new QTableView(page_2);
        tableMuon->setObjectName(QStringLiteral("tableMuon"));

        gridLayout_3->addWidget(tableMuon, 2, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        btnPay = new QPushButton(page_2);
        btnPay->setObjectName(QStringLiteral("btnPay"));
        btnPay->setEnabled(true);

        horizontalLayout_5->addWidget(btnPay);


        gridLayout_3->addLayout(horizontalLayout_5, 3, 0, 1, 1);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        gridLayout_4 = new QGridLayout(page_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        txtContentPhat = new QLineEdit(page_3);
        txtContentPhat->setObjectName(QStringLiteral("txtContentPhat"));

        horizontalLayout_6->addWidget(txtContentPhat);

        btnSearchPhat = new QPushButton(page_3);
        btnSearchPhat->setObjectName(QStringLiteral("btnSearchPhat"));

        horizontalLayout_6->addWidget(btnSearchPhat);


        gridLayout_4->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        tablePhat = new QTableView(page_3);
        tablePhat->setObjectName(QStringLiteral("tablePhat"));

        gridLayout_4->addWidget(tablePhat, 1, 0, 1, 1);

        btnXuly = new QPushButton(page_3);
        btnXuly->setObjectName(QStringLiteral("btnXuly"));

        gridLayout_4->addWidget(btnXuly, 2, 0, 1, 1);

        stackedWidget->addWidget(page_3);

        retranslateUi(Librarian);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Librarian);
    } // setupUi

    void retranslateUi(QWidget *Librarian)
    {
        Librarian->setWindowTitle(QApplication::translate("Librarian", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Librarian", "N\341\273\231i dung", Q_NULLPTR));
        label_2->setText(QApplication::translate("Librarian", "L\341\273\215c theo:", Q_NULLPTR));
        btnSearch->setText(QApplication::translate("Librarian", "T\303\254m ki\341\272\277m", Q_NULLPTR));
        btnTim->setText(QApplication::translate("Librarian", "T\303\254m ki\341\272\277m", Q_NULLPTR));
        lblID->setText(QApplication::translate("Librarian", "ID:", Q_NULLPTR));
        btnPay->setText(QApplication::translate("Librarian", "Tr\341\272\243 s\303\241ch", Q_NULLPTR));
        btnSearchPhat->setText(QApplication::translate("Librarian", "T\303\254m ki\341\272\277m", Q_NULLPTR));
        btnXuly->setText(QApplication::translate("Librarian", "Xu ly", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Librarian: public Ui_Librarian {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBRARIAN_H
