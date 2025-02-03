#include "common.h"

void addStudentPathway() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Maximum students reached!\n");
        return;
    }

    char studentID[20];
    printf("Enter student ID: ");
    scanf(" %s", studentID);

    strcpy(studentHistory[studentCount].studentID, studentID);
    studentHistory[studentCount].courseCount = 0;
    studentCount++;
    printf("Student pathway added.\n");
}

void deleteStudentPathway() {
    if (studentCount == 0) {
        printf("No students found!\n");
        return;
    }

    char studentID[20];
    printf("Enter student ID to delete: ");
    scanf(" %s", studentID);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(studentHistory[i].studentID, studentID) == 0) {
            for (int j = i; j < studentCount - 1; j++) {
                studentHistory[j] = studentHistory[j + 1];
            }
            studentCount--;
            printf("Student pathway deleted.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

void searchStudentPathway() {
    if (studentCount == 0) {
        printf("No students found!\n");
        return;
    }

    char studentID[20];
    printf("Enter student ID to search: ");
    scanf(" %s", studentID);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(studentHistory[i].studentID, studentID) == 0) {
            printf("Student ID: %s\n", studentHistory[i].studentID);
            printf("Completed Courses:\n");
            for (int j = 0; j < studentHistory[i].courseCount; j++) {
                printf("  %s\n", studentHistory[i].completedCourses[j]);
            }
            return;
        }
    }
    printf("Student not found.\n");
}
