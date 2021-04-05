#ifndef CDATE_H
#define CDATE_H
#include <iostream>
using namespace std;

class CDate
{
    public:

    // Nom :CDate  Constructeur
    // R�le : Initialise ce qui caract�rise la date
    // Sortie : la date cr��e

        CDate(int annee, int mois, int jour, int heure, int minute, int seconde);

    // Nom : Accesseurs
    // R�le : indiquent les attributs de la date appelant la m�thode
    // Entr�e : la date appelant la m�thode
    // Valeur de retour : son ann�e, son mois, son jour, son heure, sa minute, sa seconde

        int getAnnee();
        int getMois();
        int getJour();
        int getHeure();
        int getMinute();
        int getSeconde();

    // Nom : ajouterSeconde
    // R�le : Permet d'ajouter une seconde � une date
    // Entr�e / sortie : la date appelant la m�thode

        void ajouterSeconde();

    // Nom : operator
    // R�le : Permettent de comparer 2 dates
    // Entr�es : la date appelant la m�thode et la date dont on souhaite faire la comparaison
    // Valeur de retour : un bool�en indiquant quelle date est la plus r�cente, �loign�e, ou bien si elles sont �gales.

        bool operator > (const CDate d1);

        bool operator < (const CDate d1);

        bool operator == (const CDate d1);

    // Nom : CDate  Destructeur

        virtual ~CDate();



    private:
        int annee;
        int mois;
        int jour;
        int heure;
        int minute;
        int seconde;
};

#endif // CDATE_H
