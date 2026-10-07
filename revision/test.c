#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* front = NULL;
struct ListNode* rear = NULL;

struct ListNode *createNode(int val) {
    struct ListNode *newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        printf("Memory Allocation failed");
        exit(0);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// enqeueu
void enqueue(int val) {
    struct ListNode* newNode = createNode(val);
    if (front == NULL && rear == NULL) {
        front = newNode;
        rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

void dequeue() {
    if (front == NULL && rear == NULL) {
        printf("Queue is Empty");
        return;
    }
    
    struct ListNode *temp;
    int dequeuedElement;

    if(front == rear) {
        temp = front;
        dequeuedElement = front->val;
        front = rear = NULL;
        free(temp);
    }else {
        temp = front;
        dequeuedElement = front->val;
        front = front->next;
        free(temp);
    }

    printf("DequeuedElement: %d\n", dequeuedElement);
}

void display() {
    if (front == NULL && rear == NULL) {
        printf("Queue is Empty");
        return;
    }

    for (struct ListNode *node = front; node != NULL; node = node->next) {
        printf("%d ", node->val);
    }

    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    dequeue();
    display();
    dequeue();
    dequeue();

}