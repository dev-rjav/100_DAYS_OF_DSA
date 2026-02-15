
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a code name: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character from input string
    str[strcspn(str, "\n")] = '\0';
    
    // Reverse the string
    for (int i = 0; i < strlen(str) / 2; i++) {
        char temp = str[i];
        str[i] = str[strlen(str) - i - 1];
        str[strlen(str) - i - 1] = temp;
    }
    
    // Print the reversed code name
    printf("Reversed code name: %s\n", str);
    
    return 0;
}