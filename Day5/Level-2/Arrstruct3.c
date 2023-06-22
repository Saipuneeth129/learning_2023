/*
L2-Day5
3. Write a C function to swap 2 members in different indexes (based on user input) in the above array of structures
*/
/*Source Code:*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Employee {
    int empId;
    char name[50];
    float salary;
};

void swapEmployees(struct Employee* arr, int index1, int index2) {
    struct Employee temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

int main() {
    struct Employee employees[5];

    employees[0].empId = 1;
    strcpy(employees[0].name, "Puneeth");
    employees[0].salary = 6000.0;

    employees[1].empId = 2;
    strcpy(employees[1].name, "Pratheek");
    employees[1].salary = 8000.0;

    employees[2].empId = 3;
    strcpy(employees[2].name, "Praveen");
    employees[2].salary = 6600.0;

    employees[3].empId = 4;
    strcpy(employees[3].name, "Prithvi");
    employees[3].salary = 7500.0;

    employees[4].empId = 5;
    strcpy(employees[4].name, "Purna");
    employees[4].salary = 4800.0;

    int index1, index2;

    printf("Enter the indexes of the employees to swap (0-4): ");
    scanf("%d %d", &index1, &index2);

    if (index1 >= 0 && index1 < 5 && index2 >= 0 && index2 < 5) {
        swapEmployees(employees, index1, index2);

        printf("After swapping:\n");
        printf("Employee %d: %s, Salary: %.2f\n", employees[index1].empId, employees[index1].name, employees[index1].salary);
        printf("Employee %d: %s, Salary: %.2f\n", employees[index2].empId, employees[index2].name, employees[index2].salary);
    } else {
        printf("Invalid indexes!\n");
    }

    return 0;
}
/*
Output for this code:
Enter the indexes of the employees to swap (0-4): 2
1
After swapping:
Employee 2: Pratheek, Salary: 8000.00
Employee 3: Praveen, Salary: 6600.00
*/
