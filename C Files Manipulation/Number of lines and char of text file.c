#include <stdio.h>
#include <string.h>

/******************- NB OF CHAR -******************/
int nb_caracteres_fichier(char nom_fichier[30]) {
  FILE * ptr_de_mon_fichier;
  char k;
  int nb_caracteres = 0;
  ptr_de_mon_fichier = fopen(nom_fichier, "r");
  if (ptr_de_mon_fichier == NULL) {
    // Le Fichier N'existe Pas
    nb_caracteres = 0;
  } else {
    while (!feof(ptr_de_mon_fichier)) {
      //on lire tout les caracteres du fichier jusqua la fin (feof)
      k = fgetc(ptr_de_mon_fichier); 
      if (!feof(ptr_de_mon_fichier) && k != '\n') {
        nb_caracteres++;
      }
    }
    fclose(ptr_de_mon_fichier);
  }
  return nb_caracteres;
}

/******************- NB OF LINES -******************/
int nb_lignes_fichier(char nom_fichier[30]) {
  FILE * ptr_de_mon_fichier;
  char k;
  int nb_lignes = 0;
  ptr_de_mon_fichier = fopen(nom_fichier, "r");
  if (ptr_de_mon_fichier == NULL) {
    // Le Fichier N'existe Pas
    nb_lignes = 0;
  } else {
    while (!feof(ptr_de_mon_fichier)) {
      k = fgetc(ptr_de_mon_fichier);
      if (!feof(ptr_de_mon_fichier) && k != '\n') {
        nb_lignes++;
      }
      while (!feof(ptr_de_mon_fichier) && k != '\n') {
        k = fgetc(ptr_de_mon_fichier);
      }
    }
    fclose(ptr_de_mon_fichier);
  }
  return nb_lignes;
}

/******************- SHOW TEXT FILE TO CONFIRM -******************/
void Affichage(char nom_fichier[30]) {
  FILE * ptr_de_mon_fichier;
  char caracteres;
  ptr_de_mon_fichier = fopen(nom_fichier, "r");
  while ((caracteres = fgetc(ptr_de_mon_fichier)) != EOF) {
    printf("%c", caracteres);
  }
  fclose(ptr_de_mon_fichier);
}

int main() {
  char nom_fichier[30];
  printf("Donnez le nom du Fichier: ");
  gets(nom_fichier);
  printf("\nNb_Char  : %5d \n", nb_caracteres_fichier(nom_fichier));
  printf("\nNb_lines : %5d \n", nb_lignes_fichier(nom_fichier));
  printf("\nFILE\n");
  Affichage(nom_fichier);
  return 0;
}