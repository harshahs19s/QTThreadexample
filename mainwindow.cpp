#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "facrorial_thread.h"
#include "singalton.h"
#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    n=0;
    ui->progressBar->setValue(0);
    ui->progressBar_2->setValue(0);
    f_in = singalton::getInstance();
    p_in = prime_singalton::getInstance();

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    f_in->factn = ui->spinBox->value();
    f = new facrorial_thread(this);
    connect(f,SIGNAL(f_through()),this,SLOT(factorial()));
    f->start();
     n=(5*f_in->factn)/100;
     per = (n*100)/f_in->factn;


}

void MainWindow::factorial()
{

    per +=5;
    ui->progressBar->setValue(per);
    if(f_in->flag==1)
    {
        ui->progressBar->setValue(100);
        f_in->flag=0;
        ui->textEdit->setText(QString::number(f_in->result));

    }
    else {
          ui->textEdit->setText("0");
        }


// qDebug()<<"result"<<f_in->result;

}

void MainWindow::prime()
{
    for(int i=0;p_in->result[i]!=NULL;i++)
{
    qDebug()<<p_in->result[i];
    ui->textEdit_2->append(QString::number(p_in->result[i]));

   // p_in->result[i]=0;
}
ui->progressBar_2->setValue(100);

}

void MainWindow::on_pushButton_2_clicked()
{
    p_in->prime = ui->spinBox_2->value();
    ui->textEdit_2->setText("");
    p = new primenumbers_thread(this);
    connect(p,SIGNAL(p_through()),this,SLOT(prime()));
    p->start();

}

void MainWindow::on_pushButton_6_clicked()
{
    ui->progressBar_2->setValue(0);
    ui->textEdit_2->setText("");
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->progressBar->setValue(0);
    ui->textEdit->setText("");
}

void MainWindow::on_pushButton_3_clicked()
{
    f->stop=true;

}

void MainWindow::on_pushButton_5_clicked()
{
    ui->progressBar_2->setValue(0);
    ui->textEdit_2->setText("");
}
