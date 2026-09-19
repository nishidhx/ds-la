#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

// Question 1: Write a function to create a new node with the given value and return it.
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Question 2: Write a function to display all elements of the circular linked list.
void display(struct Node* head) {
    if (head == NULL) {
        printf("Circular list is empty\n");
        return;
    }

    struct Node* temp = head;

    do {
        printf("%d", temp->data);
        temp = temp->next;

        if (temp != head) {
            printf(" -> ");
        }
    } while (temp != head);

    printf(" -> back to head\n");
}

// Question 3: Write a function to count the number of nodes in a circular linked list.
int countNodes(struct Node* head) {
    if (head == NULL) {
        return 0;
    }

    int count = 0;
    struct Node* temp = head;

    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

// Question 4: Write a function to insert a new node at the beginning of a circular linked list.
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    struct Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    return newNode;
}

// Question 5: Write a function to insert a new node at the end of a circular linked list.
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    struct Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    return head;
}

// Question 6: Write a function to delete the first node from a circular linked list.
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (head->next == head) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    struct Node* last = head;

    while (last->next != head) {
        last = last->next;
    }

    last->next = head->next;
    head = head->next;
    free(temp);
    return head;
}

// Question 7: Write a function to delete the last node from a circular linked list.
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (head->next == head) {
        free(head);
        return NULL;
    }

    struct Node* prev = NULL;
    struct Node* temp = head;

    do {
        prev = temp;
        temp = temp->next;
    } while (temp->next != head);

    prev->next = head;
    free(temp);
    return head;
}

// Question 8: Write a function to search for a given value in a circular linked list.
bool searchNode(struct Node* head, int key) {
    if (head == NULL) {
        return false;
    }

    struct Node* temp = head;

    do {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    } while (temp != head);

    return false;
}

// Question 9: Write a function to find the maximum value in the circular linked list.
int findMax(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return -1;
    }

    int max = head->data;
    struct Node* temp = head->next;

    while (temp != head) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }

    return max;
}

// Question 10: Write a function to find the minimum value in the circular linked list.
int findMin(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return -1;
    }

    int min = head->data;
    struct Node* temp = head->next;

    while (temp != head) {
        if (temp->data < min) {
            min = temp->data;
        }
        temp = temp->next;
    }

    return min;
}

// Question 11: Write a function to insert a node after a specific value in a circular linked list.
struct Node* insertAfterValue(struct Node* head, int target, int value) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct Node* newNode = createNode(value);
    struct Node* temp = head;

    do {
        if (temp->data == target) {
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Target not found\n");
    free(newNode);
    return head;
}

// Question 12: Write a function to delete a node with a given value from a circular linked list.
struct Node* deleteByValue(struct Node* head, int value) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (head->next == head && head->data == value) {
        free(head);
        return NULL;
    }

    struct Node* prev = NULL;
    struct Node* temp = head;

    do {
        if (temp->data == value) {
            if (prev == NULL) {
                // deleting head
                struct Node* last = head;
                while (last->next != head) {
                    last = last->next;
                }

                last->next = head->next;
                free(head);
                return last->next;
            }

            prev->next = temp->next;
            free(temp);
            return head;
        }

        prev = temp;
        temp = temp->next;
    } while (temp != head);

    printf("Value not found\n");
    return head;
}

int main() {
    struct Node* head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    printf("Original circular linked list:\n");
    display(head);

    printf("Count of nodes: %d\n", countNodes(head));
    printf("Search 20: %s\n", searchNode(head, 20) ? "Found" : "Not Found");
    printf("Maximum value: %d\n", findMax(head));
    printf("Minimum value: %d\n", findMin(head));

    head = insertAtBeginning(head, 5);
    printf("After inserting 5 at beginning:\n");
    display(head);

    head = insertAfterValue(head, 20, 25);
    printf("After inserting 25 after 20:\n");
    display(head);

    head = deleteByValue(head, 30);
    printf("After deleting 30:\n");
    display(head);

    head = deleteFromBeginning(head);
    printf("After deleting first node:\n");
    display(head);

    head = deleteFromEnd(head);
    printf("After deleting last node:\n");
    display(head);

    return 0;
}
