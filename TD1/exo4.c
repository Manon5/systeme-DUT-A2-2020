#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include "tools.h"

int main(int argc, char *argv[]) {
    srand(time(NULL)); //initialise le générateur aléatoire

    int tailleTableau = saisirTailleTableau();

    if (verifierValiditeSaisie(tailleTableau, TAILLE_MIN, TAILLE_MAX) == -1) {
        return -1;
    }

    printf("Construction d'un tableau de taille %d\n", tailleTableau);
    int *tableau = constructionTableau(tailleTableau);
    afficherTableau(tableau, tailleTableau);
    destructionTableau(tableau);

    return 0;
}
