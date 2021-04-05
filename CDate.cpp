/*************************************************/
// Nom du projet: Date
// Nom du fichier: CDate.cpp
// Version : 1.0
// Nom du programmeur: G Oglan
// Date de création : 22/03/2021
// Rôle du fichier: Contient le code des méthodes de la date
// Nom des composants utilises: CDate.h
// Historique du fichier:
/*************************************************/
#include "CDate.h"
#include <iostream>
using namespace std;

    // Nom :CDate  Constructeur
    // Rôle : Initialise ce qui caractérise la date
    // Sortie : la date créée

CDate::CDate(int annee, int mois, int jour, int heure, int minute, int seconde)
{
    this->annee = annee;
    this->mois = mois;
    this->jour = jour;
    this->heure = heure;
    this->minute = minute;
    this->seconde = seconde;
}

    // Nom : Accesseurs
    // Rôle : indiquent les attributs de la date appelant la méthode
    // Entrée : la date appelant la méthode
    // Valeur de retour : son année, son mois, son jour, son heure, sa minute, sa seconde

int CDate::getAnnee()
{
    return this->annee;
}
int CDate::getMois()
{
    return this->mois;
}
int CDate::getJour()
{
    return this->jour;
}
int CDate::getHeure()
{
    return this->heure;
}
int CDate::getMinute()
{
    return this->minute;
}
int CDate::getSeconde()
{
    return this->seconde;
}
    // Nom : operator
    // Rôle : Permettent de comparer 2 dates
    // Entrées : la date appelant la méthode et la date dont on souhaite faire la comparaison
    // Valeur de retour : un booléen indiquant quelle date est la plus récente, éloignée, ou bien si elles sont égales.

    bool CDate::operator > (const CDate d1)
    {
        return (this->annee > d1.annee || this->annee == d1.annee && this->mois > d1.mois || this->annee == d1.annee && this->mois == d1.mois && this->jour > d1.jour || this->annee == d1.annee && this->mois == d1.mois && this->jour == d1.jour && this->heure > d1.heure || this->annee == d1.annee && this->mois == d1.mois && this->jour == d1.jour && this->heure == d1.heure && this->minute > d1.minute || this->annee == d1.annee && this->mois == d1.mois && this->jour == d1.jour && this->heure == d1.heure && this->minute == d1.minute && this->seconde > d1.seconde);
    }
    bool CDate::operator < (const CDate d1)
    {
        return (this->annee < d1.annee || this->annee == d1.annee && this->mois < d1.mois || this->annee == d1.annee && this->mois == d1.mois && this->jour < d1.jour || this->annee == d1.annee && this->mois == d1.mois && this->jour == d1.jour && this->heure < d1.heure || this->annee == d1.annee && this->mois == d1.mois && this->jour == d1.jour && this->heure == d1.heure && this->minute < d1.minute || this->annee == d1.annee && this->mois == d1.mois && this->jour == d1.jour && this->heure == d1.heure && this->minute == d1.minute && this->seconde < d1.seconde);
    }
    bool CDate::operator == (const CDate d1)
    {
        return (this->annee == d1.annee && this->mois == d1.mois && this->jour == d1.jour && this->heure == d1.heure && this->minute == d1.minute && this->seconde == d1.seconde);
    }

    // Nom : ajouterSeconde
    // Rôle : Permet d'ajouter une seconde à une date
    // Entrée / sortie : la date appelant la méthode

    void CDate::ajouterSeconde()
    {
        this->seconde++;

        if (this->seconde == 60)
        {
            this->minute++;
            this->seconde = 0;
        }
        if (this->minute == 60)
        {
            this->heure++;
            this->minute = 0;
        }
        if (this->heure == 24)
        {
            this->jour++;
            this->heure = 0;
        }
        if ((this->jour == 29 && this->mois == 2 && this->annee %4 != 0 || (this->annee %100 == 0 && this->annee %400 != 0)) || (this->jour == 30 && this->mois == 2 && this->annee %4 == 0 && this->annee %100 != 0 || this->annee %400 == 0) || this->jour == 31 && this->mois == 4 || this->jour == 31 && this->mois == 6 || this->jour == 31 && this->mois == 9 || this->jour == 31 && this->mois == 11 || this->jour == 32 && this->mois == 1 || this->jour == 32 && this->mois == 3 || this->jour == 32 && this->mois == 5 || this->jour == 32 && this->mois == 7 || this->jour == 32 && this->mois == 8 || this->jour == 32 && this->mois == 10 || this->jour == 32 && this->mois == 12)
        {
            this->mois++;
            this->jour = 1;
        }
        if (this->mois == 13)
        {
            this->annee++;
            this->mois = 1;
        }
    }

    // Nom : CDate  Destructeur
CDate::~CDate()
{
}
