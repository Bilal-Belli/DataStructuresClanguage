#include <stdio.h>

#include <string.h>

/* Calcul de nombre de lignes & le nombre de caracteres **/
/*  **********************************************************************  */
/* *****************- MODULE D'AFFICHAGE DE UN FICHIER TEXTE  -******************/
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
/* *****************- MODULE D'AFFICHAGE DE UN FICHIER TEXTE  -******************/
/*  **********************************************************************  */
int calcul_occurence(char nom_fichier[30], char mot[30]) {
    FILE * ptr_de_mon_fichier;
    char caracteres;
    int resultat = 0;
    char mot_extrait[30];
    char ligne[30];
    const char s[2] = " ";
    ptr_de_mon_fichier = fopen(nom_fichier, "r");
    if (ptr_de_mon_fichier == NULL) {
        resultat = 0;
    } else {
        while (!feof(ptr_de_mon_fichier)) {
        fgets(ligne, sizeof(ligne), ptr_de_mon_fichier);
        while (strtok(ligne, mot_extrait, s) != "\n") {
            if (strcmp(strtok(ligne, mot_extrait), mot) == 0) {
            resultat++;
            printf("\n %d", resultat);
            }
        }
        }
        fclose(ptr_de_mon_fichier);
    }
    return resultat;
}
/*  **********************************************************************  */
/* *****************- PROGRAMME PRINCIPALE -******************/
/*  **********************************************************************  */
int main() {
    char nom_fichier[30];
    char mot[30];
    printf("Donnez le nom_fichier: ");
    gets(nom_fichier);
    printf("Donnez le mot: ");
    gets(mot);
    printf("\nLE NOMBRE DE OCCURENCE DU MOT ENTRIE EST : %d", calcul_occurence(nom_fichier, mot));
    printf("\n\nAffichage du FICHIER \n");
    printf("********************\n");
    Affichage(nom_fichier);
    return 0;
}