#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include "exo8.h"

int main(int argc, int *argv[]) {
    int i;
    int longueur;
    char tampon[MAX_LONGUEUR_CHAINE];

    int taille = saisirNombreChaines(tampon);
    if (verifierValiditeTaille(taille, MIN_NB_MOTS, MAX_NB_MOTS) == -1) {
        return -1;
    }

    char **tableau = construireTableau(taille);
    if (tableau == NULL) {
        printf("L'allocation a échouée!\n");
        return -1;
    }

    for (i = 0; i < taille; i++) {
        saisirChaine(tampon, i + 1);

        longueur = strlen(tampon) + 1; // +1 pour le marqueur de fin de chaine \n
        tableau[i] = (char *) malloc(longueur * sizeof(char));
        strcpy(tableau[i], tampon);
    }

    printf("\nVoici le tableau de chaines :\n\n");
    afficherTableauChaines(tableau, taille);

    detruireTableauChaines(tableau, taille);

    return 0;
}


char **construireTableau(const int taille) {
    char **tableau = malloc(taille * sizeof(char *));
    return tableau;
}

void detruireTableauChaines(char **chaines, const int taille) {
    for (int i = 0; i < taille; i++) {
        free(chaines[i]);
    }

    free(chaines);
    chaines = NULL;
}

void afficherTableauChaines(char **chaines, const int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%d. %s",i + 1 , chaines[i]);
    }
}

void saisirChaine(char tampon[], const int numero) {
    printf("Saisir la chaine %d\n", numero);
    fgets(tampon, MAX_LONGUEUR_CHAINE, stdin);
}

int saisirNombreChaines(char tampon[]) {
    int taille;
    printf("Saisir le nombre de chaines (%d -> %d):\n", MIN_NB_MOTS, MAX_NB_MOTS);
    fgets(tampon, 10, stdin);
    taille = atoi(tampon);
    return taille;
}

int verifierValiditeTaille(const int taille, const int min, const int max) {
    if (taille > max) {
        printf("Nombre trop grand. Fin du programme\n");
        return -1;
    }

    if (taille < min) {
        printf("Nombre trop petit. Fin du programme\n");
        return -1;
    }

    return 0;
}
