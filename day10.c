#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int start, end;
    int isPalindrome = 1;

    // Input
    scanf("%s", str);

    start = 0;
    end = strlen(str) - 1;

    // Two-pointer comparison
    while (start < end) {
        if (str[start] != str[end]) {
            isPalindrome = 0;
            break;
        }
        start++;
        end--;
    }

    // Output
    if (isPalindrome)
        printf("YES");
    else
        printf("NO");

    return 0;
}