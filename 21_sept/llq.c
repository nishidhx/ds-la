#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

struct Node* createNode(int val) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL) {
		printf("Memory ALlocation failed");
		return NULL;
	}
	newNode->data = val;
	newNode->next = NULL;
	return newNode;
}
// enqueue implementation using linked list
void enqueue(int val) {
    struct Node* newNode = createNode(val);
    if (front == NULL && rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

// dequeue implementation using linked list
void dequeue() {
    if (front == NULL && rear == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    struct Node* temp = front;
    front = front->next;
    printf("Popped element: %d\n", temp->data);
    free(temp);
    if (front == NULL) {
        rear = NULL;
    }
}

// front implementation using linked list
void front1() {
    if (front == NULL && rear == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front: %d\n", front->data);
}

void display() {
    if (front == NULL && rear == NULL) {
        printf("Queue is empty");
        return;
    }
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display(); // Output: 10 20 30
    return 0;
}