#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LOV_C_machine_abstraite.h"
#include "TOVC_machine_abstrait.h"
#include "LOVC_machine_abstraite.h"
#include "TOF_machine_abstraite.h"
#include "Modules_Affichage_Structures.h"

Buffer      buf;//Ouvrages.bin
Buffer_TOVC buf1;//livres.bin
Buffer_LOVC buf2;//memoires.bin
Buffer_TOVC buf3;//articles.bin
TOFBuffer   buf4;//periodiques.bin
int C1;
int C2;
int C3;
int C4;
int C51;
int C52;
int C53;
int C54;
int C6;
int C7;
int C8;

/* lire la table d'index du fichier 'nomFichier' et la mettre dans 'index' */
void lireIndex(Index *index, char nomFichier[])
{
    FILE *f = fopen(nomFichier, "rb+");

    if(f != NULL)
    {
        fread(index, sizeof(Index), 1, f);
    }

    fclose(f);
}


void ecrireIndex(Index *index, char nomFichier[])
{
    FILE *f = fopen(nomFichier, "wb+");

    if(f != NULL)
    {
        fwrite(index, sizeof(Index), 1, f);
    }

    fclose(f);
}

/* *****************- MODULE POUR CRIER UNE TABLE DES IDENTIFIANTES ALEATOIRES -******************/
/*
taille:c'est la taille du tableau ou dans notre cas c'est un nombre aleatoire//nb_ouvrages

*/
void creation_table_identifiantes(int *taille,int tmp_table[])
{
    int i,j,k,temp;
    for (i=0; i<(*taille); i++) //boucle de generation
    {
        tmp_table[i]=Aleanombre(9999);  //le nombre maximum d'un identifiant est 9999
    }
    for (i=0; i<(*taille); i++)//boucle de la supprition des reputitions
    {

        for (j=i+1; j<(*taille);)
        {
            if (tmp_table[i]==tmp_table[j])
            {
                for (k=j; k<(*taille); k++)
                {
                    tmp_table[k]=tmp_table[k+1];
                }
                (*taille)--;
            }
            else
            {
                j++;
            }
        }
    }
    for (i=0; i<(*taille); i++)//boucle du triage
    {

        for (j=0; j<(*taille); j++)
        {

            if (tmp_table[j]>tmp_table[j+1])
            {
                temp=tmp_table[j];
                tmp_table[j]=tmp_table[j+1];
                tmp_table[j+1]=temp;
            }
        }
    }
}
/* *****************- MODULE DE CREATION DU FICHIER  LOV~C -******************/
void creation_fichier_LOV_C(LOV_C **fichier)
{
    /*---------------------------*/
    int  nb_ouvrages_au_debut;
    int cle_entier,somme_des_tailles_entier,disponible_entier,type_entier,annee_publication_entier;
    int taille_chaine_titre,taille_chaine_auteur,taille_chaine_cote,taille_chaine_resume;

    char cle_char[4],somme_des_tailles_char[3],disponible_char[1],type_char[1],annee_publication_char[4];

    int nb_globale_inseres=0,nbblocs=0,j=0,compteur_nb_caracteres_chaque_bloc=0;
    Ouvrage Ouvrage_crier; //L'ARTUCLE QUE ON UTILISE TEMPOREREMENT
    int i;   //COMPTEUR POUR ARRETER LA BOUCLE
    int I0,I1; //ADRESSE BLOC
    C1=0;

    int taille_table;
    int tmp_table[1024];//car il
    taille_table = 150;//Aleanombre(60 );// ENTRE 1 ET 60 ARTUCLE AU DEBUT i.e: COMBIEN PEUT ON ECRIRE EN DEBUT
    creation_table_identifiantes(&taille_table,tmp_table);

    /*---------------------------*/
    nb_ouvrages_au_debut =taille_table;
    ouvrir(fichier,"Ouvrages.bin",'n');
    I0= entete(*fichier,1);
    for(    i=0 ;   i < nb_ouvrages_au_debut   ;   i++ )
    {
        /*DES VALEURS ENTIER ET NOUS DOIT TRANSFORMER EN CHAINE POUR L'ECRIRE */
        cle_entier=tmp_table[i];
        disponible_entier=Aleanombre(2);
        type_entier= 1 + Aleanombre(4) ; //SOIT 1 2 3 4
        annee_publication_entier= 1950 + Aleanombre(71);  // 2021-1950 = 71   PUISQUE L'AMPLUTIDE D'INTERVALE [1950;2021]
        taille_chaine_titre=10+Aleanombre(15);  // MIN=10 CARACTERES , MAX=25 CARACTERES
        taille_chaine_auteur=10+Aleanombre(15); // MIN=10 CARACTERES , MAX=25 CARACTERES  POUR DES RAISONS D'AFFICHAGE
        taille_chaine_cote=10+Aleanombre(15);   // MIN=10 CARACTERES , MAX=25 CARACTERES
        taille_chaine_resume=5+Aleanombre(905); // MIN=10 CARACTERES , MAX=1000 CARACTERES
        somme_des_tailles_entier=4+3+1+1+1+4+taille_chaine_titre+1+taille_chaine_auteur+1+taille_chaine_cote+1+taille_chaine_resume+1;
        //SOMME DU TAILLE DES CHAMPS:IDENTIFIANT+TAILLE+EFFACE+DISPONIBLE+TYPE+ANNE+TITRE+$+AUTEUR+$+COTE+$+RESUME
        /*
        |-------------|--------|--------|------------|------|------|-------|---|--------|---|------|---|--------|----|
        | IDENTIFIANT | TAILLE | EFFACE | DISPONIBLE | TYPE | ANNE | TITRE | $ | AUTEUR | $ | COTE | $ | RESUME | $  |
        |_____________|________|________|____________|______|______|_______|___|________|___|______|___|________|____|
        */
        /*la transformation ENTIER-->CHAINE */
        int_vers_string(cle_char,cle_entier,4); //IDENTIFIANT<=>CLE
        //  char cle_char1=cle_char;
        int_vers_string(annee_publication_char,annee_publication_entier,4);
        //   char annee_publication_char1=annee_publication_char;
        //TEST printf("\ncle :%s ",cle_char );
        int_vers_string(somme_des_tailles_char,somme_des_tailles_entier,3);
        //   char somme_des_tailles_char1=somme_des_tailles_char;
        int_vers_string(disponible_char,disponible_entier,1);
        //  char disponible_char1=disponible_char;
        int_vers_string(type_char,type_entier,1);
        //  char type_char1=type_char;
        /*AFFECTATION EN UN OUVRAGE */
        strcpy(Ouvrage_crier.Identifiant, cle_char);
        strcpy(Ouvrage_crier.Taille, somme_des_tailles_char);
        strcpy(Ouvrage_crier.Efface, "0");      //VALEUR INITIAL
        strcpy(Ouvrage_crier.Disponible, disponible_char  );
        strcpy(Ouvrage_crier.Type, type_char);             // SEULEMENT  1U2U3U4
        strcpy(Ouvrage_crier.Anne, annee_publication_char );
        //printf("\ncle :%s ",Ouvrage_crier.Anne );
        char titre_chaine[taille_chaine_titre];
        Aleachaine(titre_chaine, taille_chaine_titre);
        strcpy(Ouvrage_crier.Titre, titre_chaine);

        char auteur_chaine[taille_chaine_auteur];
        Aleachaine(auteur_chaine, taille_chaine_auteur);
        strcpy(Ouvrage_crier.Auteur, auteur_chaine );

        char cote_chaine[taille_chaine_cote];
        Aleachaine(cote_chaine, taille_chaine_cote);
        strcpy(Ouvrage_crier.Cote, cote_chaine );

        char resume_chaine[taille_chaine_resume];
        Aleachaine(resume_chaine, taille_chaine_resume);
        strcpy(Ouvrage_crier.Resume, resume_chaine );
        // printf("\n ---%s -----\n",resume_chaine);
        /*---------------------------*/
        compteur_nb_caracteres_chaque_bloc = somme_des_tailles_entier + compteur_nb_caracteres_chaque_bloc;
        if (compteur_nb_caracteres_chaque_bloc<=MAX_CAR)
        {
            //TEST  buf.tab <-- ouvrage   //printf("%d\n",compteur_nb_caracteres_chaque_bloc );
            ecrire_chaine( 4, &j, Ouvrage_crier.Identifiant, &buf);
            ecrire_chaine( 3, &j,Ouvrage_crier.Taille, &buf);
            ecrire_chaine( 1, &j,Ouvrage_crier.Efface, &buf);
            ecrire_chaine( 1, &j,Ouvrage_crier.Disponible, &buf);
            ecrire_chaine( 1, &j,Ouvrage_crier.Type, &buf);
            ecrire_chaine( 4, &j,Ouvrage_crier.Anne, &buf);
            ecrire_chaine( taille_chaine_titre, &j,Ouvrage_crier.Titre, &buf);
            ecrire_chaine( 1, &j,"$", &buf);   //SEPARATEUR ENTRE LES CHAMPS VARIABLES
            ecrire_chaine( taille_chaine_auteur, &j,Ouvrage_crier.Auteur, &buf);
            ecrire_chaine( 1, &j,"$", &buf);   //SEPARATEUR ENTRE LES CHAMPS VARIABLES
            ecrire_chaine( taille_chaine_cote, &j,Ouvrage_crier.Cote, &buf);
            ecrire_chaine( 1, &j,"$", &buf);   //SEPARATEUR ENTRE LES CHAMPS VARIABLES
            ecrire_chaine( taille_chaine_resume, &j,Ouvrage_crier.Resume, &buf);
            ecrire_chaine( 1, &j,"#", &buf);   //SEPARATEUR ENTRE LES CHAMPS VARIABLES
            /*---------------------------*/
            buf.nb =compteur_nb_caracteres_chaque_bloc;
        }
        else
        {
            I1 = allocBloc(*fichier);
            buf.suivant= I1;
            ecrireDir(*fichier,I0,&buf);
            C1++;
            //printf("bloc crier ok \n");//TEST
            nb_globale_inseres = buf.nb + nb_globale_inseres;
            nbblocs ++;
            I0=I1;
            compteur_nb_caracteres_chaque_bloc=somme_des_tailles_entier;//POUR NE PAS ECRAZER
            j=0;
            //TEST  //printf("%d\n",compteur_nb_caracteres_chaque_bloc );
            ecrire_chaine( 4, &j, Ouvrage_crier.Identifiant, &buf);
            ecrire_chaine( 3, &j,Ouvrage_crier.Taille, &buf);
            ecrire_chaine( 1, &j,Ouvrage_crier.Efface, &buf);
            ecrire_chaine( 1, &j,Ouvrage_crier.Disponible, &buf);
            ecrire_chaine( 1, &j,Ouvrage_crier.Type, &buf);
            ecrire_chaine( 4, &j,Ouvrage_crier.Anne, &buf);
            ecrire_chaine( taille_chaine_titre, &j,Ouvrage_crier.Titre, &buf);
            ecrire_chaine( 1, &j,"$", &buf);   //SEPARATEUR ENTRE LES CHAMPS VARIABLES
            ecrire_chaine( taille_chaine_auteur, &j,Ouvrage_crier.Auteur, &buf);
            ecrire_chaine( 1, &j,"$", &buf);   //SEPARATEUR ENTRE LES CHAMPS VARIABLES
            ecrire_chaine( taille_chaine_cote, &j,Ouvrage_crier.Cote, &buf);
            ecrire_chaine( 1, &j,"$", &buf);   //SEPARATEUR ENTRE LES CHAMPS VARIABLES
            ecrire_chaine( taille_chaine_resume, &j,Ouvrage_crier.Resume, &buf);
            ecrire_chaine( 1, &j,"#", &buf);   //SEPARATEUR ENTRE LES CHAMPS VARIABLES
            /*---------------------------*/
            buf.nb =compteur_nb_caracteres_chaque_bloc;
            buf.suivant= -1;
        }
    }
    ecrireDir(*fichier, I0,&buf);
    C1++;
    nb_globale_inseres = buf.nb + nb_globale_inseres;
    nbblocs ++;
    aff_entete(*fichier, 2, nb_globale_inseres);
    aff_entete(*fichier, 3, 0);
    aff_entete(*fichier, 4, nbblocs);
    fermer(*fichier);
}


int C2 = 0;//le cout de la recherche
int C3 = 0;//le cout de l'insertion

/* extraire de 'buf' la chaine 'chaine' de taille 'n'
 * à partir de la position 'i' */
void extraire(char chaine[], int n, int* i)
{
    for(int j = 0; j < (n-1); j++)
    {
        chaine[j] = buf.tab[(*i)];
        (*i)++;
    }

    chaine[n-1] = '\0';
}


/* recherche dans le fichier  'f' l'ouvrage
 * identifié par 'cle', s'il existe 'touve' est egal  à 1
 * 'i' le numéro du bloc et 'j' l'indice du début de l'ouvrage
 * sinon, 'touve' est egal à 0  et 'i' est le numero du bloc où l'ouvrage
 * avec 'cle' doit etre inséré et 'j' est l'indice dans le bloc */
void recherche(LOV_C *f, int cle, int* trouve, int* i, int* j)
{
    *trouve = 0;
    *i = entete(f, 1);
    *j = 0;
    int jSauv;
    char taille[4];
    char identifiant[5];
    char efface;

    lireDir(f, *i, &buf);
    C4++;
    C2 = 1;//car 1er accès au fichier
    jSauv = *j;
    extraire(identifiant, 5, j);
    efface = buf.tab[*j + 3];

    while( atoi(identifiant) < cle)
    {
        extraire(taille, 4, j);
        *j = (*j) + atoi(taille) - 7;

        if( (*j) >= buf.nb )  //si on a depassé le nombre de caratères insérés dans le bloc
        {

            if(buf.suivant != -1)
            {
                *i = buf.suivant;
                *j = 0;
                lireDir(f, *i, &buf);
                C2++;
                C4++;
            }
            else
            {
                break;
            }
        }
        jSauv = *j;
        extraire(identifiant, 5, j);
        efface = buf.tab[*j + 3];
    }

    if(cle == atoi(identifiant) && efface == '0')
    {
        (*trouve) = 1;
    }
    if( atoi(identifiant) < cle)
    {
        extraire(taille, 4, j);
        *j = (*j) + atoi(taille) - 3;
        jSauv = *j;
    }
    *j = jSauv;
}


/* insérer 'ouvrage' dans le fichier 'f'
 * 'taille' est la taille de 'ouvrage' */
void insertion(LOV_C *f, char ouvrage[], int taille)
{
    int i, j, trouve, suivant;
    char cle[5];
    int k;
    char* tmpData;
    int tmpTaille;

    strncpy(cle, ouvrage, 4);//RECUPERER LA CLé
    cle[4] = '\0';

    recherche(f, atoi(cle), &trouve, &i, &j);
    C3 = C2;//LE COUT DE LA RECHERCHE

    if(trouve == 0)  //L'OUVRAGE N'EXISTE PAS DONC ON PEUT L'INSERER
    {
        lireDir(f, i, &buf);
        C3++;


        if(taille <= (MAX_CAR - buf.nb) )  //IL Y A ASSEZ D'ESPACE DANS LE BLOC
        {

            tmpTaille = buf.nb - j;
            if(tmpTaille > 0)
            {
                tmpData = malloc(sizeof(char) * tmpTaille);//RESERVER UNE CHAINE TEMPORAIRE POUR SAUVEGARDER LES DONNéES EXISTANTES
            }

            for(k = 0; k < tmpTaille; k++)  //SAUVEGARDER LES DONNéES EXISTANTES DANS UNE CHAINE TEMPORAIRE
            {
                tmpData[k] = buf.tab[j + k];
            }


            for(k = 0; k < taille; k++)  //INSERER LE NOUVEAU OUVRAGE
            {
                buf.tab[j] = ouvrage[k];
                j++;
            }

            for(k = 0; k < tmpTaille; k++)
            {
                buf.tab[j] = tmpData[k];
                j++;
            }

            buf.nb += taille;
            ecrireDir(f, i, &buf);
            C3++;
        }
        else  //il n'y a pas assez d'espace dans le bloc
        {
            //exemple
            //on suppose le bloc peut contenir 1000
            //etat initiale
            // 500 (remplie) + (nouveau ouvrage doit etre ici 900) 300(remplie [ancien data]) + 200(libre)
            //la suite

            //etat finale
            //500 + 500(libre)
            //900(nouveau) + 100(libre) [nouveau bloc]
            //300 (ancien) + 700(libre) [nouveau bloc]
            //la suite

            tmpTaille = buf.nb - j;
            if(tmpTaille > 0)
            {
                tmpData = malloc(sizeof(char) * tmpTaille);//RESERVER UNE CHAINE TEMPORAIRE POUR SAUVEGARDER LES DONNéES EXISTANTES
            }

            for(k = 0; k < tmpTaille; k++)  //SAUVEGARDER LES DONNéES EXISTANTES DANS UNE CHAINE TEMPORAIRE
            {
                tmpData[k] = buf.tab[j + k];
            }

            suivant = buf.suivant;
            buf.suivant = allocBloc(f);//ALLOUER UN NOUVEAU BLOC ET FAIRE LE CHAINAGE
            buf.nb -= tmpTaille;//CAR ON VA DEPLACER LES DONNéES EXISTANTS DANS UN NOUVEAU BLOC
            if(buf.nb > 0)
            {
                ecrireDir(f, i, &buf);//ECRIRE L'ANCIEN BLOC
                C3++;

                i = buf.suivant;

                for(k = 0; k < taille; k++)
                {
                    buf.tab[k] = ouvrage[k];
                }

                buf.nb = taille;
            }
            else  //DANS LE CAS Où LE NOUVEAU OUVRAGE DOIT éTRE INSéRé AU DEBUT
            {
                for(k = 0; k < taille; k++)
                {
                    buf.tab[j + k] = ouvrage[k];
                }

                buf.nb = taille;
            }

            if(tmpTaille <= (MAX_CAR - buf.nb))  //S'IL Y A ASSEZ D'ESPACE DANS LE NOUVEAU BLOC POUR METTRE LES DONNéES DéJA EXISTANTES DANS LE BLOC PRECEDANT
            {
                j = buf.nb;

                for(k = 0; k < tmpTaille; k++)  //ECRIRE LES DONNéES EXISTANTES APRèS LE NOUVEAU OUVRAGE
                {
                    buf.tab[j] = tmpData[k];
                    j++;
                }

                if(tmpTaille > 0)
                {
                    buf.nb += tmpTaille;
                }

                buf.suivant = suivant;//FAIRE LE CHAINAGE
                ecrireDir(f, i, &buf);
                C3++;
            }
            else  //S'IL N'Y A PAS ASSEZ D'ESPACE DANS LE NOUVEAU BLOC POUR ECRIRE LES DONNéES EXISTANTES
            {
                buf.suivant = allocBloc(f);//ON ALLOUE UN AUTRE BLOC ET ON FAIT LE CHAINAGE
                ecrireDir(f, i, &buf);
                C3++;
                i = buf.suivant;

                for(k = 0; k < tmpTaille; k++)
                {
                    buf.tab[k] = tmpData[k];
                }

                if(tmpTaille > 0)
                {
                    buf.nb = tmpTaille;
                }

                buf.suivant = suivant;
                ecrireDir(f, i, &buf);
                C3++;
            }
        }

        aff_entete(f, 2, entete(f, 2) + taille);
        if(tmpData != NULL)
            free(tmpData);//LIBERER LA CHAINE TEMPORAIRE

        printf("L'ouvrage a ete insere\n");
    }
    else
    {
        printf("L'ouvrage existe deja!\n");
    }

}

/* *****************- MODULE POUR MODIFIER LA DISPONIBILITER -******************/
void modifier_diponibiliti_LOV_C(LOV_C **fichier)
{
    int cle,dispon;
    C4 =0;
    int trouve, i, j;
    printf("\n\nENTRER LA  CLE DE L'OUVRAGE A MODIFIER:");
    scanf("%d", &cle);
    printf("\nDISPONIBLE 1   / INDISPONIBLE 0 (0/1):");
    scanf("%d", &dispon);
    if (dispon==1)//METTRE L'OUVRAGE DISPONIBLE
    {
        ouvrir(fichier,"Ouvrages.bin", 'A');
        recherche(*fichier, cle, &trouve, &i, &j);
        lireDir(*fichier,i,&buf);
        C4++;
        buf.tab[j+8]='1'; //METTRE A JOUR LA POSITION 8 DE L'ARTUCLE (OU LE CHAMP DISPONIBLE)
        ecrireDir(*fichier,i,&buf);
        C4++;
        fermer(*fichier);
    }
    else if  (dispon==0)//METTRE L'OUVRAGE INDISPONIBLE
    {
        ouvrir(fichier,"Ouvrages.bin", 'A');
        recherche(*fichier, cle, &trouve, &i, &j);
        lireDir(*fichier,i,&buf);
        C4++;
        buf.tab[j+8]='0';//METTRE A JOUR LA POSITION 8 DE L'ARTUCLE  (OU LE CHAMP DISPONIBLE)
        ecrireDir(*fichier,i,&buf);
        C4++;
        fermer(*fichier);
    }
    else
    {
        printf("\n\nLE CHOIX N'EST PAS VALIDE!");
    }
}

/* creer leS fihcier : 'Livres.bin','Memoires.bin','Articles.bin','Periodiques.bin'à partir
 * du fichier 'Ouvrages.bin'
 * 'fichier1' est 'Ouvarges.bin'
 * fichier_TOVC_Livres est 'Livres.bin'
 * fichier_Memoires est 'Memoires.bin'
 * fichier_TOVC_Articles est 'Articles.bin'
 * 'fichier2' est 'Periodiques.bin'*/
void creer_Fichiers(LOV_C **fichier1,TOVC **fichier_TOVC_Livres,LOVC **fichier_Memoires,TOVC **fichier_TOVC_Articles, TOF **fichier2)
{
    int i,i1,i2,i3,i4,i_2;
    int j,j1,j2,j3,j4;
    int jSauv;//POUR SAUVGARDER j
    int sau;//pour sauvgarder j1 ou j3
    int nbPeriodiques = 0;
    int nbBlocs = 0;
    char taille[4];
    char numero[5];
    char annee[5];
    int inc,k;//INC POUR FAIRE LES BOUCLES DE REMPLISSAGE DES BUFFERS
    int nbblocs=0;
    int inseres_fichier_memoire=0;//UN COMPTEUR DE NOMBRE DES CARACTERES INSERER DANS UN BLOC DU FICHIER Memoires

    ouvrir      (fichier1,"Ouvrages.bin",'A'   );
    Ouvrir_TOVC (fichier_TOVC_Livres,"Livres.bin",'N'   );
    ouvrir_LOVC (fichier_Memoires,"Memoires.bin",'N'   );
    Ouvrir_TOVC (fichier_TOVC_Articles,"Articles.bin",'N'   );
    ouvrirTOF   (fichier2,"Periodiques.bin",'N'   );

    i = entete(*fichier1, 1);//i est le numero de bloc actuel dans fichier1
    i1=0;       //  est nouveaux bloc
    i2= enteteLOVC(*fichier_Memoires,1);//LA TETE DU FICHIER memoires.bin
    i3=0;
    i4 = 1;//i4 est le numero de bloc actuel dans fichier2

    j  = 0; //indice de caractère dans buf.tab
    j1 = 0; //indice de livre dans buf1.tab
    j2 = 0; //indice de memoire dans buf2.tab
    j3 = 0; //indice de article dans buf3.tab
    j4 = 0; //indice de periodique dans buf4.tab

    C51=0;
    C52=0;
    C53=0;
    C54 = 0; //INITIALISATION LES COUTS DE CHARGEMENT DE CHAQUE FICHIER DE FRAGMENTATION
    buf4.nb = 0;

    while(i != -1)
    {
        lireDir(*fichier1, i, &buf);
        //ON INCREMNETE TOUS LES COMPTEURS DES FICHIERS CAR CETTE LECTURE EST NECESSAIRE POUR LA CREATION DES 4 FICHIERS
        C54++;
        C51++;
        C52++;
        C53++;


        while(j < buf.nb)
        {
            jSauv = j;

            if(buf.tab[j + 9] == '4')  //si le type == 4 donc c'est une périodique
            {
                extraire(numero, 5, &j);//recuperer le champ 'numero'
                buf4.tab[j4].numero = atoi(numero);

                extraire(taille, 4, &j);//recuperer la taille

                j++;//pour se positioner au champ 'disponible'

                if(buf.tab[j] == '0')  //recuperer le champ 'disponible'
                {
                    buf4.tab[j4].disponible = 0;
                }
                else if(buf.tab[j] == '1')
                {
                    buf4.tab[j4].disponible = 1;
                }


                j += 2;
                extraire(annee, 5, &j);//recuperer le champ 'année'
                buf4.tab[j4].annee = atoi(annee);

                k = 0;//recuperer le champ 'titre'
                while(buf.tab[j] != '$')
                {
                    buf4.tab[j4].titre[k] = buf.tab[j];
                    j++;
                    k++;
                }

                buf4.tab[j4].titre[k] = '\0';

                j += 1;
                k = 0;//recuperer le champ 'auteur'
                while(buf.tab[j] != '$')
                {
                    buf4.tab[j4].auteur[k] = buf.tab[j];
                    j++;
                    k++;
                }


                buf4.nb++;//incrementer le nombre de periodiques dans le bloc
                nbPeriodiques++;//incrementer le nombre totale de periodiques écrites
                j4++;//passer à la prochaine case dans le tableau

                if(buf4.nb == B)  //si ce bloc est remplie, on l'ecrit dans fichier2
                {
                    ecrireDirTOF(*fichier2, i4, &buf4);
                    C54++;
                    buf4.nb = 0;
                    j4 = 0;
                    i4++;//passer au prochain bloc
                    nbBlocs++;//incrementer le nombre totale de blocs écrits
                }
            }
            else
            {
                if (buf.tab[j + 9] == '1')
                {
                    //si le type == 2 donc c'est un livre
                    sau=j;
                    extraire(numero, 5, &j);
                    extraire(taille, 4, &j);
                    j=sau;
                    for (inc=0; inc<atoi(taille); inc++)
                    {
                        j1++;
                        if (inc==9)//CETTE CONDITION EST POUR ELIMINER LE CHAMP TYPE
                        {
                            j1--;
                        }
                        else//AFFECTATION DE TOUT LES CHAMPS SAUF LE CHAMP DISPONIBLE
                        {
                            buf1.tab[j1]=buf.tab[j];
                        }
                        j++;
                        if (j1==MAX_CAR)//SI LE BUFFER BLOC EST PLEIN ,ON L-ECRIRE
                        {
                            j1=0;
                            i1++;
                            Ecriredir_TOVC(*fichier_TOVC_Livres,i1,&buf1);
                            C51++;
                        }
                    }
                }

                else
                {

                    if (buf.tab[j + 9] == '3')
                    {
                        //si le type == 3 donc c'est un article
                        sau=j;
                        extraire(numero, 5, &j);
                        extraire(taille, 4, &j);
                        j=sau;
                        int nbdolars=0;
                        for (inc=0; inc<atoi(taille); inc++)
                        {
                            j3++;
                            if (buf.tab[j]=='$')
                            {
                                nbdolars++;
                            }
                            if (buf.tab[j]=='$' && nbdolars==2)//CETTE BOUCLE EST POUR ELIMINER LE CHAMP COTE
                            {
                                sau=j;
                                j++;
                                while (buf.tab[j]!='$')
                                {
                                    j++;
                                }
                                inc+=(j-sau);
                            }

                            if (inc==9)//POUR ELIMINER LE CHAMP DISPONIBLE
                            {
                                j3--;
                            }
                            else
                            {
                                buf3.tab[j3]=buf.tab[j];
                            }
                            j++;
                            if (j3==MAX_CAR)
                            {
                                j3=0;
                                i3++;
                                Ecriredir_TOVC(*fichier_TOVC_Articles,i3,&buf3);
                                C53++;
                            }
                        }
                    }
                    else
                    {
                        if(buf.tab[j + 9] == '2')  //si le type == 2 donc c'est un memoire
                        {
                            sau=j;
                            extraire(numero, 5, &j);
                            extraire(taille, 4, &j);
                            j=sau;
                            for (inc=0; inc<atoi(taille); inc++)
                            {
                                j2++;
                                if (inc==9)//POUR ELIMINER LE CHAMP DISPONIBLE
                                {
                                    j2--;
                                }
                                else
                                {
                                    buf2.tab[j2]=buf.tab[j];
                                }
                                buf2.nb =j2;
                                j++;
                                if (j2==MAX_CAR)
                                {

                                    i_2 = allocBloc_LOVC(*fichier_Memoires);
                                    buf2.suivant= i_2;
                                    ecrireDir_LOVC(*fichier_Memoires,i2,&buf2);
                                    C52++;
                                    inseres_fichier_memoire+=j2;
                                    nbblocs ++;
                                    i2=i_2;
                                    j2=0; //nb inseres en chaque bloc
                                    buf2.suivant= -1;
                                }
                            }
                        }
                        else  //si cet ouvrage n'est pas un des cas passees
                        {
                            j += 4;
                            extraire(taille, 4, &j);//recuperer la taille de cet ouvrage
                        }
                    }
                }
            }
            j = jSauv;
            j += atoi(taille);//sauter cet ouvrage
        }
        i = buf.suivant;//passer au bloc suivant dans fichier1
        j = 0;
    }


    ecrireDirTOF(*fichier2, i4, &buf4);//ecrire le dernier bloc
    C54++;
    nbBlocs++;//incrementer le nombre totale de blocs écrits

    if (j1!=0)//ecriture du dernier bloc livre (les caracteres qui sont reste au dernier buf)
    {
        buf1.tab[j1+1]='\0';
        i1++;
        Ecriredir_TOVC(*fichier_TOVC_Livres,i1,&buf1);
        C51++;
    }
    if (j3!=0)//ecriture du dernier bloc article (les caracteres qui sont reste au dernier buf)
    {
        buf3.tab[j3+1]='\0';
        i3++;
        Ecriredir_TOVC(*fichier_TOVC_Articles,i3,&buf3);
        C53++;
    }

    if (j2!=0)//ecriture du dernier bloc memoires (les caracteres qui sont reste au dernier buf)
    {
        inseres_fichier_memoire+=j2;
        ecrireDir_LOVC(*fichier_Memoires, i2,&buf2);
        C52++;
        nbblocs ++;
    }
    aff_entete_LOVC(*fichier_Memoires, 2, inseres_fichier_memoire);
    aff_entete_LOVC(*fichier_Memoires, 3, nbblocs);


    aff_enteteTOF(*fichier2, 1, nbBlocs);
    aff_enteteTOF(*fichier2, 2, nbPeriodiques);

    Aff_Entete_TOVC(*fichier_TOVC_Livres, 1, i1);
    Aff_Entete_TOVC(*fichier_TOVC_Articles, 1, i3);

    fermer(*fichier1);
    fermerTOF(*fichier2);
    Fermer_TOVC(*fichier_TOVC_Articles);
    Fermer_TOVC(*fichier_TOVC_Livres);
    fermer_LOVC(*fichier_Memoires);
}


/* rechercher une periodique dans le fihcier 'Periodiques.bin'
 * 'numero' est le numero d'identification de la periodique
 * 'trouve' = 1 si la periodique recherchée existe, 0 sinon
 * 'i' est le numero de bloc de la periodique si elle existe, sinon c'est le numero de bloc où elle doit se trouver dans l'insertion
 * 'j' est l'indice dans le bloc 'i' où se trouve la periodique si elle existe, sinon c'est l'indice dans le bloc 'i' où elle doit se trouver dans l'insertion */
void recherchePeriodique(TOF **fichier, int numero, int *trouve, int *i, int *j)
{
    ouvrirTOF(fichier, "Periodiques.bin", 'a');
    *trouve = 0;
    int bs = enteteTOF(*fichier, 1);
    int bi = 1;
    int stop = 0;
    *j = 0;
    C6 = 0;

    int inf, sup;

    while(bi <= bs && *trouve == 0 && stop == 0 )  //recherche dichotomique dans tous les blocs
    {
        *i = (bi + bs) / 2;
        lireDirTOF(*fichier, *i, &buf4);
        C6++;

        if(numero >= buf4.tab[0].numero && numero <= buf4.tab[buf4.nb - 1].numero)
        {
            inf = 0;
            sup = buf4.nb - 1;

            while(inf <= sup && *trouve == 0)  //recherche dichotomique dans le bloc
            {
                *j = (inf + sup) / 2;

                if(numero == buf4.tab[*j].numero)
                {
                    *trouve = 1;
                }
                else
                {
                    if(numero < buf4.tab[*j].numero)
                    {
                        sup = *j - 1;
                    }
                    else
                    {
                        inf = *j + 1;
                    }
                }
            }

            if(inf > sup)
            {
                *j = inf;
            }

            stop = 1;
        }
        else
        {
            if(numero < buf4.tab[0].numero)
            {
                bs = *i - 1;
            }
            else
            {
                bi = *i + 1;
            }
        }
    }

    if(bi > bs)
    {
        *i = bi;
        *j = 0;
    }

    fermerTOF(*fichier);
}



void creer_index_periodiques(TOF **fichier, Index *index)
{
    ouvrirTOF(fichier, "Periodiques.bin", 'a');

    int nbBlocs = enteteTOF(*fichier, 1);
    int i;
    int j;
    int k = 0;
    index->nb = 0;
    C7 = 0;

    for(i = 1; i <= nbBlocs; i++)
    {
        lireDirTOF(*fichier, i, &buf4);
        C7++;

        for(j = 0; j < buf4.nb; j++)
        {
            index->tab[k].numero = buf4.tab[j].numero;
            index->tab[k].i = i;
            index->tab[k].j = j;
            index->nb++;
            k++;
        }
    }

    ecrireIndex(index, "Index_Periodiques.bin");
    fermerTOF(*fichier);
}




void recherche_TOF_index(TOF **fichier, Index *index, int numero, int *trouve, int *i, int *j)
{
    ouvrirTOF(fichier, "Periodiques.bin", 'a');

    int bi = 0;
    int bs = index->nb - 1;
    *trouve = 0;
    int centre;
    C8 = 0;

    while(bs >= bi && *trouve == 0)  //recherche dichotomique dans l'index
    {
        centre = (bs + bi) / 2;

        if(numero == index->tab[centre].numero)
        {
            *trouve = 1;
            *i = index->tab[centre].i;
            *j = index->tab[centre].j;
        }
        else
        {
            if(numero < index->tab[centre].numero)
            {
                bs = centre - 1;
            }
            else
            {
                bi = centre + 1;
            }
        }
    }

    if(*trouve == 1)
    {
        lireDirTOF(*fichier, *i, &buf4);
        C8++;
        printf("la periodique recherchee:\n");
        printf("numero: %d\ntitre: %s\nauteur: %s\nannee: %d\n", buf4.tab[*j].numero, buf4.tab[*j].titre, buf4.tab[*j].auteur, buf4.tab[*j].annee);
        printf("disponible: %s\n", buf4.tab[*j].disponible ? "OUI" : "NON");

    }
    else
    {
        printf("LA PERIODIQUE RECHERCHEE N'EXITSE PAS!\n");
    }
}


void lireOuvrage(char chaine[], int *taille)
{
    int identifiant, type, annee;
    char titre[25], auteur[25], cote[25], resume[930];

    do
    {
        printf("ENTREZ L'IDENTIFIANT (<= 9999):");
        scanf("%d", &identifiant);
    }
    while(identifiant > 9999);

    printf("ENTREZ LE TITRE DE L'OUVRAGE:");
    scanf("%s", titre);

    printf("ENTREZ LE(S) AUTEUR(S):");
    scanf("%s", auteur);


    do
    {
        printf("LE TYPE DE L'OUVRAGE:\n");
        printf("1-TEXT IMPRIME\n");
        printf("2-DOCUMENT ELECTRONIQUE\n");
        printf("3-ARTICLE\n");
        printf("4-PERIODIQUE\n");
        printf("ENTREZ LE NUMERO CORRESPONDANT AU TYPE:");
        scanf("%d", &type);
    }
    while(type < 1 || type > 4);


    do
    {
        printf("ENTREZ L'ANNEE DE PUBLICATION DE L'OUVRAGE (COMPRIS ENTRE 1950 ET 2021):");
        scanf("%d", &annee);
    }
    while(annee < 1950 || annee > 2021);


    printf("ENTREZ LA COTE DE L'OUVRAGE:");
    scanf("%s", cote);

    printf("ENTREZ LE RESUME DE L'OUVRAGE:");
    scanf("%s", resume);

    //taille = identifiant(4) + taille(3) + effacé(1) + disponible(1) + type(1) + annee(4) + titre + $ + auteur + $ + cote + $ + resume + $ + #
    *taille = 4 + 3 + 1 + 1 + 1 + 4 + strlen(auteur) + 1 + strlen(titre) + 1 + strlen(cote) + 1 + strlen(resume) + 1;

    sprintf(chaine, "%04d%03d01%d%d%s$%s$%s$%s#", identifiant, *taille, type, annee, titre, auteur, cote, resume);
}
