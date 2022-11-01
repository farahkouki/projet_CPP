#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class etudiant
{
    QString nom, prenom;
    int id;

public:
    etudiant(){}
    etudiant(int,QString,QString);

    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    int getID(int id){return id;}

    void setNom(QString n){nom=n;}
    void setPrenom(QString p){prenom=p;}
    void setID(int id){this->id=id;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool recherche(int);
};

#endif // ETUDIANT_H
