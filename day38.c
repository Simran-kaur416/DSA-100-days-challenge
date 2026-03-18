#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int isEmpty() {
    return (front == -1);
}

// Check full
int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

// Push front
void push_front(int x) {
    if (isFull()) return;

    if (isEmpty()) {
        front = rear = 0;
    }
    else if (front == 0) {
        front = MAX - 1;
    }
    else {
        front--;
    }
    deque[front] = x;
}

// Push back
void push_back(int x) {
    if (isFull()) return;

    if (isEmpty()) {
        front = rear = 0;
    }
    else if (rear == MAX - 1) {
        rear = 0;
    }
    else {
        rear++;
    }
    deque[rear] = x;
}

// Pop front
void pop_front() {
    if (isEmpty()) return;

    if (front == rear) {
        front = rear = -1;
    }
    else if (front == MAX - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

// Pop back
void pop_back() {
    if (isEmpty()) return;

    if (front == rear) {
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = MAX - 1;
    }
    else {
        rear--;
    }
}

// Get front
void getFront() {
    if (isEmpty()) printf("-1\n");
    else printf("%d\n", deque[front]);
}

// Get back
void getBack() {
    if (isEmpty()) printf("-1\n");
    else printf("%d\n", deque[rear]);
}

// Size
int getSize() {
    if (isEmpty()) return 0;
    if (rear >= front) return rear - front + 1;
    return MAX - front + rear + 1;
}

// Display deque
void display() {
    if (isEmpty()) return;

    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
}

// Main (sample handling basic operations)
int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'p' && op[5] == 'f') { // push_front
            scanf("%d", &x);
            push_front(x);
        }
        else if (op[0] == 'p' && op[5] == 'b') { // push_back
            scanf("%d", &x);
            push_back(x);
        }
        else if (op[0] == 'p' && op[4] == 'f') { // pop_front
            pop_front();
        }
        else if (op[0] == 'p' && op[4] == 'b') { // pop_back
            pop_back();
        }
        else if (op[0] == 'f') { // front
            getFront();
        }
        else if (op[0] == 'b') { // back
            getBack();
        }
        else if (op[0] == 's') { // size
            printf("%d\n", getSize());
        }
        else if (op[0] == 'e') { // empty
            printf("%d\n", isEmpty());
        }
    }

    // Final state display (if needed)
    display();

    return 0;
}