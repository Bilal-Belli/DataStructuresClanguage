#ifndef MODELE_H_INCLUDED
#define MODELE_H_INCLUDED
#define MAX_CAR 1024
#include <stdio.h>
#include <stdlib.h>

typedef struct TblocTOVC /* LE TYPE BLOC D'UN FICHIER TOVC */
{
    char tab[MAX_CAR];
}   TblocTOVC ;

typedef TblocTOVC Buffer_TOVC;

typedef struct TOVC_Entete
{
    int adress_dernier_bloc ;
}   TOVC_Entete ;

typedef struct TOVC
{
    FILE* fichier_TOVC ;
    TOVC_Entete Entete_TOVC ;
}   TOVC ;

//   LE MODèLE
void    Ouvrir_TOVC     (TOVC **f,char nom_fichier[],char mode   );
void    Fermer_TOVC     (TOVC *f                                 );
int     Entete_TOVC     (TOVC *f, int i                          );
void    Aff_Entete_TOVC (TOVC *f, int i, int val                 );
void    Ecriredir_TOVC  (TOVC *f, int i, Buffer_TOVC  *buf       );
void    Liredir_TOVC    (TOVC *f,int i, Buffer_TOVC *buf         );
int     Alloc_bloc_TOVC (TOVC *f                                 );
//




/* ******************/
void Ouvrir_TOVC(TOVC **f, char nom[], char mode)
{
    *f = malloc(sizeof(TOVC));

    if(mode == 'a' || mode == 'A')
    {
        (*f)->fichier_TOVC = fopen(nom, "rb+");

        if((*f)->fichier_TOVC != NULL)
        {
            fread(&((*f)->Entete_TOVC), sizeof(TOVC_Entete), 1, (*f)->fichier_TOVC);
        }
    }
    else if(mode == 'n' || mode == 'N')
    {
        (*f)->fichier_TOVC = fopen(nom, "wb+");

        if((*f)->fichier_TOVC != NULL)
        {
            (*f)->Entete_TOVC.adress_dernier_bloc = 0;
        }
    }
}


void Fermer_TOVC(TOVC *f)
{
    rewind(f->fichier_TOVC);
    fwrite(&(f->Entete_TOVC),sizeof(TOVC_Entete),1,f->fichier_TOVC);
    fclose(f->fichier_TOVC);
    free(f);
}


int Entete_TOVC(TOVC * f, int i)
{
    if (i ==1)
        return(f->Entete_TOVC.adress_dernier_bloc);
    else
        return -1;
}


void Aff_Entete_TOVC(TOVC * f, int i, int valeur)
{
    if (i == 1)
        f->Entete_TOVC.adress_dernier_bloc = valeur;
}


void Liredir_TOVC(TOVC *f, int i, Buffer_TOVC *buf2)
{
    fseek(f->fichier_TOVC,sizeof(TOVC_Entete)+(sizeof(TblocTOVC)*(i-1)),SEEK_SET);
    fread(buf2,sizeof(TblocTOVC),1,f->fichier_TOVC);
}


void Ecriredir_TOVC(TOVC *f, int i, Buffer_TOVC *buf2)
{
    fseek(f->fichier_TOVC,sizeof(TOVC_Entete)+(sizeof(TblocTOVC)*(i-1)),SEEK_SET);
    fwrite(buf2,sizeof(TblocTOVC),1,f->fichier_TOVC);
}


int Alloc_bloc_TOVC(TOVC *f)
{
    Aff_Entete_TOVC( f, 1, Entete_TOVC( f, 1 ) + 1 );
    return Entete_TOVC(f, 1);
}

#endif