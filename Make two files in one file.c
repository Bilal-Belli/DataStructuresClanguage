#include <stdio.h>
int main()
{   /* Criation du fichier */

    struct Tenreg
    {
        char ligne[256];  // variable enregistrement
    } e;
    FILE *f1;
    FILE *f2;
    FILE *f3;
    int k=1;
    char nom_fichier_1[200];
    char nom_fichier_2[200];
    char nom_fichier_3[200];
    printf("\nConcatination du fichiers (Fichier_1 ensuite Fichier_2)\n");
    printf("------------------------------------------------------\n");
    printf("Le resultat de concatination sera stocker en Fichier_1\n");
    printf("------------------------------------------------------\n");

    printf("Donnez nom_fichier_1 : ");
    gets(nom_fichier_1);
    printf("\n");

    printf("Donnez nom_fichier_2 : ");
    gets(nom_fichier_2);
    printf("\n");

    printf("Donnez un nom_fichier_de_concatination : ");
    gets(nom_fichier_3);
    printf("\n");

    f1 = fopen( nom_fichier_1, "r" );
    f2 = fopen( nom_fichier_2, "r" );
    f3 = fopen( nom_fichier_3, "w" );
    while ( ! feof(f1) )
    {
        fgets(e.ligne ,255,f1);
        fprintf(f3, "%s", e.ligne );  //remplir par le fichier 1
    }
    fflush(f1);
    fclose( f1 );

    fgets(e.ligne ,255,f2);
    fprintf(f3, "\n%s", e.ligne );
    while ( ! feof(f2) )
    {
        fgets(e.ligne ,255,f2);
        fprintf(f3, "%s", e.ligne );  //remplir par le fichier 2
    }
    fflush(f2);
    fclose( f2 );
    fflush(f3);
    fclose( f3 );
/* ******************************************************************** */
    /* Affichage du fichier */
    char rep[1];
    printf("\nVous Voulez afficher le resultat de concatenation ? (y/n)\n");
    scanf("%c",rep);
    if (rep[0]== 'y'){
       int n, i;
    printf("\nAffichage du FICHIER\n");
    printf("--------------------\n");
    //printf("Donnez le nom_fichier: ");
    //gets(nom_fichier_1);
    f3 = fopen( nom_fichier_3, "r" );
    i = 1;
    if ( f3 != NULL){
        fgets(e.ligne ,255,f3); // lecture des enregistrements depuis le fichier
    printf("\n\nligne%3d:  %s", i++, e.ligne);
            while ( ! feof(f3) )
            {
                fgets(e.ligne,255,f3);
                //if (feof(f1)){break;};
                printf("ligne%3d:  %s", i++, e.ligne);
            }
            fclose( f1 );
        }
        else
        {
            printf("\n***********************\n");
            printf("LE FICHIER N'EXISTE PAS\n");
            printf("***********************\n");
        }
    }
    else
    {
        if (rep[0]== 'n')
        {
            printf("*********** FIN *********\n");
        }
        else
        {
            printf("\nVuillez entrer 'y' ou 'n' la prochaine foix!! \n");
            printf("*********** FIN *********\n");
        }
    }
    return 0;}
