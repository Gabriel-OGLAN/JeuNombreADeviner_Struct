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
#include <string>
using namespace std;

//Type: structure TJoueur
// Rôle : représente un joueur. Définit les propriétés d'un joueur.

typedef struct {

string nom;  // nom du joueur
int nbPartiesJouees;
int nbPartiesGagnees;
int nbTentatives;
int nbPartiesPerdues;
} TJoueur;





// Nom :InitJoueur
// Rôle : Crée un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagnées et de parties jouées seront à 0.
// Paramètres d'entrée : nom du joueur
// Paramètres de sortie : joueur à créer
// Paramètres d'entrée/sortie : aucun

void InitJoueur (TJoueur &joueurAcreer, string un_nom);


// Nom :TirerNombreMystere
// Rôle : Tire aléatoirement un nombre à deviner entre 0 et 10
// Valeur de retour : nombre à deviner

int TirerNombreMystere();

// Nom :JouerPartie
// Rôle : Fait jouer une partie au joueur passé en paramètre
//        A la fin, met à jour les informations du joueur
// Paramètres d'entrée: Le joueur qui joue et le nombre à deviner
// Paramètres de sortie: aucun
// Paramètres d'entrée/sortie : Les infos du joueur

void JouerPartie (TJoueur &un_joueur, int nombreADeviner);

// Nom : MajResultatsJoueur
// Rôle : met à jour les informations du joueur passé en paramètre
// Paramètres d'entrée: Le nom du joueur, le nombre d'essais, et l'état de sa partie (gagné/perdu)
// Paramètres de sortie: aucun
// Paramètres d'entrée/sortie : aucun

void MajResultatsJoueur(TJoueur &un_joueur, int nbEssais, bool gagne);



// Nom : ResultatsJoueur
// Rôle : indique les résultats du joueur passé en paramètre
//        le nombre de parties gagnées, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations à l'écran
// Paramètres d'entrée: Nom du joueur
// Paramètres de sortie: Nombre de tentatives, nombre de succès et nombre d'échecs
// Paramètres d'entrée/sortie : aucun

void ResultatsJoueur(TJoueur joueur, int &nbsucces, int &nbechec, int & nbessais);


// Nom :Nom
// Rôle : retourne le nom du joueur
// Paramètres d'entrée: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur);


