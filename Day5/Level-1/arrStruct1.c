/*
Level-1:
1. Assume User will be providing input in the form of a string as show below. 
Write a function to parse the string and initialize an array of structures. 

Example String : "1001 Aron 100.00" 
Example Structure : 
    struct Student{
        int rollno;
        char name[20];
        float marks;
    };

Note: User must be able define the no. of inputs/size of the array during runtime.
*/
/*Source Code:*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(const char* inputString, struct Student* students, int numStudents) {
    const char* delimiter = " ";
    char* token;
    char* endptr;
    int i = 0;
    
    token = strtok((char*)inputString, delimiter);

    while (token != NULL && i < numStudents) {
        students[i].rollno = strtol(token, &endptr, 10);
        token = strtok(NULL, delimiter);

        if (token != NULL) {
            strncpy(students[i].name, token, sizeof(students[i].name) - 1);
            students[i].name[sizeof(students[i].name) - 1] = '\0';
            token = strtok(NULL, delimiter);
        }

        if (token != NULL) {
            students[i].marks = strtof(token, &endptr);
            token = strtok(NULL, delimiter);
        }

        i++;
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    while (getchar() != '\n');
    
    char inputString[100];
    printf("Enter the string: ");
    fgets(inputString, sizeof(inputString), stdin);
    inputString[strcspn(inputString, "\n")] = '\0';
    
    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    parseString(inputString, students, numStudents);
    printf("Parsed data:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
    
    free(students);
    
    return 0;
}
/*
Output for this code:
Enter the number of students: 2
Enter the string: 1001 puneeth 100.00
Parsed data:
Student 1:
Roll No: 1001
Name: puneeth
Marks: 100.00

Student 2:
Roll No: 1752457586
Name: eek\Desktop\learning_202│ÜVWº
Marks: 0.00
*/