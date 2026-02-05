#include <stdio.h>

int main() {
    int n;

    // read size
    scanf("%d", &n);

    int arr[n];

    // read elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // reverse using two pointers
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }

    // print reversed array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
