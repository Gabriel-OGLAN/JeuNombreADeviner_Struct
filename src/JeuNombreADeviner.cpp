/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: G Oglan
// Date de cr�ation : 25/01/2021
// R�le du fichier: Contient le code des fonctions du jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
//                              ctime
//                              cstdlib
// Historique du fichier:
/*************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "../include/JeuNombreAdeviner.h"

// Nom :InitJoueur
// R�le : Cr�e un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagn�es et de parties jou�es seront � 0.
// Param�tres d'entr�e :
// Param�tres de sortie :
// Param�tres d'entr�e/sortie :

void InitJoueur(TJoueur& joueurAcreer, string un_nom)
{
    joueurAcreer.nbTentatives = 0;
    joueurAcreer.nbPartiesJouees = 0;
    joueurAcreer.nbPartiesGagnees = 0;
    joueurAcreer.nom = un_nom;
}


// Nom :TirerNombreMystere
// R�le : Tire al�atoirement un nombre � deviner entre 0 et 10
// Valeur de retour : nombre � deviner

int TirerNombreMystere()
{
	srand((int)time(0));
    int nombreADeviner = (rand() % 11);
	return nombreADeviner;
}


// Nom :JouerPartie
// R�le : Fait jouer une partie au joueur pass� en param�tre
//        A la fin, met � jour les informations du joueur
// Param�tres d'entr�e: Le joueur qui joue et le nombre � deviner
// Param�tres de sortie: aucun
// Param�tres d'entr�e/sortie : Les infos du joueur

void JouerPartie(TJoueur& un_joueur, int nombreADeviner)
{
    int nombre_propose; // Ce sera le nombre que devinera le joueur � chaque tentative
    int i; // Ce sera le nombre de tentatives effectu�es par le joueur
    i = 0;
    nombre_propose = -1;
    while (i < 5)
    {
    cout << "Choisis un nombre entre 0 et 10 !\n";
    cin >> nombre_propose;
    if (nombre_propose == nombreADeviner)
    {
        (cout << "Tu as gagne !!!\n");
        un_joueur.nbPartiesJouees++;
        un_joueur.nbPartiesGagnees++;
        un_joueur.nbTentatives = un_joueur.nbTentatives + i;
    }
    if (nombre_propose >= nombreADeviner)
    {
        (cout << "Plus petit !!!\n");
        i++;
    }
    if (nombre_propose <= nombreADeviner)
    {
        (cout << "Plus grand !!!\n");
        i++;
    }
    }
    if (i == 5)
    {
        cout << "Tu as perdu !!!\n";
        un_joueur.nbPartiesJouees++;
        un_joueur.nbTentatives = un_joueur.nbTentatives + i;
    }
}


// Nom : MajResultatsJoueur
// R�le : met � jour les informations du joueur pass� en param�tre
// Param�tres d'entr�e:
// Param�tres de sortie:
// Param�tres d'entr�e/sortie :

void MajResultatsJoueur(TJoueur joueur, int nbEssais, bool gagne)
{
   // A COMPLETER
}

// Nom : ResultatsJoueur
// R�le : indique les r�sultats du joueur pass� en param�tre
//        le nombre de parties gagn�es, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations � l'�cran
// Param�tres d'entr�e:
// Param�tres de sortie:
// Param�tres d'entr�e/sortie :

void ResultatsJoueur(TJoueur joueur, int& nbsucces, int& nbechec, int& nbessais)
{
    // A COMPLETER
}

// Nom :Nom
// R�le : retourne le nom du joueur
// Param�tres d'entr�e: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur){

    return joueur.nom;
}

