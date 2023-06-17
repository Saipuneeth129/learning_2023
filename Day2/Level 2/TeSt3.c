/* Level-2
   Day-2
Suppose 7 names are stored in an array of pointers names[] as shown below:
 char *name[]=
 {"Santosh", "Amol", "Santosh Jain", "Kishore", "Rahul", "Amolkumar", "Hemant"}
  Write a program to arrange these names in alphabetical order.
*/
 
#include <stdio.h>
#include <string.h>

int main() {
    char *names[] = {
        "Santosh", "Amol", "Santosh Jain", "Kishore", "Rahul", "Amolkumar", "Hemant"
    };
    int numNames = sizeof(names) / sizeof(names[0]);

    // Bubble sort algorithm
    for (int i = 0; i < numNames - 1; i++) {
        for (int j = 0; j < numNames - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                // Swap the names
                char *temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }
    }

    // Print the sorted names
    printf("Sorted names:\n");
    for (int i = 0; i < numNames; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
