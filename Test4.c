#include <stdio.h>
#include <ctype.h>

int findCharType(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= 'a' && c <= 'z') {
        return 2;
    } else if (c >= '0' && c <= '9') {
        return 3;
    } else if (isprint(c)) {
        return 4;
    } else {
        return 5;
    }
}

int main() {
    char character;

    printf("Enter a character: ");
    scanf("%c", &character);

    int type = findCharType(character);

    printf("Type: %d\n", type);

    return 0;
}
