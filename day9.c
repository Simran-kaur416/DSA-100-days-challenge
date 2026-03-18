#include <stdio.h>
#include <string.h>

// Recursive function
void reverse(char str[], int start, int end) {
    if (start >= end)
        return;

    // Swap characters
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call
    reverse(str, start + 1, end - 1);
}

int main() {
    char str[100];

    // Input
    scanf("%s", str);

    int len = strlen(str);

    // Function call
    reverse(str, 0, len - 1);

    // Output
    printf("%s", str);

    return 0;
}