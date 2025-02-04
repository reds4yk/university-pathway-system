#include "data_structures.c"

void ajouterCours() {
    int id, credits;
    char nom[MAX_NOM];

    if (nbCours >= MAX_COURS) {
        printf("Le nombre maximum de cours est atteint.\n");
        return;
    }

    printf("Entrez l'ID du cours : ");
    scanf("%d", &id);
    getchar();

    printf("Entrez le nom du cours : ");
    fgets(nom, MAX_NOM, stdin);
    nom[strcspn(nom, "\n")] = 0;

    printf("Entrez le nombre de crédits du cours : ");
    scanf("%d", &credits);

    Cours nouveauCours = {id, "", credits, NULL};
    strncpy(nouveauCours.nom, nom, MAX_NOM);
    coursOfferts[nbCours++] = nouveauCours;

    printf("Cours ajouté avec succès.\n");
}

course_management.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOM 100
#define MAX_PRENOM 100
#define MAX_COURS 50
#define MAX_ETUDIANTS 100
#define MAX_COURS_PAR_ETUDIANT 10
#define ID_ETUDIANT_LONGUEUR 12

typedef struct Cours {
    int id;
    char nom[MAX_NOM];
    int credits;
    struct Cours *suivant;
} Cours;

typedef struct Etudiant {
    char id[ID_ETUDIANT_LONGUEUR + 1];
    char nom[MAX_NOM];
    char prenom[MAX_PRENOM];
    Cours *historiqueCours;
} Etudiant;

Etudiant etudiants[MAX_ETUDIANTS];
Cours coursOfferts[MAX_COURS];

int nbEtudiants = 0, nbCours = 0;

Cours *creerCours(int id, const char *nom, int credits) {
    Cours *nouveauCours = (Cours *)malloc(sizeof(Cours));
    nouveauCours->id = id;
    strncpy(nouveauCours->nom, nom, MAX_NOM);
    nouveauCours->credits = credits;
    nouveauCours->suivant = NULL;
    return nouveauCours;
}
