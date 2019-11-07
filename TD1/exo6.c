#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include "tools.h"

int main(int argc, int *argv[]) {
    srand(time(NULL)); //initialise le générateur aléatoire

    int nbLignes = saisirNombreLignes();
    if (verifierValiditeSaisie(nbLignes, MIN_LIGNE, MAX_LIGNE) == -1) {
        return -1;
    }

    int nbColonnes = saisirNombreColonnes();
    if (verifierValiditeSaisie(nbColonnes, MIN_LIGNE, MAX_LIGNE) == -1) {
        return -1;
    }

    printf("Construction d'une matrice %dx%d\n", nbLignes, nbColonnes);
    int **matrice = constructionMatrice(nbLignes, nbColonnes);

    affichageMatrice(matrice, nbLignes, nbColonnes);
    destructionMatrice(matrice, nbLignes);

    return 0;
}
