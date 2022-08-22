#include <stdio.h>
#include <string.h>
typedef struct
    {
        char ligne[256];  // variable enregistrement
    } Tenreg;
/******************- MODULE DE VEREFICATION SI LES LIGNES SONT IDENTIQUES -******************/
void Compare(char nom_fichier_1[30], char nom_fichier_2[30])
{
    FILE *ptr_de_mon_fichier_1;
    FILE *ptr_de_mon_fichier_2;
    ptr_de_mon_fichier_1 = fopen( nom_fichier_1, "r" );
    ptr_de_mon_fichier_2 = fopen( nom_fichier_2, "r" );

    Tenreg ea;
    Tenreg eb;
    char k;
    if ( ptr_de_mon_fichier_1 != NULL ^ ptr_de_mon_fichier_2 != NULL)
    {
        printf("les deux fichiers sont identiques");
    }
    else
    {
        while ( ! feof(ptr_de_mon_fichier_1) && !feof(ptr_de_mon_fichier_2))
        {
            //k=fgetc(ptr_de_mon_fichier);
            fgets(ea.ligne,255,ptr_de_mon_fichier_1);
            fgets(eb.ligne,255,ptr_de_mon_fichier_2);
            if (strcmp(ea.ligne,eb.ligne)!=0)
            {
                printf("les deux fichiers NE sont PAS identiques");
                break;
            }
            while ( ! feof(ptr_de_mon_fichier_1) && !feof(ptr_de_mon_fichier_2))
            {
            fgets(ea.ligne,255,ptr_de_mon_fichier_1);
            fgets(eb.ligne,255,ptr_de_mon_fichier_2);
            if (strcmp(ea.ligne,eb.ligne)!=0)
            {
                printf("les deux fichiers NE sont PAS identiques");
                break;
            }
            }
        }
        fclose( ptr_de_mon_fichier_1 );
        fclose( ptr_de_mon_fichier_2 );
    }
    return 0;
}
/******************- MODULE D'AFFICHAGE DE UN FICHIER TEXTE VERSION 1 -******************/
void Affichage(char nom_fichier[30])
{
    FILE *ptr_de_mon_fichier;
    char caracteres;
    ptr_de_mon_fichier = fopen( nom_fichier, "r" );
    while((caracteres=fgetc(ptr_de_mon_fichier))!=EOF)
    {
        printf("%c",caracteres);
    }
    fclose( ptr_de_mon_fichier );
}
/******************- PROGRAMME PRINCIPALE -******************/
int main()
{
    char nom_fichier_1[30];
    char nom_fichier_2[30];
    printf("\nCalcul de nombre de Lignes & Caracteres dans mon fichier:\n");
    printf("*********************************************************\n");
    printf("Donnez le nom_fichier_1: ");
    gets(nom_fichier_1);
    printf("\nDonnez le nom_fichier_2: ");
    gets(nom_fichier_2);
    printf("\nRESULTAT DE COMPARAISON\n");
    printf("************************\n");
    Compare(nom_fichier_1,nom_fichier_2);
    printf("\nAffichage du FICHIER (1)\n");
    printf("********************\n");
    Affichage(nom_fichier_1);
    printf("\nAffichage du FICHIER (2)\n");
    printf("********************\n");
    Affichage(nom_fichier_2);
    return 0;
}
