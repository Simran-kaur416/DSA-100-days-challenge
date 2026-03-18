#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Stack node (linked list)
struct Node {
    int data;
    struct Node* next;
};

// Push
void push(struct Node** top, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = *top;
    *top = newNode;
}

// Pop
int pop(struct Node** top) {
    if (*top == NULL) {
        return 0; // underflow case (not expected here)
    }
    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

// Evaluate postfix
int evaluatePostfix(char exp[]) {
    struct Node* stack = NULL;
    int i = 0;

    while (exp[i] != '\0') {
        // Skip spaces
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        // If operand (number)
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(&stack, num);
        }
        else {
            int b = pop(&stack);
            int a = pop(&stack);
            int result;

            switch (exp[i]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(&stack, result);
            i++;
        }
    }

    return pop(&stack);
}

// Main
int main() {
    char exp[100];

    // Read full line
    fgets(exp, sizeof(exp), stdin);

    int result = evaluatePostfix(exp);

    printf("%d", result);

    return 0;
}