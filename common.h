#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPECIALTIES 10
#define MAX_SECTIONS 5
#define MAX_COURSES 10
#define MAX_WAITLIST 100
#define MAX_STUDENTS 100
#define MAX_LINE_LENGTH 100

// Structures
typedef struct {
    char courseID[10];
    char day[10];
    char time[10];
} CourseSchedule;

typedef struct {
    char sectionName[10];
    char courses[MAX_COURSES][50];
    CourseSchedule planning[MAX_COURSES];
    int courseCount;
} Section;

typedef struct {
    char specialtyName[50];
    Section sections[MAX_SECTIONS];
    int sectionCount;
} Specialty;

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
extern Specialty specialties[MAX_SPECIALTIES];
extern int specialtyCount;

extern WaitlistEntry waitlist[MAX_WAITLIST];
extern int waitlistCount;

extern StudentHistory studentHistory[MAX_STUDENTS];
extern int studentCount;

// Function Prototypes (to be defined by each member)
void addSpecialty();
void addSection();
void addCourse();
void deleteSpecialty();
void deleteSection();
void deleteCourse();
void searchSpecialty();
void searchSection();
void searchCourse();
void addToWaitlist(char *studentID, char *courseID);
void enrollFromWaitlist(char *courseID);
void displayWaitlist();
void addCompletedCourse(char *studentID, char *courseID);
void displayCompletedCourses(char *studentID);
void saveToFile();
void loadFromFile();

#endif
