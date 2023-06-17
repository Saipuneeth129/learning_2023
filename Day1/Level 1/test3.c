/*Write a program to read the 
    - Roll No
    - Name (Note, you should read full name of the student including initials)
    - Marks of Physics, Math and Chemistry
    Calculate the total, percentage and print the summary.*/

#include <stdio.h>

int main() {
    int rollNo;
    char name[50];
    float physicsMarks, mathMarks, chemistryMarks;
    float totalMarks, percentage;

    // Read student information
    printf("Enter Roll No: ");
    scanf("%d", &rollNo);
    printf("Enter Name: ");
    scanf(" %[^\n]s", name);
    printf("Enter Physics Marks: ");
    scanf("%f", &physicsMarks);
    printf("Enter Math Marks: ");
    scanf("%f", &mathMarks);
    printf("Enter Chemistry Marks: ");
    scanf("%f", &chemistryMarks);

    // Calculate total and percentage
    totalMarks = physicsMarks + mathMarks + chemistryMarks;
    percentage = (totalMarks / 300) * 100;

    // Print the summary
    printf("\n--- Student Summary ---\n");
    printf("Roll No: %d\n", rollNo);
    printf("Name: %s\n", name);
    printf("Physics Marks: %.2f\n", physicsMarks);
    printf("Math Marks: %.2f\n", mathMarks);
    printf("Chemistry Marks: %.2f\n", chemistryMarks);
    printf("Total Marks: %.2f\n", totalMarks);
    printf("Percentage: %.2f%%\n", percentage);

    return 0;
}
