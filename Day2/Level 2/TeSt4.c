/*Level-2
  Day-2
    
4. Write a function xstrchr() which scans a string from beginning to end in search of a character. 
If the character is found, it should return a pointer to the first occurrence of the given character in the string.
If the given character is not found, the function returns a NULL.
The prototype of the function should be:

char *xstrchr(char *string, char ch):
*/
#include<stdio.h>
#include<string.h>
int main(){
char *xstrchr(char *string, char ch) {
    while (*string != '\0') {
        if (*string == ch) {
            return string;
        }
        string++;
    }
    return NULL;
}
}
