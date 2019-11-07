#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "tools.h"

int main(int argc, char *argv[]) {
    Coordonnees ici;

    printf("initialisation\n");
    initialise(&ici);
    affichage(&ici);

    printf("addition\n");
    addition(&ici);
    affichage(&ici);

    printf("multiplication\n");
    multiplication(&ici);
    affichage(&ici);

    return 0;
}
