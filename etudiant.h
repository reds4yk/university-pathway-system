#ifndef ETUDIANT_H
#define ETUDIANT_H

#include "cours.h"
#define MAX_NOM 100
#define MAX_PRENOM 100
#define MAX_ETUDIANTS 100
#define ID_ETUDIANT_LONGUEUR 12

typedef struct Etudiant {
    char id[ID_ETUDIANT_LONGUEUR + 1];
    char nom[MAX_NOM];
    char prenom[MAX_PRENOM];
    Cours *historiqueCours;
} Etudiant;

extern Etudiant etudiants[MAX_ETUDIANTS];
extern int nbEtudiants;

void inscrireEtudiant();
void afficherHistorique(char *idEtudiant);

#endif
