/*
L2-Day6
2. Write a C program to update an entry in the data.csv based on the "EntryNo" field

a. Use only file handling concepts

b. Use array of structures and file handling
*/
/*
Source Code:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define FILENAME "data.csv"

typedef struct {
    int entryNo;
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
} Entry;

void updateEntry(int entryNo) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    FILE *tempFile = fopen("temp.csv", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }

    char line[MAX_LENGTH];
    int found = 0;

    while (fgets(line, MAX_LENGTH, file) != NULL) {
        Entry entry;
        sscanf(line, "%d,%[^,],%s", &entry.entryNo, entry.name, entry.email);

        if (entry.entryNo == entryNo) {
            printf("Enter new name: ");
            fgets(entry.name, MAX_LENGTH, stdin);
            entry.name[strcspn(entry.name, "\n")] = '\0';

            printf("Enter new email: ");
            fgets(entry.email, MAX_LENGTH, stdin);
            entry.email[strcspn(entry.email, "\n")] = '\0';

            fprintf(tempFile, "%d,%s,%s\n", entry.entryNo, entry.name, entry.email);
            found = 1;
            printf("Entry updated successfully.\n");
        } else {
            fprintf(tempFile, "%d,%s,%s", entry.entryNo, entry.name, entry.email);
        }
    }

    if (!found) {
        printf("Entry not found.\n");
    }

    fclose(file);
    fclose(tempFile);
    remove(FILENAME);
    rename("temp.csv", FILENAME);
}

int main() {
    int entryNo;

    printf("Enter the entry number to update: ");
    scanf("%d", &entryNo);

    updateEntry(entryNo);

    return 0;
}

/*Output for this Code:
Enter the entry number to update: 
2
Error opening file.
*/

