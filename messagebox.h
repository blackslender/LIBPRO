#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H
#include <QMessageBox>

class MyMessageBox : public QMessageBox
{
public:
    MyMessageBox();
private:
    int timeout;
    bool autoClose;
    int currentTime;
public:
void showEvent(QShowEvent *event);
void timerEvent(QTimerEvent* event);
void setautoClose(bool val)
{
    autoClose=val;
}
void settimeout(int val)
{
    timeout=val;
}
};

#endif // MESSAGEBOX_H
