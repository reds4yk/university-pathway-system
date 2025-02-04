#include "data_structures.c"

void inscrireEtudiant() {
    char id[ID_ETUDIANT_LONGUEUR + 1], nom[MAX_NOM], prenom[MAX_PRENOM];

    if (nbEtudiants >= MAX_ETUDIANTS) {
        printf("Le nombre maximum d'étudiants est atteint.\n");
        return;
    }
    printf(" Félicitations pour l'obtention de votre baccalauréat et bienvenue dans votre parcours universitaire.\n");
    printf(" 1_entrez l'ID de l'étudiant (max %d caractères) : ", ID_ETUDIANT_LONGUEUR);
    scanf("%s", id);
    printf(" 2_entrez le nom de l'étudiant : ");
    scanf("%s", nom);
    printf(" 3_entrez le prénom de l'étudiant : ");
    scanf("%s", prenom);

    Etudiant nouvelEtudiant;
    strncpy(nouvelEtudiant.id, id, ID_ETUDIANT_LONGUEUR);
    nouvelEtudiant.id[ID_ETUDIANT_LONGUEUR] = '\0';
    strncpy(nouvelEtudiant.nom, nom, MAX_NOM);
    strncpy(nouvelEtudiant.prenom, prenom, MAX_PRENOM);
    nouvelEtudiant.historiqueCours = NULL;
    etudiants[nbEtudiants++] = nouvelEtudiant;
    printf("Étudiant inscrit avec succès.\n");
}

void afficherHistorique(char *idEtudiant) {
    Etudiant *etudiant = NULL;
    for (int i = 0; i < nbEtudiants; i++) {
        if (strcmp(etudiants[i].id, idEtudiant) == 0) {
            etudiant = &etudiants[i];
            break;
        }
    }

    if (etudiant == NULL) {
        printf("Aucun étudiant trouvé avec l'ID %s.\n", idEtudiant);
        return;
    }

    printf("Historique des cours de %s %s (ID : %s) :\n", etudiant->prenom, etudiant->nom, etudiant->id);
    Cours *cours = etudiant->historiqueCours;
    if (cours == NULL) {
        printf("Aucun cours suivi.\n");
    } else {
        while (cours != NULL) {
            printf("Cours %d : %s - %d crédits\n", cours->id, cours->nom, cours->credits);
            cours = cours->suivant;
        }
    }
}
