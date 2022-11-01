#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "etudiant.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent):

      QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int id=ui->lineEdit_ID->text().toInt();
    QString nom=ui->lineEdit_Nom->text();
    QString prenom=ui->lineEdit_Prenom->text();

    etudiant E(id,nom,prenom);

    bool test=E.ajouter();

    if(test)
    {
        ui->tableView->setModel(etmp.afficher());

        QMessageBox::information(nullptr, QObject::tr("OK"),QObject::tr("Ajout effectué\n"
                                                                        "Click Cancel to exit."),QMessageBox::Cancel);


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),QObject::tr("Ajout non effectué\n"
                                                                        "Click Cancel to exit."),QMessageBox::Cancel);


}

void MainWindow::on_pushButton_2_clicked()
{
    int id =ui->lineEdit_IDS->text().toInt();
    bool test=etmp.supprimer(id);
    if(test)
    {
        ui->tableView->setModel(etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),QObject::tr("Supression effectué\n"
                                                                        "Click Cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),QObject::tr("Supression non effectué\n"
                                                                        "Click Cancel to exit."),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_3_clicked()
{
    QSqlQuery query;
    int id2=ui->lineEdit_ID_2->text().toInt();
    int id3=ui->lineEdit_ID_3->text().toInt();
    QString nom=ui->lineEdit_Nom_2->text();
    QString prenom=ui->lineEdit_Prenom_2->text();


    etudiant E(id2,nom,prenom);

   bool test=etmp.supprimer(id3);
   bool test2=E.ajouter();
    if(test && test2)
    {

        ui->tableView->setModel(etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),QObject::tr("Modification effectué\n"
                                                                        "Click Cancel to exit."),QMessageBox::Cancel);
     }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),QObject::tr("Modification non effectué\n"
                                                                        "Click Cancel to exit."),QMessageBox::Cancel);
    }
}
