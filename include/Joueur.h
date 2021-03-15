/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: Joueur.h
// Version : 1.0
// Nom du programmeur: MP Pinaud et G Oglan
// Date de création : 05/02/2021
// Rôle du fichier: Contient la déclaration des attributs et méthodes de la classe qui représente un joueur
// Nom des composants utilises: string
// Historique du fichier: 03/03/2021, ajout d'un 2e joueur par g oglan
//                        14/03/2021, ajout du destructeur par g oglan
/*************************************************/
#include <string>
using namespace std;



class CJoueur {

    public:

    // Nom :CJoueur  Constructeur
    // Rôle : Initialise toutes les informations du joueur.
    //        Le nombre de tentatives, de parties gagnées et de parties jouées seront à 0.
    // Paramètre d'entrée : un_nom le nom du joueur
    // Sortie : le joueur créé


    CJoueur(string un_nom, string un_prenom);

    // Nom : CJoueur  Destructeur
    // Rôle : libérer l'espace alloué à l'objet et afficher le nom + adresse du joueur détruit
    // Paramètres d'entrée:
    //                  aucun
    // Entrée/sortie :
    //                  aucun

    ~CJoueur();

    // Nom : MajResultats
    // Rôle : met à jour les informations d'un joueur
    // Paramètres d'entrée:
    //                  - le nombre d'essais
    //                  - gagne qui vaut true si le joueur a gagné, false sinon
    // Entrée/sortie :
    //                  le joueur dont on met à jour les résultats

    void MajResultats(int nbEssais, bool gagne);

    // Nom : Resultats
    // Rôle : indique les résultats d'un joueur
    //        le nombre de parties gagnées, le nombre de parties perdues, le nombre d'essais total
    //        La fonction N'affiche PAS les informations à l'écran
    // Paramètres de sortie:
    //                      - le nombre de succès,
    //                      - le nombre d'échecs
    //                      - le nombre total d'essais
    // Entrée :
    //            -le joueur dont on veut les résultats

    void Resultats(int &nbsucces, int &nbechec, int & nbessais);

    // Nom : MoyenneEssais
    // Rôle : indique la moyenne du nombre d'essais d'un joueur
    // Valeur de retour : la moyenne du nombre d'essais
    // Entrée : le joueur dont on veut la moyenne

    float MoyenneEssais();

    // Nom :Nom
    // Rôle : retourne le nom du joueur
    // Valeur de retour : nom du joueur
    // Entrée : le joueur dont on veut le nom

    string Nom();

    // Nom : Prenom
    // Rôle : retourne le prénom du joueur
    // Valeur de retour : prénom du joueur
    // Entrée : le joueur dont on veut le prénom

    string Prenom();


    private :

        string nom;  // nom du joueur
        string prenom; // prenom du joueur
        int nbPartiesJouees;
        int nbPartiesGagnees;
        int nbTentatives;
};






