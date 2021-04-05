#ifndef CDATE_H
#define CDATE_H
#include <iostream>
using namespace std;

class CDate
{
    public:

    // Nom :CDate  Constructeur
    // Rôle : Initialise ce qui caractérise la date
    // Sortie : la date créée

        CDate(int annee, int mois, int jour, int heure, int minute, int seconde);

    // Nom : Accesseurs
    // Rôle : indiquent les attributs de la date appelant la méthode
    // Entrée : la date appelant la méthode
    // Valeur de retour : son année, son mois, son jour, son heure, sa minute, sa seconde

        int getAnnee();
        int getMois();
        int getJour();
        int getHeure();
        int getMinute();
        int getSeconde();

    // Nom : ajouterSeconde
    // Rôle : Permet d'ajouter une seconde à une date
    // Entrée / sortie : la date appelant la méthode

        void ajouterSeconde();

    // Nom : operator
    // Rôle : Permettent de comparer 2 dates
    // Entrées : la date appelant la méthode et la date dont on souhaite faire la comparaison
    // Valeur de retour : un booléen indiquant quelle date est la plus récente, éloignée, ou bien si elles sont égales.

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
