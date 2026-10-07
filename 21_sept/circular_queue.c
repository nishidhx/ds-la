#include <stdio.h>

// circular queue implementation using array
#define MAX 5

int front = -1;
int rear = -1;

int arr[MAX];

// enqueue for circular queue
int enqueue(int val) {
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        arr[rear] = val;
    }
    else if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return -1;
    }
    else {
        rear = (rear + 1) % MAX;
        arr[rear] = val;
    }
    return 0;
}

// dequeue operation for circular 
int dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue Underflow\n");
        return -1;
    }

    int poppedElement = arr[front];

    if (front == rear) {
        front = rear = -1;
    }
    else {
        front = (front + 1) % MAX;
    }

    return poppedElement;
}

// front operation for circular queue
int front1() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return -1;
    }

    return arr[front];
}

// display for circular queue
void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", arr[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display(); 

    printf("Front element: %d\n", front1()); 

    printf("Dequeued element: %d\n", dequeue()); 
    display();

    return 0;
}