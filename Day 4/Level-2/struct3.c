/*
L2-Day 4
3.Write a C program to implement structures to read, write and compute average- marks and the students scoring above
   and below the average marks for a class of N students.
*/
/*Source code:*/
#include <stdio.h>

#define MAX_STUDENTSAVG 50

struct Student1 {
    char name[50];
    float marks;
};

void readStudent(struct Student1 *student) {
    printf("Enter student name: ");
    scanf("%s", student->name);
    printf("Enter marks: ");
    scanf("%f", &(student->marks));
}

void writeStudent(struct Student1 student) {
    printf("Name: %s\n", student.name);
    printf("Marks: %.2f\n", student.marks);
}

float computeAverage(struct Student1 students[], int numStudents) {
    float sum = 0.0;
    for (int i = 0; i < numStudents; i++) {
        sum += students[i].marks;
    }
    return sum / numStudents;
}

void findingStudentsAboveAndBelowAverage(struct Student1 students[], int numStudents, float average) {
    printf("Students scoring above average:\n");
    for (int i = 0; i < numStudents; i++) {
        if (students[i].marks > average) {
            writeStudent(students[i]);
        }
    }

    printf("Students scoring below average:\n");
    for (int i = 0; i < numStudents; i++) {
        if (students[i].marks < average) {
            writeStudent(students[i]);
        }
    }
}

int main() {
    int numStudents;
    struct Student1 students[MAX_STUDENTSAVG];

    printf("Enter the number of students (up to %d): ", MAX_STUDENTSAVG);
    scanf("%d", &numStudents);

    if (numStudents <= 0 || numStudents > MAX_STUDENTSAVG) {
        printf("Invalid number of students. Please try again.\n");
        return 0;
    }

    for (int i = 0; i < numStudents; i++) {
        printf("Enter details for student %d:\n", i + 1);
        readStudent(&students[i]);
    }

    float average = computeAverage(students, numStudents);
    printf("Average marks: %.2f\n", average);

    findingStudentsAboveAndBelowAverage(students, numStudents, average);

    return 0;
}
/*
Output for this code:
Enter the number of students (up to 50): 3
Enter details for student 1:
Enter student name: puneeth
Enter marks: 75
Enter details for student 2:
Enter student name: pratheek
Enter marks: 95
Enter details for student 3:
Enter student name: Praveen
Enter marks: 100
Average marks: 90.00
Students scoring above average:
Name: pratheek
Marks: 95.00
Name: Praveen
Marks: 100.00
Students scoring below average:
Name: puneeth
Marks: 75.00
*/