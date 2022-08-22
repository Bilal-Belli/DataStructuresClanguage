#include <stdio.h>
#include <string.h>
/** Calcul de nombre de lignes & le nombre de caracteres **/
int nb_caracteres_fichier(char nom_fichier[30])
{
    FILE *ptr_de_mon_fichier;
    char k;
    int nb_caracteres=0;
    ptr_de_mon_fichier = fopen( nom_fichier, "r" );
    if ( ptr_de_mon_fichier == NULL)
    {
        nb_caracteres=0;//----  Le Fichier N'existe Pas  ----
    }
    else
    {
        while ( ! feof(ptr_de_mon_fichier) )
        {
            k=fgetc(ptr_de_mon_fichier);//on lire tout les caracteres du fichier jusqua la fin (feof)
            if (!feof(ptr_de_mon_fichier) && k!='\n')
            {
                nb_caracteres++;
            }
        }
        //fflush(ptr_de_mon_fichier);
        fclose( ptr_de_mon_fichier );
    }
    return nb_caracteres;
}
int nb_lignes_fichier(char nom_fichier[30])
{
    FILE *ptr_de_mon_fichier;
    char k;
    int nb_lignes=0;
    ptr_de_mon_fichier = fopen( nom_fichier, "r" );
    if ( ptr_de_mon_fichier == NULL)
    {
        nb_lignes=0;  //----  Le Fichier N'existe Pas  ----
    }
    else
    {
        while ( ! feof(ptr_de_mon_fichier) )
        {
            k=fgetc(ptr_de_mon_fichier);
            if (!feof(ptr_de_mon_fichier) && k!='\n')
            {
                nb_lignes++;
            }
            while (!feof(ptr_de_mon_fichier) && k!='\n')
            {
                //lire les caracteres jusqua la fin de la ligne (seul une et une seul ligne) ou trouve \n
                k=fgetc(ptr_de_mon_fichier);
            }
        }
        fclose( ptr_de_mon_fichier );
    }
    return nb_lignes;
}
int main()
{
    char nom_fichier[30];
    printf("\nCalcul de nombre de Lignes & Caracteres dans mon fichier:\n");
    printf("*********************************************************\n");
    printf("Donnez le nom_fichier: ");
    gets(nom_fichier);
    printf("\nNb_caracteres = %5d ",nb_caracteres_fichier(nom_fichier));
    printf("\nNb_lignes = %5d ",nb_lignes_fichier(nom_fichier));
    return 0;
}
