/*Level-2
  Day-3
1. Bit Operations:
https://1.bp.blogspot.com/-Tfj_D_f_AF0/VZO5QIIGAUI/AAAAAAAAAmI/5Rw6uIU3EiI/s1600/DS1307%2BTime%2BKeeper%2BRegister.PNG

DS1307 has its time registers in BCD format as shown in the image found in the above link, so 
a. Write a function to Set, clear and toggle bit of an 8-bit number

Concepts to be used.
- Operators
*/
#include <stdio.h>

// Function to set a bit at a given position
unsigned char setBit(unsigned char num, int pos) {
    unsigned char mask = (1 << pos);
    return (num | mask);
}

// Function to clear a bit at a given position
unsigned char clearBit(unsigned char num, int pos) {
    unsigned char mask = ~(1 << pos);
    return (num & mask);
}

// Function to toggle a bit at a given position
unsigned char toggleBit(unsigned char num, int pos) {
    unsigned char mask = (1 << pos);
    return (num ^ mask);
}

int main() {
    unsigned char num = 0x3C;  // 00111100 in binary

    printf("Initial number: 0x%02X\n", num);

    // Set bit 2
    num = setBit(num, 2);
    printf("After setting bit 2: 0x%02X\n", num);

    // Clear bit 5
    num = clearBit(num, 5);
    printf("After clearing bit 5: 0x%02X\n", num);

    // Toggle bit 3
    num = toggleBit(num, 3);
    printf("After toggling bit 3: 0x%02X\n", num);

    return 0;
}
