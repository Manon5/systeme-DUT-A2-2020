#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"

// exo2
void affichage(Coordonnees *c) {
    printf("x=%d y=%d z=%d\n", c->x, c->y, c->z);
}

void initialise(Coordonnees *c) {
    c->x = 10;
    c->y = 5;
    c->z = 2;
}

void addition(Coordonnees *c) {
    c->z = c->x + c->y;
}

void multiplication(Coordonnees *c) {
    c->z = c->x * c->y;
}
// fin exo2

// exo3
void initialiseEtAffichage(Coordonnees *c) {
    initialise(c);
    affichage(c);
}

void additionEtAffichage(Coordonnees *c) {
    addition(c);
    affichage(c);
}

void multiplicationEtAffichage(Coordonnees *c) {
    multiplication(c);
    affichage(c);
}
// fin exo3

// exo4
int randomNumber() {
    return (rand() % (NB_MAX - NB_MIN)) + NB_MIN;
}

int *constructionTableau(const int taille) {
    int *tableau = (int *) malloc(taille * sizeof(int));

    if (tableau == NULL) {
        printf("Allocation echouée\n");
    }

    for (int i = 0; i < taille; i++) {
        tableau[i] = randomNumber();
    }

    return tableau;
}

void destructionTableau(int *chiffres) {
    free(chiffres);
    chiffres = NULL;
}

void afficherTableau(int *chiffres, const int taille) {
    printf("Affichage\n");

    for (int i = 0; i < taille; i++) {
        printf("[%d] : %d\n", i, chiffres[i]);
    }
}

int saisirTailleTableau() {
    int taille = 0;
    printf("Saisir la taille du tableau (1 -> 1000) :\n");
    scanf("%d", &taille);

    return taille;
}

int verifierValiditeSaisie(int nombre, int min, int max) {
    if (nombre > max) {
        printf("Nombre trop grand. Fin du programme\n");
        return -1;
    }

    if (nombre < min) {
        printf("Nombre trop petit. Fin du programme\n");
        return -1;
    }
    return 0;
}
// fin exo4

// exo5
int modifierTailleTableau(int *chiffres, const int nouvelleTaille, const int ancienneTaille) {
    int *nouveau = realloc(chiffres, nouvelleTaille * sizeof(int));

    if (nouveau == NULL) {
        printf("La réallocation a échouée!\n");
        free(nouveau);

        return -1;
    }

    // si la nouvelle taille est plus grande, on génère des nombres pour les nouvelles cases
    if (nouvelleTaille > ancienneTaille) {
        for (int i = ancienneTaille; i < nouvelleTaille; i++) {
            nouveau[i] = randomNumber();
        }
    }

    chiffres = nouveau;
}

// exo6
int saisirNombreLignes() {
    int nb = 0;
    printf("Saisir le nombre de lignes (%d -> %d) :\n", MIN_LIGNE, MAX_LIGNE);
    scanf("%d", &nb);

    return nb;
}

int saisirNombreColonnes() {
    int nb = 0;
    printf("Saisir le nombre de colonnes (%d -> %d) :\n", MIN_LIGNE, MAX_LIGNE);
    scanf("%d", &nb);

    return nb;
}

void affichageMatrice(int **matrice, const int nbLignes, const int nbColonnes) {
    for (int i = 0; i < nbLignes; i++) {
        for (int j = 0; j < nbColonnes; j++) {
            printf("%d\t", matrice[i][j]);
        }
        printf("\n");
    }
}

int **constructionMatrice(const int nbLignes, const int nbColonnes) {
    int **matrice = (int **) malloc(nbLignes * sizeof(int *));

    if (matrice == NULL) {
        printf("L'allocation a échouée!\n");
    }

    for (int i = 0; i < nbLignes; i++) {
        matrice[i] = constructionTableau(nbColonnes);
    }

    return matrice;
}

void destructionMatrice(int **matrice, const int nbLignes) {
    for (int i = 0; i < nbLignes; i++) {
        free(matrice[i]);
    }

    free(matrice);
    matrice = NULL;
}

// exo7
void verifierSiMoinsDeLignes(const int ancienNbLignes, const int newNbLignes, int **matrice) {
    //suppression data si moins de lignes
    if (newNbLignes < ancienNbLignes) {
        for (int i = newNbLignes; i < ancienNbLignes; i++) {
            free(matrice[i]);
        }
    }
}

void renseignerNouvellesColonnes(int **matrice, const int ancienNbLignes,
                                 const int newNbColonnes, const int ancienNbColonnes) {
    for (int i = 0; i < ancienNbLignes; ++i) {
        for (int j = ancienNbColonnes; j < newNbColonnes; ++j) {
            matrice[i][j] = randomNumber();
        }
    }
}

void renseignerNouvellesLignes(int **matrice, const int newNbLignes,
                               const int ancienNbLignes, const int newNbColonnes) {
    for (int i = ancienNbLignes; i < newNbLignes; ++i) {
        for (int j = 0; j < newNbColonnes; ++j) {
            matrice[i][j] = randomNumber();
        }
    }
}
