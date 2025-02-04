#include "data_structures.c"
#include "course_management.c"
#include "student_management.c"

void inscrireCours() {
    char idEtudiant[ID_ETUDIANT_LONGUEUR + 1];
    int idCours;

    printf("Entrez l'ID de l'étudiant : ");
    scanf("%s", idEtudiant);

    printf("Entrez l'ID du cours : ");
    scanf("%d", &idCours);

    Etudiant *etudiant = NULL;
    for (int i = 0; i < nbEtudiants; i++) {
        if (strcmp(etudiants[i].id, idEtudiant) == 0) {
            etudiant = &etudiants[i];
            break;
        }
    }

    if (etudiant == NULL) {
        printf("Étudiant non trouvé.\n");
        return;
    }

    Cours *cours = NULL;
    for (int i = 0; i < nbCours; i++) {
        if (coursOfferts[i].id == idCours) {
            cours = &coursOfferts[i];
            break;
        }
    }

    if (cours == NULL) {
        printf("Cours non trouvé.\n");
        return;
    }

    Cours *nouveauCours = creerCours(cours->id, cours->nom, cours->credits);
    nouveauCours->suivant = etudiant->historiqueCours;
    etudiant->historiqueCours = nouveauCours;

    printf("L'étudiant %s %s a été inscrit au cours %s.\n", etudiant->prenom, etudiant->nom, cours->nom);
}

int main() {
    int choix;
    do {
        printf("\n=== Menu ===\n");
        printf("1. Ajouter un cours\n");
        printf("2. Inscrire un étudiant\n");
        printf("3. Afficher l'historique des cours d'un étudiant\n");
        printf("4. Inscrire un étudiant à un cours\n");
        printf("5. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        
        switch(choix) {
            case 1: ajouterCours(); 
            break;
            case 2: inscrireEtudiant(); 
            break;
            case 3: { char id[ID_ETUDIANT_LONGUEUR + 1]; printf("ID étudiant : "); scanf("%s", id); afficherHistorique(id); 
            break; }
            case 4: inscrireCours(); 
            break;
            case 5: printf("Au revoir  !\n"); 
            break;
            default: printf("Choix invalide.\n");
        }
    } while(choix != 5);

    return 0;
}
