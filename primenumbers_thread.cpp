#include "primenumbers_thread.h"
#include "QDebug"
#include"prime_singalton.h"

primenumbers_thread::primenumbers_thread(QObject *parent): QThread(parent)
{

    p = prime_singalton::getInstance();
}

void primenumbers_thread::run()
{

    SieveOfEratosthenes(p->prime);
}

void primenumbers_thread::SieveOfEratosthenes(int n)
{
    int arr[5000] = {0};


       for (int i = 2; i < n; i++)
       {
           for (int j = i * i; j < n; j+=i)
           {
               arr[j - 1] = 1;
           }

       }
       int j=0;
       for (int i = 1; i < n; i++)
       {
           if (arr[i - 1] == 0)
           {
              // qDebug()<<i;
               p->result[j] = i;
               // qDebug()<<p->result[j];
              // emit p_through();
               j++;
           }
       }
       p->result[j] = NULL;

    emit p_through();
}
