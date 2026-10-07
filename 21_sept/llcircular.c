#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory ALlocation failed");
        exit(0);
    }

    newNode->data = val;
    newNode->next = newNode;
    return newNode;
}

void enqueue(int val) {
    struct Node* newNode = createNode(val);

    if (front == NULL && rear == NULL) {
        front = rear = newNode;

        front->data = val;
        rear->next = front;
    }

    rear->next = newNode;
    rear = newNode;
    rear->next = front;
}

void dequeue() {
    struct Node* temp = NULL;
    int poppedElement;

    if (front == NULL && rear == NULL) {
        printf("Queue is empty");
    }else if (front == rear) {
        temp = front;
        poppedElement = front->data;
        front = rear = NULL;
        free(temp);
    }else {
        temp = front;
        poppedElement = front->data;
        front = front->next;
        free(temp);
        rear->next = front;
    }

    printf("Popped element is %d\n", poppedElement);
}

void display() {
    struct Node* temp = front;
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Elements in the queue are: ");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != front);
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(100);
    enqueue(120);


    display();
    dequeue();
    display();
    dequeue();
    dequeue();
    display();
    enqueue(10);
    display();
    return 0;
}   