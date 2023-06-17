#include <stdio.h>

void decimalToBCD(int decimal, int *bcd)
{
    int i = 0;
    
    while (decimal > 0) {
        bcd[i] = decimal % 10;
        decimal /= 10;
        i++;
    }
}

int main()
{
    int decimal = 1234;
    int bcd[10];  // Assuming a maximum of 10 digits
    
    decimalToBCD(decimal, bcd);
    
    printf("BCD representation: ");
    
    for (int i = 9; i >= 0; i--) {
        printf("%d", bcd[i]);
    }
    
    printf("\n");
    
    return 0;
}
