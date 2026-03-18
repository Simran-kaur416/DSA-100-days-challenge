#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create Circular Linked List
struct Node* createCircularList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Make it circular
    if (temp != NULL)
        temp->next = head;

    return head;
}

// Traverse Circular Linked List
void printCircular(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);  // stop when back to head
}

// Main function
int main() {
    int n;

    scanf("%d", &n);
    struct Node* head = createCircularList(n);

    printCircular(head);

    return 0;
}