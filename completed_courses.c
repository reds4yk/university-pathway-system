#include "common.h"

void addCompletedCourse() {
    if (studentCount == 0) {
        printf("No students found!\n");
        return;
    }

    char studentID[20], courseID[10];
    printf("Enter student ID: ");
    scanf(" %s", studentID);
    printf("Enter course ID: ");
    scanf(" %s", courseID);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(studentHistory[i].studentID, studentID) == 0) {
            if (studentHistory[i].courseCount >= MAX_COURSES) {
                printf("Maximum courses reached for this student.\n");
                return;
            }

            strcpy(studentHistory[i].completedCourses[studentHistory[i].courseCount], courseID);
            studentHistory[i].courseCount++;
            printf("Course added to student history.\n");
            return;
        }
    }
    printf("Student not found.\n");
}
