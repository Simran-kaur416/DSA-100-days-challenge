#include <stdio.h>

int main() {
    int n, i, j, count;

    // Input size
    scanf("%d", &n);

    int arr[n];
    int visited[n];  // to track counted elements

    // Initialize visited array
    for(i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Input elements
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Count frequency
    for(i = 0; i < n; i++) {
        if(visited[i] == 1)
            continue;

        count = 1;

        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                visited[j] = 1;
            }
        }

        printf("%d:%d ", arr[i], count);
    }

    return 0;
}