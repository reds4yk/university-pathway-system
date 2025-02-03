#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_COURSES 10

// Structures
typedef struct {
    char studentID[20];
    char courseID[10];
} WaitlistEntry;

typedef struct {
    char studentID[20];
    char completedCourses[MAX_COURSES][10];
    int courseCount;
} StudentHistory;

// Global Variables
extern StudentHistory studentHistory[MAX_STUDENTS];
extern int studentCount;

extern WaitlistEntry waitlist[MAX_STUDENTS];
extern int waitlistCount;

// Function Prototypes (to be defined by each member)
void addStudentPathway();
void deleteStudentPathway();
void searchStudentPathway();
void addCompletedCourse();
void addToWaitlist();
void enrollFromWaitlist();
void displayWaitlist();

#endif
