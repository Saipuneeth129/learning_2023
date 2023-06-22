/*
L2-Day5
1. Write a C function to add a member at the end of the above array of structures
Note : Code must use Dynamic Memory concept
*/
/*Source Code*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int id;
    char name[50];
} Member;

Member* addMember(Member* array, int size, int newId, const char* newName) {
    Member newMember;
    newMember.id = newId;
    strcpy(newMember.name, newName);
    Member* newArray = realloc(array, (size + 1) * sizeof(Member));
    if (newArray == NULL) {
        printf("Memory allocation failed. Unable to add member.\n");
        return array;
    }
    newArray[size] = newMember;

    return newArray;
}

int main() {
    int size = 3;
    Member* array = malloc(size * sizeof(Member));
    array[0].id = 1;
    strcpy(array[0].name, "Pratheek");
    array[1].id = 2;
    strcpy(array[1].name, "Puneeth");
    array[2].id = 3;
    strcpy(array[2].name, "Praveen");
    array = addMember(array, size, 4, "Prithvi");
    size++;
    for (int i = 0; i < size; i++) {
        printf("Member %d: ID = %d, Name = %s\n", i + 1, array[i].id, array[i].name);
    }
    free(array);

    return 0;
}
/*
Output for this code:
Member 1: ID = 1, Name = Pratheek
Member 2: ID = 2, Name = Puneeth
Member 3: ID = 3, Name = Praveen
Member 4: ID = 4, Name = Prithvi
*/