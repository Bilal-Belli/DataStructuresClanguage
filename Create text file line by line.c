#include <stdio.h>

struct Tenreg {
  char ligne[256]; // variable enregistrement
} e;

int main() {
  FILE * f;
  char nom_fichier[200];
  int k=1;

  printf("FILE NAME : "); //scanner le nom du fichier meme si il ya des espaces
  gets(nom_fichier); // creation du nouveau fichier
  f = fopen(nom_fichier, "w"); // insertion des enregistrements lus à la console
  printf("Give line %d( 0 TO END): ",k);
  gets(e.ligne); // scanner la ligne donneé par utilisateur
  while (e.ligne[0] != '0') {
    fprintf(f, "%s\n", e.ligne); // chaque ligne est un variable existe dans l'enregistrement
    k++;
    printf("Give line %d( 0 TO END): ",k);
    gets(e.ligne); // scanner la ligne donneé par utilisateur (boucle)
  }
  fclose(f);
  return 0;
}