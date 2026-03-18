#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create list
struct Node* createList(int n) {
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
    return head;
}

// Get length
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Find intersection point
int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Move pointer of longer list
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            head1 = head1->next;
    } else {
        for (int i = 0; i < diff; i++)
            head2 = head2->next;
    }

    // Traverse both
    while (head1 != NULL && head2 != NULL) {
        if (head1->data == head2->data)  // comparing values (for this problem)
            return head1->data;

        head1 = head1->next;
        head2 = head2->next;
    }

    return -1;
}

// Main
int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* list1 = createList(n);

    scanf("%d", &m);
    struct Node* list2 = createList(m);

    int result = findIntersection(list1, list2);

    if (result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}