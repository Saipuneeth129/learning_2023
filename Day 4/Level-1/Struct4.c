/*
L1 Activity Day-4
write a C program to Store Data for n students in Structures Dynamically. 
*/
/*Source code:*/
#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int Age;
    float grade;
};

int main() {
    int n;
    struct Student* students;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for 'n' students
    students = (struct Student*)malloc(n * sizeof(struct Student));

    
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);

        printf("Enter name: ");
        scanf("%s", students[i].name);

        printf("Enter Age: ");
        scanf("%d", &students[i].Age);

        printf("Enter grade: ");
        scanf("%f", &students[i].grade);
    }

    
    printf("\n\nStudent Data:\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].Age);
        printf("Grade: %.2f\n", students[i].grade);
    }

    // Free dynamically allocated memory
    free(students);

    return 0;
}

/*
Output for this code:
Enter the number of students: 2

Student 1:
Enter name: Puneeth
Enter Age: 22
Enter grade: 16

Student 2:
Enter name: Pratheek
Enter Age: 17
Enter grade: 12


Student Data:

Student 1:
Name: Puneeth
Age: 22
Grade: 16.00

Student 2:
Name: Pratheek
Age: 17
Grade: 12.00
*/
