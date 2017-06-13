/********************************************************************************
** Form generated from reading UI file 'reader.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READER_H
#define UI_READER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
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

class Ui_READER
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label_4;
    QLineEdit *txtContent;
    QLabel *label_3;
    QComboBox *FilterBox;
    QPushButton *btnSearch;
    QTableView *tableBook;
    QWidget *page_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QTableView *tableMuon;
    QWidget *page_3;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QComboBox *Filter2;
    QTableView *tablenews;
    QListWidget *listWidget;

    void setupUi(QWidget *READER)
    {
        if (READER->objectName().isEmpty())
            READER->setObjectName(QStringLiteral("READER"));
        READER->resize(528, 312);
        stackedWidget = new QStackedWidget(READER);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(110, 10, 288, 266));
        stackedWidget->setStyleSheet(QStringLiteral("border-color: rgb(255, 85, 255);"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        gridLayout = new QGridLayout(page);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_4 = new QLabel(page);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        txtContent = new QLineEdit(page);
        txtContent->setObjectName(QStringLiteral("txtContent"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtContent);

        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        FilterBox = new QComboBox(page);
        FilterBox->setObjectName(QStringLiteral("FilterBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, FilterBox);


        horizontalLayout->addLayout(formLayout);

        btnSearch = new QPushButton(page);
        btnSearch->setObjectName(QStringLiteral("btnSearch"));

        horizontalLayout->addWidget(btnSearch);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tableBook = new QTableView(page);
        tableBook->setObjectName(QStringLiteral("tableBook"));

        gridLayout->addWidget(tableBook, 1, 0, 2, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        gridLayout_2 = new QGridLayout(page_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(page_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        tableMuon = new QTableView(page_2);
        tableMuon->setObjectName(QStringLiteral("tableMuon"));

        gridLayout_2->addWidget(tableMuon, 1, 0, 1, 1);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        gridLayout_3 = new QGridLayout(page_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        Filter2 = new QComboBox(page_3);
        Filter2->setObjectName(QStringLiteral("Filter2"));

        horizontalLayout_2->addWidget(Filter2);


        gridLayout_3->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        tablenews = new QTableView(page_3);
        tablenews->setObjectName(QStringLiteral("tablenews"));

        gridLayout_3->addWidget(tablenews, 1, 0, 1, 1);

        stackedWidget->addWidget(page_3);
        listWidget = new QListWidget(READER);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 20, 91, 192));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        retranslateUi(READER);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(READER);
    } // setupUi

    void retranslateUi(QWidget *READER)
    {
        READER->setWindowTitle(QApplication::translate("READER", "Form", Q_NULLPTR));
        label_4->setText(QApplication::translate("READER", "N\341\273\231i dung:", Q_NULLPTR));
        label_3->setText(QApplication::translate("READER", "L\341\273\215c theo:", Q_NULLPTR));
        btnSearch->setText(QApplication::translate("READER", "T\303\254m", Q_NULLPTR));
        label->setText(QApplication::translate("READER", "S\303\241ch \304\221ang ch\341\273\235 duy\341\273\207t:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class READER: public Ui_READER {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READER_H
