#include "common.h"

int main() {
    int choice;
    do {
        printf("\n=== University Pathway Management ===\n");
        printf("1. Add Student Pathway\n");
        printf("2. Delete Student Pathway\n");
        printf("3. Search Student Pathway\n");
        printf("4. Add Completed Course\n");
        printf("5. Add to Waitlist\n");
        printf("6. Enroll from Waitlist\n");
        printf("7. Display Waitlist\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudentPathway(); break;
            case 2: deleteStudentPathway(); break;
            case 3: searchStudentPathway(); break;
            case 4: addCompletedCourse(); break;
            case 5: addToWaitlist(); break;
            case 6: enrollFromWaitlist(); break;
            case 7: displayWaitlist(); break;
            case 8: printf("Exiting program.\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 8);

    return 0;
}
