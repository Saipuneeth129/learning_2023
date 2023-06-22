/*
L2-Day4 Activity
2. Write a C program to enter to Cartesian coordinate points and display the distance between them.
*/
/*Source code*/
#include <stdio.h>
#include <math.h>

int main() {
    int x1, y1, x2, y2;
    double dist;

    printf("Enter the coordinates of the first point (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the coordinates of the second point (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    printf("The distance between the two points is: %lf\n", dist);

    return 0;
}
/*
Output of this code:
Enter the coordinates of the first point (x1 y1): 4 5
Enter the coordinates of the second point (x2 y2): 10 12
The distance between the two points is: 9.219544
*/
