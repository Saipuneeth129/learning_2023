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
