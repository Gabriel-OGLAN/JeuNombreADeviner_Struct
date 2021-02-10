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
using namespace std;

#include "../include/JeuNombreADeviner.h"

int main()
{
    string un_nom;
    TJoueur joueurAcreer;
    cout << "Vous allez jouer pour deviner un nombre secret" << endl;
    cout << "Veuillez entrer votre nom" << endl;
    cin >> un_nom;
    InitJoueur(joueurAcreer, un_nom);
    JouerPartie(joueurAcreer, TirerNombreMystere());
    MajResultatsJoueur(joueurAcreer, joueurAcreer.nbTentatives, joueurAcreer.nbPartiesGagnees);
    ResultatsJoueur(joueurAcreer, joueurAcreer.nbPartiesGagnees, joueurAcreer.nbPartiesPerdues, joueurAcreer.nbTentatives);
    cout << joueurAcreer.nom << ", Tu as mis " << joueurAcreer.nbTentatives << " tentatives, tu as reussi " << joueurAcreer.nbPartiesGagnees << " et tu as perdu " << joueurAcreer.nbPartiesPerdues << " parties.";
    return 0;
}

