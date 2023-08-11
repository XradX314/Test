#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    contador= new QTimer(this);
    connect(contador,&QTimer::timeout,this,&MainWindow::contar);
    counter=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::contar(){
    if(ui->radioButton->isChecked()){
        counter--;
    }else{
        counter++;
    }
    if(counter>1000){
        counter=0;
    }
    ui->lcdNumber->display(QString("%1").arg(counter));


}
void MainWindow::on_pushButton_clicked()
{
    if(contador->isActive()){
        contador->stop();
        counter=0;
        ui->lcdNumber->display(QString("%1").arg(counter));
    }else{
        contador->start(100);
    }

}


void MainWindow::on_pushButton_2_clicked()
{
    counter=0;
    ui->lcdNumber->display(QString("%1").arg(counter));
}



void MainWindow::on_pushButton_3_clicked()
{
    if(contador->isActive()){
        contador->stop();
    }else{
        contador->start(100);
    }
}


void MainWindow::on_radioButton_clicked()
{

}

