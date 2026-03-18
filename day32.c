#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int x) {
    if (top == MAX - 1) {
        return; // overflow ignored
    }
    stack[++top] = x;
}

// Pop operation
void pop() {
    if (top == -1) {
        return; // underflow ignored
    }
    top--;
}

// Display stack (top to bottom)
void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int n, m, x;

    // Read number of elements
    scanf("%d", &n);

    // Push elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    // Number of pops
    scanf("%d", &m);

    // Perform pop operations
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Print remaining stack
    display();

    return 0;
}
