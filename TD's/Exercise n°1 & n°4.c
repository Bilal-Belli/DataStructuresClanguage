#include <stdio.h>

#include <string.h>

/* Calcul de nombre de lignes & le nombre de caracteres **/
/*  **********************************************************************  */
/*  MODULE DE CALCULE DE NOMBRE DE CARACTERES  */
/*  **********************************************************************  */
int nb_caracteres_fichier(char nom_fichier[30]) {
  FILE * ptr_de_mon_fichier;
  char caractere_de_lecture;
  int nb_caracteres = 0;
  ptr_de_mon_fichier = fopen(nom_fichier, "r");
  if (ptr_de_mon_fichier == NULL) {
    nb_caracteres = 0; //----  Le Fichier N'existe Pas  ----
  } else {
    while (!feof(ptr_de_mon_fichier)) {
      caractere_de_lecture = fgetc(ptr_de_mon_fichier); //on lire tout les caracteres du fichier jusqua la fin (feof)
      if (!feof(ptr_de_mon_fichier) && caractere_de_lecture != '\n') {
        nb_caracteres++;
      }
    }
    fclose(ptr_de_mon_fichier);
  }
  return nb_caracteres;
}
/*  **********************************************************************  */
/* *****************- MODULE DE CALCULE DE NOMBRE DE LIGNES -******************/
/*  **********************************************************************  */
int nb_lignes_fichier(char nom_fichier[30]) {
  FILE * ptr_de_mon_fichier;
  char caractere_de_lecture;
  int nb_lignes = 0;
  ptr_de_mon_fichier = fopen(nom_fichier, "r");
  if (ptr_de_mon_fichier == NULL) {
    nb_lignes = 0; //----  Le Fichier N'existe Pas  ----
  } else {
    while (!feof(ptr_de_mon_fichier)) {
      caractere_de_lecture = fgetc(ptr_de_mon_fichier);
      if (!feof(ptr_de_mon_fichier) && caractere_de_lecture != '\n') {
        nb_lignes++;
      }
      while (!feof(ptr_de_mon_fichier) && caractere_de_lecture != '\n') {
        //lire les caracteres jusqua la fin de la ligne (seul une et une seul ligne) ou trouve \n
        caractere_de_lecture = fgetc(ptr_de_mon_fichier);
      }
    }
    fclose(ptr_de_mon_fichier);
  }
  return nb_lignes;
}
/*  **********************************************************************  */
/* *****************- MODULE D'AFFICHAGE DE UN FICHIER TEXTE VERSION 2 -******************/
/*  **********************************************************************  */
void Affichage(char nom_fichier[30]) {
  FILE * ptr_de_mon_fichier;
  char caracteres;
  ptr_de_mon_fichier = fopen(nom_fichier, "r");
  if (ptr_de_mon_fichier == NULL) {
    printf("----  Le Fichier N'existe Pas  ----");
  } else {
    while (!feof(ptr_de_mon_fichier)) {
      caracteres = fgetc(ptr_de_mon_fichier);
      printf("%c", caracteres);
      while (!feof(ptr_de_mon_fichier) && caracteres != '\n') {
        caracteres = fgetc(ptr_de_mon_fichier);
        printf("%c", caracteres);
      }
    }
    fclose(ptr_de_mon_fichier);
  }
  return 0;
}
/*  **********************************************************************  */
/* *****************- PROGRAMME PRINCIPALE -******************/
/*  **********************************************************************  */
int main() {
  char nom_fichier[30];
  printf("Donnez le nom_fichier: ");
  gets(nom_fichier);
  printf("\nNb_caracteres (version 1) : %5d \n", nb_caracteres_fichier(nom_fichier));
  printf("\nNb_lignes                 : %5d \n", nb_lignes_fichier(nom_fichier));
  printf("\n\nAffichage du FICHIER \n");
  printf("********************\n");
  Affichage(nom_fichier);
  return 0;
}