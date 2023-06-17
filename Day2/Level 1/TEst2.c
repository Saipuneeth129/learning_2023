#include <stdio.h>
#include <string.h>
void swap(void *a, void *b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

int main() {
    int num1 = 10, num2 = 20;
    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2, sizeof(int));
    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);

    char char1 = 'A', char2 = 'B';
    printf("Before swapping: char1 = %c, char2 = %c\n", char1, char2);
    swap(&char1, &char2, sizeof(char));
    printf("After swapping: char1 = %c, char2 = %c\n", char1, char2);

    double double1 = 3.14, double2 = 2.71;
    printf("Before swapping: double1 = %lf, double2 = %lf\n", double1, double2);
    swap(&double1, &double2, sizeof(double));
    printf("After swapping: double1 = %lf, double2 = %lf\n", double1, double2);

    return 0;
}
