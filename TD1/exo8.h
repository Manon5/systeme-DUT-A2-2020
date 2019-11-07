#ifndef SYSTEME_EXO8_H
#define SYSTEME_EXO8_H

#define MIN_NB_MOTS 2
#define MAX_NB_MOTS 20
#define MAX_LONGUEUR_CHAINE 1000

int saisirNombreChaines(char tampon[]);
char **construireTableau(const int taille);
void detruireTableauChaines(char **chaines, const int taille);
void afficherTableauChaines(char **chaines, const int taille);
void saisirChaine(char tampon[], const int numero);
int verifierValiditeTaille(const int taille, const int min, const int max);

#endif //SYSTEME_EXO8_H
