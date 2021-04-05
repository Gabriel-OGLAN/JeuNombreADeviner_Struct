//********************************************************
// Auteurs : MP Pinaud, G Oglan, L Riviere
// date : 19/03/2021
// fichier: TU_CDate.cpp
// Programme de test unitaire de la classe CDate
// Difficult� B
//********************************************************
#include <iostream>
#include <ctime>
using namespace std;
#include "CDate.h"
#include "time.h"



void test_constructeur();
void test_egal();
void test_constructeurSansParametre();
void test_sup();
void test_inf();
void test_incrementerSec();
void saisirDate(int &j, int &m, int &a, int &s, int &mn, int &h);
void afficherDate(CDate &d);

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
    cout << "Saisis le jour de la date" << endl;
    cin >> j;
    cout << "Saisis le mois de la date" << endl;
    cin >> m;
    cout << "Saisis l'annee de la date" << endl;
    cin >> a;
    cout << "Saisis l'heure de la date" << endl;
    cin >> h ;
    cout << "Saisis la minute de la date" << endl;
    cin >> mn;
    cout << "Saisis la seconde de la date" << endl;
    cin >> s;
}
//**************************************************************
// Fonction:afficherDate
// R�le :	affiche la date pass�e en param�tre
// Param�tre d'entr�e : la date � afficher
//***************************************************************
void afficherDate (CDate &d)
{
    cout << d.getJour() << "/" << d.getMois() << "/" << d.getAnnee() << "    " << d.getHeure() << ":" << d.getMinute() << ":" << d.getSeconde();
}


//**************************************************************
// Fonction:test_constructeur
// R�le :	teste le constructeur et affiche la date  � l'aide des m�thodes d'acc�s
//***************************************************************

void test_constructeur()
{
    int j,m,a,h,mn,s;
    cout << "Test du constructeur de la classe CDate" << endl;
	cout << "--------------------------------------------" << endl;
    saisirDate(j,m,a,s,mn,h);
    CDate date(a,m,j,h,mn,s);
    cout << "Voici la date saisie" << endl;
    afficherDate(date);
}

//**************************************************************
// Fonction:test_constructeur
// R�le :	teste le constructeur sans param�tre de la classe CDate
//***************************************************************

void test_constructeurSansParametre()
{
    time_t curr_time;
	curr_time = time(NULL);
    struct tm *tm = localtime(&curr_time);
    int j,m,a,h,mn,s;
    a = tm->tm_year+1900;
    m = tm->tm_mon+1;
    j = tm->tm_mday;
    h = tm->tm_hour;
    mn = tm->tm_min;
    s = tm->tm_sec;
    CDate date (a,m,j,h,mn,s);
    cout << "Voici la date actuelle" << endl;
    afficherDate(date);
}

//**************************************************************
// Fonction:test_egal
// R�le :	teste de l'op�rateur == de la classe CDate
//***************************************************************
void test_egal()
{

    int j, m, a,s,mn,h;
	cout << "Test de l'operateur == de la classe CDate" << endl;
	cout << "--------------------------------------------" << endl;

	cout << "Saisir la 1re date utilisee pour tester" << endl;
    saisirDate(j,m,a,s,mn,h);

	// Cr�ation de la 1re date
	CDate d1(a,m,j,h,mn,s);

	cout << "Saisir la 2e date utilisee pour tester" << endl;
    saisirDate(j,m,a,s,mn,h);

	// Cr�ation de la 2e date
	CDate d2(a,m,j,h,mn,s);

	// Comparer les deux dates avec == et afficher le r�sultat de la comparaison
	if (d1 == d2)
    {
        cout << "Les 2 dates sont egales " << endl;
    }
    else
    {
        cout << "Les 2 dates sont differentes " << endl;
    }

}


//**************************************************************
// Fonction:test_sup
// R�le :	teste de l'op�rateur >  de la classe CDate
//***************************************************************

void test_sup()
{
    int j, m, a,s,mn,h;
	cout << "Test de l'operateur > de la classe CDate" << endl;
	cout << "--------------------------------------------" << endl;

	cout << "Saisir la 1re date utilisee pour tester" << endl;
    saisirDate(j,m,a,s,mn,h);

	// Cr�ation de la 1�re date
	CDate d1(a,m,j,h,mn,s);

	cout << "Saisir la 2e date utilisee pour tester" << endl;
    saisirDate(j,m,a,s,mn,h);

	// Cr�ation de la 2�me date
	CDate d2(a,m,j,h,mn,s);

	// Comparer les deux dates avec > et afficher le r�sultat de la comparaison
	if (d1 > d2)
    {
        cout << "La 1re date est la plus recente " << endl;
        cout << "La 2e date est la plus ancienne " << endl;
    }
    else
    {
        cout << "La 1re date est la plus ancienne " << endl;
        cout << "La 2e date est la plus recente " << endl;
    }
}


//**************************************************************
// Fonction:test_inf
// R�le :	teste l'op�rateur < de la classe CDate
//***************************************************************

void test_inf()
{

    int j, m, a,s,mn,h;
	cout << "Test de l'operateur > de la classe CDate" << endl;
	cout << "--------------------------------------------" << endl;

	cout << "Saisir la 1re date utilisee pour tester" << endl;
    saisirDate(j,m,a,s,mn,h);

	// Cr�ation de la 1re date
	CDate d1(a,m,j,h,mn,s);

	cout << "Saisir la 2e date utilisee pour tester" << endl;
    saisirDate(j,m,a,s,mn,h);

	// Cr�ation de la 2e date
	CDate d2(a,m,j,h,mn,s);

	// Comparer les deux dates avec < et afficher le r�sultat de la comparaison
	if (d1 < d2)
    {
        cout << "La 1re date est la plus ancienne " << endl;
        cout << "La 2e date est la plus recente " << endl;
    }
    else
    {
        cout << "La 1re date est la plus recente " << endl;
        cout << "La 2e date est la plus ancienne " << endl;
    }

}

//**************************************************************
// Fonction:test_incrementerSec
// R�le :	teste la la m�thode incr�menterSec de la classe CDate
//***************************************************************
void test_incrementerSec()
{
    int j, m, a,s,mn,h;
	cout << "Test de la methode ajouterSeconde de la classe CDate" << endl;
	cout << "--------------------------------------------" << endl;
    cout << "Saisir la date utilisee pour tester" << endl;
    saisirDate(j,m,a,s,mn,h);
    CDate date(a,m,j,h,mn,s);
    date.ajouterSeconde();
    cout << "Voici la date modifiee" << endl;
    afficherDate(date);
}
