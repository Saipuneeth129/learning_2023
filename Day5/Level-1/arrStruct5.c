/*
L1-Day 5
5. Write a C function to perform a search operation on the array of structures based on name of the student
*/
/*Source Code*/
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTHCOUNT 50
#define MAX_STUDENTSPRESENT 100

typedef struct {
    char name[MAX_NAME_LENGTHCOUNT];
    int age;
    float gpa;
} Student;

int searchStudentByName(Student students[], int numStudents, const char* name) {
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    Student students[MAX_STUDENTSPRESENT];
    int numStudents;
    numStudents = 3;
    strcpy(students[0].name, "Puneeth");
    students[0].age = 20;
    students[0].gpa = 3.8;
    
    strcpy(students[1].name, "Pratheek");
    students[1].age = 21;
    students[1].gpa = 3.5;
    
    strcpy(students[2].name, "Praveen");
    students[2].age = 19;
    students[2].gpa = 3.9;
    
    char searchName[MAX_NAME_LENGTHCOUNT];
    printf("Enter the name of the student to search: ");
    scanf("%s", searchName);
    
    int index = searchStudentByName(students, numStudents, searchName);
    
    if (index != -1) {
        printf("Student found at index %d\n", index);
        printf("Name: %s\n", students[index].name);
        printf("Age: %d\n", students[index].age);
        printf("GPA: %.2f\n", students[index].gpa);
    } else {
        printf("Student not found.\n");
    }
    
    return 0;
}
/*
Output for this code:
Enter the name of the student to search: Puneeth
Student found at index 0
Name: Puneeth
Age: 20
GPA: 3.80
*/