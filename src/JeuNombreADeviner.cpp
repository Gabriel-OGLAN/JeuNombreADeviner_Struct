/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud - G Oglan
// Date de cr�ation : 25/01/2021
// R�le du fichier: Contient le code des fonctions du jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
//                              ctime
//                              cstdlib
// Historique du fichier: 25/01/2021 : cr�ation des fonctions et des commentaires par MP Pinaud
//                        01/02/2021 : cr�ation de la fonction JouerPartie par G Oglan
//                        08/02/2021 : finalisation de la fonction main par G Oglan
//                        10/02/2021 : v�rification finale du code, corrections mineures et production de la recette par G Oglan
/*************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "../include/JeuNombreAdeviner.h"

// Nom :InitJoueur
// R�le : Cr�e un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagn�es et de parties jou�es seront � 0.
// Param�tres d'entr�e : Nom du joueur
// Param�tres de sortie : aucun
// Param�tres d'entr�e/sortie : aucun

void InitJoueur(TJoueur& joueurAcreer, string un_nom)
{
    joueurAcreer.nbTentatives = 0;
    joueurAcreer.nbPartiesJouees = 0;
    joueurAcreer.nbPartiesGagnees = 0;
    joueurAcreer.nom = un_nom;
    joueurAcreer.nbPartiesPerdues = 0;
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
    i = 1;
    nombre_propose = -1;
    while (i < 5)
    {
    cout << "Choisis un nombre entre 0 et 10 !\n";
    cin >> nombre_propose;
    if (nombre_propose == nombreADeviner)
    {
        (cout << "Tu as gagne !!!\n");
        MajResultatsJoueur(un_joueur, i, true);
        i=6;
    }
    else if (nombre_propose > nombreADeviner)
    {
        (cout << "Plus petit !!!\n");
        i++;
    }
    else if (nombre_propose < nombreADeviner)
    {
        (cout << "Plus grand !!!\n");
        i++;
    }
    }
    if (i == 5)
    {
        cout << "Tu as perdu !!!\n";
        MajResultatsJoueur(un_joueur, 4, false);
    }
}


// Nom : MajResultatsJoueur
// R�le : met � jour les informations du joueur pass� en param�tre
// Param�tres d'entr�e: Le nom du joueur, le nombre d'essais, et l'�tat de sa partie (gagn�/perdu)
// Param�tres de sortie: aucun
// Param�tres d'entr�e/sortie : aucun

void MajResultatsJoueur(TJoueur &un_joueur, int nbEssais, bool gagne)
{
    un_joueur.nbTentatives = un_joueur.nbTentatives+nbEssais;
    if (gagne == true)
    {
        un_joueur.nbPartiesGagnees++;
    }
    un_joueur.nbPartiesJouees++;
}

// Nom : ResultatsJoueur
// R�le : indique les r�sultats du joueur pass� en param�tre
//        le nombre de parties gagn�es, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations � l'�cran
// Param�tres d'entr�e: Nom du joueur
// Param�tres de sortie: Nombre de tentatives, nombre de succ�s et nombre d'�checs
// Param�tres d'entr�e/sortie : aucun

void ResultatsJoueur(TJoueur joueur, int& nbsucces, int& nbechec, int& nbessais)
{
    nbsucces = (joueur.nbPartiesGagnees)/2;
    nbechec = (joueur.nbPartiesJouees - joueur.nbPartiesGagnees)/2;
    nbessais = (joueur.nbTentatives)/2;
}

// Nom :Nom
// R�le : retourne le nom du joueur
// Param�tres d'entr�e: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur){

    return joueur.nom;
}

