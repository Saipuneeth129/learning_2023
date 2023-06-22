/*
L2 Activity-Day4
*/
/*Source Code*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int id;
    char name[50];
} Student;


Student* modifyStructure(Student* student) {
    student->id = 1924144;
    strcpy(student->name, "Puneeth");

    return student;
}

int main() {
    Student student;
    student.id = 0;
    strcpy(student.name, "UnknownGuy");
    Student* modifiedStudent = modifyStructure(&student);


    printf("Modified ID: %d\n", modifiedStudent->id);
    printf("Modified Name: %s\n", modifiedStudent->name);

    return 0;
}
/*
Output for this code:
Modified ID: 1924144
Modified Name: Puneeth
*/