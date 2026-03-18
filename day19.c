#include <stdio.h>
#include <stdlib.h>  // for abs()

int main() {
    int n, i, j;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input elements
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min_sum = arr[0] + arr[1];
    int a = arr[0], b = arr[1];

    // Check all pairs
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];

            if(abs(sum) < abs(min_sum)) {
                min_sum = sum;
                a = arr[i];
                b = arr[j];
            }
        }
    }

    // Output result
    printf("%d %d", a, b);

    return 0;
}