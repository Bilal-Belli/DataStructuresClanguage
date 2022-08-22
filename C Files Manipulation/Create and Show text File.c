#include <stdio.h>

struct Tenreg {
  char ligne[256];
}e;

int main() {
  FILE * f;
  int k = 1;
  char nom_fichier[200];

  printf("FILE NAME : "); // instruction a l'utilisateur
  gets(nom_fichier); //scanner le nom du fichier meme si il ya des espaces
  f = fopen(nom_fichier, "w"); // creation du nouveau fichier
  printf("\n(0 TO END PROCESS) line%3d: ", k++); // insertion des enregistrements lus à la console
  gets(e.ligne); // scanner la ligne donneé par utilisateur
  while (e.ligne[0] != '0') {
    fprintf(f, "%s\n", e.ligne); // chaque ligne est un variable existe dans l'enregistrement
    printf("(0 TO END PROCESS) line%3d: ", k++);
    gets(e.ligne); // scanner la ligne donneé par utilisateur (boucle)
  }
  fflush(f);
  fclose(f);

  /* Affichage du fichier */
  int n, i;
  printf("FILE NAME : ");
  gets(nom_fichier);
  f = fopen(nom_fichier, "r");
  i = 1;
  if (f != NULL) {
    fgets(e.ligne, 255, f); // lecture des enregistrements depuis le fichier
    printf("\n\nline%3d:  %s", i++, e.ligne);
    while (!feof(f)) {
      fgets(e.ligne, 255, f);
      if (feof(f)) {
        break;
      };
      printf("line%3d:  %s", i++, e.ligne);
    }
    fclose(f);
  } else {
    printf("\nTHE FILE DOES NOT EXISTE\n");
  }
  return 0;
}