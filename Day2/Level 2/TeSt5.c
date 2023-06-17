#include <stdio.h>
#include <string.h>

void encode(char* str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        str[i] = str[i] + 5;  // Add 5 to each character
    }
}

void decode(char* str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        str[i] = str[i] - 5;  // Subtract 5 from each character
    }
}

int main() {
    char message[100];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    // Remove newline character from fgets
    if (message[strlen(message) - 1] == '\n') {
        message[strlen(message) - 1] = '\0';
    }

    // Encode the message
    encode(message);
    printf("Encoded message: %s\n", message);

    // Decode the message
    decode(message);
    printf("Decoded message: %s\n", message);

    return 0;
}
