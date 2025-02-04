#ifndef COURS_H
#define COURS_H

#define MAX_COURS 50

typedef struct Cours {
    int id;
    char nom[MAX_NOM];
    int credits;
    struct Cours *suivant;
} Cours;

extern Cours coursOfferts[MAX_COURS];
extern int nbCours;

Cours *creerCours(int id, const char *nom, int credits);
void ajouterCours();

#endif 
