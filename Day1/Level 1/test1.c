/* 1. Write a function to find biggest of 2 numbers using 
    - ternary operator*/
    
#include <stdio.h>

int findMax(int num1, int num2) {
    int max = (num1 > num2) ? num1 : num2;
    return max;
}

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    
    int result = findMax(a, b);
    printf("The biggest number is: %d\n", result);
    
    return 0;
}
