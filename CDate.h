//*****************************************************************************************************************************//
//Auteur : MP Pinaud
//Date : 16/03/2020
//Fichier : CDate.h
//D�claration des m�thodes et des attributs de la classe CDate.
//*****************************************************************************************************************************//


#ifndef CDATE_H
#define CDATE_H
class CDate
{

    public:
    //***************************************************************
	// m�thode :constructeur
	// r�le:initialise les attributs jour,mois,annee de la date cr��e
	// param�tres d'entr�e:
	//				j: valeur du jour
	//				m: valeur du mois
	//				a: valeur de l'ann�e
	//              s : seconde
	//              mi : minutes
	//              h : heure
	// Objet courant : Sortie
	//***************************************************************
        CDate(int j,int m, int a, int s=0, int mi=0, int h=0);

   //***************************************************************
	// m�thode :constructeur
	// r�le:initialise lla date � la date syst�me
	// Objet courant : Sortie
	//***************************************************************
        CDate();

    //***************************************************************
	// m�thode :getDay
	// r�le:retourne le jour
	// Objet courant : Entr�e
	//***************************************************************
        int getDay();

    //***************************************************************
	// m�thode :getMonth
	// r�le:retourne le mois
	// Objet courant : Entr�e
	//***************************************************************
        int getMonth();
    //***************************************************************
	// m�thode :getYear
	// r�le:retourne l'ann�e
	// Objet courant : Entr�e
	//***************************************************************
        int getYear();
    //***************************************************************
	// m�thode :getSec
	// r�le:retourne les secondes
	// Objet courant : Entr�e
	//***************************************************************
        int getSec();
    //***************************************************************
	// m�thode :getMinute
	// r�le:retourne les minutes
	// Objet courant : Entr�e
	//***************************************************************
        int getMinute();
    //***************************************************************
	// m�thode :getHour
	// r�le:retourne les heures
	// Objet courant : Entr�e
	//***************************************************************
        int getHour();



    //***********************************************************************
	// m�thode: op�rateur ==
	// r�le: compare la date courante et la date pass�e en param�tre
	// param�tre d'entr�e:
	//		d: date � comparer � la date courante
	// valeur de retour:
	//		true si les 2 dates sont �gales
	//      false si les 2 dates sont diff�rentes
	// Objet courant : Entr�e
	//************************************************************************
        bool operator == (const CDate &d);



    //***********************************************************************
	// m�thode: op�rateur >
	// r�le: compare la date courante et la date pass�e en param�tre
	// param�tre d'entr�e:
	//		d: date � comparer � la date courante
	// valeur de retour:
	//		true si la date courante est post�rieure � la date pass�e en param�tre
	//      false sinon
	// Objet courant : Entr�e
	//************************************************************************
        bool operator > (const CDate &d);

    //***********************************************************************
	// m�thode: op�rateur <
	// r�le: compare la date courante et la date pass�e en param�tre
	// param�tre d'entr�e:
	//		d: date � comparer � la date courante
	// valeur de retour:
	//		true si la date courante est ant�rieure � la date pass�e en param�tre
	//      false sinon
	// Objet courant : Entr�e
	//************************************************************************
        bool operator < (const CDate &d);


    //***********************************************************************
	// m�thode: incrementerSec
	// r�le: ajoute 1 seconde � la date courante
	// Objet courant : Entr�e/Sortie
	//************************************************************************
        void incrementerSec ();



    //***************************************************************
	// m�thode :destructeur
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
