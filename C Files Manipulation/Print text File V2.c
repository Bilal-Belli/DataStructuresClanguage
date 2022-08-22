#include <stdio.h>
#include <string.h>

void affichage(FILE * ptr_de_mon_fichier) {
    char caracteres;
    while ((caracteres = fgetc(ptr_de_mon_fichier)) != EOF) {
    printf("%c", caracteres);
    }
}
int main() {
    FILE * f;
    char nom_fichier[25];
    printf("Donnez le nom du Fichier : ");
    gets(nom_fichier);
    f = fopen(nom_fichier, "r");
    if (f != NULL) {
    affichage(f);
    fclose(f);
    } else {
    printf("LE FICHIER N'EXISTE PAS DANS VOTRE REPERTOIRE DU PROGRAME ACTUEL\n");
    }
    return 0;
}