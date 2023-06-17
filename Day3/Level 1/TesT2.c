/* Level-1
   Day-3
 2. Prints Bits:
Scan a 32bit integer and prints its bits.

Concepts to be used.
- Loops
- Bitwise Operators

 */
#include <stdio.h>

void printBits(int num) {
    unsigned int mask = 1 << 31;  // Starting from the leftmost bit (most significant bit)

    for (int i = 0; i < 32; i++) {
        if ((num & mask) == 0)
            printf("0");
        else
            printf("1");

        mask >>= 1;  // Shift the mask one bit to the right
    }
    printf("\n");
}

int main() {
    int num;

    printf("Enter a 32-bit integer: ");
    scanf("%d", &num);

    printf("Bits: ");
    printBits(num);

    return 0;
}
