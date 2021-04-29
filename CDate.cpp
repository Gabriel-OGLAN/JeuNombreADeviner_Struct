//*****************************************************************************************************************************//
//Auteur : MP Pinaud
//Date : 16/03/2020
//Fichier : CDate.cpp
//Code des m�thodes de la classe CDate.
// Solution avec les op�rateurs
//*****************************************************************************************************************************//

#include <time.h>
#include <iostream>
using namespace std;

#include "CDate.h"


    //***************************************************************
	// m�thode :constructeur
	// r�le:initialise les attributs jour,mois,year de la date cr��e
	// param�tres d'entr�e:
	//				j: valeur du jour
	//				m: valeur du mois
	//				a: valeur de l'ann�e
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
	// m�thode :constructeur
	// r�le:initialise lla date � la date syst�me
	// Objet courant : Sortie
	//***************************************************************
    CDate::CDate()
    {
       time_t temps; /*nombre de secondes depuis le 1/1/1970, retour de la fonction time */
       struct tm *detail_temps; /*contient les informations de la date syst�me    */

       temps = time (&temps); /*r�cup�ration du nombre de secondes depuis le 1/1/1970*/
       detail_temps = gmtime(&temps);  /*construction de la structure contenant les    */
                           /* informations de la date correspondant � temps*/


       /* Mise � jour des informations de date_jour avec les informations contenues dans detail_temps */
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
	// m�thode :getDay
	// r�le:retourne le jour
	// Objet courant : Entr�e
	//***************************************************************
    int CDate::getDay()
    {
        return this->day;
    }

    //***************************************************************
	// m�thode :getMonth
	// r�le:retourne le mois
	// Objet courant : Entr�e
	//***************************************************************
    int CDate::getMonth()
    {
        return this->month;
    }

    //***************************************************************
	// m�thode :getYear
	// r�le:retourne l'ann�e
	// Objet courant : Entr�e
	//***************************************************************
    int CDate::getYear()
    {
        return this->year;
    }

    //***************************************************************
	// m�thode :getSec
	// r�le:retourne les secondes
	// Objet courant : Entr�e
	//***************************************************************
    int CDate::getSec()
    {
        return this->sec;
    }


    //***************************************************************
	// m�thode :getMinute
	// r�le:retourne les minutes
	// Objet courant : Entr�e
	//***************************************************************
    int CDate::getMinute()
    {
        return this->minute;
    }


    //***************************************************************
	// m�thode :getHour
	// r�le:retourne les heures
	// Objet courant : Entr�e
	//***************************************************************
    int CDate::getHour()
    {
        return this->hour;
    }


    //***********************************************************************
	// m�thode: operator ==
	// r�le: compare la date courante et la date pass�e en param�tre
	// param�tre d'entr�e:
	//		d: date � comparer � la date courante
	// valeur de retour:
	//		true si les 2 dates sont �gales
	//      false si les 2 dates sont diff�rentes
	// Objet courant : Entr�e
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
	// m�thode: operator >
	// r�le: compare la date courante et la date pass�e en param�tre
	// param�tre d'entr�e:
	//		d: date � comparer � la date courante
	// valeur de retour:
	//		true si la date courante est post�rieure � la date pass�e en param�tre
	//      false sinon
	// Objet courant : Entr�e
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
	// m�thode: operator <
	// r�le: compare la date courante et la date pass�e en param�tre
	// param�tre d'entr�e:
	//		d: date � comparer � la date courante
	// valeur de retour:
	//		true si la date courante est ant�rieure � la date pass�e en param�tre
	//      false sinon
	// Objet courant : Entr�e
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
	// m�thode :destructeur
	//***************************************************************
    CDate::~CDate()
    {

    }


     //***********************************************************************
	// m�thode: incrementerSec
	// r�le: ajoute 1 seconde � la date courante
    // Objet courant : Entr�e/sortie
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


                case 2: //f�vrier
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

