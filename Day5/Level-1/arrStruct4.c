/*
L1-Day5
4. Write a C function to sort the array of structures in descending order based on marks. 
*/
/*Source Code:*/
#include <stdio.h>

struct Student {
    int rollNumber;
    char name[50];
    float marks;
};

void swap(struct Student* a, struct Student* b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

void sortDescending(struct Student arr[], int size) {
    int i, j;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j].marks < arr[j + 1].marks) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    struct Student students[] = {
        { 1, "Shyaeera", 86.25 },
        { 2, "Alqzeera", 95.0 },
        { 3, "Alknanda", 76.75 },
        { 4, "Mark Roy", 95.5 },
        { 5, "Siachen", 80.0 }
    };

    int size = sizeof(students) / sizeof(students[0]);
    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll Number: %d, Name: %s, Marks: %.2f\n",
               students[i].rollNumber, students[i].name, students[i].marks);
    }
    sortDescending(students, size);
    printf("\nSorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll Number: %d, Name: %s, Marks: %.2f\n",
               students[i].rollNumber, students[i].name, students[i].marks);
    }

    return 0;
}
/*
Output for this code:
Original array:
Roll Number: 1, Name: Shyaeera, Marks: 86.25
Roll Number: 2, Name: Alqzeera, Marks: 95.00
Roll Number: 3, Name: Alknanda, Marks: 76.75
Roll Number: 4, Name: Mark Roy, Marks: 95.50
Roll Number: 5, Name: Siachen, Marks: 80.00

Sorted array:
Roll Number: 4, Name: Mark Roy, Marks: 95.50
Roll Number: 2, Name: Alqzeera, Marks: 95.00
Roll Number: 1, Name: Shyaeera, Marks: 86.25
Roll Number: 5, Name: Siachen, Marks: 80.00
Roll Number: 3, Name: Alknanda, Marks: 76.75
*/