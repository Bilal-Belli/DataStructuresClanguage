#include <stdio.h>

int main() {

  struct Tenreg {
    char ligne[256];
  } e;

  FILE * f;
  char nom_fichier[200];
  int n, i;

  printf("File Name : ");
  gets(nom_fichier);
  f = fopen(nom_fichier, "r");
  i = 1;
  if (f != NULL) {
    fgets(e.ligne, 255, f);
    i++;
    while (!feof(f)) {
      fgets(e.ligne, 255, f);
      if (feof(f)) {
        break;
      };
      i++;
    }
    fclose(f);
  } else {
    printf("File does not exist\n");
  }

  printf("LE NOMBRE DE LIGNES EST : %5d \n", i);
  return 0;
}