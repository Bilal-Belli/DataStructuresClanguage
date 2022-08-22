#include <stdio.h>
#include <string.h>
/*
CE que fait la deffirence etre les deux types de concatination c'est que il ya 3 types:

1-concatination direct quelque soit i.e: n'a pas de saut a la ligne (on ne sauter pas)
2-concatination avec le saut de la ligne entre les deux fichiers
3-concatination cologne (par des enregistrements)

-et j'ai faire la deffirence par print("\n",...);
*/
/*  **********************************************************************  */
/* *****************- MODULE DE CONCATINATION en_saut_de_la_ligne -******************/
/*  **********************************************************************  */
void concatination_en_saut_de_la_ligne(char nom_fichier1[30],char nom_fichier2[30])
{
    FILE *ptr_de_mon_fichier1;
    FILE *ptr_de_mon_fichier2;
    char caracteres[255];
    ptr_de_mon_fichier1 = fopen( nom_fichier1, "a" );
    ptr_de_mon_fichier2 = fopen( nom_fichier2, "r" );
    if ( ptr_de_mon_fichier1 == NULL)
    {
        printf("----  Le Fichier 1 N'existe Pas  ----");
    }
    if ( ptr_de_mon_fichier2 == NULL)
    {
        printf("----  Le Fichier 2 N'existe Pas  ----");
    }
    else
    {   fputs("\n",ptr_de_mon_fichier1);
        while (! feof(ptr_de_mon_fichier2))
        {
            fputs(fgets(caracteres , sizeof(caracteres) ,ptr_de_mon_fichier2),ptr_de_mon_fichier1);
        }
        fclose(ptr_de_mon_fichier1);
        fclose(ptr_de_mon_fichier2);
    }
    return 0;
}
/*  **********************************************************************  */
/* *****************- MODULE DE CONCATINATION _direct -******************/
/*  **********************************************************************  */
void concatination_direct(char nom_fichier1[30],char nom_fichier2[30])
{
    FILE *ptr_de_mon_fichier1;
    FILE *ptr_de_mon_fichier2;
    char caracteres[255];
    ptr_de_mon_fichier1 = fopen( nom_fichier1, "a" );
    ptr_de_mon_fichier2 = fopen( nom_fichier2, "r" );
    if ( ptr_de_mon_fichier1 == NULL)
    {
        printf("----  Le Fichier 1 N'existe Pas  ----");
    }
    if ( ptr_de_mon_fichier2 == NULL)
    {
        printf("----  Le Fichier 2 N'existe Pas  ----");
    }
    else
    {   //fputs("\n",ptr_de_mon_fichier1);
        while (! feof(ptr_de_mon_fichier2))
        {
            fputs(fgets(caracteres , sizeof(caracteres) ,ptr_de_mon_fichier2),ptr_de_mon_fichier1);
        }
        fclose(ptr_de_mon_fichier1);
        fclose(ptr_de_mon_fichier2);
    }
    return 0;
}
/*  **********************************************************************  */
/* *****************- MODULE D'AFFICHAGE DE UN FICHIER TEXTE -******************/
/*  **********************************************************************  */
void Affichage(char nom_fichier[30])
{
    FILE *ptr_de_mon_fichier;
    char caracteres;
    ptr_de_mon_fichier = fopen( nom_fichier, "r" );
    if ( ptr_de_mon_fichier == NULL)
    {
        printf("----  Le Fichier N'existe Pas  ----");
    }
    else
    {
        while ( ! feof(ptr_de_mon_fichier) )
        {
            caracteres=fgetc(ptr_de_mon_fichier);
            printf("%c",caracteres);
            while (! feof(ptr_de_mon_fichier) && caracteres!='\n')
            {
                caracteres=fgetc(ptr_de_mon_fichier);
                printf("%c",caracteres);
            }
        }
        fclose(ptr_de_mon_fichier);
    }
    return 0;
}
/*  **********************************************************************  */
/* *****************- PROGRAMME PRINCIPALE -******************/
/*  **********************************************************************  */
int main()
{
    char nom_fichier1[30];
    char nom_fichier2[30];
    printf("Donnez le nom_fichier1: ");
    gets(nom_fichier1);
    printf("Donnez le nom_fichier2: ");
    gets(nom_fichier2);
    printf("\n\nConcatination du deux FICHIERs \n");
    concatination_en_saut_de_la_ligne(nom_fichier1,nom_fichier2);
    printf("\n\nAffichage du FICHIER de CONCATINATION en saut \n");
    printf("****************************************\n");
    Affichage(nom_fichier1);
    return 0;
}
