#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (n == 0) return 0;

    // First element is always unique
    int write = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[write - 1]) {
            arr[write] = arr[i];
            write++;
        }
    }

    // Print unique elements
    for (int i = 0; i < write; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
