#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int left = 0, right;
    int palindrome = 1;

    // Input
    scanf("%s", s);

    right = strlen(s) - 1;

    // Two-pointer check
    while (left < right) {
        if (s[left] != s[right]) {
            palindrome = 0;
            break;
        }
        left++;
        right--;
    }

    // Output
    if (palindrome)
        printf("YES");
    else
        printf("NO");

    return 0;
}