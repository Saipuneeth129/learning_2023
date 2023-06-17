#include <stdio.h>

// Function to count the number of set bits in an integer
int countSetBits(int num)
{
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

// Function to count the total number of set bits in an array
int countTotalSetBits(int arr[], int size)
{
    int totalSetBits = 0;
    for (int i = 0; i < size; i++) {
        totalSetBits += countSetBits(arr[i]);
    }
    return totalSetBits;
}

int main()
{
    int arr[] = {5, 3, 10, 6, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    int totalSetBits = countTotalSetBits(arr, size);

    printf("Total number of set bits: %d\n", totalSetBits);

    return 0;
}
