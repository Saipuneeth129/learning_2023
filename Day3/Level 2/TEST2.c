/*Level-2
  Day-3
2. BCD to Decimal:
https://1.bp.blogspot.com/-Tfj_D_f_AF0/VZO5QIIGAUI/AAAAAAAAAmI/5Rw6uIU3EiI/s1600/DS1307%2BTime%2BKeeper%2BRegister.PNG

DS1307 has its time registers in BCD format as shown in the image found in the above link, To set the time we need to convert the decimal number to BCD format, hence, write a fucntion to convert decimal to BCD

Concepts to be used.
- Operators
- Preprocessor
*/
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
