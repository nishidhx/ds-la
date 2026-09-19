#include <stdio.h>
#include <stdlib.h>

// Stack implementation using linked list
// Each node stores one integer value and a pointer to the next node.
struct Node {
    int data;
    struct Node* next;
};

// Global pointer representing the top of the stack.
struct Node* top = NULL;

// Creates a new node with the given value.
struct Node* createNode(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// Push operation: inserts a new node at the top of the stack.
struct Node* push(struct Node* top, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = top;
    top = newNode;
    return top;
}

// Pop operation: removes the top element and returns the new top.
struct Node* pop(struct Node* top) {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return NULL;
    }

    struct Node* temp = top;
    top = top->next;
    printf("%d\n", temp->data); // print removed value
    free(temp);
    return top;
}

// Peek operation: shows the top element without deleting it.
struct Node* peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is Empty\n");
        return NULL;
    }

    printf("%d\n", top->data);
    return top;
}

// Displays all nodes in the stack from top to bottom.
struct Node* display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is Empty\n");
        return NULL;
    }

    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return top;
}

// Frees all memory used by the stack.
struct Node* freeStack(struct Node* top) {
    struct Node* temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
    return NULL;
}

int main() {
    // Example usage of stack operations.
    top = push(top, 1);
    top = push(top, 3);
    top = push(top, 2);
    display(top);

    peek(top);
    printf("\n");

    top = pop(top);

    printf("\n");
    display(top);

    top = freeStack(top);

    return 0;
}