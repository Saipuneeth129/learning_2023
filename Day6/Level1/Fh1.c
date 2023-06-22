/*
L1-Day 6
1. File Copy: Write a C program to copy a file using file operations.
*/
/*Source Code:*/
#include <stdio.h>

#define LOAD_MEASURE 4096

int main() {
    FILE *sourceFile, *destinationFile;
    char sourcePath[100], destinationPath[100];
    char buffer[LOAD_MEASURE];
    size_t bytesRead;

    printf("Enter the path of the source file: ");
    scanf("%s", sourcePath);

    sourceFile = fopen(sourcePath, "rb");
    if (sourceFile == NULL) {
        printf("Failed to open the source file.\n");
        return 1;
    }

    printf("Enter the path of the destination file: ");
    scanf("%s", destinationPath);

    destinationFile = fopen(destinationPath, "wb");
    if (destinationFile == NULL) {
        printf("Failed to create the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    while ((bytesRead = fread(buffer, 1, LOAD_MEASURE, sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);

    printf("File copied successfully.\n");

    return 0;
}
/*
Output for this code:
Enter the path of the source file: [user enters the path of the source file]
Enter the path of the destination file: [user enters the path of the destination file]
File copied successfully.

*/