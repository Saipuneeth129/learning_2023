#include <stdio.h>

int deleteDigit(int num) {
    int largest = 0;
    int multiplier = 1;

    while (num > 0) {
        int deletedNum = (num / 10) * multiplier + (num % 10);
        if (deletedNum > largest)
            largest = deletedNum;
        num /= 10;
        multiplier *= 10;
    }

    return largest;
}

int main() {
    int number;

    printf("Enter a 4-digit number: ");
    scanf("%d", &number);

    if (number < 1000 || number > 9999) {
        printf("Invalid input! Please enter a 4-digit number.\n");
        return 1;
    }

    int largestNum = deleteDigit(number);
    printf("The largest number after deleting a single digit: %d\n", largestNum);

    return 0;
}
