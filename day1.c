#include <stdio.h>
int main() {
    int n;

    // read number of elements
    scanf("%d", &n);

    int arr[n + 1];   // extra space for insertion

    // read the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int pos, x;
    scanf("%d", &pos);   // position (1-based)
    scanf("%d", &x);     // element to insert

    // shift elements to the right
    for (int i = n; i >= pos; i--) 
    {
        arr[i] = arr[i - 1];
    }
    // insert new element
    arr[pos - 1] = x;

    // print updated array
    for (int i = 0; i <= n; i++) 
    {
        printf("%d", arr[i]);
        if (i < n) printf(" ");
    }

    return 0;
}
