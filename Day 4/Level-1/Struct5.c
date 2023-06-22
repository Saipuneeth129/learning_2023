/*
L1 Activity-Day4 
5.Write a C program to demonstrate the swapping the fields of two structures using pointers.
*/
/*Source Code:*/
#include <stdio.h>

struct Point {
    int x;
    int y;
};

void swapPoints(struct Point *p1, struct Point *p2) {
 
    int tempX = p1->x;
    p1->x = p2->x;
    p2->x = tempX;

    
    int tempY = p1->y;
    p1->y = p2->y;
    p2->y = tempY;
}

int main() {
    struct Point point1 = {10, 7};
    struct Point point2 = {15, 20};

    printf("Before swapping:\n");
    printf("Point 1: x = %d, y = %d\n", point1.x, point1.y);
    printf("Point 2: x = %d, y = %d\n", point2.x, point2.y);

    // Passing pointers to the swapping the pointers->swapPoints function
    swapPoints(&point1, &point2);

    printf("\nAfter swapping:\n");
    printf("Point 1: x = %d, y = %d\n", point1.x, point1.y);
    printf("Point 2: x = %d, y = %d\n", point2.x, point2.y);

    return 0;
}

/*
Output for this code:
Before swapping:
Point 1: x = 10, y = 7
Point 2: x = 15, y = 20

After swapping:
Point 1: x = 15, y = 20
Point 2: x = 10, y = 7
*/