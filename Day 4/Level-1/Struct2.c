/*
L1-Day4
2. Write a C program that uses functions to perform the following operations: 
     i) Reading a complex number 
     ii) Writing a complex number 
     iii) Addition of two complex numbers 
     iv) Multiplication of two complex numbers 
  (Note: represent complex number using a structure.
*/
#include <stdio.h>

// Structure to represent complex numbers
typedef struct {
    float real;
    float imag;
} Complex;

void readComplex(Complex *c) {
    printf("Enter the real part: ");
    scanf("%f", &(c->real));
    printf("Enter the imaginary part: ");
    scanf("%f", &(c->imag));
}


void writeComplex(Complex c) {
    printf("Complex number: %.2f + %.2fi\n", c.real, c.imag);
}


Complex addComplex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}


Complex multiplyComplex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;
    return result;
}

int main() {
    Complex num1, num2, sum, product;

    printf("Enter the first complex number:\n");
    readComplex(&num1);

    printf("\nEnter the second complex number:\n");
    readComplex(&num2);

    printf("\n");

    // Addition of two complex numbers
    sum = addComplex(num1, num2);
    printf("Addition: ");
    writeComplex(sum);

    // Multiplication of two complex numbers
    product = multiplyComplex(num1, num2);
    printf("Multiplication: ");
    writeComplex(product);

    return 0;
}
/*
Output:
Enter the first complex number:
Enter the real part: 3.5
Enter the imaginary part: 2.7
Enter the second complex number:
Enter the real part: 1.2
Enter the imaginary part: 4.9

First complex number: Complex number: 3.50 + 2.70i
Second complex number: Complex number: 1.20 + 4.90i
Sum of the complex numbers: Complex number: 4.70 + 7.60i
Product of the complex numbers: Complex number: -9.03 + 20.53i

*/
