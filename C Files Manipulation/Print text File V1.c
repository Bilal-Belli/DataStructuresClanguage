#include <stdio.h>
#include <string.h>

int main() {
    char k;
    FILE * f;
    char nom_fichier[200];
    printf("Donnez le nom du Fichier : ");
    gets(nom_fichier);
    f = fopen(nom_fichier, "r");
    if (f == NULL) {
    printf("LE FICHIER N'EXISTE PAS DANS VOTRE REPERTOIRE DU PROGRAME ACTUEL");
    } else {
    while (!feof(f)) {
        k = fgetc(f);
        printf("%c", k);
        while (!feof(f) && k != '\n') {
        k = fgetc(f);
        printf("%c", k);
        }
    }
    fclose(f);
    }
    return 0;
}