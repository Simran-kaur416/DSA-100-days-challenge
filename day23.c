#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node {
    int data;
    struct Node* next;
};

// Create linked list
struct Node* createList(int arr[], int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

// Merge two sorted linked lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    if (l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}

// Print linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m;

    // First list
    scanf("%d", &n);
    int arr1[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr1[i]);

    // Second list
    scanf("%d", &m);
    int arr2[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &arr2[i]);

    struct Node* list1 = createList(arr1, n);
    struct Node* list2 = createList(arr2, m);

    struct Node* merged = mergeLists(list1, list2);

    printList(merged);

    return 0;
}