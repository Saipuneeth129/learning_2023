/* Level-1
    Day -2
    3. Write a program to sum every alternate elements of a given array starting for element 0
For example, let's say we have a[5] = {10, 20, 30, 40, 50}, the result should be 10 + 30 + 50 = 90

Topics to be covered
- Arrays
- Loops
- Basic Operators
*/
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int length = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;

    for (int i = 0; i < length; i += 2) {
        sum += arr[i];
    }

    printf("The sum of alternate elements starting from element 0 is: %d\n", sum);

    return 0;
}
