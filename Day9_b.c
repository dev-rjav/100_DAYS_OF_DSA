#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str)-1] = '\0'; // remove the newline character
    char rev_str[100];
    for (int i = 0; i < strlen(str); i++) {
        rev_str[i] = str[strlen(str) - 1 - i];
    }
    rev_str[strlen(rev_str)] = '\0';
    printf("Reversed string: %s\n", rev_str);
    return 0;
}