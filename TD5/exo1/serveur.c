#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 6000
#define MAX_BUFFER 1000


int main(int argc , char const *argv[]) {
    int fdSocketAttente;
    int fdSocketCommunication;
    struct sockaddr_in coordonneesServeur;
    struct sockaddr_in coordonneesAppelant;
    char tampon[MAX_BUFFER];
    int nbRecu;
    int longueurAdresse;

    fdSocketAttente = socket(PF_INET, SOCK_STREAM, 0);

    if (fdSocketAttente < 0) {
        printf("socket incorrecte\n");
        exit(EXIT_FAILURE);
    }

    // On prépare l’adresse d’attachement locale
    longueurAdresse = sizeof(struct sockaddr_in);
    memset(&coordonneesServeur, 0x00, longueurAdresse);

    coordonneesServeur.sin_family = PF_INET;
    // toutes les interfaces locales disponibles
    coordonneesServeur.sin_addr.s_addr = htonl(INADDR_ANY);
    // toutes les interfaces locales disponibles
    coordonneesServeur.sin_port = htons(PORT);

    if (bind(fdSocketAttente, (struct sockaddr *) &coordonneesServeur, sizeof(coordonneesServeur)) == -1) {
        printf("erreur de bind\n");
        exit(EXIT_FAILURE);
    }

    if (listen(fdSocketAttente, 5) == -1) {
        printf("erreur de listen\n");
        exit(EXIT_FAILURE);
    }

    socklen_t tailleCoord = sizeof(coordonneesAppelant);

    printf("En attente de connexion...");

    if ((fdSocketCommunication = accept(fdSocketAttente, (struct sockaddr *) &coordonneesAppelant,
                                        &tailleCoord)) == -1) {
        printf("erreur de accept\n");
        exit(-1);
    }

    printf("Client connecté\n");

    // on attend le message du client
    // la fonction recv est bloquante
    nbRecu = recv(fdSocketCommunication, tampon, MAX_BUFFER, 0);

    if (nbRecu > 0) {
        tampon[nbRecu] = 0;
        printf("Recu : %s\n", tampon);
    }

    strcpy(tampon, "Message renvoyé par le serveur vers le client !");
    // on envoie le message au client
    send(fdSocketCommunication, tampon, strlen(tampon), 0);

    close(fdSocketCommunication);
    close(fdSocketAttente);

    return EXIT_SUCCESS;
}
