/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud et G Oglan
// Date de création : 05/02/2021
// Rôle du fichier: Contient le code jeu
// Nom des composants utilises: CPartie
//                              CJoueur
//                              iostream
// Historique du fichier: 03/03/2021, ajout d'un 2e joueur par g oglan
/*************************************************/
#include <iostream>
using namespace std;

#include "../include/Partie.h"

int main()
{

    //Création d'un joueur
    cout << "Joueur 1, vous allez jouer pour deviner un nombre secret" << endl;
    cout << "----------------------------------------------"<< endl;
    cout << "Veuillez entrer votre nom" << endl;
    string un_nom;
    cin >> un_nom;
    cout << "Veuillez entrer votre prenom" << endl;
    string un_prenom;
    cin >> un_prenom;

    cout << "Joueur 2, vous allez jouer pour deviner un nombre secret" << endl;
    cout << "----------------------------------------------"<< endl;
    cout << "Veuillez entrer votre nom" << endl;
    string un_nom2;
    cin >> un_nom2;
    cout << "Veuillez entrer votre prenom" << endl;
    string un_prenom2;
    cin >> un_prenom2;

    // Création des joueurs
    CJoueur joueur (un_nom, un_prenom);
    CJoueur joueur2 (un_nom2, un_prenom2);

    cout << "----------------------------------------------"<< endl;
    cout << "Combien de parties voulez-vous jouer ?" << endl;
    int nbParties;
    cin >> nbParties;


    for (int i = 0; i <nbParties; i++)
    {
        cout << "----------------------------------------------"<< endl;
        cout <<"Partie Numero : " << i+1 << endl;
        cout << "----------------------------------------------"<< endl;

        CPartie partie (0,10,4); // nombre à deviner entre 0 et 10, nombre de tentatives maximum 4

        partie.Jouer(joueur); // exécution d'une partie pour le joueur 1
        partie.Jouer(joueur2); // exécution d'une partie pour le joueur 2
    }


    cout << "----------------------------------------------"<< endl;
    cout << "Affichage des resultats du joueur "<< joueur.Nom() << " " << joueur.Prenom() << endl;
    cout << "----------------------------------------------"<< endl;

    // Récupération des résultats du joueur
    int nbsucces, nbechecs, nbessais;
    int nbsucces2, nbechecs2, nbessais2;
    joueur.Resultats(nbsucces, nbechecs, nbessais);  // les paramètres sont passés par référence
    joueur2.Resultats(nbsucces2, nbechecs2, nbessais2);
    // Affichage des résultats
    cout << "Nombre de parties gagnees : " << nbsucces << endl;
    cout << "Nombre de parties perdues : " << nbechecs << endl;
    cout << "Nombre de tentatives totales : " << nbessais << endl;
    cout << "Nombre d'essais moyen par partie : " << joueur.MoyenneEssais() << endl;
    cout << "----------------------------------------------"<< endl;
    cout << "Affichage des resultats du joueur "<< joueur2.Nom() << " " << joueur2.Prenom() << endl;
    cout << "----------------------------------------------"<< endl;
    cout << "Nombre de parties gagnees : " << nbsucces2 << endl;
    cout << "Nombre de parties perdues : " << nbechecs2 << endl;
    cout << "Nombre de tentatives totales : " << nbessais2 << endl;
    cout << "Nombre d'essais moyen par partie : " << joueur2.MoyenneEssais() << endl;
    cout << "----------------------------------------------"<< endl;
    if (nbsucces > nbsucces2)
    {
    cout << "----------------------------------------------"<< endl;
    cout << joueur.Nom() <<  " " << joueur.Prenom() << " a gagne + de parties " << endl;
    cout << "----------------------------------------------"<< endl;
    }
    if (nbsucces < nbsucces2)
    {
    cout << "----------------------------------------------"<< endl;
    cout << joueur2.Nom() << " " << joueur2.Prenom() << " a gagne + de parties " << endl;
    cout << "----------------------------------------------"<< endl;
    }
    if (nbsucces == nbsucces2)
    {
        if (nbessais < nbessais2)
        {
            cout << "----------------------------------------------"<< endl;
            cout << joueur.Nom() << " gagne au nombre d'essais " << endl;
            cout << "----------------------------------------------"<< endl;
        }
        if (nbessais > nbessais2)
        {
            cout << "----------------------------------------------"<< endl;
            cout << joueur2.Nom() << " gagne au nombre d'essais " << endl;
            cout << "----------------------------------------------"<< endl;
        }
        if (nbessais == nbessais2)
        {
            cout << "----------------------------------------------"<< endl;
            cout << " Ex aequo " << endl;
            cout << "----------------------------------------------"<< endl;
        }
    }
    return 0;
}

