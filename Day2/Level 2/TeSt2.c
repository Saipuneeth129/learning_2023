/* Level-2
   Day-2
2. W.A.P to compare the items in a box, assume equal size boxes
Boxes shall have unique items stored in random order
Boxes are compared True if there is one to one mapping of items
return the final result 1 or 0

Example of Equal Boxes:
A[3] = {200, 10, -90}
B[3] = {-90, 200, 10}    

Example of Unequal Boxes:
A[3] = {200, 9, -90}
B[3] = {-90, 200, 10}    

Note: The array should not be sorted

Topics to be covered
- Arrays
- Loops
- Basic Operators
*/
#include <stdio.h>

int compareBoxes(int A[], int B[], int size) {
    int i, j;
    int found;

    for (i = 0; i < size; i++) {
        found = 0;

        for (j = 0; j < size; j++) {
            if (A[i] == B[j]) {
                found = 1;
                break;
            }
        }

        if (found == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int A[] = {200, 10, -90};
    int B[] = {-90, 200, 10};
    int size = sizeof(A) / sizeof(A[0]);

    int result = compareBoxes(A, B, size);

    if (result == 1) {
        printf("Equal boxes\n");
    } else {
        printf("Unequal boxes\n");
    }

    return 0;
}
