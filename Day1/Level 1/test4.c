#include <stdio.h>

int main() {
    double operand1, operand2;
    char operator;

    printf("Enter Number1: ");
    scanf("%lf", &operand1);

    printf("Enter the operator: ");
    scanf(" %c", &operator);

    printf("Enter Number2: ");
    scanf("%lf", &operand2);

    double result;
    switch (operator) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            result = operand1 / operand2;
            break;
        default:
            printf("Invalid operator\n");
            return 0;
    }

    printf("Result: %.2lf\n", result);

    return 0;
}
