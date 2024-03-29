#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define ecs 27
typedef struct {
    char ville[20];
    int date;
    int temperature;
} Tenreg;

/* *****************- MODULE TEMPERATURE MINIMALE&MAXIMAL&MOYENNE -******************/
void Etat_de_Temperature(char nom_fichier[30]) {
    Tenreg e;
    int n;
    FILE * ptr_de_mon_fichier;
    char nom_ville_a_chercher[20];
    int somme_des_temperatures_de_une_ville = 0;
    int compteur = 0;
    int moyenne;
    int min, max;
    printf("DONNER LE NOM DE LA VILLE A CHERCHER: ");
    scanf("%s", nom_ville_a_chercher);
    ptr_de_mon_fichier = fopen(nom_fichier, "rb");
    if (fread( & e, sizeof(e), 1, ptr_de_mon_fichier)) {
        if (strcmp(e.ville, nom_ville_a_chercher) == 0) //affectation en début
        {
        max = e.temperature;
        min = e.temperature;
        compteur++;
        somme_des_temperatures_de_une_ville = somme_des_temperatures_de_une_ville + e.temperature;
        }
    }
    while (!feof(ptr_de_mon_fichier)) {
        if (fread( & e, sizeof(e), 1, ptr_de_mon_fichier)) {
        if (strcmp(e.ville, nom_ville_a_chercher) == 0) //on compare le nom de la ville
        {
            if (min <= e.temperature) {
            min = e.temperature;
            }
            if (max >= e.temperature) {
            max = e.temperature;
            }
            compteur++;
            somme_des_temperatures_de_une_ville = somme_des_temperatures_de_une_ville + e.temperature;
        }
        }
    }
    moyenne = somme_des_temperatures_de_une_ville / compteur;
    printf("\nla temperature minimale de la ville que vous donnee est : %d", min);
    printf("\nla temperature maximale de la ville que vous donnee est : %d", max);
    printf("\nla moyenne de la temperature de la ville que vous donnee est : %d", moyenne);
    fclose(ptr_de_mon_fichier);
}
/* *****************- MODULE AFFICHAGE DU FICHIER BINAIRE -******************/
void affichage(char nom_fichier[30]) {
    Tenreg e;
    int n;
    FILE * ptr_de_mon_fichier;
    ptr_de_mon_fichier = fopen(nom_fichier, "rb");
    if (ptr_de_mon_fichier == NULL) {
        printf("Erreur De L'ouverture du fichier \n");
    }
    n = fread( & e, sizeof(e), 1, ptr_de_mon_fichier);
    if (n == 1) {
        printf("ville: %s \t date: %d \t temperature: %d\n", e.ville, e.date, e.temperature);
    }
    while (!feof(ptr_de_mon_fichier)) {
        n = fread( & e, sizeof(e), 1, ptr_de_mon_fichier);
        if (n == 1)
        printf("ville: %s \t date: %d \t temperature: %d\n", e.ville, e.date, e.temperature);
    }
    fclose(ptr_de_mon_fichier);
}
/* *****************- MODULE CRIER DES VILLES -******************/
void crier_fichier(char nom_fichier[30]) {
    Tenreg e;
    FILE * ptr_vers_fichier;
    ptr_vers_fichier = fopen(nom_fichier, "ab");
    if (ptr_vers_fichier == NULL) {
        printf("Erreur De L'ouverture du fichier \n");
    }
    printf("Donnez NOM VILLE ----> ");
    scanf("%s", e.ville);
    printf("DATE        ----> ");
    scanf("%d", & e.date);
    printf("TEMPURATURE ----> ");
    scanf("%d", & e.temperature);
    while ((e.date != 0) && (e.ville[0] != '0')) {
        fwrite( & e, sizeof(e), 1, ptr_vers_fichier);
        printf("click on ESC if you want to exit or any key to stay Entred\n");
        if (_getch() == 27) {
        break;
        }
        printf("Donnez NOM VILLE ----> ");
        scanf("%s", e.ville);
        printf("DATE        ----> ");
        scanf("%d", & e.date);
        printf("TEMPURATURE ----> ");
        scanf("%d", & e.temperature);
    }
    fclose(ptr_vers_fichier);
}
/* *****************- MODULE RAJOUTER DES VILLES -******************/
void rajouter_au_fichier(char nom_fichier[30]) {
    Tenreg e;
    FILE * ptr_vers_fichier;
    ptr_vers_fichier = fopen(nom_fichier, "ab");
    if (ptr_vers_fichier == NULL) {
        printf("Erreur De L'ouverture du fichier \n");
    }
    printf("Donnez NOM VILLE ----> ");
    scanf("%s", e.ville);
    printf("DATE        ----> ");
    scanf("%d", & e.date);
    printf("TEMPURATURE ----> ");
    scanf("%d", & e.temperature);
    fwrite( & e, sizeof(e), 1, ptr_vers_fichier);
    fclose(ptr_vers_fichier);
}
/* *****************- MODULE POUR MODIFIER LA TEMPERATURE -******************/
void Modifier_la_Temperature(char nom_fichier[30]) {
    int nb_enrgs = 0;
    int nouvelle_temperature;
    FILE * ptr_vers_fichier;
    char nom_ville[20];
    int date_ville;
    Tenreg e;
    printf("\nNOM VILLE MODIFIER ? ");
    scanf("%s", nom_ville);
    printf("\nDATE ? ");
    scanf("%d", & date_ville);
    printf("\nLA TEMPERATURE QUE VOUS VOULLEZ ? ");
    scanf("%d", & nouvelle_temperature);

    ptr_vers_fichier = fopen(nom_fichier, "rb+");
    if (ptr_vers_fichier != NULL) {
        while (fread( & e, sizeof(e), 1, ptr_vers_fichier) /*!feof(ptr_vers_fichier)*/ ) {
        nb_enrgs++; {
            if ((strcmp(e.ville, nom_ville) == 0) && (e.date == date_ville)) {
            fseek(ptr_vers_fichier, (nb_enrgs - 1) * sizeof(e), SEEK_SET);
            e.temperature = nouvelle_temperature;
            fwrite( & e, sizeof(e), 1, ptr_vers_fichier);
            fclose(ptr_vers_fichier);
            }
        }
        }
    }
}
/* *****************- MODULE POUR SUPPRIMER -******************/
void Supprimer(char nom_fichier[30], char nom_fichier_new[30]) {
    FILE * ptr_vers_fichier_new;
    FILE * ptr_vers_fichier;
    char nom_ville[20];
    Tenreg e;
    printf("\nNOM VILLE A SUPPRIMER ");
    scanf("%s", nom_ville);
    ptr_vers_fichier = fopen(nom_fichier, "rb");
    ptr_vers_fichier_new = fopen(nom_fichier_new, "wb");
    if (ptr_vers_fichier != NULL) {
        while (fread( & e, sizeof(e), 1, ptr_vers_fichier)) {
        if (strcmp(e.ville, nom_ville) != 0) {
            fwrite( & e, sizeof(e), 1, ptr_vers_fichier_new);
        }
        }
    } else {
        printf("le fichier ne existe pas ");
    }
    fclose(ptr_vers_fichier);
    fclose(ptr_vers_fichier_new);
}
/* *****************- PROGRAMME PRINCIPALE -******************/
int main() {
    char nom_fichier[30];
    char nom_fichier_new[30];
    printf("\nCREATION DU FICHIER : ");
    printf("\n******************** \n");
    printf("DONNER LE NOM_FICHIER : ");
    gets(nom_fichier);
    crier_fichier(nom_fichier);
    printf("\nETAT DE TEMPERATURE : ");
    printf("\n******************** \n");
    Etat_de_Temperature(nom_fichier);
    printf("\nAFFICHAGE DU FICHIER : ");
    printf("\n******************** \n");
    affichage(nom_fichier);
    printf("\nAJOUTE UNE VILLES : ");
    printf("\n******************* \n");
    rajouter_au_fichier(nom_fichier);
    printf("\nAFFICHAGE DU FICHIER : ");
    printf("\n******************** \n");
    affichage(nom_fichier);
    printf("\nMODIFIAGE AU FICHIER : ");
    printf("\n******************** \n");
    Modifier_la_Temperature(nom_fichier);
    printf("\nAFFICHAGE DU FICHIER : ");
    printf("\n******************** \n");
    affichage(nom_fichier);
    printf("\nSUPPRITION AU FICHIER : ");
    printf("\n******************** \n");
    printf("DONNER LE NOM_FICHIER_nouveau (de supprition): ");
    scanf("%s", nom_fichier_new);
    Supprimer(nom_fichier, nom_fichier_new);
    printf("\nAFFICHAGE DU FICHIER : ");
    printf("\n******************** \n");
    affichage(nom_fichier_new);
    return 0;
}