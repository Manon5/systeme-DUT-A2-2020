#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "tools.h"

int main(int argc, char *argv[]) {
    Coordonnees ici;

    printf("initialisation\n");
    initialiseEtAffichage(&ici);

    printf("addition\n");
    additionEtAffichage(&ici);

    printf("multiplication\n");
    multiplicationEtAffichage(&ici);

    return 0;
}
