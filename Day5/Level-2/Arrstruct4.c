/*
L2-Day 5
4.Write a C function to rotate the above array of structures by K positions.
*/
/*Source Code:*/
#include <stdio.h>

struct MyStruct {
    int data;
};

void rotateArray(struct MyStruct arr[], int size, int k) {
    k = k % size;
    if (k < 0)
        k += size;

    int i, j;
    for (i = 0, j = size - 1; i < j; i++, j--) {
        struct MyStruct temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    for (i = 0, j = k - 1; i < j; i++, j--) {
        struct MyStruct temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    for (i = k, j = size - 1; i < j; i++, j--) {
        struct MyStruct temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void printArray(struct MyStruct arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    struct MyStruct arr[] = {
        {1}, {2}, {3}, {4}, {5}
    };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    int k = 2;

    rotateArray(arr, size, k);

    printf("Rotated array: ");
    printArray(arr, size);

    return 0;
}
/*
Output Code:
Original array: 1 2 3 4 5 
Rotated array: 4 5 1 2 3 
*/