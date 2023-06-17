/*Level-1
  Day-3
5. Write a program to find both smallest and largest digits in given n numbers
For example let's say we have n = 3, and n1 = 8, n2 = 156, n3 = 123450, the result will be "Not Valid", 1 and 6, 0 and 5
*/
#include <stdio.h>

// Function to find the smallest digit in a number
int findSmallestDigit(int num) {
    int smallest = 9; // Initialize with largest possible digit

    while (num > 0) {
        int digit = num % 10;
        if (digit < smallest)
            smallest = digit;
        num /= 10;
    }

    return smallest;
}

// Function to find the largest digit in a number
int findLargestDigit(int num) {
    int largest = 0; // Initialize with smallest possible digit

    while (num > 0) {
        int digit = num % 10;
        if (digit > largest)
            largest = digit;
        num /= 10;
    }

    return largest;
}

int main() {
    int n, num, smallest, largest;

    printf("Enter the number of values: ");
    scanf("%d", &n);

    printf("Enter %d numbers: \n", n);
    scanf("%d", &num);

    smallest = findSmallestDigit(num);
    largest = findLargestDigit(num);

    for (int i = 1; i < n; i++) {
        scanf("%d", &num);
        int smallestDigit = findSmallestDigit(num);
        int largestDigit = findLargestDigit(num);

        if (smallestDigit < smallest)
            smallest = smallestDigit;
        if (largestDigit > largest)
            largest = largestDigit;
    }

    printf("Smallest digit: %d\n", smallest);
    printf("Largest digit: %d\n", largest);

    return 0;
}
