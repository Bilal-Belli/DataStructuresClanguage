#include <stdio.h>

#include <string.h>

/* Calcul de nombre de lignes & le nombre de caracteres **/
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
    printf("\n----  Le Fichier N'existe Pas  ----");
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
/* *****************- MODULE De DETECT SI IDENTIQUES -******************/
/*  **********************************************************************  */
void identiques(char nom_fichier1[30], char nom_fichier2[30]) {
  FILE * ptr_de_mon_fichier1;
  FILE * ptr_de_mon_fichier2;
  char ligne1[255];
  char ligne2[255];
  int identi = 1;
  int i = 0;
  ptr_de_mon_fichier1 = fopen(nom_fichier1, "r");
  ptr_de_mon_fichier2 = fopen(nom_fichier2, "r");
  if (ptr_de_mon_fichier2 != NULL && ptr_de_mon_fichier1 != NULL) {
    if (nb_lignes_fichier(nom_fichier1) == nb_lignes_fichier(nom_fichier2)) //  PEUT ETRE IDENTIQUES
    {
      while (!feof(ptr_de_mon_fichier2)) //il suffit une seul condition car il sont egaux dans le nb de lignes
      {
        i++;
        fgets(ligne1, 255, ptr_de_mon_fichier1);
        fgets(ligne2, 255, ptr_de_mon_fichier2);
        if (strcmp(ligne1, ligne2) != 0) {
          identi = 0; //les deux fichiers NE sont PAS identiques
          printf("\nfichier_1 ligne %d : %s", i, ligne1);
          printf("\nfichier_2 ligne %d : %s", i, ligne2);
        } else {
          if (i == nb_lignes_fichier(nom_fichier1)) {
            identi = 1;
          }
        }
      }
    } else //  NE SONT PAS IDENTIQUES
    {
      while (!feof(ptr_de_mon_fichier2)) //que ce soit fichier 1 est granda le deuxieme
      {
        i++;
        fgets(ligne1, 255, ptr_de_mon_fichier1);
        fgets(ligne2, 255, ptr_de_mon_fichier2);
        if (strcmp(ligne1, ligne2) != 0) {
          identi = 0; //les deux fichiers NE sont PAS identiques
          printf("\nfichier_1 ligne %d : %s", i, ligne1);
          printf("\nfichier_2 ligne %d : %s", i, ligne2);
        }
      }
    }
  } else {
    identi = 0; //  NE SONT PAS IDENTIQUES ----  UN DES DEUX Fichiers N'existe Pas  ----
  }
  fclose(ptr_de_mon_fichier1);
  fclose(ptr_de_mon_fichier2);
  if (identi == 1) {
    printf("\n\n----  LES DEUX FICHIERS SONT IDENTIQUES  ----");
  } // conclusion
  else {
    printf("\n\n----  NE SONT PAS IDENTIQUES  ----");
  }
  return 0;
}
/*  **********************************************************************  */
/* *****************- PROGRAMME PRINCIPALE -******************/
/*  **********************************************************************  */
int main() {
  char nom_fichier1[30];
  char nom_fichier2[30];
  printf("Donnez le nom_fichier1: ");
  gets(nom_fichier1);
  printf("Donnez le nom_fichier2: ");
  gets(nom_fichier2);
  identiques(nom_fichier1, nom_fichier2);
  printf("\n\nAffichage du FICHIER 1 \n");
  printf("********************\n");
  Affichage(nom_fichier1);
  printf("\n\nAffichage du FICHIER 2 \n");
  printf("********************\n");
  Affichage(nom_fichier2);
  return 0;
}