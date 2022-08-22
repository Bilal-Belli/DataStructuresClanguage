#ifndef MODULES_AFFICHAGE_STRUCTURES_H_INCLUDED
#define MODULES_AFFICHAGE_STRUCTURES_H_INCLUDED
#include "LOVC_machine_abstraite.h"
#include "LOV_C_machine_abstraite.h"
#include "TOVC_machine_abstrait.h"
#include "TOF_machine_abstraite.h"
#include <conio.h>
#include <windows.h>
//pour l'utilisation des couleurs
typedef enum
{BLACK,BLUE,GREEN,CYAN,RED,MAGENTA,BROWN,LIGHTGRAY,DARKGRAY,LIGHTBLUE,LIGHTGREEN, LIGHTCYAN,LIGHTRED,LIGHTMAGENTA,YELLOW,WHITE} COLORS;
static int __FOREGROUND = LIGHTGRAY;
static int __BACKGROUND = BLACK;
void textcolor (int color)
{
    __FOREGROUND = color;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
                             color + (__BACKGROUND << 4));
}
Buffer      buf;
Buffer_TOVC buf1;//livres.bin
Buffer_LOVC buf2;//memoires.bin
Buffer_TOVC buf3;//articles.bin
TOFBuffer   buf4;//periodiques.bin


typedef struct Tcouple
{
    int numero;//numero de periodique
    int i;//numero de bloc
    int j;//indice dans le bloc
} Tcouple;

typedef struct Index
{
    Tcouple tab[100];
    int nb;
} Index;

/* *****************- MODULE NOMBRE ALEATOIRE -******************/
int Aleanombre( int N )
{
    return ( rand() % N );
}
/* *****************- MODULE MOT ALEATOIRE -******************/
void  Aleachaine ( char chaine[], int N )
{
    int k;
    char Chr1[26] = "abcdefghijklmnopqrstuvwxyz";
    char Chr2[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (k=0; k<N; k++)
    {
        switch ( rand() % 2 )
        {
        case 0 :
            chaine[k] = Chr1[rand() % 26];
            break ;
        case 1 :
            chaine[k] = Chr2[rand() % 26];
            break ;
        }
    }
}
/* *****************- MODULE UN NOMBRE EN UNE CHAINE SUR UNE LONGEUR DETERMINER -******************/
void int_vers_string(char chaine[], int n, int longueur)
{

    int k;
    for(k=longueur-1; k>=0; k--)
    {
        chaine[k]=(n%10)+'0';          // EXTRACTION CHIFFRE PAR CHIFFRE
        n=n/10;                        // CHIFFRE SUIVANT
    }
}
/* *****************- MODULE POUR ECRIRE LA CHAINE DE CARACTERES EN BUFFER -******************/
void ecrire_chaine( int n, int *j, char chaine[], Buffer *buf)
{
    int k;
    for(k=0; k<n; k++)
    {
        if((*j)<=MAX_CAR)
        {
            buf->tab[*j]=chaine[k];
            (*j)++;
        }
    }
}
/************************************************************************/
/* ****** AFFICHER LES ENREGISTREMENTS DANS LE BLOC NUMERO 'i' DANS LE FICHIER 'Ouvrages.bin' *******/
void affichage_bloc_LOV_C(LOV_C **fichier, int i) {
	ouvrir(fichier, "Ouvrages.bin", 'a');
	lireDir(*fichier, i, &buf);

	printf("BLOC NUMERO %d DE FICHIER 'Ouvrages.bin'\n", i);
	int j = 0;

	while(j < buf.nb) {

    	textcolor(2);
		printf("IDENTIFIANT: ");
		textcolor (15);
		printf("%c%c%c%c\n", buf.tab[j], buf.tab[j+1], buf.tab[j+2], buf.tab[j+3]);
		j += 4;

    	textcolor (2);
		printf("TAILL: ");
		textcolor (15);
		printf("%c%c%c\n", buf.tab[j], buf.tab[j+1], buf.tab[j+2]);
		j += 3;

    	textcolor (2);
		printf("EFFACE: ");
		textcolor (15);
		printf("%s\n",buf.tab[j] == '0' ? "NON" : "OUI");
		j++;

    	textcolor (2);
		printf("DISPONIBLE: ");
        textcolor (15);
		printf("%s\n", buf.tab[j] == '0' ? "NON" : "OUI");
		j++;

    	textcolor (2);
		printf("TYPE: ");
		textcolor (15);
		switch(buf.tab[j]) {
			case '1':
				printf("TEXT IMPRIME\n");
				break;
			case '2':
				printf("DOCUMENT ELECTRONIQUE\n");
				break;
			case '3':
				printf("ARTICLE\n");
				break;
			case '4':
				printf("PERIODIQUE\n");
				break;
		}

		j++;

    	textcolor (2);
		printf("ANNEE DE PUBLICATION: ");
		textcolor (15);
		printf("%c%c%c%c\n", buf.tab[j], buf.tab[j+1], buf.tab[j+2], buf.tab[j+3]);

		j += 4;

    	textcolor (2);
		printf("TITRE: ");
		textcolor (15);
		while(buf.tab[j] != '$') {
			printf("%c", buf.tab[j]);
			j++;
		}

		j++;

    	textcolor (2);
		printf("\nAUTEUR: ");
		textcolor (15);
		while(buf.tab[j] != '$') {
			printf("%c", buf.tab[j]);
			j++;
		}

		j++;

    	textcolor (2);
		printf("\nCOTE: ");
		textcolor (15);
		while(buf.tab[j] != '$') {
			printf("%c", buf.tab[j]);
			j++;
		}

		j++;

    	textcolor (2);
		printf("\nRESUME: ");
		textcolor (15);
		while(buf.tab[j] != '#') {
			printf("%c", buf.tab[j]);
			j++;
		}

		j++;

    	textcolor (5);
		printf("\n-----------------------------------------------------------------------------------------------------------\n");
	}
        textcolor (15);

}
/* *****************- MODULE AFFICHAGE DU FICHIER  LOV~C -******************/
void affichage_fichier_LOV_C(LOV_C **fichier)
{
    printf("\n|-------------|--------|--------|------------|------|------|-------|---|--------|---|------|---|--------|----|\n");
    printf(  "| IDENTIFIANT | TAILLE | EFFACE | DISPONIBLE | TYPE | ANNE | TITRE | $ | AUTEUR | $ | COTE | $ | RESUME | $  |\n");
    printf(  "|_____________|________|________|____________|______|______|_______|___|________|___|______|___|________|____|\n");
    int I0; //ADRESSE BLOC
    int cmpt=1,j=0;
    ouvrir(fichier,"Ouvrages.bin",'A');
    I0 = entete(*fichier,1);

    while (I0 != -1)
    {
        lireDir(*fichier, I0, &buf);
        textcolor(2);
        printf("\nBLOC Ouvrages.bin : %3d\n",cmpt);
        textcolor(15);
        for (j=0; j<buf.nb ; j++)
        {
            printf("%c",buf.tab[j]);
        }
        I0 = buf.suivant;
        cmpt++;
    }
    fermer(*fichier);
}
/**************************************************************************/
/* *****************- AFFICHAGE DU BLOC NUMERO 'i' DANS LE FICHIER NOMMé 'nom' -******************/
void affichage_bloc_TOVC(TOVC **fichier, char nom[],int i) {
	Ouvrir_TOVC(fichier, nom, 'a');
	Liredir_TOVC(*fichier, i, &buf1);
	textcolor(2);
	printf("BLOC NUMERO %d DU FICHIER '%s':\n", i, nom);
	textcolor(15);
	for(int j = 0; j < MAX_CAR; j++) {
		printf("%c", buf1.tab[j]);
	}
	printf("\n\n");
	Fermer_TOVC(*fichier);
}
/* *****************- MODULE AFFICHAGE DU FICHIER Livres TOVC -******************/
void affichage_fichier_TOVC_Livres(TOVC **fichier_TOVC)
{
    int i=1,inc=1,I_fin;
    char c;
    Ouvrir_TOVC(fichier_TOVC,"Livres.bin",'A');
    I_fin = Entete_TOVC(*fichier_TOVC,1);
    printf("AFFICHAGE DE FICHIER 'Livres.bin':\n\n");
    for (i=1; i<=I_fin; i++)
    {
        Liredir_TOVC(*fichier_TOVC, i, &buf1);
        textcolor(2);
        printf("\nBLOC Livres.bin: %3d\n",i);
        textcolor(15);
        c=buf1.tab[1];
        while (c!='\0')
        {
            printf("%c",c);
            inc++;
            c=buf1.tab[inc];
        }
        printf("\n");
        inc=0;
    }
    Fermer_TOVC(*fichier_TOVC);
}
/*********************************************************************/
/* affichage du bloc numero 'i' dans le fichier 'memoires.bin' */
void affichage_bloc_LOVC(LOVC **fichier, int i) {
	ouvrir_LOVC(fichier, "Memoires.bin", 'a');
	lireDir_LOVC(*fichier, i, &buf2);
	textcolor(2);
	printf("BLOC NUMERO %d DU FICHIER 'Memoires.bin':\n", i);
	textcolor(15);
	for(int j = 0; j < MAX_CAR; j++) {
		printf("%c", buf2.tab[j]);
	}
	printf("\n");
	fermer_LOVC(*fichier);
}
/* *****************- MODULE AFFICHAGE DU FICHIER Memoires  LOVC -******************/
void affichage_fichier_Memoires(LOVC **fichier)
{
    int I0; //ADRESSE BLOC
    int cmpt=1,j=0;
    ouvrir_LOVC(fichier,"Memoires.bin",'A');
    I0 = enteteLOVC(*fichier,1);

    while (I0 != -1)
    {
        lireDir_LOVC(*fichier, I0, &buf2);
        textcolor(2);
        printf("\nBLOC Memoires.bin: %3d\n",cmpt);
        textcolor(15);
        for (j=0; j<buf2.nb ; j++)
        {
            printf("%c",buf2.tab[j]);
        }
        I0 = buf2.suivant;
        cmpt++;
    }
    fermer_LOVC(*fichier);
}
/* *****************- MODULE AFFICHAGE DU FICHIER Articles  TOVC -******************/
void affichage_fichier_TOVC_Articles(TOVC **fichier_TOVC)
{
    int i=1,inc=1,I_fin;
    char c;
    Ouvrir_TOVC(fichier_TOVC,"Articles.bin",'A');
    I_fin = Entete_TOVC(*fichier_TOVC,1);
    printf("AFFICHAGE DE FICHIER 'Articles.bin':\n\n");
    for (i=1; i<=I_fin; i++)
    {
        Liredir_TOVC(*fichier_TOVC, i, &buf1);
        textcolor(2);
        printf("\nBLOC Articles.bin: %3d\n",i);
        textcolor(15);
        c=buf1.tab[1];
        while (c!='\0')
        {
            printf("%c",c);
            inc++;
            c=buf1.tab[inc];
        }
        printf("\n");
        inc=0;
    }
    Fermer_TOVC(*fichier_TOVC);
}
/* ****************************************************************************************/
/* affichage du bloc numero 'i' dans le fichier 'Periodiques.bin' */
void affichage_bloc_TOF(TOF **fichier, int i) {
	ouvrirTOF(fichier, "Periodiques.bin", 'a');
	lireDirTOF(*fichier, i, &buf4);
	printf("BLOC NUMERO %d DU FICHIER 'Periodiques':\n", i);
    for(int j = 0; j < buf4.nb; j++)
    {
            printf("periodique: %d\n", j+1);
            textcolor(10);
            printf("numero: ");
            textcolor(15);
            printf("%d\n", buf4.tab[j].numero);
            textcolor(10);
            printf("titre: ");
            textcolor(15);
            printf("%s\n", buf4.tab[j].titre);
            textcolor(10);
            printf("auteur: ");
            textcolor(15);
            printf("%s\n", buf4.tab[j].auteur);
            textcolor(10);
            printf("annee: ");
            textcolor(15);
            printf("%d\n", buf4.tab[j].annee);
            textcolor(10);
            printf("disponible: ");
            textcolor(15);
            printf("%s\n", buf4.tab[j].disponible ? "OUI" : "NON");
            textcolor(5);
        printf("-------------------------------------\n");
    }
    printf("\n");
    fermerTOF(*fichier);
}
/* *****************- MODULE AFFICHAGE DU FICHIER Periodiques  TOF -******************/
/* afficher le contenu des blocs du
 * fichier 'fichier' de type TOF */
void affichage_fichier_TOF(TOF **fichier)
{
    ouvrirTOF(fichier, "Periodiques.bin", 'a');
    int nbBlocs = enteteTOF(*fichier, 1);

    printf("AFFICHAGE DE FICHIER 'Periodiques.bin':\n\n");

    for(int i = 1; i <= nbBlocs; i++)
    {
        lireDirTOF(*fichier, i, &buf4);

        printf("BLOC Periodiques: %d\n", i);
        for(int j = 0; j < buf4.nb; j++)
        {
            printf("periodique: %d\n", j+1);
            textcolor(10);
            printf("numero: ");
            textcolor(15);
            printf("%d\n", buf4.tab[j].numero);
            textcolor(10);
            printf("titre: ");
            textcolor(15);
            printf("%s\n", buf4.tab[j].titre);
            textcolor(10);
            printf("auteur: ");
            textcolor(15);
            printf("%s\n", buf4.tab[j].auteur);
            textcolor(10);
            printf("annee: ");
            textcolor(15);
            printf("%d\n", buf4.tab[j].annee);
            textcolor(10);
            printf("disponible: ");
            textcolor(15);
            printf("%s\n", buf4.tab[j].disponible ? "OUI" : "NON");
            textcolor(5);
            printf("-------------------------------------\n");
        }
        printf("\n");
    }
    textcolor(15);
    fermerTOF(*fichier);
}
/* *****************- MODULE AFFICHAGE ENTETR FICHIER  LOV~C -******************/
void affichage_entete_LOV_C(LOV_C **fichier)
{
    ouvrir(fichier,"Ouvrages.bin",'A');
    textcolor(10);
    printf("\n|------|-------------|-----------|-----------------|\n");
    printf(  "| TETE | LES INSERES | SUPPRIMES | NOMBRE DE BLOCS |\n");
    printf(  "|______|_____________|___________|_________________|\n");
    printf(  "|      |             |           |                 |\n");
    printf(  "|%6d|%13d|%11d|%17d|\n",entete(*fichier,1),entete(*fichier,2),entete(*fichier,3),entete(*fichier,4));
    printf(  "|______|_____________|___________|_________________|\n");
    textcolor(15);
    fermer(*fichier);
}
/* *****************- MODULE AFFICHAGE ENTETE FICHIER_LIVRES  TOVC -******************/
void affichage_entete_Livres(TOVC **fichier_TOVC)
{   Ouvrir_TOVC(fichier_TOVC,"Livres.bin",'A');
    textcolor(10);
    printf("\n|-----------------|\n");
    printf(  "| NOMBRE DE BLOCS |\n");
    printf(  "|_________________|\n");
    printf(  "|                 |\n");
    printf(  "|   %11d   |\n",Entete_TOVC(*fichier_TOVC,1));
    printf(  "|_________________|\n");
    textcolor(15);
    Fermer_TOVC(*fichier_TOVC);
}
/* *****************- MODULE AFFICHAGE ENTETE FICHIER_MEMOIRES  LOVC -******************/
void affichage_entete_Memoires(LOVC **fichier)
{
    ouvrir_LOVC(fichier,"Memoires.bin",'A');
    textcolor(10);
    printf("\n|------|-------------|-----------------|\n");
    printf(  "| TETE | LES INSERES | NOMBRE DE BLOCS |\n");
    printf(  "|______|_____________|_________________|\n");
    printf(  "|      |             |                 |\n");
    printf(  "|%6d|%13d|%17d|\n",enteteLOVC(*fichier,1),enteteLOVC(*fichier,2),enteteLOVC(*fichier,3));
    printf(  "|______|_____________|_________________|\n");
    textcolor(15);
    fermer_LOVC(*fichier);
}
/* *****************- MODULE AFFICHAGE ENTETE FICHIER_Articles  TOVC -******************/
void affichage_entete_Articles(TOVC **fichier_TOVC)
{
    Ouvrir_TOVC(fichier_TOVC,"Articles.bin",'A');
    textcolor(10);
    printf("\n|-----------------|\n");
    printf(  "| NOMBRE DE BLOCS |\n");
    printf(  "|_________________|\n");
    printf(  "|                 |\n");
    printf(  "|   %11d   |\n",Entete_TOVC(*fichier_TOVC,1));
    printf(  "|_________________|\n");
    textcolor(15);
    Fermer_TOVC(*fichier_TOVC);
}
/* *****************- MODULE AFFICHAGE ENTETE FICHIER_PERIODIQUES  TOF -******************/
void affichage_entete_TOF(TOF **fichier)
{
    ouvrirTOF(fichier, "Periodiques.bin", 'a');
    textcolor(10);
    printf("\n|-----------------|-----------------------|\n");
    printf(  "| NOMBRE DE BLOCS | NOMBRE DE PERIODIQUES |\n");
    printf(  "|_________________|_______________________|\n");
    printf(  "|                 |                       |\n");
    printf(  "|   %11d   |     %13d     |\n",enteteTOF(*fichier, 1),enteteTOF(*fichier, 2));
    printf(  "|_________________|_______________________|\n");
    textcolor(15);
    fermerTOF(*fichier);
}
/* *****************- MODULE AFFICHAGE INDEX_PERIODIQUES -******************/
void affichage_Index_Periodiques(Index *index)
{
    printf("INDEX de Periodiques.bin:\n\n");
    for(int i = 0; i < index->nb; i++)
    {
        printf("NUMERO: %d\n", index->tab[i].numero);
        printf("NUMERO DE BLOC: %d\n", index->tab[i].i);
        printf("NUMERO DE CASE: %d\n", index->tab[i].j);
        printf("------------------------------\n");
    }
}


//   LES MODULES
int Aleanombre( int N );
void  Aleachaine ( char chaine[], int N );
void int_vers_string(char chaine[], int n, int longueur);
void ecrire_chaine( int n, int *j, char chaine[], Buffer *buf);
void affichage_fichier_LOV_C(LOV_C **fichier);
void affichage_entete_LOV_C(LOV_C **fichier);
void affichage_fichier_TOVC_Livres(TOVC **fichier_TOVC);
void affichage_fichier_TOVC_Articles(TOVC **fichier_TOVC);
void affichage_fichier_TOF(TOF **fichier);
void affichage_entete_TOF(TOF **fichier);
void affichage_entete_Livres(TOVC **fichier_TOVC);
void affichage_entete_Articles(TOVC **fichier_TOVC);
void affichage_entete_TOF(TOF **fichier);
void affichage_entete_Livres(TOVC **fichier_TOVC);
void affichage_entete_Articles(TOVC **fichier_TOVC);
void affichage_Index_Periodiques(Index *index);
//

#endif // MODULES_AFFICHAGE_STRUCTURES_H_INCLUDED


