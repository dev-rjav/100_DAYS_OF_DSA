#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Input string with max size of 100 characters
    
    printf("Enter a string: ");
    scanf("%s", s);

    int start = 0;
    int end = strlen(s) - 1;

    while (start < end) {
        if (s[start] != s[end]) { // If characters don't match, break loop
            return 0;
        }
        start++;
        end--;
    }

    printf("YES\n"); // String is a palindrome
    return 0;
}