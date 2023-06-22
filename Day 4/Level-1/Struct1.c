/*
Day-4 
L1 Activities:Write a C program using structures?

1. Use structures to find the volume and the total surface area of the box. 
   You need to access the members of the structure with the help of a structure pointer:
    a. With the help of (*) asterisk or indirection operator and (.) dot operator.
    b. With the help of ( -> ) Arrow operator using pointer as well as dot representation.
*/
#include <stdio.h>

struct Cylinder {
    float radius;
    float height;
};

float calculateVolume(struct Cylinder *cylinder) {
    return 3.14 * cylinder->radius * cylinder->radius * cylinder->height;
}

float calculateSurfaceArea(struct Cylinder *cylinder) {
    return 2 * 3.14 * cylinder->radius * (cylinder->radius + cylinder->height);
}

int main() {
    struct Cylinder myCylinder;
    struct Cylinder *ptrCylinder;

    // Accessing members using dot operator
    myCylinder.radius = 3.5;
    myCylinder.height = 6.0;

    printf("Using dot operator:\n");
    printf("Radius: %.2f\n", myCylinder.radius);
    printf("Height: %.2f\n", myCylinder.height);
    printf("Volume: %.2f\n", calculateVolume(&myCylinder));
    printf("Surface Area: %.2f\n", calculateSurfaceArea(&myCylinder));

    // Accessing members using arrow operator with pointer
    ptrCylinder = &myCylinder;
    ptrCylinder->radius = 7.0;
    ptrCylinder->height = 10.0;

    printf("\nUsing arrow operator:\n");
    printf("Radius: %.2f\n", ptrCylinder->radius);
    printf("Height: %.2f\n", ptrCylinder->height);
    printf("Volume: %.2f\n", calculateVolume(ptrCylinder));
    printf("Surface Area: %.2f\n", calculateSurfaceArea(ptrCylinder));

    return 0;
}
/*
Output for Day-4 L1 activity of struct1
Using dot operator:
Radius: 3.50
Height: 6.00
Volume: 230.79
Surface Area: 208.81

Using arrow operator:
Radius: 7.00
Height: 10.00
Volume: 1538.60
Surface Area: 747.32
*/

#include <stdio.h>

// Structure definition for a box
struct Box {
    double length;
    double width;
    double height;
};

// Function to calculate the volume of the box
double calculateVolume(struct Box* box) {
    return box->length * box->width * box->height;
}

// Function to calculate the total surface area of the box
double calculateSurfaceArea(struct Box* box) {
    return 2 * (box->length * box->width + box->length * box->height + box->width * box->height);
}

int main() {
    // Declare a box structure variable
    struct Box myBox;
    
    // Initialize the box dimensions
    myBox.length = 5.0;
    myBox.width = 3.0;
    myBox.height = 4.0;
    
    // Calculate the volume and surface area using the structure pointer with (*) asterisk and (.) dot operators
    double volume = calculateVolume(&myBox);
    double surfaceArea = calculateSurfaceArea(&myBox);
    
    // Print the results
    printf("Volume: %.2f\n", volume);
    printf("Total Surface Area: %.2f\n", surfaceArea);
    
    return 0;
}