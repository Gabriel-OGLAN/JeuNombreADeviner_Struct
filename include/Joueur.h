/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: Joueur.h
// Version : 1.0
// Nom du programmeur: MP Pinaud et G Oglan
// Date de cr�ation : 05/02/2021
// R�le du fichier: Contient la d�claration des attributs et m�thodes de la classe qui repr�sente un joueur
// Nom des composants utilises: string
// Historique du fichier: 03/03/2021, ajout d'un 2e joueur par g oglan
//                        14/03/2021, ajout du destructeur par g oglan
/*************************************************/
#include <string>
using namespace std;



class CJoueur {

    public:

    // Nom :CJoueur  Constructeur
    // R�le : Initialise toutes les informations du joueur.
    //        Le nombre de tentatives, de parties gagn�es et de parties jou�es seront � 0.
    // Param�tre d'entr�e : un_nom le nom du joueur
    // Sortie : le joueur cr��


    CJoueur(string un_nom, string un_prenom);

    // Nom : CJoueur  Destructeur
    // R�le : lib�rer l'espace allou� � l'objet et afficher le nom + adresse du joueur d�truit
    // Param�tres d'entr�e:
    //                  aucun
    // Entr�e/sortie :
    //                  aucun

    ~CJoueur();

    // Nom : MajResultats
    // R�le : met � jour les informations d'un joueur
    // Param�tres d'entr�e:
    //                  - le nombre d'essais
    //                  - gagne qui vaut true si le joueur a gagn�, false sinon
    // Entr�e/sortie :
    //                  le joueur dont on met � jour les r�sultats

    void MajResultats(int nbEssais, bool gagne);

    // Nom : Resultats
    // R�le : indique les r�sultats d'un joueur
    //        le nombre de parties gagn�es, le nombre de parties perdues, le nombre d'essais total
    //        La fonction N'affiche PAS les informations � l'�cran
    // Param�tres de sortie:
    //                      - le nombre de succ�s,
    //                      - le nombre d'�checs
    //                      - le nombre total d'essais
    // Entr�e :
    //            -le joueur dont on veut les r�sultats

    void Resultats(int &nbsucces, int &nbechec, int & nbessais);

    // Nom : MoyenneEssais
    // R�le : indique la moyenne du nombre d'essais d'un joueur
    // Valeur de retour : la moyenne du nombre d'essais
    // Entr�e : le joueur dont on veut la moyenne

    float MoyenneEssais();

    // Nom :Nom
    // R�le : retourne le nom du joueur
    // Valeur de retour : nom du joueur
    // Entr�e : le joueur dont on veut le nom

    string Nom();

    // Nom : Prenom
    // R�le : retourne le pr�nom du joueur
    // Valeur de retour : pr�nom du joueur
    // Entr�e : le joueur dont on veut le pr�nom

    string Prenom();


    private :

        string nom;  // nom du joueur
        string prenom; // prenom du joueur
        int nbPartiesJouees;
        int nbPartiesGagnees;
        int nbTentatives;
};






