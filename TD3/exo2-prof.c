#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void affichePids();

void affichePids() {
    printf("je suis un fils mon pid:%d le pid de mon pere:%d\n", getpid(), getppid());
}

int main() {
    int pid1, pid2, pid3, pid4; //stocker les trois valeurs de retour des forks
//process 1
    printf("je suis le patriarche mon pid vaut:%d\n", getpid());
    pid1 = fork(); //on crée le fils 2

    if (pid1 == 0) { // process 2
        affichePids();
        pid2 = fork(); //créer process 3

        if (pid2 == 0) {// process 3
            affichePids();
            // 3 n'a pas de fils
            exit(EXIT_SUCCESS);
        } else {
            // 2 doit creer aussi un  fils 4
            pid3 = fork(); //créer process 4

            if (pid3 == 0) {// process 4
                affichePids();
                // 4 doit creer un  fils 5
                pid4 = fork(); //créer process 5

                if (pid4 == 0) {// process 5
                    affichePids();
                    // 5 n'a pas de fils
                    exit(EXIT_SUCCESS);
                } else {
                    //4 doit attendre la fin de 5
                    waitpid(pid4, NULL, 0);
                }
            } else {
                //2 doit attendre la fin de 4
                waitpid(pid4, NULL, 0);
            }

            //2 doit attendre la fin de 3
            waitpid(pid2, NULL, 0);
            exit(EXIT_SUCCESS);
        }

    } else {
        //1 doit attendre la fin de 2
        waitpid(pid1, NULL, 0);
        getchar();

        printf("fin%d\n", getpid());
        exit(EXIT_SUCCESS);
    }

    printf("Je suis le père\nFin du programme exo2\n");
    return EXIT_SUCCESS;
}
