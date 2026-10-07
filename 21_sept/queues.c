#include <stdio.h>

#define MAX 5



int front = -1;
int rear = -1;
int arr[MAX];

void enqueue(int val) {
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        arr[rear] = val;
    }
    else if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return;
    }
    else {
        rear = (rear + 1) % MAX;
        arr[rear] = val;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue Underflow\n");
        return;
    }

    if ((front + 1) % MAX == rear) {
        printf("Popped element: %d\n", arr[front]);
        front = rear = -1;
        return;
    }

    printf("Popped element: %d\n", arr[front]);
    front = (front + 1) % MAX;
}

void front1() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Front: %d\n", arr[front]);
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = front; i <= rear; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(30);
    enqueue(30);
    enqueue(30);
    dequeue();
    dequeue();
    dequeue();
    
    display();
    enqueue(40);

    display();

    front1();

    return 0;
}