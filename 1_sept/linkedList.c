#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

// Question 1: Write a function to create a new node with the given value, assign its data and next pointer, and return the newly created node.
// Create a new node
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

// Question 2: Write a function to count how many nodes are present in the linked list and print the total number of elements.
void count(struct Node* head) {
    struct Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Count: %d", count);
    return;
}   

// Question 3: Write a function to traverse the linked list and calculate the sum of all node values, then print the result.
void sum_of_nodes(struct Node* head) {
    struct Node* temp = head;
    int sum = 0;
    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }
    printf("Sum: %d", sum);
    return;
}   

// Question 4: Write a function to display all elements of the linked list in order from head to NULL, separating them with arrows.
// Display the linked list
void display(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d", temp->data);

        if (temp->next != NULL) {
            printf(" -> ");
        }

        temp = temp->next;
    }

    printf(" -> NULL\n");
}

// Question 5: Write a function to delete all nodes in the linked list and free the allocated memory so there are no memory leaks.
// Free the linked list
void freeList(struct Node* head) {
    struct Node* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Question 6: Write a function to search for a target value in the linked list and return true if it exists, otherwise false.
bool linear_search(struct Node* head, int target) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (target == temp->data) {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

// Question 7: Write a function to insert a new node at the end of the linked list, keeping the order of existing nodes unchanged.
 // add last
void add_last(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    struct Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}


// Question 8: Write a function to find and print the maximum value present in the linked list.
// max element 
int max_ll(struct Node* head) {
    struct Node* temp = head;
    int max = -9999;
    while(temp != NULL) {
        if (max < temp->data) {
            max = temp->data;
        }
        temp = temp->next;
    }

    printf("max element: %d\n", max);
    return 0;
}

// Question 9: Write a function to insert a new node at the beginning of the linked list and return the new head pointer.
// assign a new head 
struct Node* new_head(struct Node* head, int value) {
    struct Node* newHead = createNode(value);
    newHead->next = head;
    return newHead;
}

void new_head_node(struct Node** head, int data) {
    struct Node* newHead = createNode(data);

    if (newHead == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newHead->next = *head;
    *head = newHead;
    
}

// Question 10: Write a function to find and print the minimum value present in the linked list.
// max element 
int min_ll(struct Node* head) {
    struct Node* temp = head;
    int min = -9999;
    while(temp != NULL) {
        if (min > temp->data) {
            min = temp->data;
        }
        temp = temp->next;
    }

    printf("min element: %d\n", min);
    return 0;
}

struct Node* first_head(struct Node* head) {
    if (head == NULL) {printf("list is empty"); return NULL;}
    struct Node* temp = head;

    head = head->next;
    free(temp);
    return head;
}

// add at kth position
struct Node* add_kth(struct Node* head, int val, int k) {
    int count = 0;

     struct Node* temp = head;
    while (count != k-1) {
        temp = temp->next;
        count++;
    }

    struct Node* newNode = createNode(val);

    temp->next = newNode;
    newNode->next = temp->next->next;

    return head; 

}

// delete last
struct Node* delete_last(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    return head;
}

// join two linked list 
struct Node* join_ll(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) {
        return head2;
    }

    struct Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head2;

    return head1;
}

int main() {

    // Create linked list
    struct Node* head1 = createNode(10);

    head1->next = createNode(20);
    head1->next->next = createNode(30);

    // Display linked list
    display(head1);

    // struct Node* head2 = createNode(10);

    // head2->next = createNode(20);
    // head2->next->next = createNode(30);

    // // Display second linked list
    addew_kth(head1, 5, 2);
    display(head1);

    // // Join the two linked lists
    // struct Node* joinedHead = join_ll(head1, head2);
    // printf("Joined linked list:\n");
    // display(joinedHead);
    
    // printf("\n");
    // sum_of_nodes(head);

    // printf("Found: %d\n", linear_search(head, 20));

    // max_ll(head);
    // min_ll(head);

    // head =new_head(head, 5);
    // display(head);
    // head = delete_last(head);
    // // add_last(head, 40);
    // display(head);
    // Free allocated memory
    // freeList(head);

    return 0;

}