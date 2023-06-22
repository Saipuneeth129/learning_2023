/*
L1-Day6
2. Case Handler:
Write a C program to copy a file by considering the user option to handle the text case
-u, to change file content to Upper Case
-l, to change file content to Lower Case
-s, to change file content to Sentence Case
if no options are passed then it should be a normal copy

Example, say we have a file f1 with the following content
f1:
-----------------------
This is the file data
testing Case copy
application
-----------------------

./cp -s f1 f2
f2:
-----------------------
This Is The Tile Data
Testing Case Copy
Application
-----------------------

./cp -l f1 f3
f3:
-----------------------
this is the tile data
testing case copy
application
-----------------------

./cp -u f1 f4
f4:
-----------------------
THIS IS THE FILE DATA
TESTING CASE COPY
APPLICATION
-----------------------

./cp f1 f5
Should perform a normal copy
*/

/*Source Code:*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void copyFile(const char* srcFilename, const char* destFilename, int convertCase) {
    FILE* srcFile = fopen(srcFilename, "r");
    FILE* destFile = fopen(destFilename, "w");

    if (srcFile == NULL || destFile == NULL) {
        printf("Failed to open the file.\n");
        exit(1);
    }

    int ch;
    while ((ch = fgetc(srcFile)) != EOF) {
        if (convertCase == 1)
            ch = toupper(ch);
        else if (convertCase == -1)
            ch = tolower(ch);
        else if (convertCase == 0)
            ch = isalnum(ch) ? tolower(ch) : ch;
        else if (convertCase == 2) {
            if (isalpha(ch)) {
                if (islower(ch) && !isalpha(fgetc(srcFile))) {
                    ch = toupper(ch);
                } else {
                    ch = tolower(ch);
                }
            }
        }

        fputc(ch, destFile);
    }

    fclose(srcFile);
    fclose(destFile);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp [option] source_file destination_file\n");
        return 1;
    }

    int convertCase = 0;
    char* option = argv[1];
    if (option[0] == '-') {
        switch (option[1]) {
            case 'u':
                convertCase = 1;
                break;
            case 'l':
                convertCase = -1;
                break;
            case 's':
                convertCase = 2;
                break;
            default:
                printf("Invalid option: %s\n", option);
                return 1;
        }
    }

    char* srcFile = argv[2];
    char* destFile = argv[3];

    copyFile(srcFile, destFile, convertCase);

    printf("File copied successfully.\n");

    return 0;
}

/*Output for this code:
Insufficient arguments
*/
