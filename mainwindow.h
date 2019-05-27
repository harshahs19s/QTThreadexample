#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "facrorial_thread.h"
#include "singalton.h"
#include "primenumbers_thread.h"
#include "prime_singalton.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    facrorial_thread *f;
    primenumbers_thread *p;
    int n;
    singalton *f_in;
    prime_singalton *p_in;
    int per;


private slots:
    void on_pushButton_clicked();
    void factorial();
    void prime();
    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
