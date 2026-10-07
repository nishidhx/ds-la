#include <stdio.h>
#define MAX 5

int top = -1;
int Stack[MAX];

void push(int* arr, int val) {
    if (top == MAX -1) {
        printf("Stack overflow\n");
        return;
    }

    top++;
    arr[top] = val;
}

void pop(int* arr) {
    if (top == -1) {
        printf("Stack underflow\n");
        return;
    }

    int poppedElement = arr[top];
    printf("poppedELement: %d\n", poppedElement);
    top--;
}

void peek(int* arr) {
    if (top == -1) {
        printf("Stack underflow\n");
        return;
    }

    printf("Top Most element: %d", arr[top]);
}

void display(int* arr) {
    if (top == -1) {
        printf("Stack is Empty");
        return;
    }

    printf("Stack display");
    for (int i = top; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int isEmpty() {
    return top == -1;
}

int main() {
    push(Stack, 10);
    push(Stack, 20);
    push(Stack, 30);

    display(Stack);

    peek(Stack);
    pop(Stack);
    peek(Stack);

    return 0;
}