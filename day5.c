#include <stdio.h>

int main() {
    int p, q;

    // read first log
    scanf("%d", &p);
    int a[p];
    for (int i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    // read second log
    scanf("%d", &q);
    int b[q];
    for (int i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    int i = 0, j = 0;

    // merge both logs
    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            printf("%d ", a[i]);
            i++;
        } else {
            printf("%d ", b[j]);
            j++;
        }
    }

    // print remaining entries from log 1
    while (i < p) {
        printf("%d ", a[i]);
        i++;
    }

    // print remaining entries from log 2
    while (j < q) {
        printf("%d ", b[j]);
        j++;
    }

    return 0;
}
