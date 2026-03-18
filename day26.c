#include <stdio.h>
#include <stdlib.h>

// Node structure for Doubly Linked List
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Create Doubly Linked List
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
    return head;
}

// Traverse and print forward
void printForward(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

// Main function
int main() {
    int n;

    scanf("%d", &n);
    struct Node* head = createList(n);

    printForward(head);

    return 0;
}