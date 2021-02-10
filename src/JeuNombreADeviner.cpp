/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud - G Oglan
// Date de création : 25/01/2021
// Rôle du fichier: Contient le code des fonctions du jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
//                              ctime
//                              cstdlib
// Historique du fichier: 25/01/2021 : création des fonctions et des commentaires par MP Pinaud
//                        01/02/2021 : création de la fonction JouerPartie par G Oglan
//                        08/02/2021 : finalisation de la fonction main par G Oglan
//                        10/02/2021 : vérification finale du code, corrections mineures et production de la recette par G Oglan
/*************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "../include/JeuNombreAdeviner.h"

// Nom :InitJoueur
// Rôle : Crée un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagnées et de parties jouées seront à 0.
// Paramètres d'entrée : Nom du joueur
// Paramètres de sortie : aucun
// Paramètres d'entrée/sortie : aucun

void InitJoueur(TJoueur& joueurAcreer, string un_nom)
{
    joueurAcreer.nbTentatives = 0;
    joueurAcreer.nbPartiesJouees = 0;
    joueurAcreer.nbPartiesGagnees = 0;
    joueurAcreer.nom = un_nom;
    joueurAcreer.nbPartiesPerdues = 0;
}


// Nom :TirerNombreMystere
// Rôle : Tire aléatoirement un nombre à deviner entre 0 et 10
// Valeur de retour : nombre à deviner

int TirerNombreMystere()
{
	srand((int)time(0));
    int nombreADeviner = (rand() % 11);
	return nombreADeviner;
}


// Nom :JouerPartie
// Rôle : Fait jouer une partie au joueur passé en paramètre
//        A la fin, met à jour les informations du joueur
// Paramètres d'entrée: Le joueur qui joue et le nombre à deviner
// Paramètres de sortie: aucun
// Paramètres d'entrée/sortie : Les infos du joueur

void JouerPartie(TJoueur& un_joueur, int nombreADeviner)
{
    int nombre_propose; // Ce sera le nombre que devinera le joueur à chaque tentative
    int i; // Ce sera le nombre de tentatives effectuées par le joueur
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
// Rôle : met à jour les informations du joueur passé en paramètre
// Paramètres d'entrée: Le nom du joueur, le nombre d'essais, et l'état de sa partie (gagné/perdu)
// Paramètres de sortie: aucun
// Paramètres d'entrée/sortie : aucun

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
// Rôle : indique les résultats du joueur passé en paramètre
//        le nombre de parties gagnées, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations à l'écran
// Paramètres d'entrée: Nom du joueur
// Paramètres de sortie: Nombre de tentatives, nombre de succès et nombre d'échecs
// Paramètres d'entrée/sortie : aucun

void ResultatsJoueur(TJoueur joueur, int& nbsucces, int& nbechec, int& nbessais)
{
    nbsucces = (joueur.nbPartiesGagnees)/2;
    nbechec = (joueur.nbPartiesJouees - joueur.nbPartiesGagnees)/2;
    nbessais = (joueur.nbTentatives)/2;
}

// Nom :Nom
// Rôle : retourne le nom du joueur
// Paramètres d'entrée: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur){

    return joueur.nom;
}

