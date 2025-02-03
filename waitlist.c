#include "common.h"

void addToWaitlist() {
    if (waitlistCount >= MAX_STUDENTS) {
        printf("Waitlist is full!\n");
        return;
    }

    char studentID[20], courseID[10];
    printf("Enter student ID: ");
    scanf(" %s", studentID);
    printf("Enter course ID: ");
    scanf(" %s", courseID);

    strcpy(waitlist[waitlistCount].studentID, studentID);
    strcpy(waitlist[waitlistCount].courseID, courseID);
    waitlistCount++;
    printf("Student added to waitlist.\n");
}

void enrollFromWaitlist() {
    if (waitlistCount == 0) {
        printf("Waitlist is empty!\n");
        return;
    }

    char courseID[10];
    printf("Enter course ID to enroll from waitlist: ");
    scanf(" %s", courseID);

    for (int i = 0; i < waitlistCount; i++) {
        if (strcmp(waitlist[i].courseID, courseID) == 0) {
            printf("Enrolling student %s into course %s.\n", waitlist[i].studentID, courseID);

            // Remove from waitlist
            for (int j = i; j < waitlistCount - 1; j++) {
                waitlist[j] = waitlist[j + 1];
            }
            waitlistCount--;
            return;
        }
    }
    printf("No students waiting for this course.\n");
}

void displayWaitlist() {
    if (waitlistCount == 0) {
        printf("Waitlist is empty.\n");
        return;
    }

    printf("Waitlist:\n");
    for (int i = 0; i < waitlistCount; i++) {
        printf("Student: %s, Course: %s\n", waitlist[i].studentID, waitlist[i].courseID);
    }
}
