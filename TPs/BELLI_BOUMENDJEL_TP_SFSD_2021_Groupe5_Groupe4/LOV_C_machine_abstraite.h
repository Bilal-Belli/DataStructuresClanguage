#ifndef LOV_C_MACHINE_ABSTRAITE_H_INCLUDED
#define LOV_C_MACHINE_ABSTRAITE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define MAX_CAR 1024   // NOMBRE MAXIMUM DE CARACTèRE DANS UN BLOC  = B

/* LE TYPE BLOC D'UN FICHIER LOV-C */
typedef struct TblocLOV_C
{
    char tab[MAX_CAR];
    int suivant;
    int nb;     // NOMBRE DE CARATèRES INSéRéS DANS LE BLOC
} TblocLOV_C;

typedef struct Ouvrage
{
    char    Identifiant[4];
    char    Taille[3];
    char    Efface[1];
    char    Disponible[1];  // GENERER ALEATOIREMENT SOIT 1 SOIT 0
    char    Type[1];        // GENERER ALEATOIREMENT DEPUIS UN ENSEMBLE TQ: '1'-LIVRE '2'-MEMOIRE/PFE '3'-ARTICL '4'-PéRIODIQUE
    char    Anne[4];        // GENERER ALEATOIREMENT ENTRE 1950 ET 2021
    /*LES CHAMPS VARIABLES */
    char    Titre[25];      // ALEATOIREMENT (10~25)
    char    Auteur[25];     // ALEATOIREMENT (10~25)
    char    Cote[25];       //ALEATOIREMENT (10~25)
    char    Resume[930];    // {(MAX_CAR -4-3-1-1-4-1-25-25-25 -5'SUPPLIMENTAIRES) POUR RESUMER= 930 }
} Ouvrage;

/* STRUCTURE D'UN OUVRAGE: (DANS CET ORDRE)
- IDENTIFIANT: 4 CARACTèRES (ENTRE 0001 ET 9999)
- TAILLE: 3 CARACTèRES
- EFFACé: 1 CARACTèRE ('0' OU '1')
- DISPONIBLE: 1 CARACTèRE ('0' OU '1')
- TYPE: 1 CARACTèRE
	'1' => TEXTE IMRPIMé
	'2' => DOCUMENT éLECTRONIQUE
	'3' => ARTICLE
	'4' => PéRIODIQUE
- ANNéE DE PUBLICATION: 4 CARACTèRES (ENTRE 1950 ET 2021).
- TITRE.
- AUTEURS.
- LA COTE
- RéSUMé
(LES CHAMPS QUI N'ONT PAS DE TAILLE FIXE SONT SéPARéS PAR LE CARACTèRE '$')
*/

//LE TYPE ENTETE D'UN FICHIER LOV-C
typedef struct Entete
{
    int tete;       //NUMERO DU PREMIER BLOC
    int inseres;    //NOMBRES GLOBAL DE CARATèRES INSéRéS
    int supprimes;  //NOMBRES GLOBAL DE CARATèRE SUPPRIMéS
    int nbBloc;     //NOMBRE DE BLOCS
} Entete;

//LE TYPE DU FICHIER LOV-C
typedef struct LOV_C
{
    FILE* fichier;
    Entete entete;
} LOV_C;

//LE TYPE BUFFER
typedef TblocLOV_C Buffer;

//LES MACHINES ABSTRAITES
void ouvrir     (LOV_C **f, char nom[], char mode );
void fermer     (LOV_C *f                         );
int entete      (LOV_C *f, int i                  );
void aff_entete (LOV_C *f, int i, int valeur      );
void lireDir    (LOV_C *f, int i, Buffer *buf     );
void ecrireDir  (LOV_C *f, int i, Buffer *buf     );
int  allocBloc  (LOV_C *f                         );


void ouvrir(LOV_C **f, char nom[], char mode)
{
    *f = malloc(sizeof(LOV_C));

    if(mode == 'a' || mode == 'A')
    {
        (*f)->fichier = fopen(nom, "rb+");

        if((*f)->fichier != NULL)
        {
            fread(&((*f)->entete), sizeof(Entete), 1, (*f)->fichier);
        }
    }
    else if(mode == 'n' || mode == 'N')
    {
        (*f)->fichier = fopen(nom, "wb+");

        if((*f)->fichier != NULL)
        {
            (*f)->entete.tete = 1;
            (*f)->entete.inseres = 0;
            (*f)->entete.supprimes = 0;
            (*f)->entete.nbBloc = 1;
        }
    }
}


void fermer(LOV_C *f)
{
    rewind(f->fichier);
    fwrite(&(f->entete), sizeof(Entete), 1, f->fichier);
    fclose(f->fichier);
    free(f);
}


int entete(LOV_C *f, int i)
{
    if(i == 1)
        return f->entete.tete;
    else if(i == 2)
        return f->entete.inseres;
    else if(i == 3)
        return f->entete.supprimes;
    else if(i == 4)
        return f->entete.nbBloc;
    else
        return -1;
}


void aff_entete(LOV_C *f, int i, int valeur)
{
    if(i == 1)
        f->entete.tete = valeur;
    else if(i == 2)
        f->entete.inseres = valeur;
    else if(i == 3)
        f->entete.supprimes = valeur;
    else if(i == 4)
        f->entete.nbBloc = valeur;
}


void lireDir(LOV_C *f, int i, Buffer *buf)
{
    fseek(f->fichier, sizeof(Entete) + sizeof(TblocLOV_C)*(i-1), SEEK_SET);
    fread(buf, sizeof(TblocLOV_C), 1, f->fichier);
}


void ecrireDir(LOV_C *f, int i, Buffer *buf)
{
    fseek(f->fichier, sizeof(Entete) + sizeof(TblocLOV_C)*(i-1), SEEK_SET);
    fwrite(buf, sizeof(TblocLOV_C), 1, f->fichier);
}


int allocBloc(LOV_C *f)
{
    aff_entete(f, 4, entete(f, 4) + 1);
    return entete(f, 4);
}


#endif // LOV_C_MACHINE_ABSTRAITE_H_INCLUDED
