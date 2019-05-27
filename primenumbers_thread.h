#ifndef PRIMENUMBERS_THREAD_H
#define PRIMENUMBERS_THREAD_H

#include <QThread>
#include <QObject>
#include <QSpinBox>
#include "singalton.h"
#include "prime_singalton.h"

class primenumbers_thread : public QThread
{
    Q_OBJECT
public:
    explicit primenumbers_thread(QObject *parent = nullptr);
    void run();
    bool stop;
    void SieveOfEratosthenes(int);
    //long int multiplyNumbers(long int);
    prime_singalton *p;

signals:
    void p_through();

};

#endif // PRIMENUMBERS_THREAD_H
