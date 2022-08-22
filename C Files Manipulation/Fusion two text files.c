#include <stdio.h>

int main() {
  struct Tenreg {
    char ligne[256];
  } e;

  FILE * f1;
  FILE * f2;
  FILE * f3;
  int k = 1;
  char nom_fichier_1[200];
  char nom_fichier_2[200];
  char nom_fichier_3[200];

  printf("NOTE: THE RESULT WILL BE STORED ON FILE 1\n");
  printf("FILE 1 NAME : ");
  gets(nom_fichier_1);
  printf("\nFILE 2 NAME : ");
  gets(nom_fichier_2);
  printf("\nRESULT FILE NAME : ");
  gets(nom_fichier_3);
  printf("\n");

  f1 = fopen(nom_fichier_1, "r");
  f2 = fopen(nom_fichier_2, "r");
  f3 = fopen(nom_fichier_3, "w");
  while (!feof(f1)) {
    fgets(e.ligne, 255, f1);
    fprintf(f3, "%s", e.ligne); //remplir par le fichier 1
  }
  fflush(f1);
  fclose(f1);

  fgets(e.ligne, 255, f2);
  fprintf(f3, "\n%s", e.ligne);
  while (!feof(f2)) {
    fgets(e.ligne, 255, f2);
    fprintf(f3, "%s", e.ligne); //remplir par le fichier 2
  }
  fflush(f2);
  fclose(f2);
  fflush(f3);
  fclose(f3);

  /* Affichage du fichier */
  char rep[1];
  printf("\nYOU WANT TO SHOW THE RESULT ? (y/n)\n");
  scanf("%c", rep);
  if (rep[0] == 'y') {
    int n, i;
    f3 = fopen(nom_fichier_3, "r");
    i = 1;
    if (f3 != NULL) {
      fgets(e.ligne, 255, f3);
      printf("\n\nligne%3d:  %s", i++, e.ligne);
      while (!feof(f3)) {
        fgets(e.ligne, 255, f3);
        printf("ligne%3d:  %s", i++, e.ligne);
      }
      fclose(f1);
    } else {
      printf("LE FICHIER N'EXISTE PAS\n");
    }
  } else {
    if (rep[0] == 'n') {
      printf("*********** FIN *********\n");
    } else {
      printf("\nVuillez entrer 'y' ou 'n' la prochaine foix!! \n");
      printf("*********** FIN *********\n");
    }
  }
  return 0;
}