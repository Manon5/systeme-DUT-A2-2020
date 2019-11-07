#ifndef SYSTEME_TOOLS_H
#define SYSTEME_TOOLS_H

#define TAILLE_MIN 1
#define TAILLE_MAX 1000
#define NB_MIN 0
#define NB_MAX 100
#define MIN_LIGNE 2
#define MAX_LIGNE 10

typedef struct {
    int x;
    int y;
    int z;
} Coordonnees;

// exo2
void initialise(Coordonnees *c);
void affichage(Coordonnees *c);
void addition(Coordonnees *c);
void multiplication(Coordonnees *c);

// exo3
void initialiseEtAffichage(Coordonnees *c);
void additionEtAffichage(Coordonnees *c);
void multiplicationEtAffichage(Coordonnees *c);

// exo4
int randomNumber();
int *constructionTableau(const int taille);
void destructionTableau(int *chiffres);
void afficherTableau(int *chiffres, const int taille);
int saisirTailleTableau();
int verifierValiditeSaisie(int nombre, int min, int max);

// exo5
int modifierTailleTableau(int *chiffres, const int nouvelleTaille, const int ancienneTaille);

// exo6
int saisirNombreLignes();
int saisirNombreColonnes();
void affichageMatrice(int **matrice, const int nbLignes, const int nbColonnes);
int **constructionMatrice(const int nbLignes, const int nbColonnes);
void destructionMatrice(int **matrice, const int nbLignes);

// exo7
void verifierSiMoinsDeLignes(const int ancienNbLignes, const int newNbLignes, int **matrice);
void renseignerNouvellesColonnes(int **matrice, const int ancienNbLignes,
                                 const int newNbColonnes, const int ancienNbColonnes);
void renseignerNouvellesLignes(int **matrice, const int newNbLignes,
                               const int ancienNbLignes, const int newNbColonnes);

#endif //SYSTEME_TOOLS_H
