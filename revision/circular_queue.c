#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void dequeue() {
    struct Node* temp =NULL;
    if (front == NULL && rear == NULL) {
        printf("Queue Underflow");
        return;
    }

    if (front == rear ) {
        temp = front;
        printf("Popped Element: %d", front->data);
        front = rear = NULL;
        free(temp);
        return;
    }

    printf("Popped ELement: %d", front->data);
    front = front->next;
    rear->next = front;
    free(temp);
    if (front == NULL) {
        rear = NULL;
    }  
    return;
}

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
        rear->next = front;
    }

    rear->next = newNode;
    rear = newNode;
    rear->next = front;
}


void display() {
    struct Node* temp = front;
    if (front == NULL) {
        printf("Queue underflow");
        return;
    }else {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        }while(temp != front);
        printf("\n");
    }

    return;
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