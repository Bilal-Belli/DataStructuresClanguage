#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LOV_C_machine_abstraite.h"
#include "TOVC_machine_abstrait.h"
#include "LOVC_machine_abstraite.h"
#include "TOF_machine_abstraite.h"
#include "Modules_Affichage_Structures.h"
#include "fonctions.h"
/* **************************************************************************
TP SFSD 2020/2021
*****************

REALISE PAR: BOUMENDJEL MOHAMED ISLAM - GROUPE 4 - & BELLI BILAL - GROUPE 5



REPONCE A LA QUESTION 8:
-----------------------

LORSQUE LE TESTE PLUSIEUR FOIX ON NOTE QUE /

  COUT RECHECHE PAR INDEX  << COUT DE RECHERCHE PAR LE NEMURO (CLE DE RECHERCHE)

CONCLUSION/ LA RECHERCHE PAR UTILISATION D'INDEX EST TRES BON POUR AMELIORER LES PERFORMENCES DE RECHECHE

******************************************************************************************************************/




int main()
{
    LOV_C *fichier;
    TOVC *fichier1;//livres.bin
    LOVC *fichier2;//memoires.bin
    TOVC *fichier3;//articles.bin
    TOF *fichier4;//periodiques.bin
    srand(time(0));
    FILE *ptr_f;
    int choix;
    int numeroBloc;
    int trouve, i, j;
    int cle;
    char ouvrage[1000];
    int taille;
    Index index;


	printf("TP SFSD 2020/2021\n");
	printf("*****************\n\n");
	printf("REALISE PAR: BOUMENDJEL MOHAMED ISLAM - GROUPE 4 - ET BELLI BILAL - GROUPE 5 -\n\n\n");

    do {
        textcolor(2);
    	printf("\n\t\t\t\t~~~~~~~~~~~~~~~~ MENU ~~~~~~~~~~~~~~~~\n");
    	textcolor(4);
    	printf("\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        textcolor(15);
        int ouvrage_existe=0;
        ptr_f = fopen("Ouvrages.bin", "rb+");//tester si le fichier d'ouvrages existe
            if (ptr_f==0)
            {
                ouvrage_existe=0;
            }
            else
            {
                ouvrage_existe=1;
            }
            fclose(ptr_f);
            int livre_existe=0;
          ptr_f = fopen("Livres.bin", "rb+");//tester si le fichier des livres existe
            if (ptr_f==0)
            {
                livre_existe=0;
            }
            else
            {
                livre_existe=1;
            }
            fclose(ptr_f);
            int memoire_existe=0;
            ptr_f = fopen("Memoires.bin", "rb+");
            if (ptr_f==0)
            {
                memoire_existe=0;
            }
            else
            {
                memoire_existe=1;
            }
            fclose(ptr_f);
            int articles_existe=0;
            ptr_f = fopen("Articles.bin", "rb+");
            if (ptr_f==0)
            {
                articles_existe=0;
            }
            else
            {
                articles_existe=1;
            }
            fclose(ptr_f);
            int periodiques_existe=0;
            ptr_f = fopen("Periodiques.bin", "rb+");
            if (ptr_f==0)
            {
                periodiques_existe=0;
            }
            else
            {
                periodiques_existe=1;
            }
            fclose(ptr_f);


    	printf("0) SORTIR\n");
    	printf("1) CREATION du fichier 'Ouvrages.bin'\n");
    	printf("2) AFFICHAGE de l'entete du fichier 'Ouvrages.bin'\n");
    	printf("3) AFFICHAGE d'un bloc du fichier 'Ouvrages.bin'\n");
    	printf("4) AFFICHAGE de tous les blocs du fichier 'Ouvrages.bin'\n");
    	printf("5) RECHERCHER un ouvrage dans le fichier 'Ouvrages.bin'\n");
    	printf("6) inserer un ouvrage dans le fichier 'Ouvrages.bin'\n");
    	printf("7) modifier l'etat d'un ouvrage dans le ficheir 'Ouvrages.bin'\n");
    	printf("8) CREATION des fichiers 'Livres.bin', 'Memoire.bin', 'Articles.bin' et 'Periodiques.bin'\n");
    	printf("9) AFFICHAGE de l'entete du fichier 'Livres.bin'\n");
    	printf("10) AFFICHAGE d'un bloc du fichier 'Livres.bin'\n");
    	printf("11) AFFICHAGE de tous les blocs du fichier 'Livres.bin'\n");
    	printf("12) AFFICHAGE de l'entete du fichier 'Memoire.bin'\n");
    	printf("13) AFFICHAGE d'un bloc du fichier 'Memoire.bin'\n");
    	printf("14) AFFICHAGE de tous les blocs du fichier 'Memoire.bin'\n");
    	printf("15) AFFICHAGE de l'entete du fichier 'Articles.bin'\n");
    	printf("16) AFFICHAGE d'un bloc du fichier 'Articles.bin'\n");
    	printf("17) AFFICHAGE de tous les blocs du fichier 'Articles.bin'\n");
    	printf("18) AFFICHAGE de l'entete du fichier 'Periodiques.bin'\n");
    	printf("19) AFFICHAGE d'un bloc du fichier 'Periodiques.bin'\n");
    	printf("20) AFFICHAGE de tous les blocs du fichier 'Periodiques.bin'\n");
    	printf("21) RECHERCHE d'une periodique dans le fichier 'Periodiques.bin'\n");
    	printf("22) CREATION de la table d'index primaire du fichier 'Periodiques.bin'\n");
    	printf("23) RECHERCHE d'une periodique dans le fichier 'Periodiques.bin' en utilisant la table d'index\n");
    	printf("24) AFFICHAGE de la table d'index\n");
    	printf("\nENTRER VOTRE CHOIX:");

    	scanf("%d", &choix);

    	switch(choix) {
    		case 0:
    			printf("sortir...\n");
    			break;
    		case 1:
    			printf("creation du fichier 'Ouvrages.bin'\n");
    			creation_fichier_LOV_C(&fichier);
    			printf("LE COUT DE CETTE OPERATION EST: ");
    			textcolor(2);
    			printf("%d ", C1);
    			textcolor(15);
    			printf("ACCES AU FICHIER\n");
    			break;
    		case 2:
            if (ouvrage_existe==0)
            {textcolor(4);
                printf("LE FICHIER N'EXISTE PAS\n");textcolor(15);
            }
            else
            {
                affichage_entete_LOV_C(&fichier);
            }
    			break;
    		case 3:
                if (ouvrage_existe==0)
                {textcolor(4);
                    printf("LE FICHIER N'EXISTE PAS\n");textcolor(15);
                }
                else
                {
                    printf("ENTRER LE NUMERO DE BLOC DU FICHIER 'Ouvrages.bin' QUE VOUS VOULEZ AFFICHER:");
                    scanf("%d", &numeroBloc);
                    affichage_bloc_LOV_C(&fichier, numeroBloc);
                }
    			break;
    		case 4:
                if (ouvrage_existe==0)
                {textcolor(4);
                    printf("LE FICHIER N'EXISTE PAS\n");textcolor(15);
                }
                else
                {
                    affichage_fichier_LOV_C(&fichier);
                }
    			break;
    		case 5:
    		    if (ouvrage_existe==0)
                {textcolor(4);
                    printf("LE FICHIER N'EXISTE PAS\n");textcolor(15);
                }
                else
                {
                printf("ENTRER LA CLE DE RECHERCHE:");
    			scanf("%d", &cle);
    			ouvrir(&fichier, "Ouvrages.bin", 'A');
    			recherche(fichier, cle, &trouve, &i, &j);
    			fermer(fichier);
    			printf("TROUVE: ");
    			textcolor(2);
    			printf("%s\n", trouve == 1 ? "OUI" : "NON");
    			textcolor(15);
    			printf("NUMERO DE BLOC: ");
    			textcolor(2);
    			printf("%d\n",i);
    			textcolor(15);
    			printf("POSITION DANS LE BLOC: ");
    			textcolor(2);
    			printf("%d\n",j);
    			textcolor(15);
    			printf("LE COUT DE LA RECHERCHE EST: ");
    			textcolor(2);
    			printf("%d ", C2);
    			textcolor(15);
    			printf("ACCES AU FICHIER\n");
                }

    			break;
    		case 6:
    		    if (ouvrage_existe==0)
                {textcolor(4);
                    printf("LE FICHIER N'EXISTE PAS\n");textcolor(15);
                }
                else
                {
                lireOuvrage(ouvrage, &taille);
    			ouvrir(&fichier, "Ouvrages.bin", 'A');
    			insertion(fichier, ouvrage, taille);
    			fermer(fichier);
    			printf("LE COUT DE L'INSERTION EST: ");
    			textcolor(2);
    			printf("%d\n", C3);
    			textcolor(15);
                }

    			break;
    		case 7:
    		    if (ouvrage_existe==0)
                {textcolor(4);
                    printf("LE FICHIER N'EXISTE PAS\n");textcolor(15);
                }
                else
                {
                modifier_diponibiliti_LOV_C(&fichier);
    			printf("LE COUT DE LA MODIFICATION EST: ");
    			textcolor(2);
    			printf("%d\n", C4);
    			textcolor(15);
                }

    			break;
    		case 8:
    		    if (ouvrage_existe==0)
                {textcolor(4);
                    printf("LE FICHIER N'EXISTE PAS\n");textcolor(15);
                }
                else
                {
                printf("CREATION DES FICHIERS 'Livres.bin', 'Memoires.bin', 'Articles.bin' et 'Periodiques.bin'\n");
    			creer_Fichiers(&fichier, &fichier1, &fichier2, &fichier3, &fichier4);
    			printf("LE COUT DE LA CREATION DE 'Livres.bin' EST: ");
    			textcolor(2);
    			printf("%d\n", C51);
    			textcolor(15);
    			printf("LE COUT DE LA CREATION DE 'Memoires.bin' EST: ");
    			textcolor(2);
    			printf("%d\n", C52);
    			textcolor(15);
    			printf("LE COUT DE LA CREATION DE 'Articles.bin' EST: ");
    			textcolor(2);
    			printf("%d\n", C53);
    			textcolor(15);
    			printf("LE COUT DE LA CREATION DE 'Periodiques.bin' EST: ");
    			textcolor(2);
    			printf("%d\n", C54);
    			textcolor(15);
                }

    			break;
    		case 9:
    		    if (livre_existe==0)
                {textcolor(4);
                    printf("LE FICHIER N'EXISTE PAS\n");textcolor(15);
                }
                else
                {
                 affichage_entete_Livres(&fichier1);
                }

    			break;
    		case 10:
    		    if (livre_existe==0)
                {textcolor(4);
                    printf("LE FICHIER N'EXISTE PAS\n");textcolor(15);
                }
                else
                {
                 printf("ENTRER LE NUMERO DE BLOC DU FICHIER 'Livres.bin' QUE VOUS VOULEZ AFFICHER:");
    			scanf("%d", &numeroBloc);
    			affichage_bloc_TOVC(&fichier1, "Livres.bin", numeroBloc);
                }

    			break;
    		case 11:
    		    if (livre_existe==0)
                {textcolor(4);
                    printf("LE FICHIER N'EXISTE PAS\n");textcolor(15);
                }
                else
                {
                affichage_fichier_TOVC_Livres(&fichier1);
                }

    			break;
    		case 12:
    		    if (memoire_existe==0)
                {textcolor(4);
                    printf("LE FICHIER N'EXISTE PAS\n");textcolor(15);
                }
                else
                {
                affichage_entete_Memoires(&fichier2);
                }

    			break;
    		case 13:
    		    if (memoire_existe==0)
                {textcolor(4);
                    printf("LE FICHIER N'EXISTE PAS\n");textcolor(15);
                }
                else
                {
                printf("ENTRER LE NUMERO DE BLOC DU FICHIER 'Memoires.bin' QUE VOUS VOULEZ AFFICHER:");
    			scanf("%d", &numeroBloc);
    			affichage_bloc_LOVC(&fichier2, numeroBloc);
                }
    			break;
    		case 14:
    		    if (memoire_existe==0)
                {textcolor(4);
                    printf("LE FICHIER N'EXISTE PAS\n");textcolor(15);
                }
                else
                {
                affichage_fichier_Memoires(&fichier2);
                }
    			break;
    		case 15:
    		    if (articles_existe==0)
                {textcolor(4);
                    printf("LE FICHIER N'EXISTE PAS\n");textcolor(15);
                }
                else
                {
                affichage_entete_Articles(&fichier3);
                }
    			break;
    		case 16:
    		    if (articles_existe==0)
                {textcolor(4);
                    printf("LE FICHIER N'EXISTE PAS\n");textcolor(15);
                }
                else
                {
                printf("ENTRER LE NUMERO DE BLOC DU FICHIER 'Articles.bin' QUE VOUS VOULEZ AFFICHER:");
    			scanf("%d", &numeroBloc);
    			affichage_bloc_TOVC(&fichier3, "Articles.bin", numeroBloc);
                }
    			break;
    		case 17:
    		    if (articles_existe==0)
                {textcolor(4);
                    printf("LE FICHIER N'EXISTE PAS\n");textcolor(15);
                }
                else
                {
                affichage_fichier_TOVC_Articles(&fichier3);
                }
    			break;
    		case 18:
    		    if (periodiques_existe==0)
                {textcolor(4);
                    printf("LE FICHIER N'EXISTE PAS\n");textcolor(15);
                }
                else
                {
                affichage_entete_TOF(&fichier4);
                }
    			break;
    		case 19:
    		    if (periodiques_existe==0)
                {
                    textcolor(4);
                    printf("LE FICHIER N'EXISTE PAS\n");textcolor(15);
                }
                else
                {
    			printf("ENTRER LE NUMERO DE BLOC DU FICHIER 'Periodiques.bin' QUE VOUS VOULEZ AFFICHER:");
    			scanf("%d", &numeroBloc);
    			affichage_bloc_TOF(&fichier4, numeroBloc);
                }
    			break;
    		case 20:
    		    if (periodiques_existe==0)
                {textcolor(4);
                    printf("LE FICHIER N'EXISTE PAS\n");textcolor(15);
                }
                else
                {
    			affichage_fichier_TOF(&fichier4);
                }
    			break;
    		case 21:
    		    if (periodiques_existe==0)
                {textcolor(4);
                    printf("LE FICHIER N'EXISTE PAS\n");textcolor(15);
                }
                else
                {
    			printf("ENTRER LA CLE DE RECHERCHE DE LA PERIODIQUE DANS LE FICHIER 'Periodiques.bin':");
    			scanf("%d", &cle);
    			recherchePeriodique(&fichier4, cle, &trouve, &i, &j);
    			if(trouve == 1) {
    				printf("TROUVE: OUI\n");
    				printf("NUMERO DE BLOC: %d\n", i);
    				printf("POSITION DANS LE BLOC: %d\n", j);
    				ouvrirTOF(&fichier4, "Periodiques.bin", 'A');
    				lireDirTOF(fichier4, i, &buf4);
    				printf("NUMERO: %d\nTITRE: %s\nAUTEUR: %s\nANNEE: %d\n", buf4.tab[j].numero, buf4.tab[j].titre, buf4.tab[j].auteur, buf4.tab[j].annee);
        			printf("DISPONIBLE: %s\n", buf4.tab[j].disponible ? "OUI" : "NON");
    				fermerTOF(fichier4);
    			}
    			else {
    				printf("TROUVE: NON\n");
    				printf("NUMERO DE BLOC: %d\n", i);
    				printf("POSITION DANS LE BLOC: %d\n", j);
    			}
    			printf("LE COUT DE CETTE RECHERCHE EST: ");
    			textcolor(2);
    			printf("%d\n", C6);
    			textcolor(15);
                }
    			break;
    		case 22:
    		     if (periodiques_existe==0)
                {textcolor(4);
                    printf("LE FICHIER N'EXISTE PAS\n");textcolor(15);
                }
                else
                {
    			printf("CREATION DE LA TABLE D'INDEX POUR LE FICHIER 'Periodiques.bin'\n");
    			creer_index_periodiques(&fichier4, &index);
    			lireIndex(&index, "Index_Periodiques.bin");
    			printf("LE COUT DE LA CREATION DE L'INDEX EST: ");
    			textcolor(2);
    			printf("%d\n", C7);
    			textcolor(15);
                }
    			break;
    		case 23:
    			printf("ENTRER LA CLE DE RECHERCHE (AVEC INDEX):");
    			scanf("%d", &cle);
    			recherche_TOF_index(&fichier4, &index, cle, &trouve, &i, &j);
    			printf("LE COUT DE CETTE RECHERCHE EST: ");
    			textcolor(2);
    			printf("%d", C8);
    			textcolor(15);
    			break;
    		case 24:
    			affichage_Index_Periodiques(&index);
    			break;
    		default:
    		    textcolor(4);
    			printf("CHOIX INVALIDE!\n");textcolor(15);
    			break;
    	}
    }while(choix != 0);
    ecrireIndex(&index, "Index_Periodiques.bin");
    return 0;
}
