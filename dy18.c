#include <stdio.h>

int main() {
    int n, i, k;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input elements
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input k
    scanf("%d", &k);

    // Handle k greater than n
    k = k % n;

    int temp[n];

    // Copy last k elements to beginning
    for(i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // Copy remaining elements
    for(i = k; i < n; i++) {
        temp[i] = arr[i - k];
    }

    // Print rotated array
    for(i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}