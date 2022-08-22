#include <stdio.h>

struct Tenreg {
  char ligne[256]; // variable enregistrement
}e;

int main() {
  /* Affichage du fichier */
  FILE * f;
    char nom_fichier[200];
    int n, i;
    printf("\nAffichage du FICHIER\n");
    printf("--------------------\n");
    printf("Donnez le nom_fichier: ");
    gets(nom_fichier);
    f = fopen(nom_fichier, "r");
    i = 1;
    if (f != NULL) {
        fgets(e.ligne, 255, f); // lecture des enregistrements depuis le fichier
        printf("\n\nligne%3d:  %s", i++, e.ligne);
        while (!feof(f)) {
        fgets(e.ligne, 255, f);
        if (feof(f)) {
            break;
        };
        printf("ligne%3d:  %s", i++, e.ligne);
        }
        fclose(f);
    } else {
    printf("\n***********************\n");
    printf("LE FICHIER N'EXISTE PAS\n");
    printf("***********************\n");
    }
    return 0;
}