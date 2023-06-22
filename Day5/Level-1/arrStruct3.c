/*
L1-Day 5
3. Write a C function to display all members in the above array of structures
*/
/*Source Code:*/
#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

void displayEmployees(Employee employees[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Employee ID: %d\n", employees[i].id);
        printf("Employee Name: %s\n", employees[i].name);
        printf("Employee Salary: %.2f\n", employees[i].salary);
        printf("\n");
    }
}

int main() {
    // Example usage
    Employee employees[3] = {
        {1, "H Saipuneeth", 10000.20},
        {2, "H Pratheek", 3000.25},
        {3, "H Praveen", 2500.70}
    };

    int size = sizeof(employees) / sizeof(employees[0]);
    displayEmployees(employees, size);

    return 0;
}

/*Output for this code:
Employee ID: 1
Employee Name: H Saipuneeth
Employee Salary: 10000.20

Employee ID: 2
Employee Name: H Pratheek
Employee Salary: 3000.25

Employee ID: 3
Employee Name: H Praveen
Employee Salary: 2500.70

*/
