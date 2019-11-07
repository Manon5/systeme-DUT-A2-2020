#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include "tools.h"

int main(int argc, char const *argv[]) {
    int **matrice;
    srand(time(NULL));

    int nbLignes = saisirNombreLignes();
    if (verifierValiditeSaisie(nbLignes, MIN_LIGNE, MAX_LIGNE) == -1) {
        return -1;
    }

    int nbColonnes = saisirNombreColonnes();
    if (verifierValiditeSaisie(nbColonnes, MIN_LIGNE, MAX_LIGNE) == -1) {
        return -1;
    }

    printf("Construction d'une matrice %dx%d\n", nbLignes, nbColonnes);
    matrice = constructionMatrice(nbLignes, nbColonnes);

    affichageMatrice(matrice, nbLignes, nbColonnes);

    // modification
    int newNbLignes = saisirNombreLignes();
    if (verifierValiditeSaisie(newNbLignes, MIN_LIGNE, MAX_LIGNE) == -1) {
        return -1;
    }

    int newNbColonnes = saisirNombreColonnes();
    if (verifierValiditeSaisie(newNbColonnes, MIN_LIGNE, MAX_LIGNE) == -1) {
        return -1;
    }

    printf("Construction d'une matrice %dx%d\n", newNbLignes, newNbColonnes);
    verifierSiMoinsDeLignes(nbLignes, newNbLignes, matrice);

    matrice = (int **) realloc(matrice, sizeof(int *) * newNbLignes);
    if (matrice == NULL) {
        destructionMatrice(matrice, nbLignes);
        return -1;
    }

    for (int i = 0; i < nbLignes; ++i) {
        matrice[i] = (int *) realloc(matrice[i], sizeof(int) * newNbColonnes);

        if (matrice[i] == NULL) {
            printf("La réallocation a échouée!\n");
            destructionMatrice(matrice, newNbLignes);
            return -1;
        }
    }

    // on alloue de la memoire pour les nouvelles lignes
    // si newNbLignes < nbLignes --> jamais executé
    for (int i = nbLignes; i < newNbLignes; ++i) {
        matrice[i] = (int *) malloc(sizeof(int) * newNbColonnes);

        if (matrice[i] == NULL) {
            printf("L'allocation a échouée!\n");
            destructionMatrice(matrice, newNbLignes);
            return -1;
        }
    }

    renseignerNouvellesColonnes(matrice, nbLignes, newNbColonnes, nbColonnes);
    renseignerNouvellesLignes(matrice, newNbLignes, nbLignes, newNbColonnes);

    affichageMatrice(matrice, newNbLignes, newNbColonnes);
    destructionMatrice(matrice, newNbLignes);

    return 0;
}
