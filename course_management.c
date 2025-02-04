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
