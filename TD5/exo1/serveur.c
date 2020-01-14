#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(int argc , char const *argv[]) {

   int fdSocketAttente;
   int fdSocketCommunication;
   struct sockaddr_in AdServeur;
   struct sockaddr_in AdClient;
   int longueurAdresse;
   int port = 6000; //en vrai jsp


   // Créer primitive socket
  int fdSocketAttente=socket(AF_INET,SOCK_STREAM ,0);
  if(fdSocketAttente== -1) {
    printf("Erreur de création de socket\n");
    exit(0);
  }


  // Création structure d'adresse
  longueurAdresse = sizeof(struct sockaddr_in);
  memset(&AdServeur , 0x00, longueurAdresse);

  AdServeur.sin_family = AF_INET;
  AdServeur.sin_addr.s_addr = htonl(INADDR_ANY);
  // toutes les interfaces locales disponibles
  AdServeur.sin_port = htons(6000);
  //permet d’attendre la connexion sur le port 6000

  // Bind
  if(bind(fdSocketAttente,(struct sockaddr*)&AdServeur ,longueurAdresse) == -1) {
    printf("Erreur de  bind \n");
     exit(0);
  }

  // le serveur se met en attente de connexion
  if(listen(fdSocketAttente ,5)== -1) {
    printf("Erreur de listen \n");
    exit(0);
  }

    printf("Le serveur est en attente d'une connexion\n");

    int longueurAdresse=sizeof(AdClient);
    int fdSocketCommunication=accept(fdSocketAttente,(struct sockaddr*)&AdClient ,&longueurAdresse);
    if(fdSocketCommunication == -1) {
        printf("Erreur d’accept \n");
        exit(0);
    }

}

