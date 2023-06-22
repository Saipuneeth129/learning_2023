/*
L2-Day5
2. Write a function to initialize all members in the above array of structures
*/
/*Source Code:*/
#include <stdio.h>

struct MyStruct {
    int id;
    float value;
    char name[20];
};

void initializeStructArray(struct MyStruct array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i].id = 0;
        array[i].value = 0.0;
        array[i].name[0] = '\0';
    }
}

int main() {
    struct MyStruct myArray[5];

    initializeStructArray(myArray, 5);
    for (int i = 0; i < 5; i++) {
        printf("Element %d: id = %d, value = %f, name = %s\n", i, myArray[i].id, myArray[i].value, myArray[i].name);
    }

    return 0;
}
/*
Output for this code:
Element 0: id = 0, value = 0.000000, name = 
Element 1: id = 0, value = 0.000000, name = 
Element 2: id = 0, value = 0.000000, name = 
Element 3: id = 0, value = 0.000000, name = 
Element 4: id = 0, value = 0.000000, name = 
*/
