#include "connect.h"
#include "ui_connect.h"
#include "mainwindow.h"
#include <QApplication>

Connect::Connect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connect)
{
    ui->setupUi(this);
}

Connect::~Connect()
{
    delete ui;
}

bool Connect::on_pushButton_clicked()
{

    MainWindow m;
    m.show();
    return true;

}
