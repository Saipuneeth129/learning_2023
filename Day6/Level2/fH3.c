/*
L2-Day 6
3. Write a C program to delete an entry in the file data.csv file  on the "EntryNo" field

a. Use only file handling concepts

b. Use array of structures and file handling
*/
/*Source Code:*/
/*a. Here's a C program that uses only file handling concepts to delete an entry in the "data.csv" file based on 
the "EntryNo" field:*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100


void deleteEntry(const char* filename, int entryNo) {

    FILE* inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        printf("Failed to open file: %s\n", filename);
        return;
    }
    FILE* tempFile = fopen("temp.csv", "w");
    if (tempFile == NULL) {
        printf("Failed to create temporary file.\n");
        fclose(inputFile);
        return;
    }

    char line[MAX_LINE_LENGTH];
    int entryDeleted = 0;
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        char* token = strtok(line, ",");
        int currentEntryNo = atoi(token);
        if (currentEntryNo == entryNo) {
            entryDeleted = 1;
            continue;
        }


        fputs(line, tempFile);
    }
    fclose(inputFile);
    fclose(tempFile);

    if (remove(filename) != 0) {
        printf("Failed to delete the original file.\n");
        return;
    }
    if (rename("temp.csv", filename) != 0) {
        printf("Failed to rename the temporary file.\n");
        return;
    }

    if (entryDeleted) {
        printf("Entry with EntryNo %d deleted successfully.\n", entryNo);
    } else {
        printf("Entry with EntryNo %d not found.\n", entryNo);
    }
}

int main() {
    int entryNo;

    printf("Enter the EntryNo to delete: ");
    scanf("%d", &entryNo);

    deleteEntry("data.csv", entryNo);

    return 0;
}
/*Output for this a.code:
Enter the EntryNo to delete: 2
Failed to open file: data.csv
*/

/*b. Here's a C program that uses an array of structures and file handling to delete an entry 
in the "data.csv" file based on the "EntryNo" field:*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50

struct Entry {
    int entryNo;
    char name[MAX_NAME_LENGTH];
};

void deleteEntry(const char* filename, int entryNo) {
    struct Entry entries[MAX_ENTRIES];
    int numEntries = 0;
    FILE* inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        printf("Failed to open file: %s\n", filename);
        return;
    }
    while (fscanf(inputFile, "%d,%[^\n]", &entries[numEntries].entryNo, entries[numEntries].name) != EOF) {
        numEntries++;
    }

    fclose(inputFile);

    int entryDeleted = 0;

    FILE* tempFile = fopen("temp.csv", "w");
    if (tempFile == NULL) {
        printf("Failed to create temporary file.\n");
        return;
    }

    for (int i = 0; i < numEntries; i++) {
        if (entries[i].entryNo == entryNo) {
            entryDeleted = 1;
            continue;
        }

        fprintf(tempFile, "%d,%s\n", entries[i].entryNo, entries[i].name);
    }

    fclose(tempFile);

    if (remove(filename) != 0) {
        printf("Failed to delete the original file.\n");
        return;
    }

    if (rename("temp.csv", filename) != 0) {
        printf("Failed to rename the temporary file.\n");
        return;
    }

    if (entryDeleted) {
        printf("Entry with EntryNo %d deleted successfully.\n", entryNo);
    } else {
        printf("Entry with EntryNo %d not found.\n", entryNo);
    }
}

int main() {
    int entryNo;

    printf("Enter the EntryNo to delete: ");
    scanf("%d", &entryNo);

    deleteEntry("data.csv", entryNo);

    return 0;
}
/*Output for this b.code:

*/