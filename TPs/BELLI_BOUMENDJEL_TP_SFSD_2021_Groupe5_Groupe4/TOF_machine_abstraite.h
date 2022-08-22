#ifndef TOF_machine_abstraite_H_INCLUDED
#define TOF_machine_abstraite_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define B 10

typedef struct periodique {
	int numero;
	char titre[25];
	char auteur[25];
	int annee;
	int disponible;
}periodique;


typedef struct TOFbloc {
	periodique tab[B];
	int nb;
}TOFbloc;

typedef struct TOFbloc TOFBuffer;

typedef struct TOFentete {
	int nbBloc;//nombre de blocs dans le fichier
	int nbPeriodiques;//nombre de periodiques insérés dans le fichier
}TOFentete;

typedef struct TOF {
	FILE* fichier;
	TOFentete entete;
}TOF;


void ouvrirTOF(TOF **f, char nom[], char mode);
void fermerTOF(TOF *f);
int enteteTOF(TOF *f, int i);
void aff_enteteTOF(TOF *f, int i, int valeur);
void lireDirTOF(TOF *f, int i, TOFBuffer *buf);
void ecrireDirTOF(TOF *f, int i, TOFBuffer *buf);


void ouvrirTOF(TOF **f, char nom[], char mode) {
	*f = malloc(sizeof(TOF));

	if (mode == 'a' || mode == 'A') {
		(*f)->fichier = fopen(nom, "rb+");

		if ( (*f)->fichier != NULL) {
			fread(&((*f)->entete), sizeof(TOFentete), 1, (*f)->fichier);
		}
	}
	else if (mode == 'n' || mode == 'N') {
		(*f)->fichier = fopen(nom, "wb+");

		if ( (*f)->fichier != NULL) {
			(*f)->entete.nbBloc = 1;
			(*f)->entete.nbPeriodiques = 0;
		}
	}
}


void fermerTOF(TOF *f) {
	rewind(f->fichier);
	fwrite(&(f->entete), sizeof(TOFentete), 1, f->fichier);
	fclose(f->fichier);
	free(f);
}


int enteteTOF(TOF *f, int i) {
	if(i == 1) return f->entete.nbBloc;
	else if(i == 2) return f->entete.nbPeriodiques;
	else return -1;
}


void aff_enteteTOF(TOF *f, int i, int valeur) {
	if(i == 1) f->entete.nbBloc = valeur;
	else if(i == 2) f->entete.nbPeriodiques = valeur;
}


void lireDirTOF(TOF *f, int i, TOFBuffer *buf) {
	fseek(f->fichier, sizeof(TOFentete) + sizeof(TOFbloc)*(i - 1), SEEK_SET);
	fread(buf, sizeof(TOFbloc), 1, f->fichier);
}


void ecrireDirTOF(TOF *f, int i, TOFBuffer *buf) {
	fseek(f->fichier, sizeof(TOFentete) + sizeof(TOFbloc)*(i - 1), SEEK_SET);
	fwrite(buf, sizeof(TOFbloc), 1, f->fichier);
}

#endif