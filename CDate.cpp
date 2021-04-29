//*****************************************************************************************************************************//
//Auteur : MP Pinaud
//Date : 16/03/2020
//Fichier : CDate.cpp
//Code des méthodes de la classe CDate.
// Solution avec les opérateurs
//*****************************************************************************************************************************//

#include <time.h>
#include <iostream>
using namespace std;

#include "CDate.h"


    //***************************************************************
	// méthode :constructeur
	// rôle:initialise les attributs jour,mois,year de la date créée
	// paramètres d'entrée:
	//				j: valeur du jour
	//				m: valeur du mois
	//				a: valeur de l'année
	//              s : seconde
	//              mi : minutes
	//              h : heure
	// Objet courant : Sortie
	//***************************************************************
    CDate::CDate(int j,int m, int a, int s, int mi, int h)
    {
        this->day=j;
        this->month=m;
        this->year=a;
        this->sec=s;
        this->minute=mi;
        this->hour=h;
    }


   //***************************************************************
	// méthode :constructeur
	// rôle:initialise lla date à la date système
	// Objet courant : Sortie
	//***************************************************************
    CDate::CDate()
    {
       time_t temps; /*nombre de secondes depuis le 1/1/1970, retour de la fonction time */
       struct tm *detail_temps; /*contient les informations de la date système    */

       temps = time (&temps); /*récupération du nombre de secondes depuis le 1/1/1970*/
       detail_temps = gmtime(&temps);  /*construction de la structure contenant les    */
                           /* informations de la date correspondant à temps*/


       /* Mise à jour des informations de date_jour avec les informations contenues dans detail_temps */
       this->day = detail_temps->tm_mday;
       this->month = detail_temps->tm_mon+1 ;
       this->year = detail_temps->tm_year + 1900;
                                               /* 1900 est l'anne de debut de     */
                                               /* comptage de la date systeme     */

        this->hour = detail_temps->tm_hour +2;
        this->minute = detail_temps->tm_min;
        this->sec = detail_temps->tm_sec;
    }

    //***************************************************************
	// méthode :getDay
	// rôle:retourne le jour
	// Objet courant : Entrée
	//***************************************************************
    int CDate::getDay()
    {
        return this->day;
    }

    //***************************************************************
	// méthode :getMonth
	// rôle:retourne le mois
	// Objet courant : Entrée
	//***************************************************************
    int CDate::getMonth()
    {
        return this->month;
    }

    //***************************************************************
	// méthode :getYear
	// rôle:retourne l'année
	// Objet courant : Entrée
	//***************************************************************
    int CDate::getYear()
    {
        return this->year;
    }

    //***************************************************************
	// méthode :getSec
	// rôle:retourne les secondes
	// Objet courant : Entrée
	//***************************************************************
    int CDate::getSec()
    {
        return this->sec;
    }


    //***************************************************************
	// méthode :getMinute
	// rôle:retourne les minutes
	// Objet courant : Entrée
	//***************************************************************
    int CDate::getMinute()
    {
        return this->minute;
    }


    //***************************************************************
	// méthode :getHour
	// rôle:retourne les heures
	// Objet courant : Entrée
	//***************************************************************
    int CDate::getHour()
    {
        return this->hour;
    }


    //***********************************************************************
	// méthode: operator ==
	// rôle: compare la date courante et la date passée en paramètre
	// paramètre d'entrée:
	//		d: date à comparer à la date courante
	// valeur de retour:
	//		true si les 2 dates sont égales
	//      false si les 2 dates sont différentes
	// Objet courant : Entrée
	//************************************************************************
    bool CDate::operator == (const CDate &d)
    {
        if((this->day==d.day)&&(this->month==d.month)&&(this->year==d.year)&&(this->sec==d.sec)&&(this->minute==d.minute)&&(this->sec==d.sec))
        {
            return true;
        }
        return false;
    }


    //***********************************************************************
	// méthode: operator >
	// rôle: compare la date courante et la date passée en paramètre
	// paramètre d'entrée:
	//		d: date à comparer à la date courante
	// valeur de retour:
	//		true si la date courante est postérieure à la date passée en paramètre
	//      false sinon
	// Objet courant : Entrée
	//************************************************************************
    bool CDate::operator > (const CDate &d)
    {
        bool resultat=false;

        resultat=((this->year>d.year)
                  ||((this->year==d.year)&&(this->month>d.month))
                  ||((this->year==d.year)&&(this->month==d.month)&&(this->day>d.day))
                  ||((this->year==d.year)&&(this->month==d.month)&&(this->day==d.day)&&(this->hour>d.hour))
                  ||((this->year==d.year)&&(this->month==d.month)&&(this->day==d.day)&&(this->hour==d.hour)&&(this->minute>d.minute))
                  ||((this->year==d.year)&&(this->month==d.month)&&(this->day==d.day)&&(this->hour==d.hour)&&(this->minute==d.minute)&&(this->sec>d.sec)));

        return resultat;
    }


    //***********************************************************************
	// méthode: operator <
	// rôle: compare la date courante et la date passée en paramètre
	// paramètre d'entrée:
	//		d: date à comparer à la date courante
	// valeur de retour:
	//		true si la date courante est antérieure à la date passée en paramètre
	//      false sinon
	// Objet courant : Entrée
	//************************************************************************
    bool CDate::operator < (const CDate &d)
    {
        if((*this) > d || (*this) ==d)
        {
            return false;
        }
        return true;
    }


    //***************************************************************
	// méthode :destructeur
	//***************************************************************
    CDate::~CDate()
    {

    }


     //***********************************************************************
	// méthode: incrementerSec
	// rôle: ajoute 1 seconde à la date courante
    // Objet courant : Entrée/sortie
	//************************************************************************

    void CDate::incrementerSec()
{
    bool bissextile = false;
    if((this->year%4==0 && this->year%100!=0) || this->year%400==0)
    {
        bissextile = true;
    }

    this->sec++;

    if(this->sec==60)
    {
        this->sec=0;
        this->minute++;

        if(this->minute==60)
        {
            this->minute=0;
            this->hour++;

            if(this->hour==24)
            {
                this->hour=0;
                this->day++;


                switch(this->month)
                {
                case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                    {
                        if(this->day==32)
                        {
                            this->day=1;
                            this->month++;
                        }
                    }break;

                case 4:case 6:case 9:case 11:
                    {
                        if(this->day==31)
                        {
                            this->day=1;
                            this->month++;
                        }
                    }break;


                case 2: //février
                    {
                        if(bissextile==false && this->day==29)
                        {
                            this->day=1;
                            this->month++;
                        }
                        if(bissextile==true && this->day==30)
                        {
                            this->day=1;
                            this->month++;
                        }
                    }break;
                }

                if(this->month==13)
                {
                    this->month=1;
                    this->year++;
                }
            }
        }
    }
}

