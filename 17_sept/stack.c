#include <stdio.h>

#define MAX 5

// Stack array and global pointer/index to the top element.
int arr[MAX];
int top = -1;

// Checks whether the stack is empty.
int isEmpty(int top) {
    return top == -1 ? 1 : 0;
}

// Adds an element to the top of the stack.
void push(int* arr, int value) {
    // If the stack is full, we cannot insert more elements.
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    // Increase the top index and insert the value.
    top++;
    arr[top] = value;
}

// Removes the element from the top of the stack and prints it.
void pop(int* arr) {
    if (isEmpty(top)) {
        printf("Stack Underflow\n");
        return;
    }

    printf("%d\n", arr[top]);
    top--;
}

// Shows the top element without removing it.
void peek(int* arr) {
    if (isEmpty(top)) {
        printf("Stack is Empty\n");
        return;
    }

    printf("%d\n", arr[top]);
}

// Displays all elements from the top to the bottom.
void display(int* arr) {
    if (isEmpty(top)) {
        printf("Stack is Empty\n");
        return;
    }

    for (int i = top; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Example usage of stack operations.
    push(arr, 1);
    push(arr, 3);
    push(arr, 2);
    display(arr);

    return 0;
}