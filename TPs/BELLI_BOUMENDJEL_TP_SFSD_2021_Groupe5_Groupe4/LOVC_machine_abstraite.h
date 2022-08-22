#ifndef LOVC_machineabstraite_H_INCLUDED
#define LOVC_machineabstraite_H_INCLUDED
#define MAX_CAR 1024   // NOMBRE MAXIMUM DE CARACTËRE DANS UN BLOC  = B
#include <stdio.h>
#include <stdlib.h>
typedef struct TblocLOVC
{
    char tab[MAX_CAR];
    int suivant;
    int nb;     // NOMBRE DE CARATËRES INSÈRÈS DANS LE BLOC POUR DES RAISON D'AFFICHAGE
} TblocLOVC;

typedef TblocLOVC Buffer_LOVC;

typedef struct EnteteLOVC
{
    int tete;       //NUMERO DU PREMIER BLOC
    int inseres;    //NOMBRES GLOBAL DE CARATERES INSERES
    int nbBloc;     //NOMBRE DE BLOCS
} EnteteLOVC;

typedef struct LOVC
{
    FILE* fichier;
    EnteteLOVC entete;
} LOVC;

void ouvrir_LOVC        (LOVC **f, char nom[], char mode        );
void fermer_LOVC        (LOVC *f                                );
int enteteLOVC          (LOVC *f, int i                         );
void aff_entete_LOVC    (LOVC *f, int i, int valeur             );
void lireDir_LOVC       (LOVC *f, int i, Buffer_LOVC *buf       );
void ecrireDir_LOVC     (LOVC *f, int i, Buffer_LOVC *buf       );
int  allocBloc_LOVC     (LOVC *f                                );

/* ******************/

void ouvrir_LOVC(LOVC **f, char nom[], char mode)
{
    *f = malloc(sizeof(LOVC));

    if(mode == 'a' || mode == 'A')
    {
        (*f)->fichier = fopen(nom, "rb+");

        if((*f)->fichier != NULL)
        {
            fread(&((*f)->entete), sizeof(EnteteLOVC), 1, (*f)->fichier);
        }
    }
    else if(mode == 'n' || mode == 'N')
    {
        (*f)->fichier = fopen(nom, "wb+");

        if((*f)->fichier != NULL)
        {
            (*f)->entete.tete = 1;
            (*f)->entete.inseres = 0;
            (*f)->entete.nbBloc = 1;
        }
    }
}
void fermer_LOVC(LOVC *f)
{
    rewind(f->fichier);
    fwrite(&(f->entete), sizeof(EnteteLOVC), 1, f->fichier);
    fclose(f->fichier);
    free(f);
}
int enteteLOVC(LOVC *f, int i)
{
    if(i == 1)
        return f->entete.tete;
    else if(i == 2)
        return f->entete.inseres;
    else if(i == 3)
        return f->entete.nbBloc;
    else
        return -1;
}
void aff_entete_LOVC(LOVC *f, int i, int valeur)
{
    if(i == 1)
        f->entete.tete = valeur;
    else if(i == 2)
        f->entete.inseres = valeur;
    else if(i == 3)
        f->entete.nbBloc = valeur;
}
void lireDir_LOVC(LOVC *f, int i, Buffer_LOVC *buf)
{
    fseek(f->fichier, sizeof(EnteteLOVC) + sizeof(TblocLOVC)*(i-1), SEEK_SET);
    fread(buf, sizeof(TblocLOVC), 1, f->fichier);
}
void ecrireDir_LOVC(LOVC *f, int i, Buffer_LOVC *buf)
{
    fseek(f->fichier, sizeof(EnteteLOVC) + sizeof(TblocLOVC)*(i-1), SEEK_SET);
    fwrite(buf, sizeof(TblocLOVC), 1, f->fichier);
}
int allocBloc_LOVC(LOVC *f)
{
    aff_entete_LOVC(f, 3, enteteLOVC(f, 3) + 1);
    return enteteLOVC(f, 3);
}
#endif
