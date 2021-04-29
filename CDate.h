//*****************************************************************************************************************************//
//Auteur : MP Pinaud
//Date : 16/03/2020
//Fichier : CDate.h
//Déclaration des méthodes et des attributs de la classe CDate.
//*****************************************************************************************************************************//


#ifndef CDATE_H
#define CDATE_H
class CDate
{

    public:
    //***************************************************************
	// méthode :constructeur
	// rôle:initialise les attributs jour,mois,annee de la date créée
	// paramètres d'entrée:
	//				j: valeur du jour
	//				m: valeur du mois
	//				a: valeur de l'année
	//              s : seconde
	//              mi : minutes
	//              h : heure
	// Objet courant : Sortie
	//***************************************************************
        CDate(int j,int m, int a, int s=0, int mi=0, int h=0);

   //***************************************************************
	// méthode :constructeur
	// rôle:initialise lla date à la date système
	// Objet courant : Sortie
	//***************************************************************
        CDate();

    //***************************************************************
	// méthode :getDay
	// rôle:retourne le jour
	// Objet courant : Entrée
	//***************************************************************
        int getDay();

    //***************************************************************
	// méthode :getMonth
	// rôle:retourne le mois
	// Objet courant : Entrée
	//***************************************************************
        int getMonth();
    //***************************************************************
	// méthode :getYear
	// rôle:retourne l'année
	// Objet courant : Entrée
	//***************************************************************
        int getYear();
    //***************************************************************
	// méthode :getSec
	// rôle:retourne les secondes
	// Objet courant : Entrée
	//***************************************************************
        int getSec();
    //***************************************************************
	// méthode :getMinute
	// rôle:retourne les minutes
	// Objet courant : Entrée
	//***************************************************************
        int getMinute();
    //***************************************************************
	// méthode :getHour
	// rôle:retourne les heures
	// Objet courant : Entrée
	//***************************************************************
        int getHour();



    //***********************************************************************
	// méthode: opérateur ==
	// rôle: compare la date courante et la date passée en paramètre
	// paramètre d'entrée:
	//		d: date à comparer à la date courante
	// valeur de retour:
	//		true si les 2 dates sont égales
	//      false si les 2 dates sont différentes
	// Objet courant : Entrée
	//************************************************************************
        bool operator == (const CDate &d);



    //***********************************************************************
	// méthode: opérateur >
	// rôle: compare la date courante et la date passée en paramètre
	// paramètre d'entrée:
	//		d: date à comparer à la date courante
	// valeur de retour:
	//		true si la date courante est postérieure à la date passée en paramètre
	//      false sinon
	// Objet courant : Entrée
	//************************************************************************
        bool operator > (const CDate &d);

    //***********************************************************************
	// méthode: opérateur <
	// rôle: compare la date courante et la date passée en paramètre
	// paramètre d'entrée:
	//		d: date à comparer à la date courante
	// valeur de retour:
	//		true si la date courante est antérieure à la date passée en paramètre
	//      false sinon
	// Objet courant : Entrée
	//************************************************************************
        bool operator < (const CDate &d);


    //***********************************************************************
	// méthode: incrementerSec
	// rôle: ajoute 1 seconde à la date courante
	// Objet courant : Entrée/Sortie
	//************************************************************************
        void incrementerSec ();



    //***************************************************************
	// méthode :destructeur
	//***************************************************************
        ~CDate();

    private:

        int day;
        int month;
        int year;
        int sec;
        int minute;
        int hour;
};





#endif // CDATE_H
