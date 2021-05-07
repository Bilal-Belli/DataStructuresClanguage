/*-----------------------  INFORMATION                    -----------*/
    //  BINOME    BELLI_BILAL   ATEK ABDELJALIL   _TP1_G5
    //  ENS : .BOULEKRADECH
/*-----------------------  LES BIBLIOTHEQUES UTILISEE     -----------*/
#include "LA_BIBLIOTHEQUE_DE_DESIGNE.h"
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
/*-----------------------LES STRUCTURES STATIQUES         -----------*/
typedef char tab[100][100];
/*-----------------------LES STRUCTURES SPECIAL DES LISTES-----------*/
typedef struct Maillon
{
    char  val[20];
    struct Maillon *next;
    struct Maillon *next1;     // POUR LES PARENTS
    struct Maillon *next2;     // POUR LES ENFANTS
    struct Maillon *next3;     // POUR LES VOITURES
} Maillon;
void allouer(Maillon **nouveau)
{
    *nouveau=(Maillon*)malloc(sizeof(Maillon));
}
typedef struct ENFENT
{
    char  prenom[20];
    char  sexe[20];
    struct ENFENT *next2;     // POUR LES ENFANTS
} ENFENT;
typedef struct VOITURE
{
    char  marque[20];
    char  numuro[12];
    struct VOITURE *next3;     // POUR LES VOITURES
} VOITURE;
void allouer2(ENFENT **nouveau)
{
    *nouveau=(ENFENT*)malloc(sizeof(ENFENT));
}
void allouer3(VOITURE **nouveau)
{
    *nouveau=(VOITURE*)malloc(sizeof(VOITURE));
}
int prenom(ENFENT *p)
{
    return p->prenom;
}
int sexe(ENFENT *p)
{
    return p->sexe;
}
int marque(VOITURE *p)
{
    return p->marque;
}
int numuro(VOITURE *p)
{
    return p->numuro;
}
void aff_adr(Maillon *p,Maillon *q)  //LA LISTE DES NOMFAMILLES
{
    p->next=q;                                     //POUR LES NOMFAMILLES
}
void aff_adr1(Maillon *p,Maillon *q)//LA LISTE DES PARENTS
{
    p->next1=q;                                 // POUR LES PARENTS
}
void aff_adr2(Maillon *p,Maillon *q)//LA LISTE DES ENFANTS
{
    p->next2=q;                                // POUR LES ENFANTS
}
void aff_adr3(Maillon *p,Maillon *q)//LA LISTE DES VOITURES
{
    p->next3=q;                                //  POUR LES VOITURES
}
void aff_val(struct Maillon *p, char  valeur[30])
{
    int i;
    for (i=0; i<20; i++)
    {
        p->val[i] =valeur[i];
    }
}
void aff_numuro(struct VOITURE *p, char  valeur[15])
{
    int i;
    for (i=0; i<13; i++)
    {
        p->numuro[i] =valeur[i];
    }
}
void aff_marque(struct VOITURE *p, char  valeur[30])
{
    int i;
    for (i=0; i<20; i++)
    {
        p->marque[i] =valeur[i];
    }
}
void aff_sexe(struct ENFENT *p, char  valeur[30])
{
    int i;
    for (i=0; i<20; i++)
    {
        p->sexe[i] =valeur[i];
    }
}
void aff_prenom(struct ENFENT *p, char  valeur[30])
{
    int i;
    for (i=0; i<20; i++)
    {
        p->prenom[i] =valeur[i];
    }
}
Maillon *suivant(Maillon *p)
{
    return p->next;//POUR LES NOMFAMILLES
}
Maillon *suivant1(Maillon *p)
{
    return p->next1; // POUR LES PARENTS
}
Maillon *suivant2(Maillon *p)
{
    return p->next2;  // POUR LES ENFANTS
}
Maillon *suivant3(Maillon *p)
{
    return p->next3;  //  POUR LES VOITURES
}
int valeur(Maillon *p)
{
    return p->val;
}
void liberer(Maillon**ancien)
{
    free(*ancien);
    *ancien=NULL;
}
/*-----------------------LA FONCTION ALIATOIRE -----------------------*/
int rand1(int n)
{
    int limit;
    int r;
    limit= RAND_MAX -( RAND_MAX % n);
    while ((r = rand ())>= limit );
    return r % n ;
}
/*-----------------------LE PROCEDURE QUI CRIEER UNE LISTE PARENTS -------------*/
Maillon *cree_prt(int n)
{
    Maillon *tete;
    Maillon *p;
    Maillon *q;
    int i;
    int r;
    int cnst;
    char mot[20];
    char alpha1[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char alpha2[]="abcdefghijklmnopqrstuvwxyz";
    //srand(time(0));
    allouer(&p);
    //aff_val(p,mot);
    tete=p;
    for (i=1; i<n; i++)
    {
        mot[0]=alpha1[rand1(26)];
        cnst=(rand1(12)+1)+3;
        for (r=1; r<cnst; r++)
        {
            mot[r]=alpha2[rand1(26)];
        }
        mot[cnst]='\0';
        allouer(&q);
        aff_val(q,mot);
        aff_adr1(p,q);
        p=q;
    }
    aff_adr1(p,NULL);
    return tete;
}
/*-----------------------LE PROCEDURE QUI CRIER UNE LISTE ENFANTS-------------*/
Maillon *cree_enf(int n)
{
    Maillon *tete;
    Maillon *p;
    Maillon *q;
    int i;
    int r;
    int cnst;
    char mot[20];
    char mot2[20];
    char alpha1[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char alpha2[]="abcdefghijklmnopqrstuvwxyz";
    char alpha3[]="FM";
    allouer2(&p);
    tete=p;
    for (i=1; i<n; i++)
    {
        mot[0]=alpha1[rand1(26)];
        cnst=(rand1(12)+1)+3;
        for (r=1; r<cnst; r++)
        {
            mot[r]=alpha2[rand1(26)];
        }
        mot[cnst]='\0';
        mot2[0]=alpha3[rand1(2)];
        mot2[1]='\0';
        allouer(&q);
        aff_prenom(q,mot);
        aff_sexe(q,mot2);
        aff_adr2(p,q);
        p=q;
    }
    aff_adr2(p,NULL);
    return tete;
}
/*-----------------------LE PROCEDURE QUI CRIER UNE LISTE VOITURE-------------*/
VOITURE *cree_voi(int n)
{
    tab a= {"Volkswagen","Volvo","Volvo Trucks","Tata","Tesla","Toyota","Alfa Romeo"
            ,"Alpine","Alvis","Audi","Bugatti","Cadillac","Chevrolet","Citroen","Dacia","Daihatsu"
            ,"Ferrari","Fiat","Ford","Honda","Hyundai","Isuzu","Iveco","Jaguar","Kia","Lamborghini"
            ,"Land Rover","Lotus","Mahindra","Maruti","Mazda","Mega","Mercedes","Mitsubishi","Nissan"
            ,"Pagani","Peugeot","Porsche","Renault","Renault Trucks","Shelby","Skoda","Sozoki"
           };
    VOITURE *tete;
    VOITURE *p;
    VOITURE *q;
    int i;
    int x;
    int r;
    int cnst;
    char mot[20];
    char mot1[12];
    char alpha1[]="012345678";   // COMME LES MATRICULES DANS NOTRE PAY
    char alpha12[]="01234";     // COMME LES MATRICULES DANS NOTRE PAY
    char alpha2[]="1235468790";   // COMME LES MATRICULES DANS NOTRE PAY
    allouer3(&p);
    tete=p;
    for (i=1; i<n; i++)
    {
        cnst=rand1(42);
        mot1[0]='\0';
        for (x=0; x<strlen( a[cnst]); x++)
        {
            mot[x]= a[cnst][x];
        }
        mot[strlen( a[cnst])]='\0';
        for (r=0; r<5; r++)
        {
            mot1[r]=alpha2[rand1(10)];
        }
        mot1[5]='-';
        for (r=6; r<9; r++)
        {
            mot1[r]=alpha2[rand1(10)];
        }
        mot1[9]='-';
        for (r=10; r<12; r++)
        {
            mot1[r]=alpha2[rand1(10)];
        }
        mot1[10]=alpha12[rand1(4)];
        mot1[11]=alpha1[rand1(8)];
        mot1[12]='\0';
        free(mot1);
        allouer(&q);
        aff_marque(q,mot);
        aff_numuro(q,mot1);
        aff_adr3(p,q);
        p=q;
    }
    aff_adr3(p,NULL);
    return tete;
}
/*-----------------------LE PROCEDURE QUI CRIER UNE LISTE-------------*/
Maillon *cree_pop(int n)
{
    Maillon *tete;
    Maillon *prt;
    Maillon *enf;
    Maillon *voi;
    Maillon *p;
    Maillon *q;
    int i;
    int r;
    int cnst;
    char mot[20];
    char alpha1[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char alpha2[]="abcdefghijklmnopqrstuvwxyz";
    srand(time(0));
    allouer(&p);
    aff_val(p,mot);
    tete=p;
    for (i=1; i<n; i++)
    {
        mot[0]=alpha1[rand1(26)];
        cnst=(rand1(12)+1)+3;
        for (r=1; r<cnst; r++)
        {
            mot[r]=alpha2[rand1(26)];
        }
        mot[cnst]='\0';


        allouer(&q);
        aff_val(q,mot);
        prt=cree_prt(rand1(4));
        enf=cree_enf(rand1(7));
        voi=cree_voi(rand1(5));//COMME JE VEUX DIRE ECRIRE DE 2 NOMS         I.E: MAXIMUM 2 VOITURE
        aff_adr(p,q);
        aff_adr1(p,prt);
        aff_adr2(p,enf);
        aff_adr3(p,voi);
        p=q;
    }
    aff_adr(p,NULL);
    prt=cree_prt(rand1(4));
    enf=cree_enf(rand1(7));
    voi=cree_voi(rand1(5));
    aff_adr1(p,prt);
    aff_adr2(p,enf);
    aff_adr3(p,voi);
    return tete;
}
/*-----------------------LE PROCEDURE QUI AFFICHE UNE LISTE-------------*/
void afficher(Maillon *p)
{
    int i=0;
    int k=6;
    p=suivant(p);
    Locate(7,k);
    while(p!=NULL)
    {
        i++;
        if (6==i)
        {
            k++;
            Locate(7,k);
            i=0;
        }
        printf("| %s |--",valeur(p));
        p=suivant(p);
    }
}
/*-----------------------LE PROCEDURE QUI AFFICHE UNE SEUL LISTE DES PARENTS -------------*/
void afficher1(Maillon *p)
{

    p=suivant1(p);
    p=suivant1(p);
    while(p!=NULL)
    {
        printf("| %s |--",valeur(p));
        p=suivant1(p);
    }
}
/*-----------------------LE PROCEDURE QUI AFFICHE UNE SEUL LISTE DES ENFANTS -------------*/
void afficher2(Maillon *p)
{
    int i=0;
    p=suivant2(p);
    p=suivant2(p);
    while(p!=NULL)
    {
        i++;
        if (5==i)
        {
            printf("\n");
            i=0;
        }
        printf("|%s (%s) |--",prenom(p),sexe(p));
        p=suivant2(p);
    }
}
/*-----------------------LE PROCEDURE QUI AFFICHE UNE SEUL LISTE DES VOITURES -------------*/
void afficher3(Maillon *p)
{
    int i=0;
    p=suivant3(p);
    p=suivant3(p);
    while(p!=NULL)
    {
        i++;
        if (5==i)
        {
            printf("\n");
            i=0;
        }
        printf("|%s ( %11s )|--",marque(p),numuro(p));
        p=suivant3(p);
    }
}
/*-----------------------LE PROCEDURE QUI AFFICHE TOUT LISTE DES PARENTS -------------*/
void afficher_tout_parents(Maillon *p)
{
    int i=0;
    p=suivant(p);
    while(p!=NULL)
    {
        i++;
        printf("FAMILLE %d_#%s#____",i,valeur(p));
        afficher1(p);
        printf("\n");
        printf("\n");
        p=suivant(p);
    }
}
/*-----------------------LE PROCEDURE QUI AFFICHE TOUT LISTE DES ENFANTS -------------*/
void afficher_tout_enfants(Maillon *p)
{
    int i=0;
    p=suivant(p);
    while(p!=NULL)
    {
        i++;
        printf("FAMILLE %d_#%s#____",i,valeur(p));
        afficher2(p);
        printf("\n");
        printf("\n");
        p=suivant(p);
    }
}
/*-----------------------LE PROCEDURE QUI AFFICHE TOUT LISTE DES VOITURES-------------*/
void afficher_tout_voitures(Maillon *p)
{
    int i=0;
    p=suivant(p);
    while(p!=NULL)
    {
        i++;
        printf("FAMILLE %d_#%s#____",i,valeur(p));
        afficher3(p);
        printf("\n");
        printf("\n");
        p=suivant(p);
    }
}
/*-----------------------LA FONCTION BOOLEAN QUI DONNE 0 SI LA VOITURE EST DANS LA FAMILLE ET IL DONNE 1 SINON -------------*/
int Rech_Fam_Voit(Maillon *p,char num[20],char mark[20])
{
    int i=0;
    p=suivant3(p);
    p=suivant3(p);
    while(p!=NULL)
    {
        if ( strcomp(marque(p),mark) == 0   &&  strcomp(numuro(p),num) == 0)
        {
            i=1;
        }

        p=suivant3(p);
    }
    return i;
}
/*-----------------------LA FONCTION QUI DONNER L'ADRESS DE LA FAMILLE QUI A LA VOITURE RECHERCHER-------------*/
int RechFamVoit_1(Maillon *p,int num,char mark[20])
{
    int i=0;
    p=suivant(p);
    while(p!=NULL)
    {
        if (Rech_Fam_Voit(p,num,mark)==1)
        {
            i=p;//Locate(8,15);
            // printf("#L'adress Du Prioritere De La Voiture %s (%s) Est : %d (La Famille : %s )",mark,num,p,valeur(p));
        }
        p=suivant(p);
    }
    return i;
}
/*----------------------LA FONCTION QUI COMPARER DEUX STRINGS-----------*/
int strcomp(char * chaine1,char *chaine2)
{
    int j=0;
    while(chaine1[j] != '\0' && chaine2[j] != '\0')
    {
        if (chaine1[j] != chaine2[j])
        {
            if (chaine1[j] > chaine2[j])
                return (1);
            if (chaine1[j] < chaine2[j])
                return (-1);
        }
        j++;
    }
    return (0);
}
/*-----------------------LE PROCEDURE QUI PERMUTER  DEUX MAILLONS (ADDRESS+VALEUR) -------------*/
void PERMUTER (int *A, int *B)
{
    int AIDE;
    AIDE = *A;
    *A = *B;
    *B = AIDE;
}
/*-----------------------LE PROCEDURE QUI TRIER LES FAMILLES -------------*/
void  trier_pop(Maillon *p)
{
    int l=0;
    struct Maillon *d;
    struct Maillon *q;
    d=p;
    while (l != 1)
    {
        l=1;
        p=d;
        q=d;
        p=suivant(p);
        while(p!=NULL)
        {
            q=p;
            p=suivant(p);
            if (p!=NULL)
            {
                if ( (strcomp(valeur(q),valeur(p)) != (-1)) && (strcomp(valeur(q),valeur(p)) != (0)) )
                {
                    l=0;
                    PERMUTER (&p,&q);
                    PERMUTER (p,q);
                    /*J'AI PERMUTER LES VALEURS ET JE PROFITER A LA CASE D QUI
                                              EST VIDE C'EST COMME UNE TETE LA CASE D*/

                }
            }
        }
    }
    aff_val(d,"\0");
}
/*--------------LA FONCTION QUI DONNE LE NOMBRE DE FAMILLES -----------*/
int nbfamille(Maillon *p)
{
    p=suivant(p);
    int i=0;
    while(p!=NULL)
    {
        i++;
        p=suivant(p);
    }
    return (i);
}
/*--------------LA FONCTION QUI DONNE LE NOMBRE DES PARENTS DANS UNE FAMILLES-----------*/
int nb_parents_famille(Maillon *p)
{
    p=suivant1(p);
    int i=0;
    while(p!=NULL)
    {
        i++;
        p=suivant1(p);
    }
    return (i-1);
}
/*--------------LA FONCTION QUI DONNE LE NOMBRE DES ENFANTS DANS UNE FAMILLES -----------*/
int nb_enfants_famille(Maillon *p)
{
    p=suivant2(p);
    int i=0;
    while(p!=NULL)
    {
        i++;
        p=suivant2(p);
    }
    return (i-1);
}
/*--------------LA FONCTION QUI DONNE LE NOMBRE DES ENFANTS DE UNE FAMILLE DONNER -----------*/
int  nbenfnomfam(Maillon *p,char mot[20])
{
    int i=0;
    p=suivant(p);
    while(p!=NULL)
    {
        if ( strcomp(valeur(p),mot) == 0 )
        {
            i=nb_enfants_famille(p);
        }
        p=suivant(p);
    }
    return i;
}
/*--------------LA FONCTION QUI DONNE LE NOMBRE DES VOITURES DANS UNE FAMILLES -----------*/
int nb_voitures_famille(Maillon *p)
{
    p=suivant3(p);
    int i=0;
    while(p!=NULL)
    {
        i++;
        p=suivant3(p);
    }
    return (i-1);
}
/*-----------------------LA FONCTION QUI DONNE LE NOMBRE DES PARENTS DANS POP-------------*/
int nb_tout_parents(Maillon *p)
{
    int s=0;
    p=suivant(p);
    while(p!=NULL)
    {
        s=s+nb_parents_famille(p);
        p=suivant(p);
    }
    return s;
}
/*-----------------------LA FONCTION QUI DONNE LE NOMBRE DES ENFANTS DANS POP-------------*/
int  nbenfant(Maillon *p)     //NB_TOUT_ENFANTS
{
    int s=0;
    p=suivant(p);
    while(p!=NULL)
    {
        s=s+nb_enfants_famille(p);
        p=suivant(p);
    }
    return s;
}
/*-----------------------LA FONCTION QUI DONNE LE NOMBRE DES VOITURES DANS POP-------------*/
int nb_tout_voitures(Maillon *p)
{
    int i=0;
    int s=0;
    p=suivant(p);
    while(p!=NULL)
    {
        s=s+nb_voitures_famille(p);
        p=suivant(p);
    }
    return s;
}
/*-----------------------LA FONCTION QUI DONNE LE NOMBRE DES FAMILLES SANS PARENTES DANS POP-------------*/
int nbfamillesansparent(Maillon *p)
{
    int s=0;
    int i=0;
    p=suivant(p);
    while(p!=NULL)
    {
        if (nb_parents_famille(p)==0)
        {
            i++;
        }
        p=suivant(p);
    }
    return i;
}
/*--------------LA FONCTION QUI RENVOI L ADRESS DU NOM-FAMILLES --------*/
int present(Maillon *p,char mot[20])
{
    int l=0;
    int i;
    p = suivant( p ) ;
    while((p!=NULL))
    {
        if ( strcomp(valeur(p),mot) == 0 )
        {
            i = p ;
            l = 1 ;
        }
        p = suivant( p ) ;
    }
    if (l==0)
    {
        return (NULL);
    }
    if (l==1)
    {
        return (i);
    }
}
/*--------------LA PROCEDURE QUI INSERER UN MAILLON       --------*/
void ins_pos(Maillon *p,char mot[20])
{
    int i;
    int j;
    int l;
    struct Maillon *q;
    struct Maillon *tete;
    tete=p;
    while((p!=NULL))
    {
        i=p;
        p = suivant( p ) ;
    }
    p=tete;
    while((p!=NULL))
    {
        if (i==p)
        {
            allouer(&q);
            aff_val(q,mot);
            aff_adr(p,q);
            p=q;
            aff_adr(p,NULL);
        }
        p = suivant( p ) ;
    }
}
/*--------------la PROCEDURE QUI INSERER UN NOMFAMILLE        --------*/
void inser(Maillon *p,char mot[20])
{
    ins_pos(p,mot);
    trier_pop(p);
}
/*--------------la FONCTION QUI DONNER L ADRESS DU POINTEUR QUI POINT A L ADRESS DE UN NOMFAMILLE (PRECEDE) --------*/
int pre_adr(Maillon *p )
{
    struct Maillon *d;
    int i;
    d=p;
    //p = suivant( p ) ;
    while((p!=NULL))
    {
        if (d == suivant( p ))
        {
            d=p;
        }
        p = suivant( p ) ;
    }
    return d;
}
/*--------------la PROCEDURE QUI INSERER UN MAILLON ENFANT       --------*/
void ins_pos2(Maillon *p,char mot[20],char mot2[20])
{
    int i;
    int j;
    int l;
    struct Maillon *q;
    struct Maillon *tete;


    //p=pre_adr( p );
    //p = suivant2( p ) ;

    tete=p;

    while((p!=NULL))
    {
        i=p;
        p = suivant2( p ) ;
    }
    p=tete;

    while((p!=NULL))
    {
        if (i==p)
        {
            allouer(&q);
            aff_prenom(q,mot);
            aff_sexe(q,mot2);
            aff_adr2(p,q);
            p=q;
            aff_adr2(p,NULL);
        }
        p = suivant2( p ) ;
    }

}
/*--------------la PROCEDURE QUI INSERER UN ENFANT        --------*/
void naissanceTrie(Maillon *p,char mot[20],char mot2[20])
{
    ins_pos2(p,mot,mot2);
    trier_pop(p);
}
/*--------------la PROCEDURE QUI LIRE UNE CHAINE ENTREE lire --------*/
void parler(char *chaine)//ON INTRODUIT JUSTE LA CHAINE DE CARACTERE
{
    char temp1[256];
    sprintf(temp1,"echo m=\"%s\" > file.vbs",chaine);
    system(temp1);
    sprintf(temp1,"echo CreateObject(\"SAPI.SpVoice\").Speak m >> file.vbs");
    system(temp1);
    sprintf(temp1,"file.vbs");
    system(temp1);
    remove("file.vbs");
}
/*--------------la PROCEDURE QUI SUPRIMER UN NOMFAMILLE  PAR POSITION     --------*/
void supr_pos(Maillon *p,int pos)
{
    struct Maillon  *q ;
    struct Maillon  *tete ;
    if (nbfamille(p)<pos)
    {
        printf("POSITION INTROUVABLE");
    }
    else
    {
        tete=p;

        q=NULL;
        int i=1;
        if (pos==1)
        {
            q=p;
            p=suivant(p);
            aff_adr(q,suivant(p));
            free(p);
        }
        else
        {
            p=suivant(p);
            while((i<pos)&&(p!=NULL))
            {
                q=p;
                p=suivant(p);
                i++;
            }
            if(p!=NULL)
            {
                aff_adr(q,suivant(p));
                free(p);
            }
        }
    }

}
/*--------------la PROCEDURE QUI DONNE UN INDICE DE UNE VALEUR DANS LA LISTE        --------*/
int indice_de_valeur_dans_la_liste(Maillon *p,char val[20])
{
    int k;
    int i=0;
    struct Maillon  *tete ;
    p=suivant(p);
    tete=p;
    while (p != NULL)
    {
        i++;
        if (strcomp(valeur(p),val)==0)
        {
            k=i;
        }
        p = suivant(p);
    }
    return k;
}
/*--------------la PROCEDURE QUI SUPPRIMER UN NOMFAMILLE PAR VALEUR  --------*/
void supr_val(Maillon *p,char val[20])
{
    int k;
    int l;
    int i=0;
    struct Maillon  *tete ;
    if (present(p,val)==0)
    {
        printf("VALEUR INTROUVABLE");
    }
    else
    {
        tete=p;
        supr_pos(p,indice_de_valeur_dans_la_liste(p,val));
    }

}
/*-------------- EXACTEMENT COMME GOTO() --------*/
void Locate(SHORT x,SHORT y)
{
    HANDLE hmenu=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(hmenu,Pos);
}
/*-------------- DEPLACER LE CURSEUR OU BIEN LE POINTEUR EN MENU PRINCIPALE --------*/
int Choisir_principale()
{
    int curs = 0;
    int touche;
    do
    {
        Afficher_principale(curs);
        touche = _getch();
        if (touche==0xE0)
        {
            touche = _getch();
            if (touche==0x50 && curs==0)
            {
                curs = 1;   // fleche bas
            }
            else if (touche==0x50 && curs==1)
            {
                curs = 2;   // fleche bas
            }
            else if (touche==0x50 && curs==2)
            {
                curs = 0;   // fleche bas
            }
            else if (touche==0x48 && curs==2)
            {
                curs = 1;   // fleche haut
            }
            else if (touche==0x48 && curs==1)
            {
                curs = 0;   // fleche haut
            }
            else if (touche==0x48 && curs==0)
            {
                curs = 2;   // fleche haut
            }
        }
    }
    while (touche!=0x0D);   // enter
    return curs;
}
/*-------------- DEPLACER LE CURSEUR OU BIEN LE POINTEUR EN MENU PARTIE1 --------*/
int Choisir_partie1()
{
    int curs = 0;
    int touche;
    do
    {
        Afficher_partie1(curs);
        touche = _getch();
        if (touche==0xE0)
        {
            touche = _getch();
            if (touche==0x50 && curs==0)
            {
                curs = 1;   // fleche bas
            }
            else if (touche==0x50 && curs==1)
            {
                curs = 2;   // fleche bas
            }
            else if (touche==0x50 && curs==2)
            {
                curs = 3;   // fleche bas
            }
            else if (touche==0x50 && curs==3)
            {
                curs = 4;   // fleche bas
            }
            else if (touche==0x50 && curs==4)
            {
                curs = 5;   // fleche bas
            }
            else if (touche==0x50 && curs==5)
            {
                curs = 6;   // fleche bas
            }
            else if (touche==0x50 && curs==6)
            {
                curs = 7;   // fleche bas
            }
            else if (touche==0x50 && curs==7)
            {
                curs = 0;   // fleche bas
            }
            else if (touche==0x48 && curs==7)
            {
                curs = 6;   // fleche haut
            }
            else if (touche==0x48 && curs==6)
            {
                curs = 5;   // fleche haut
            }
            else if (touche==0x48 && curs==5)
            {
                curs = 4;   // fleche haut
            }
            else if (touche==0x48 && curs==4)
            {
                curs = 3;   // fleche haut
            }
            else if (touche==0x48 && curs==3)
            {
                curs = 2;   // fleche haut
            }
            else if (touche==0x48 && curs==2)
            {
                curs = 1;   // fleche haut
            }
            else if (touche==0x48 && curs==1)
            {
                curs = 0;   // fleche haut
            }
            else if (touche==0x48 && curs==0)
            {
                curs = 7;   // fleche haut
            }
        }
    }
    while (touche!=0x0D);   // enter
    return curs;
}
/*-------------- DEPLACER LE CURSEUR OU BIEN LE POINTEUR EN MENU DU PARTIE2 --------*/
int Choisir_partie2()
{
    int curs = 0;
    int touche;
    do
    {
        Afficher_partie2(curs);
        touche = _getch();
        if (touche==0xE0)
        {
            touche = _getch();
            if (touche==0x50 && curs==0)
            {
                curs = 1;   // fleche bas
            }
            else if (touche==0x50 && curs==1)
            {
                curs = 2;   // fleche bas
            }
            else if (touche==0x50 && curs==2)
            {
                curs = 3;   // fleche bas
            }
            else if (touche==0x50 && curs==3)
            {
                curs = 4;   // fleche bas
            }
            else if (touche==0x50 && curs==4)
            {
                curs = 5;   // fleche bas
            }
            else if (touche==0x50 && curs==5)
            {
                curs = 6;   // fleche bas
            }
            else if (touche==0x50 && curs==6)
            {
                curs = 7;   // fleche bas
            }
            else if (touche==0x50 && curs==7)
            {
                curs = 0;   // fleche bas
            }
            else if (touche==0x48 && curs==7)
            {
                curs = 6;   // fleche haut
            }
            else if (touche==0x48 && curs==6)
            {
                curs = 5;   // fleche haut
            }
            else if (touche==0x48 && curs==5)
            {
                curs = 4;   // fleche haut
            }
            else if (touche==0x48 && curs==4)
            {
                curs = 3;   // fleche haut
            }
            else if (touche==0x48 && curs==3)
            {
                curs = 2;   // fleche haut
            }
            else if (touche==0x48 && curs==2)
            {
                curs = 1;   // fleche haut
            }
            else if (touche==0x48 && curs==1)
            {
                curs = 0;   // fleche haut
            }
            else if (touche==0x48 && curs==0)
            {
                curs = 7;   // fleche haut
            }
        }
    }
    while (touche!=0x0D);   // enter
    return curs;
}
/*-------------- LE DESIGNE MENU PRINCIPALE --------*/
void Afficher_principale(int curs)
{
    textbackground(0);
    gotoxy(1,1);
    printf("                                                                                                                \n");
    textcolor(WHITE);
    gotoxy(3,3);
    printf("     ");
    gotoxy(3,4);
    printf("  ");
    gotoxy(3,5);
    printf("     ");
    gotoxy(3,6);
    printf("  ");
    gotoxy(3,7);
    printf("     ");
    gotoxy(9,3);
    printf("     ");
    gotoxy(9,4);
    printf("  ");
    gotoxy(9,5);
    printf("     ");
    gotoxy(12,6);
    printf("  ");
    gotoxy(9,7);
    printf("     ");
    gotoxy(15,3);
    textcolor(BLUE);
    printf("OO");
    textcolor(WHITE);
    gotoxy(15,4);
    printf("");
    gotoxy(15,5);
    printf("  ");
    gotoxy(15,6);
    printf("  ");
    gotoxy(15,7);
    printf("  ");
    gotoxy(18,3);
    printf("Ecole Nationale Superieure D'informatique");
    gotoxy(33,5);
    textbackground(0);
    printf("1 CPI  - Annee Universitaire 2019/2020 _ (Semestre 2)\n\n");
    gotoxy(24,12);
    textbackground(0);
    printf("  ~~~~~~~~~~~~~  MENU  ~~~~~~~~~~~  ");
    Locate(30,14);
    printf("%c 1.PARTIE 1 DU TP\n\n",(curs==0)?'X':' ');
    Locate(30,16);
    printf("%c 2.PARTIE 2 DU TP\n\n",(curs==1)?'X':' ');
    Locate(30,18);
    printf("%c 3.QUITER LE PROGRAME\n\n",(curs==2)?'X':' ');
    textbackground(0);
    Locate(0,24);
    printf("                                                                                                                          \n");
    Locate(0,25);
    textbackground(13);
    printf("                                                                                                                          \n");
    Locate(4,26);
    textbackground(0);
    printf("Realiser Par : BINOME BELLI_ATEK");
    textbackground(13);
    printf("                  ");
    textbackground(0);
    printf("TP1   ALSDD");
    textbackground(13);
    printf("                  ");
    textbackground(0);
    printf("Ens: Dr M Boulakradeche");
    textbackground(13);
    Locate(0,27);
    printf("                                                                                                                \n");
    textbackground(0);
    Locate(0,28);
    printf("                                                                                                                \n");
    Locate(5,28);
}
/*-------------- LE DESIGNE MENU PARTIE 1 --------*/
void Afficher_partie1(int curs)
{
    textbackground(0);
    gotoxy(1,1);
    printf("                                                                                                                          ");
    textcolor(WHITE);
    gotoxy(3,3);
    printf("     ");
    gotoxy(3,4);
    printf("  ");
    gotoxy(3,5);
    printf("     ");
    gotoxy(3,6);
    printf("  ");
    gotoxy(3,7);
    printf("     ");
    gotoxy(9,3);
    printf("     ");
    gotoxy(9,4);
    printf("  ");
    gotoxy(9,5);
    printf("     ");
    gotoxy(12,6);
    printf("  ");
    gotoxy(9,7);
    printf("     ");
    gotoxy(15,3);
    textcolor(BLUE);
    printf("OO");
    textcolor(WHITE);
    gotoxy(15,4);
    printf("");
    gotoxy(15,5);
    printf("  ");
    gotoxy(15,6);
    printf("  ");
    gotoxy(15,7);
    printf("  ");
    gotoxy(18,3);
    printf("Ecole Nationale Superieure D'informatique");
    gotoxy(33,5);
    textbackground(0);
    printf(" PARTIE 1 DU TP  \n\n");
    gotoxy(24,12);
    textbackground(0);
    printf("  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  MENU  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  ");
    Locate(30,14);
    printf("%c 1.Construire La Liste Du Nom Familes Popilation POP\n\n",(curs==0)?'X':' ');
    Locate(30,16);
    printf("%c 2.Affichage La Liste Du Popilation POP (Nom Familes)\n\n",(curs==1)?'X':' ');
    Locate(30,18);
    printf("%c 3.Trier La Liste Du Popilation POP (Nom Familes)\n\n",(curs==2)?'X':' ');
    Locate(30,20);
    printf("%c 4.Afficher Combien Des NomFamilles Dans La Popilation POP\n\n",(curs==3)?'X':' ');
    Locate(30,22);
    printf("%c 5.Inserer Un Nom Famille dans la liste Du Popilation POP\n\n",(curs==4)?'X':' ');
    Locate(30,24);
    printf("%c 6.Supprimer Un Nom Famille dans la liste Du Popilation POP\n\n",(curs==5)?'X':' ');
    Locate(30,26);
    printf("%c 7.Chercher Un Nom Famille dans la liste Du Popilation POP\n\n",(curs==6)?'X':' ');
    Locate(30,28);
    printf("%c 8.Retour Au Menu Principale\n\n",(curs==7)?'X':' ');
    textbackground(0);
    Locate(0,32);
    printf("                                                                                                                          \n");
    Locate(0,33);
    textbackground(13);
    printf("                                                                                                                          \n");
    Locate(4,34);
    textbackground(0);
    printf("Realiser Par : BINOME BELLI_ATEK");
    textbackground(13);
    printf("                  ");
    textbackground(0);
    printf("TP1   ALSDD");
    textbackground(13);
    printf("                  ");
    textbackground(0);
    printf("Ens: Dr M Boulakradeche");
    textbackground(13);
    Locate(0,35);
    printf("                                                                                                                          \n");
    textbackground(0);
    Locate(0,36);
    printf("                                                                                                                          \n");
    Locate(5,36);
}
/*-------------- LE DESIGNE MENU PARTIE 2 --------*/
void Afficher_partie2(int curs)
{
    textbackground(0);
    gotoxy(1,1);
    printf("                                                                                                                          ");
    textcolor(WHITE);
    gotoxy(3,3);
    printf("     ");
    gotoxy(3,4);
    printf("  ");
    gotoxy(3,5);
    printf("     ");
    gotoxy(3,6);
    printf("  ");
    gotoxy(3,7);
    printf("     ");
    gotoxy(9,3);
    printf("     ");
    gotoxy(9,4);
    printf("  ");
    gotoxy(9,5);
    printf("     ");
    gotoxy(12,6);
    printf("  ");
    gotoxy(9,7);
    printf("     ");
    gotoxy(15,3);
    textcolor(BLUE);
    printf("OO");
    textcolor(WHITE);
    gotoxy(15,4);
    printf("");
    gotoxy(15,5);
    printf("  ");
    gotoxy(15,6);
    printf("  ");
    gotoxy(15,7);
    printf("  ");
    gotoxy(18,3);
    printf("Ecole Nationale Superieure D'informatique");
    gotoxy(33,5);
    textbackground(0);
    printf(" PARTIE 2 DU TP\n\n");
    gotoxy(24,12);
    textbackground(0);
    printf("  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  MENU  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  ");
    Locate(30,14);
    printf("%c 1.Construire La Liste Du Nom Familes Popilation POP\n\n",(curs==0)?'X':' ');
    Locate(30,16);
    printf("%c 2.Affichage Tout La Liste Du Popilation POP (PARENTS ET ENFANTS ET VOITURES)\n\n",(curs==1)?'X':' ');
    Locate(30,18);
    printf("%c 3.Affichage Du Nombre De Familles Dont Les Parents Sont Decedes\n\n",(curs==2)?'X':' ');
    Locate(30,20);
    printf("%c 4.Afficher Combien Des Enfants Dans La Popilation POP\n\n",(curs==3)?'X':' ');
    Locate(30,22);
    printf("%c 5.Chercher Combien Des Enfants Dans Une Famille Du Popilation POP\n\n",(curs==4)?'X':' ');
    Locate(30,24);
    printf("%c 6.Insirer Un Nouveau Naissance dans la liste Du Popilation POP\n\n",(curs==5)?'X':' ');
    Locate(30,26);
    printf("%c 7.Chercher De Quel Famille Une Voiture Dans La Popilation POP\n\n",(curs==6)?'X':' ');
    Locate(30,28);
    printf("%c 8.Retour Au Menu Principale\n\n",(curs==7)?'X':' ');
    textbackground(0);
    Locate(0,32);
    printf("                                                                                                                          \n");
    Locate(0,33);
    textbackground(13);
    printf("                                                                                                                          \n");
    Locate(4,34);
    textbackground(0);
    printf("Realiser Par : BINOME BELLI_ATEK");
    textbackground(13);
    printf("                  ");
    textbackground(0);
    printf("TP1   ALSDD");
    textbackground(13);
    printf("                  ");
    textbackground(0);
    printf("Ens: Dr M Boulakradeche");
    textbackground(13);
    Locate(0,35);
    printf("                                                                                                                          \n");
    textbackground(0);
    Locate(0,36);
    printf("                                                                                                                          \n");
    Locate(5,36);
}
int khiyar() //LIRE LE CHOIX DANS LA MENU DU DEBUT (PRINCIPALE)
{
    int choix;
    choix = Choisir_principale();
    Locate(30,30);
    printf("Vous avez choisi : %d    \n",(choix+1));
    Sleep(900);
    return (choix+1);
}
int khiyar1()//LIRE LE CHOIX DE LA PREMIRE PARTIE
{
    int choix;
    choix = Choisir_partie1();
    Locate(30,30);
    printf("Vous avez choisi : %d    \n",(choix+1));
    Sleep(900);
    return (choix+1);
}
int khiyar2()//LIRE LE  CHOIX DE LA DEUSIEME PARTIE
{
    int choix;
    choix = Choisir_partie2();
    Locate(30,30);
    printf("Vous avez choisi : %d    \n",(choix+1));
    Sleep(900);
    return (choix+1);
}
/*-----------------------LE PROGRAMME PRINCIPALE -----------------------*/
int main()
{
    int n;
    int M=0;
    int Z=0;
    int w;
    int pos;
    int valpos;
    int wah;
    int hh;
    char  val[20];
    char mot[20];
    char lol[20];
    char ww[20];
    char nn[20];
    char nw[20];
    char np[20];
    char mf[20];
    Maillon *tete;
    movie();

se :
    system("color D3");
    system("mode 112, 30");
    switch (khiyar())
    {
    case 1 :
me :
        system("color D3");
        system("mode 122, 38");
        switch (khiyar1())
        {
        case 1 :
            clrscr();
            system("mode 122, 33");
            system("color D3");
            cadre1();
            Locate(9,7);
            printf("Donner Le Nombre Des Noms De Familles : ");
            parler("Donner Le Nombre Des Noms De Familles");
            scanf("%d",&n);
            Locate(10,7);
            tete=cree_pop((n+1));
            M=1;
            Locate(15,15);
            loading();
            clrscr();
            goto me;
            break;
        case 2 :
            clrscr();
            system("mode 122, 33");
            system("color D3");
            cadre1();
            Locate(6,4);
            if (M==0)
            {
                printf(" VUILLIER ECRIRE AVANT UNE LISTE DE NOM-FAMILLES !\n");
                parler("ECRIRE AVANT UNE LISTE DE NOM DES FAMILLES");
                Locate(15,15);
                printf(" Cliquer  sur un button pour RETOUR   ");
                getchar();
                clrscr();
                goto me;
            }
            else
            {
                system("mode 110,900");
                printf(" AFFICHAGE DE LA LISTE DES NOMS DES FAMILLES DE LA POPULATION ALGERIEN POP \n");
                afficher(tete);
                Locate(1,1);
                system("pause");
                clrscr();
                goto me;
            }
            break;
        case 3 :
            clrscr();
            system("mode 122, 33");
            system("color D3");
            cadre1();
            Locate(6,4);
            if (M==0)
            {
                printf(" VUILLIER ECRIRE AVANT UNE LISTE DE NOM-FAMILLES !\n");
                parler("ECRIRE AVANT UNE LISTE DE NOM DES FAMILLES");
                Locate(15,15);
                printf(" Cliquer  sur un button pour RETOUR   ");
                getchar();
                clrscr();
                goto me;
            }
            else
            {
                printf(" LE TRIEAGE DE LA LISTE NOM-FAMILLES DE LA POPULATION ALGERIEN POP EST EN COURS \n");
                Locate(15,15);
                trier_pop(tete);
                Z=1;
                loading();
                clrscr();
                goto me;
            }
            break;
        case 4 :
            clrscr();
            system("mode 122, 33");
            system("color D3");
            cadre1();
            Locate(6,4);
            if (M==0)
            {
                printf(" VUILLIER ECRIRE AVANT UNE LISTE DE NOM-FAMILLES !\n");
                parler("ECRIRE AVANT UNE LISTE DE NOM DES FAMILLES");
                Locate(15,15);
                printf(" Cliquer  sur un button pour RETOUR   ");
                getchar();
                clrscr();
                goto me;
            }
            else
            {
                printf(" Le Nombre De Familles Dans La Population POP    Est :   %d",nbfamille(tete));
                Locate(15,15);
                system("pause");
                clrscr();
                goto me;
            }
            break;
        case 5 :
            clrscr();
            system("mode 122, 33");
            system("color D3");
            cadre2();
            Locate(6,4);
            if (M==0)
            {
                printf(" VUILLIER ECRIRE AVANT UNE LISTE DE NOM-FAMILLES !\n");
                parler("ECRIRE AVANT UNE LISTE DE NOM DES FAMILLES");
                Locate(15,15);
                printf(" Cliquer  sur un button pour RETOUR   ");
                getchar();
                clrscr();
                goto me;
            }
            if (Z==0)
            {
                printf(" VUILLIER TRIER AVANT VOTRE LISTE DE NOM-FAMILLES !\n");
                parler(" VUILLIER TRIER AVANT VOTRE LISTE DE NOM-FAMILLES");
                Locate(15,15);
                printf(" Cliquer  sur un button pour RETOUR   ");
                getchar();
                clrscr();
                goto me;
            }
            else
            {
                printf(" INSIRERTION DE UN NOMFAMILLE DANS LA LISTE NOM-FAMILLES DE LA POPULATION ALGERIEN POP ");
                Locate(6,5);
                printf("Veuillez Entrer La Valeur A Insrer : ");
                scanf("%15s",&lol);
                lol[0]=toupper(lol[0]);
                for(w=1; w<strlen(lol); w++)
                {
                    lol[w]=tolower(lol[w]);
                }
                Locate(15,15);
                inser(tete,lol);
                loading();
                clrscr();
                goto me;
            }
            break;
        case 6 :
            clrscr();
            system("mode 122, 33");
            system("color D3");
            cadre2();
            Locate(6,4);
            if (M==0)
            {
                printf(" VUILLIER ECRIRE AVANT UNE LISTE DE NOM-FAMILLES !\n");
                parler("ECRIRE AVANT UNE LISTE DE NOM DES FAMILLES");
                Locate(15,15);
                printf(" Cliquerez sur un button pour RETOUR   ");
                getchar();
                clrscr();
                goto me;
            }
            if (Z==0)
            {
                printf(" VUILLIER TRIER AVANT VOTRE LISTE DE NOM-FAMILLES !\n");
                parler(" VUILLIER TRIER AVANT VOTRE LISTE DE NOM-FAMILLES");
                Locate(15,15);
                printf(" Cliquerez sur un button pour RETOUR   ");
                getchar();
                clrscr();
                goto me;
            }
            else
            {
                printf(" SUPRITION DE UN NOMFAMILLE DANS LA LISTE NOM-FAMILLES DE LA POPULATION ALGERIEN POP ");
                Locate(6,6);
                printf("Veuillez Choiser Comment Supprimer :  ");
                Locate(6,8);
                printf(" 1. Supprimer Par Valeur  ");
                Locate(6,10);
                printf(" 2. Supprimer Par Position  ");
                Locate(6,12);
                printf(" Votre CHOIX :  ");
                scanf("%d",&valpos);
                if (valpos==1)
                {
                    Locate(6,14);
                    printf("Veuillez La Valeur A Supprimer :  ");
                    scanf("%15s",&val);
                    val[0]=toupper(val[0]);
                    for(w=1; w<strlen(val); w++)
                    {
                        val[w]=tolower(val[w]);
                    }
                    Locate(15,15);
                    supr_val(tete,val);
                    loading();
                    clrscr();
                    goto me;
                }
                if (valpos==2)
                {
                    Locate(6,14);
                    printf("Veuillez La Position De La Valeur A Supprimer :  ");
                    scanf("%d",&pos);
                    Locate(15,15);
                    supr_pos(tete,pos);
                    loading();
                    clrscr();
                    goto me;
                }
            }
            break;
        case 7 :
            clrscr();
            system("mode 122, 33");
            system("color D3");
            cadre2();
            Locate(6,4);
            if (M==0)
            {
                printf(" VUILLIER ECRIRE AVANT UNE LISTE DE NOM-FAMILLES !\n");
                parler("ECRIRE AVANT UNE LISTE DE NOM DES FAMILLES");
                Locate(15,15);
                printf(" Cliquerez sur un button pour RETOUR   ");
                getchar();
                clrscr();
                goto me;
            }
            if (Z==0)
            {
                printf(" VUILLIER TRIER AVANT VOTRE LISTE DE NOM-FAMILLES !\n");
                parler(" VUILLIER TRIER AVANT VOTRE LISTE DE NOM-FAMILLES");
                Locate(15,15);
                printf(" Cliquerez sur un button pour RETOUR   ");
                getchar();
                clrscr();
                goto me;
            }
            else
            {
                printf(" RECHERCHE DE UN NOM-FAMILLE DANS LA LISTE NOM-FAMILLES DE LA POPULATION ALGERIEN POP ");
                Locate(6,5);
                printf("Veuillez Entrer Le Nom De Famille A Chercher : ");
                scanf("%15s",&mot);
                mot[0]=toupper(mot[0]);
                for(w=1; w<strlen(mot); w++)
                {
                    mot[w]=tolower(mot[w]);
                }
                Locate(6,7);
                if (present(tete,mot)==0)
                {
                    printf("L'adress De %s A Chercher Est : %d  (null)",mot,present(tete,mot));
                }
                else
                {
                    printf("L'adress De %s A Chercher Est : %d",mot,present(tete,mot));
                }
                Locate(15,15);
                system("pause");
                clrscr();
                goto me;
            }
            break;
        case 8 :
            clrscr();
            goto se;
            break;
        default :
            printf("il ya un erreur \n");
        }
        break; //la fin de la partie 1 du tp



    case 2 ://la debut de la partie 2 du tp
be :
        system("color D3");
        system("mode 122, 38");
        switch (khiyar2())
        {
        case 1 :
            clrscr();
            system("mode 122, 33");
            system("color D3");
            cadre1();
            Locate(9,7);
            printf("Donner Le Nombre Des Noms De Familles : ");
            //parler("Donner Le Nombre Des Noms De Familles");
            scanf("%d",&n);
            Locate(10,7);
            tete=cree_pop((n+1));
            M=1;
            trier_pop(tete);
            Z=1;
            Locate(15,15);
            loading();
            clrscr();
            goto be;
            break;
        case 2 :
            system("mode 122, 33");
            system("color D3");
            cadre2();
            Locate(6,4);
            if (M==0)
            {
                printf(" VUILLIER ECRIRE AVANT UNE LISTE DE NOM-FAMILLES !\n");
                parler("ECRIRE AVANT UNE LISTE DE NOM DES FAMILLES");
                Locate(15,15);
                printf(" Cliquerez sur un button pour RETOUR   ");
                getchar();
                clrscr();
                goto be;
            }
            else
            {
                system("mode 110,900");
                printf("les parents :\n");
                printf("***********\n");
                afficher_tout_parents(tete);
                printf("*********************************************************\n");
                printf("les enfants :\n");
                printf("***********\n");
                afficher_tout_enfants(tete);
                printf("*********************************************************\n");
                printf("les voitures :\n");
                printf("***********\n");
                afficher_tout_voitures(tete);
                printf("*********************************************************\n");
                Locate(40,0);
                system("pause");
                clrscr();
                goto be;
            }
            break;



        case 3 :
            clrscr();
            system("mode 122, 33");
            system("color D3");
            cadre1();
            Locate(6,4);
            if (M==0)
            {
                printf(" VUILLIER ECRIRE AVANT UNE LISTE DE NOM-FAMILLES !\n");
                parler("ECRIRE AVANT UNE LISTE DE NOM DES FAMILLES");
                Locate(15,15);
                printf(" Cliquerez sur un button pour RETOUR   ");
                getchar();
                clrscr();
                goto be;
            }
            else
            {
                printf(" Le Nombre Des Familles Sans Parentes Dans La Population POP    Est :   %d",nbfamillesansparent(tete));
                Locate(15,15);
                system("pause");
                clrscr();
                goto be;
            }
            break;
        case 4 :
            clrscr();
            system("mode 122, 33");
            system("color D3");
            cadre1();
            Locate(6,4);
            if (M==0)
            {
                printf(" VUILLIER ECRIRE AVANT UNE LISTE DE NOM-FAMILLES !\n");
                parler("ECRIRE AVANT UNE LISTE DE NOM DES FAMILLES");
                Locate(15,15);
                printf(" Cliquerez sur un button pour RETOUR   ");
                getchar();
                clrscr();
                goto be;
            }
            else
            {
                printf(" Le Nombre Des enfants Dans La Population POP    Est :   %d",nbenfant(tete));
                Locate(15,15);
                system("pause");
                clrscr();
                goto be;
            }
            break;
        case 5 :
            clrscr();
            system("mode 122, 33");
            system("color D3");
            cadre1();
            Locate(6,4);
            if (M==0)
            {
                printf(" VUILLIER ECRIRE AVANT UNE LISTE DE NOM-FAMILLES !\n");
                parler("ECRIRE AVANT UNE LISTE DE NOM DES FAMILLES");
                Locate(15,15);
                printf(" Cliquerez sur un button pour RETOUR   ");
                getchar();
                clrscr();
                goto be;
            }
            else
            {
                printf(" On Informer Que On Fait Un Triage Nessessaire Dans Votre Choix ");

                Locate(6,14);
                printf("Veuillez Le Nom-Famille  :  ");
                scanf("%15s",&ww);
                ww[0]=toupper(ww[0]);
                for(w=1; w<strlen(ww); w++)
                {
                    ww[w]=tolower(ww[w]);
                }
                Locate(6,16);
                printf("Le Nombre Des Enfants Du Famille (%s) Est : %d ",ww,nbenfnomfam(tete,ww));
                Locate(15,18);
                system("pause");
                clrscr();
                goto be;
            }
            break;
        case 6 :
            clrscr();
            system("mode 122, 33");
            system("color D3");
            cadre1();
            Locate(6,4);
            if (M==0)
            {
                printf(" VUILLIER ECRIRE AVANT UNE LISTE DE NOM-FAMILLES !\n");
                parler("ECRIRE AVANT UNE LISTE DE NOM DES FAMILLES");
                Locate(15,15);
                printf(" Cliquerez sur un button pour RETOUR   ");
                getchar();
                clrscr();
                goto be;
            }
            else
            {
                printf(" On Informer Que On Fait Un Triage Nessessaire Dans Votre Choix ");

                Locate(6,9);
                printf("Veuillez Le NOM-FAMILLES du nouveau nesssance  :  ");
                scanf("%15s",&nw);
                nw[0]=toupper(nw[0]);
                for(w=1; w<strlen(nw); w++)
                {
                    nw[w]=tolower(nw[w]);
                }
                if (present(tete,nw)==0)
                {
                    Locate(6,10);
                    printf("Nom-Famille Ne Appartient Pas Dans POP ");
                }
                else
                {
                    Locate(6,10);
                    printf("Veuillez Le Prenom  Du Nouveau nessance   :  ");
                    scanf("%15s",&np);
                    np[0]=toupper(np[0]);
                    for(w=1; w<strlen(np); w++)
                    {
                        np[w]=tolower(np[w]);
                    }
                    Locate(6,11);
                    printf("Veuillez Le Sexe Du Nouveau nessance   (M/F):  ");
                    scanf("%1s",&mf);
                    mf[0]=toupper(mf[0]);
                    Locate(6,12);
                    naissanceTrie(pre_adr( present(tete,nw) ),np,mf);
                    Locate(15,15);
                    loading();
                    clrscr();
                    goto be;
                }
                Locate(15,18);
                system("pause");
                clrscr();
                goto be;
            }
            break;
        case 7 :
            clrscr();
            system("mode 122, 33");
            system("color D3");
            cadre1();
            Locate(6,4);
            if (M==0)
            {
                printf(" VUILLIER ECRIRE AVANT UNE LISTE DE NOM-FAMILLES !\n");
                parler("ECRIRE AVANT UNE LISTE DE NOM DES FAMILLES");
                Locate(15,15);
                printf(" Cliquerez sur un button pour RETOUR   ");
                getchar();
                clrscr();
                goto be;
            }
            else
            {
                printf(" On Informer Que On Fait Un Triage Nessessaire Dans Votre Choix ");

                Locate(6,9);
                printf("Veuillez La Mark Du Voiture  :  ");
                scanf("%15s",&ww);
                Locate(6,10);
                printf("Veuillez Le Matruquile  Du Voiture  (nemuro)(faitte attention il faut mait la tirer - ) :  ");
                scanf("%15s",&nn);
                ww[0]=toupper(ww[0]);
                for(w=1; w<strlen(ww); w++)
                {
                    ww[w]=tolower(ww[w]);
                }
                Locate(8,15);
                printf("#L'adress Du Prioritere De La Voiture %s (%s) Est : %d ",ww,nn,RechFamVoit_1(tete,nn,ww));
                // RechFamVoit_1(tete,nn,ww);
                Locate(15,18);
                system("pause");
                clrscr();
                goto be;
            }
            break;
        case 8 :
            clrscr();
            goto se;

            break;
        default :
            printf("il ya un erreur \n");
        }

        break;//la fin de la partie 2 du tp
    case 3 :
        movie_f();
        break;
    default :
        printf("il ya un erreur \n");
    }
    system("pause");
    return 0;
}
/*-----------------------la PROCEDURE QUI DESSIGNE UN CADRE1 -----------------------*/
void cadre1()
{
    int i;
    gotoxy(5,3) ;
    for (i=0; i<=110; i++)
    {
        textcolor (9);
        printf("$");
    }
    gotoxy(5,29) ;
    for (i=0; i<=110; i++)
    {
        textcolor (9);
        printf("$");
    }

    for (i=3; i<=29; i++)
    {
        gotoxy(5,i) ;
        textcolor (9);
        printf("$") ;
        gotoxy(115,i);
        textcolor (9);
        printf("$") ;
    }
    textcolor (15);

}
/*-----------------------la PROCEDURE QUI DESSIGNE UN CADRE2 -----------------------*/
void cadre2(void)
{
    int i ;
    for (i=3; i<=28; i++)
    {
        gotoxy(2,i) ;
        textcolor (9);
        printf("%c",219) ;
        gotoxy(119,i);
        textcolor (9);
        printf("%c",219) ;
    }
    gotoxy(2,29);
    textcolor(9);
    for (i=30; i<148; i++)
    {
        printf("%c",176);
    }
    gotoxy(2,2) ;
    for (i=30; i<148; i++)
    {
        printf("%c",176);
    }
    textcolor(15);

}
/*-----------------------la PROCEDURE QUI DESSIGNE UN CADRE3 -----------------------*/
void cadre3()
{
    int i;
    gotoxy(5,3) ;
    for (i=0; i<=110; i++)
    {
        textcolor (9);
        printf("$");
    }
    gotoxy(5,29) ;
    for (i=0; i<=110; i++)
    {
        textcolor (9);
        printf("$");
    }

    for (i=3; i<=29; i++)
    {
        gotoxy(5,i) ;
        textcolor (9);
        printf("$") ;
        gotoxy(115,i);
        textcolor (9);
        printf("$") ;
    }
    textcolor (15);

}
/*-----------------------la PROCEDURE QUI FAIT UN RETARD -----------------------*/
void loading()
{
    int l;
    textcolor(12);
    printf("\t\tLOADING ");
    for(l=0; l<14; l++)
    {
        textcolor(l);
        Sleep(100);
        printf("[+]");
    }
    textcolor(12);
    printf("  100 %c\n",37);
    Sleep(300);
    textcolor(15);
}
/*-----------------------LES MODULE QUI FAIRE LA MOVIE DE L ECRAN AU DEBUT-----------*/
void movie()
{
    system("color D3");
    system("mode 112, 30");
    textbackground(0);
    gotoxy(1,1);
    printf("                                                                                                                \n");
    textcolor(WHITE);
    gotoxy(3,3);
    printf("     ");
    gotoxy(3,4);
    printf("  ");
    gotoxy(3,5);
    printf("     ");
    gotoxy(3,6);
    printf("  ");
    gotoxy(3,7);
    printf("     ");
    gotoxy(9,3);
    printf("     ");
    gotoxy(9,4);
    printf("  ");
    gotoxy(9,5);
    printf("     ");
    gotoxy(12,6);
    printf("  ");
    gotoxy(9,7);
    printf("     ");
    gotoxy(15,3);
    textcolor(BLUE);
    printf("OO");
    textcolor(WHITE);
    gotoxy(15,4);
    printf("");
    gotoxy(15,5);
    printf("  ");
    gotoxy(15,6);
    printf("  ");
    gotoxy(15,7);
    printf("  ");
    textbackground(0);
    Locate(0,28);
    printf("                                                                                                                \n");
    Locate(0,9);
    textcolor(4);
    printf("                 #######################   ################               #######                               \n");
    Sleep(100);
    printf("                 #######################   #################             ########                               \n");
    Sleep(100);
    printf("                 #######################   #####         ####           #########                               \n");
    Sleep(100);
    printf("                          #####            #####         ####          ###  #####                               \n");
    Sleep(100);
    printf("                          #####            #####        #####         ###   #####                               \n");
    Sleep(100);
    printf("                          #####            #################                #####                               \n");
    Sleep(100);
    printf("                          #####            ###############                  #####                               \n");
    Sleep(100);
    printf("                          #####            #####                            #####                               \n");
    Sleep(100);
    printf("                          #####            #####                            #####                               \n");
    Sleep(100);
    printf("                          #####            #####                            #####                               \n");
    Sleep(100);
    printf("                          #####            #####                            #####                               \n");
    Sleep(100);
    printf("                          #####            #####                         ##########                             \n");
    Sleep(100);
    printf("                          #####            #####                         ##########                             \n");

    Sleep(2000);

    system("color D3");
    system("mode 112, 30");
    textbackground(0);
    gotoxy(1,1);
    printf("                                                                                                                \n");
    textcolor(WHITE);
    gotoxy(3,3);
    printf("     ");
    gotoxy(3,4);
    printf("  ");
    gotoxy(3,5);
    printf("     ");
    gotoxy(3,6);
    printf("  ");
    gotoxy(3,7);
    printf("     ");
    gotoxy(9,3);
    printf("     ");
    gotoxy(9,4);
    printf("  ");
    gotoxy(9,5);
    printf("     ");
    gotoxy(12,6);
    printf("  ");
    gotoxy(9,7);
    printf("     ");
    gotoxy(15,3);
    textcolor(BLUE);
    printf("OO");
    textcolor(WHITE);
    gotoxy(15,4);
    printf("");
    gotoxy(15,5);
    printf("  ");
    gotoxy(15,6);
    printf("  ");
    gotoxy(15,7);
    printf("  ");
    textbackground(0);
    Locate(0,28);
    printf("                                                                                                                \n");
    Locate(0,9);
    //textbackground(7);
    textcolor(4);
    printf("    ################    #####                    ##################  ###############   ###############          \n");
    Sleep(100);
    printf(" ###################### #####                   ##################   ####  ############  ########   ######      \n");
    Sleep(100);
    printf(" #####            ##### #####                  #####                 ####           #####             #####     \n");
    Sleep(100);
    printf(" #####            ##### #####                  #####                 ####             ####              ####    \n");
    Sleep(100);
    printf(" #####            ##### #####                  #####                 ####             ####              ####    \n");
    Sleep(100);
    printf(" #####            ##### #####                  #####                 ####             ####              ####    \n");
    Sleep(100);
    printf(" #####            ##### #####                  #####                 ####             ####              ####    \n");
    Sleep(100);
    printf(" #####            ##### #####                  #####                 ####             ####              ####    \n");
    Sleep(100);
    printf("   ##################   #####                  #####                 ####             ####              ####    \n");
    Sleep(100);
    printf("   ##################   #####                  ###################   ####             ####              ####    \n");
    Sleep(100);
    printf(" #####            ##### #####                    ##################  ####             ####              ####    \n");
    Sleep(100);
    printf(" #####            ##### #####                     ################## ####             ####              ####    \n");
    Sleep(100);
    printf(" #####            ##### #####                                  ##### ####             ####              ####    \n");
    Sleep(100);
    printf(" #####            ##### #####                                  ##### ####             ####              ####    \n");
    Sleep(100);
    printf(" #####            ##### #####                                  ##### ####             ####              ####    \n");
    Sleep(100);
    printf(" #####            ##### #####                                  ##### ####             ####              ####    \n");
    Sleep(100);
    printf(" #####            ##### #####                                  ##### ####             ####              ####    \n");
    Sleep(100);
    printf(" #####            ##### #####################                  ##### ####            ####              ####     \n");
    Sleep(100);
    printf(" #####            ##### #####################  ####################  ####  ############  ########   ######      \n");
    Sleep(100);
    printf(" #####            ##### ##################### ####################   ###############   ###############          \n");
    Sleep(2000);
    system("color D3");
    system("mode 112, 30");
    textbackground(0);
    gotoxy(1,1);
    printf("                                                                                                                \n");
    textcolor(WHITE);
    gotoxy(3,3);
    printf("     ");
    gotoxy(3,4);
    printf("  ");
    gotoxy(3,5);
    printf("     ");
    gotoxy(3,6);
    printf("  ");
    gotoxy(3,7);
    printf("     ");
    gotoxy(9,3);
    printf("     ");
    gotoxy(9,4);
    printf("  ");
    gotoxy(9,5);
    printf("     ");
    gotoxy(12,6);
    printf("  ");
    gotoxy(9,7);
    printf("     ");
    gotoxy(15,3);
    textcolor(BLUE);
    printf("OO");
    textcolor(WHITE);
    gotoxy(15,4);
    printf("");
    gotoxy(15,5);
    printf("  ");
    gotoxy(15,6);
    printf("  ");
    gotoxy(15,7);
    printf("  ");
    textbackground(0);
    Locate(0,28);
    printf("                                                                                                                \n");
    Locate(0,9);
    textcolor(4);
    printf("       ________________                                           ############      ######    ############      \n");
    Sleep(100);
    printf("      |                |                                          ##############  ##########  ##############    \n");
    Sleep(100);
    printf("      |  ____    ____  |                                          ####      ##### ##      ##  ####      #####   \n");
    Sleep(100);
    printf("      |                |                 ___________     /%c       ####       #### ##      ##  ####       ####   \n",92);
    Sleep(100);
    printf("      |  ____    ____  |                |           |   /  %c      ####       #### ##      ##  ####       ####   \n",92);
    Sleep(100);
    printf("      |                |                |  ____     |  /    %c     ####       #### ##      ##  ####       ####   \n",92);
    Sleep(100);
    printf("      |  ____    ____  |________________|           | /      %c    ##############  ##      ##  ##############    \n",92);
    Sleep(100);
    printf("      |                |                |           |/        %c   ############    ##      ##  ############      \n",92);
    Sleep(100);
    printf("      |  ____    ____  |  ____    ____  |     ____  |__________%c  ####            ##      ##  ####              \n",92);
    Sleep(100);
    printf("      |                |                |           |          |  ####            ##      ##  ####              \n");
    Sleep(100);
    printf("      |  ____    ____  |  ____    ____  |           |  _    _  |  ####            ##      ##  ####              \n");
    Sleep(100);
    printf("      |                |                |  ____     | |_|  |_| |  ####            ##      ##  ####              \n");
    Sleep(100);
    printf("      |  ____    ____  |  ____    ____  |           |          |  ####            ##      ##  ####              \n");
    Sleep(100);
    printf("      |                |                |     ____  |          |  ####            ##      ##  ####              \n");
    Sleep(100);
    printf("      |      __        |      __        |      _    |    _     |  ####            ##########  ####              \n");
    Sleep(100);
    printf("      |     |  |       |     |  |       |     | |   |   | |    |  ####              ######    ####              \n");
    Sleep(100);
    printf("      |_____|__|_______|_____|__|_______|_____|_|___|___|_|____|_____________________________                   \n");
    Sleep(100);
    printf("                                                                                                                \n");
    Sleep(100);
    printf("       |GESTION  DE LA POPULATION ALGERIENNE   POP |                                                            \n");
    Sleep(100);
    printf("                                                                                                                \n");
    Sleep(3000);
}
/*-----------------------LES MODULE QUI FAIRE LA MOVIE DE L ECRAN AU FIN-----------*/
void movie_f()
{

    system("color D3");
    system("mode 112, 30");
    textbackground(0);
    gotoxy(1,1);
    printf("                                                                                                                \n");
    textcolor(WHITE);
    gotoxy(3,3);
    printf("     ");
    gotoxy(3,4);
    printf("  ");
    gotoxy(3,5);
    printf("     ");
    gotoxy(3,6);
    printf("  ");
    gotoxy(3,7);
    printf("     ");
    gotoxy(9,3);
    printf("     ");
    gotoxy(9,4);
    printf("  ");
    gotoxy(9,5);
    printf("     ");
    gotoxy(12,6);
    printf("  ");
    gotoxy(9,7);
    printf("     ");
    gotoxy(15,3);
    textcolor(BLUE);
    printf("OO");
    textcolor(WHITE);
    gotoxy(15,4);
    printf("");
    gotoxy(15,5);
    printf("  ");
    gotoxy(15,6);
    printf("  ");
    gotoxy(15,7);
    printf("  ");
    textbackground(0);
    Locate(0,28);
    printf("                                                                                                                \n");
    Locate(0,8);
    textcolor(4);
    printf("                                                                                                                \n");
    printf("                                                                                                                \n");
    printf(" ############     ########## ################## #############              ###############    OOOO              \n");
    printf(" ############     ########## ################## ##############          ##################    OOOO              \n");
    printf(" ############     ########## ####               ####       ####       ####                                      \n");
    printf("  ##### ####       ########  ####               ####        ####     ####                     ####              \n");
    printf("  #####  ####     #### ####  ####               ####        ####    ####                      ####              \n");
    printf("  #####   ####   ####  ####  ####               ####        ####   ####                       ####              \n");
    printf("  #####    #### ####   ####  ####               ####       ####   ####                        ####              \n");
    printf("  #####     #######    ####  ###############    ####      ####    ####                        ####              \n");
    printf("  #####      #####     ####  ###############    ############      ####                        ####              \n");
    printf("  #####       ###      ####  ####               ####    ####      ####                        ####              \n");
    printf("  #####                ####  ####               ####     ####     ####                        ####              \n");
    printf("  #####                ####  ####               ####      ####     ####                       ####              \n");
    printf("  #####                ####  ####               ####       ####     ####                      ####              \n");
    printf("  #####                ####  ####               ####        ####     ####                     ####              \n");
    printf("  #####                ####  ####               ####         ####     ####                    ####              \n");
    printf("  #####                ####  ################## ####          ####      ##################    ####              \n");
    printf("  #####                ####  ################## ####           ####        ###############    ####              \n");
    printf("                                                                                                                \n");
    Sleep(2000);
}
