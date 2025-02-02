#include "common.h"

int main() {
    loadFromFile(); // Load data at the start

    int choice;
    do {
        printf("\n=== Gestion des Parcours Universitaires ===\n");
        printf("1. Ajouter une specialite\n");
        printf("2. Ajouter une section\n");
        printf("3. Ajouter un cours\n");
        printf("4. Supprimer une specialite\n");
        printf("5. Supprimer une section\n");
        printf("6. Supprimer un cours\n");
        printf("7. Rechercher une specialite\n");
        printf("8. Rechercher une section\n");
        printf("9. Rechercher un cours\n");
        printf("10. Ajouter un etudiant a la file d'attente\n");
        printf("11. Inscrire un etudiant depuis la file d'attente\n");
        printf("12. Afficher la file d'attente\n");
        printf("13. Ajouter un cours termine\n");
        printf("14. Afficher les cours termines\n");
        printf("15. Sauvegarder\n");
        printf("16. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addSpecialty(); break;
            case 2: addSection(); break;
            case 3: addCourse(); break;
            case 4: deleteSpecialty(); break;
            case 5: deleteSection(); break;
            case 6: deleteCourse(); break;
            case 7: searchSpecialty(); break;
            case 8: searchSection(); break;
            case 9: searchCourse(); break;
            case 10: {
                char studentID[20], courseID[10];
                printf("Entrez l'ID de l'etudiant : ");
                scanf(" %s", studentID);
                printf("Entrez l'ID du cours : ");
                scanf(" %s", courseID);
                addToWaitlist(studentID, courseID);
                break;
            }
            case 11: {
                char courseID[10];
                printf("Entrez l'ID du cours : ");
                scanf(" %s", courseID);
                enrollFromWaitlist(courseID);
                break;
            }
            case 12: displayWaitlist(); break;
            case 13: {
                char studentID[20], courseID[10];
                printf("Entrez l'ID de l'etudiant : ");
                scanf(" %s", studentID);
                printf("Entrez l'ID du cours : ");
                scanf(" %s", courseID);
                addCompletedCourse(studentID, courseID);
                break;
            }
            case 14: {
                char studentID[20];
                printf("Entrez l'ID de l'etudiant : ");
                scanf(" %s", studentID);
                displayCompletedCourses(studentID);
                break;
            }
            case 15: saveToFile(); break;
            case 16: printf("Fermeture du programme.\n"); break;
            default: printf("Option invalide.\n");
        }
    } while (choice != 16);

    return 0;
}
