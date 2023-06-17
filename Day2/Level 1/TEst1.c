#include <stdio.h>

int main() {
    double x = 0.7;
    unsigned long long* ptr = (unsigned long long*)&x;
    unsigned long long bits = *ptr;
    
    unsigned int exponent = (bits >> 52) & 0x7FF; // Extracting exponent bits
    
    printf("Exponent in hexadecimal: 0x%X\n", exponent);
    
    // Converting exponent to binary format
    printf("Exponent in binary: ");
    for (int i = 10; i >= 0; i--) {
        printf("%d", (exponent >> i) & 1);
    }
    printf("\n");
    
    return 0;
}
