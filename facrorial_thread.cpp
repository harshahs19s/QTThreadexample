#include "facrorial_thread.h"
#include "singalton.h"
#include <QDebug>
facrorial_thread::facrorial_thread(QObject *parent) : QThread(parent)
{
    f = singalton::getInstance();
//this->stop = false;
}
void facrorial_thread::run()
{


   f->flag=0;
   f->result = multiplyNumbers(f->factn);
   f->flag=1;
   qDebug()<<f->result;

}

long int facrorial_thread::multiplyNumbers(long int n)
{
    this->msleep(500);
    if(stop == true)
        return 0;
    if (n >= 1)
    {
        emit f_through();
        qDebug()<<"hi";
        return n*multiplyNumbers(n-1);
    }
    else
    {
        emit f_through();
        return 1;
    }

}
