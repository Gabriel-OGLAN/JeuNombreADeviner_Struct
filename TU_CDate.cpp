//********************************************************
// Auteur : MP Pinaud
// date : 19/03/2020
// fichier: TU_CDate.cpp
// Programme de test de la classe CDate
//********************************************************
#include <iostream>
using namespace std;
#include "CDate.h"



void test_constructeur();
void test_egal();
void test_constructeurSansParametre();
void test_sup();
void test_inf();
void test_incrementerSec();
void saisirDate(int &j, int &m, int &a, int &s, int &mn, int &h);
void afficherDate(CDate &d);
int jourDansLeMois(int a, int m );

int main ()
{

	int rep;
	do
	{
		cout << "Test de la classe CDate" << endl;
		cout << "**************************" << endl<< endl;

		cout << "Quelle methode voulez-vous tester ?" << endl;
		cout << "1 - Constructeur " << endl;
		cout << "2 - operateur ==" << endl;

		cout << "3 - Constructeur sans parametre" << endl;
		cout << "4 - operateur >" << endl;
		cout << "5 - operateur <" << endl;
		cout << "6 - incrementerSec" << endl;
		cout << "0 - Sortie du test de la classe CDate" <<endl;

		cin >> rep;

		switch (rep)
		{

			case 1 :	test_constructeur();
						break;
			case 2 :	test_egal();
						break;

            case 3 :	test_constructeurSansParametre();
						break;
			case 4 :	test_sup();
						break;
			case 5 :	test_inf();
						break;
            case 6:     test_incrementerSec();
						break;

			case 0 :	{
					cout << "Fin du test de la classe CDate" <<endl;
					cout << "*********************************" << endl;
							break;
						}
			default :	cout << "Erreur de saisie" <<endl;
						break;
		}
		cout <<endl << endl;
	} while (rep != 0);

	return 0;
}

//**************************************************************
// Fonction:saisirDate
// R�le :	permet de saisir les informations d'une date
// Param�tres de sortie : le jour, mois, ann�e, secondes, minutes, heures saisies
//***************************************************************
void saisirDate(int &j, int &m, int &a, int &s, int &mn, int &h)
{


    cout << "Saisir les informations de la date a creer" << endl;

    cout << "annee :";
	cin >>a;


	do{
        cout << "mois :";
        cin >>m;

    }while (m<0 || m>12);


    do{
        cout << "jour :";
        cin >>j;


    }while (j<0 || j>jourDansLeMois(a, m));


	do{
        cout << "heure :";
        cin >>h;
    }while (h<0 || h>23);


	do{
        cout << "minutes :";
        cin >>mn;
    }while (mn<0 || mn>=60);


	do{
        cout << "secondes :";
        cin >>s;
    }while (s<0 || s>=60);

}
//**************************************************************
// Fonction:afficherDate
// R�le :	affiche la date pass�e en param�tre
// Param�tre d'entr�e : la date � afficher
//***************************************************************
void afficherDate (CDate &d)
{
    // Affichage de la date sous la forme jour/mois/annee
	cout << "Affichage de la date:" << endl << endl;
	cout<< d.getDay()<< '/'<< d.getMonth()<< '/'<<d.getYear()<< " " ;
    cout<< d.getHour()<< ':'<< d.getMinute()<< ':'<<d.getSec() <<endl;
}


//**************************************************************
// Fonction:test_constructeur
// R�le :	teste le constructeur et affiche la date  � l'aide des m�thodes d'acc�s
//***************************************************************

void test_constructeur()
{
	int j, m, a,s,mn,h;
	cout << "Test du constructeur de la classe CDate:" << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "Saisir la date utilisee pour tester" << endl;

    saisirDate(j,m,a,s,mn,h);

	// Cr�ation de la date
	CDate d(j,m,a,s,mn,h);


	// Affichage de la date sous la forme jour/mois/annee
	afficherDate(d);
}

//**************************************************************
// Fonction:test_constructeur
// R�le :	teste le constructeur sans param�tre de la classe CDate
//***************************************************************

void test_constructeurSansParametre()
{

	cout << "Test du constructeur sans parametre de la classe CDate:" << endl;
	cout << "-------------------------------------------------------" << endl;

	// Cr�ation de la date
	CDate d;

	afficherDate(d);
}

//**************************************************************
// Fonction:test_egal
// R�le :	teste la la m�thode isEqual de la classe CDate
//***************************************************************
void test_egal()
{
	int j, m, a,s,mn,h;
	cout << "Test de la m�thode isEqual de la classe CDate:" << endl;
	cout << "--------------------------------------------" << endl;

	cout << "Saisir la 1ere date utilisee pour tester" << endl;
    saisirDate(j,m,a,s,mn,h);

	// Cr�ation de la 1�re date
	CDate d1(j,m,a,s,mn,h);


	cout << "Saisir la 2eme date utilisee pour tester" << endl;
    saisirDate(j,m,a,s,mn,h);

	// Cr�ation de la 2�me date
	CDate d2(j,m,a,s,mn,h);


	if (d1 == d2)
		cout << "les deux dates sont egales" << endl << endl;
	else
		cout << "les deux dates sont differentes" << endl << endl;
}

//**************************************************************
// Fonction:test_sup
// R�le :	teste la m�thode isLater de la classe CDate
//***************************************************************

void test_sup()
{
	int j, m, a,s,mn,h;
	cout << "Test de la m�thode isLater  de la classe CDate:" << endl;
	cout << "--------------------------------------------" << endl;

	cout << "Saisir la 1ere date utilisee pour tester" << endl;
    saisirDate(j,m,a,s,mn,h);
	// Cr�ation de la 1�re date
	CDate d1(j,m,a,s,mn,h);

	cout << "Saisir la 2eme date utilisee pour tester" << endl;
    saisirDate(j,m,a,s,mn,h);

	// Cr�ation de la 2�me date
	CDate d2(j,m,a,s,mn,h);

	if (d1 >d2)
		cout << "la 1ere date est posterieure a la 2eme" << endl << endl;
	else
		cout << "la 1ere date n'est pas posterieure a la 2eme" << endl << endl;
}


//**************************************************************
// Fonction:test_inf
// R�le :	teste l'op�rateur < de la classe CDate
//***************************************************************

void test_inf()
{
	int j, m, a,s,mn,h;
	cout << "Test de la m�thode isEarlier de la classe CDate:" << endl;
	cout << "--------------------------------------------" << endl;

	cout << "Saisir la 1ere date utilisee pour tester" << endl;
    saisirDate(j,m,a,s,mn,h);

	// Cr�ation de la 1�re date
	CDate d1(j,m,a,s,mn,h);

	cout << "Saisir la 2eme date utilisee pour tester" << endl;
    saisirDate(j,m,a,s,mn,h);

	// Cr�ation de la 2�me date
	CDate d2(j,m,a,s,mn,h);

	if (d1 <d2)
		cout << "la 1ere date est anterieure a la 2eme" << endl << endl;
	else
		cout << "la 1ere date n'est pas anterieure a la 2eme" << endl << endl;
}

//**************************************************************
// Fonction:test_incrementerSec
// R�le :	teste la m�thode incr�menterSec de la classe CDate
//***************************************************************
void test_incrementerSec()
{
	int j, m, a, h, mn, s;
	cout << "Test de la m�thode incrementerSec de la classe CDate:" << endl;
	cout << "--------------------------------------------" << endl;

    saisirDate(j,m,a,s,mn,h);
	// Cr�ation de la date
	CDate d(j,m,a,s,mn,h);

	cout << "Combien de secondes voulez-vous ajouter ? :";
	int nbSec;
	cin >>nbSec;

	for(int i = 0; i<nbSec; i++)
        d.incrementerSec();

	afficherDate(d);
}

//**************************************************************
// Fonction:anneeBissextile
// R�le :	verifie si une ann�e est bissextile
// Param�tre d'entr�e : l'ann�e � tester
// Valeur de retour : true si l'ann�e est bissextile, false sinon
//***************************************************************
bool anneeBisextile(int a){
    bool bissextile = false;
    if((a%4==0 && a%100!=0) || a%400==0)
    {
        bissextile = true;
    }

    return bissextile;

}

//**************************************************************
// Fonction:jourDansLeMois
// R�le :	indique le nombre de jour dans le mois
// Param�tre d'entr�e : ann�e et mois dont on veut le nombre de jours
// Valeur de retour : nombre de jours
//***************************************************************
int jourDansLeMois(int a, int m ){

    int nb = 0; // nombre de jours
    switch(m)
    {
    case 1:case 3:case 5:case 7:case 8:case 10:case 12:
        nb = 31;
        break;
    case 4:case 6:case 9: case 11 :
        nb = 30;
        break;
    case 2:
        {
            if(anneeBisextile(a)== false)
            {
                nb = 28;
            }
            else
            {
                nb = 29;
            }
            break;
        }
    default :   cout <<"Erreur : mois invalide";

    }
    return nb;
}
