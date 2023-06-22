/*
L2-Day5
2. Write a C function to delete a member at the start of the above array of structures
Note : Code must use Dynamic Memory concept
*/
/*Source Code:*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int id;
    char name[50];
    int age;
} Member;

void deleteMemberAtStart(Member** array, int* size) {
    if (*size <= 0) {
        printf("Array is empty. Cannot delete member.\n");
        return;
    }
    for (int i = 0; i < *size - 1; i++) {
        (*array)[i] = (*array)[i + 1];
    }

    *size -= 1;

    Member* newArray = (Member*)realloc(*array, (*size) * sizeof(Member));
    if (newArray == NULL) {
        printf("Memory reallocation failed. Unable to delete member.\n");
        return;
    }

    *array = newArray;

    printf("Member at the start deleted successfully.\n");
}

int main() {
    Member* members = (Member*)malloc(3 * sizeof(Member));
    int size = 3;

    members[0].id = 1;
    strcpy(members[0].name, "Puneeth");
    members[0].age = 25;

    members[1].id = 2;
    strcpy(members[1].name, "Pratheek");
    members[1].age = 28;

    members[2].id = 3;
    strcpy(members[2].name, "Puneeth");
    members[2].age = 30;
    printf("Array before deletion:\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", members[i].id, members[i].name, members[i].age);
    }

    deleteMemberAtStart(&members, &size);

    printf("Array after deletion:\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", members[i].id, members[i].name, members[i].age);
    }

    free(members);

    return 0;
}

/*
Output for this code:
Array before deletion:
ID: 1, Name: Puneeth, Age: 25
ID: 2, Name: Pratheek, Age: 28
ID: 3, Name: Puneeth, Age: 30
Member at the start deleted successfully.
Array after deletion:
ID: 2, Name: Pratheek, Age: 28
ID: 3, Name: Puneeth, Age: 30
*/