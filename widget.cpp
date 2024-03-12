#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateButtonsState(){
    ui->pbCoffee->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 500);
    ui->pbTang->setEnabled(money >= 1000);
}

void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
    updateButtonsState();
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);

}


void Widget::on_pbTea_clicked()
{
    changeMoney(-500);
}


void Widget::on_pbTang_clicked()
{
    changeMoney(-1000);
}

void Widget::on_pbReset_clicked()
{
    QString m500 = QString::number(money / 500);
    QString m100 = QString::number((money%500)/100);
    QString m50 = QString::number((money%100)/50);
    QString m10 = QString::number((money%50)/10);
    QMessageBox::information(this, "잔돈", "500원 " + m500 +"개, 100원 " + m100 +"개, 50원 "+ m50 +"개, 10원 "+ m10 +"개" );
}
