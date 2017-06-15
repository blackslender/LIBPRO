#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <QDialog>
#include <QSqlDatabase>
#include "user.h"
#include <QMessageBox>
namespace Ui {
class Feedback;
}

class Feedback : public QDialog
{
    Q_OBJECT

public:
    explicit Feedback(QWidget *parent = 0);
    ~Feedback();

private slots:
    void on_btnSend_released();

    void on_btnCancel_released();

private:
    Ui::Feedback *ui;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","FEEDBACK");
};

#endif // FEEDBACK_H
