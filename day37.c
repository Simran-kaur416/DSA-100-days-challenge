#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert element
void insert(int x) {
    if (size == MAX)
        return; // overflow ignored

    pq[size++] = x;
}

// Delete (remove highest priority → smallest element)
void deletePQ() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    int minIndex = 0;

    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }

    printf("%d\n", pq[minIndex]);

    // Shift elements
    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
}

// Peek (show highest priority element)
void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    int min = pq[0];

    for (int i = 1; i < size; i++) {
        if (pq[i] < min) {
            min = pq[i];
        }
    }

    printf("%d\n", min);
}

// Main
int main() {
    int n, x;
    char op[10];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'i') { // insert
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'd') { // delete
            deletePQ();
        }
        else if (op[0] == 'p') { // peek
            peek();
        }
    }

    return 0;
}