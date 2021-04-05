/*************************************************/
// Nom du projet: Date
// Nom du fichier: CDate.cpp
// Version : 1.0
// Nom du programmeur: G Oglan
// Date de cr�ation : 22/03/2021
// R�le du fichier: Contient le code des m�thodes de la date
// Nom des composants utilises: CDate.h
// Historique du fichier:
/*************************************************/
#include "CDate.h"
#include <iostream>
using namespace std;

    // Nom :CDate  Constructeur
    // R�le : Initialise ce qui caract�rise la date
    // Sortie : la date cr��e

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
    // R�le : indiquent les attributs de la date appelant la m�thode
    // Entr�e : la date appelant la m�thode
    // Valeur de retour : son ann�e, son mois, son jour, son heure, sa minute, sa seconde

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
    // R�le : Permettent de comparer 2 dates
    // Entr�es : la date appelant la m�thode et la date dont on souhaite faire la comparaison
    // Valeur de retour : un bool�en indiquant quelle date est la plus r�cente, �loign�e, ou bien si elles sont �gales.

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
    // R�le : Permet d'ajouter une seconde � une date
    // Entr�e / sortie : la date appelant la m�thode

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
