#include <stdio.h>
#include "etudiant.h"
#include "cours.h"
#include "inscription.h"

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
