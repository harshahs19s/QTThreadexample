#ifndef FACRORIAL_THREAD_H
#define FACRORIAL_THREAD_H
#include <QThread>
#include <QObject>
#include <QSpinBox>
#include "singalton.h"

class facrorial_thread : public QThread
{
    Q_OBJECT
public:
    explicit facrorial_thread(QObject *parent = nullptr);
    void run();
    bool stop;
    long int multiplyNumbers(long int);
    singalton *f;
signals:
    void f_through();

};

#endif // FACRORIAL_THREAD_H
