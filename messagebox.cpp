#include "messagebox.h"

MyMessageBox::MyMessageBox()
{
}
void MyMessageBox::showEvent(QShowEvent* event)
{
    currentTime=0;
    if(autoClose)
    {
        this->startTimer(1000);
    }
}
void MyMessageBox::timerEvent(QTimerEvent *event)
{
    currentTime++;
    if(currentTime>=timeout)
        this->done(0);
}
