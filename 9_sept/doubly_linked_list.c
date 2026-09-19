#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct doubly_listNode {
    struct doubly_listNode* prev;
    struct doubly_listNode* next;
    int val;
};

// Question 1: Write a function to create a new node for the doubly linked list, assign the value, and initialize both prev and next to NULL.
struct doubly_listNode* createNode(int val) {
    struct doubly_listNode* newNode = malloc(sizeof(struct doubly_listNode));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->val = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Question 2: Write a function to display all elements of the doubly linked list from head to tail.
void display(struct doubly_listNode* head) {
    struct doubly_listNode* temp = head;

    printf("Head -> ");
    while (temp != NULL) {
         printf("%d", temp->val);

        if (temp->next != NULL) {
            printf(" <-> ");
        }

        temp = temp->next;
    }

    printf(" -> NULL\n");
}

// Question 3: Write a function to count the total number of nodes in the doubly linked list and print the result.
int count_nodes(struct doubly_listNode* head) {
    struct doubly_listNode* temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Count: %d\n", count);
    return count;
}

// Question 4: Write a function to calculate and print the sum of all values in the doubly linked list.
int sum_nodes(struct doubly_listNode* head) {
    struct doubly_listNode* temp = head;
    int sum = 0;

    while (temp != NULL) {
        sum += temp->val;
        temp = temp->next;
    }

    printf("Sum: %d\n", sum);
    return sum;
}

// Question 5: Write a function to insert a new node at the beginning of the doubly linked list.
struct doubly_listNode* add_first(struct doubly_listNode* head, int val) {
    struct doubly_listNode* newNode = createNode(val);

    if (head == NULL) {
        return newNode;
    }

    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Question 6: Write a function to insert a new node at the end of the doubly linked list.
struct doubly_listNode* add_last(struct doubly_listNode* head, int val) {
    struct doubly_listNode* temp = head;
    struct doubly_listNode* newNode = createNode(val);

    if (head == NULL) {
        return newNode;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Question 7: Write a function to search for a target value in the doubly linked list and return true if it exists, otherwise false.
bool linear_search(struct doubly_listNode* head, int target) {
    struct doubly_listNode* temp = head;

    while (temp != NULL) {
        if (temp->val == target) {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

// Question 8: Write a function to find and print the maximum value present in the doubly linked list.
int max_dll(struct doubly_listNode* head) {
    struct doubly_listNode* temp = head;
    int max = head == NULL ? -9999 : head->val;

    while (temp != NULL) {
        if (temp->val > max) {
            max = temp->val;
        }
        temp = temp->next;
    }

    printf("Maximum: %d\n", max);
    return max;
}

// Question 9: Write a function to find and print the minimum value present in the doubly linked list.
int min_dll(struct doubly_listNode* head) {
    struct doubly_listNode* temp = head;
    int min = head == NULL ? 9999 : head->val;

    while (temp != NULL) {
        if (temp->val < min) {
            min = temp->val;
        }
        temp = temp->next;
    }

    printf("Minimum: %d\n", min);
    return min;
}

// Question 10: Write a function to delete the first node of the doubly linked list and return the new head.
struct doubly_listNode* delete_first(struct doubly_listNode* head) {
    struct doubly_listNode* temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
    return head;
}

// Question 11: Write a function to delete the last node of the doubly linked list and return the updated head.
struct doubly_listNode* delete_last(struct doubly_listNode* head) {
    struct doubly_listNode* temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
    return head;
}

// Question 12: Write a function to delete all nodes in the doubly linked list and free the allocated memory.
void free_list(struct doubly_listNode* head) {
    struct doubly_listNode* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct doubly_listNode* head = createNode(10);
    head->next = createNode(20);
    head->next->prev = head;
    head->next->next = createNode(30);
    head->next->next->prev = head->next;

    display(head);
    count_nodes(head);
    sum_nodes(head);
    printf("Search 20: %s\n", linear_search(head, 20) ? "Found" : "Not Found");
    max_dll(head);
    min_dll(head);

    head = add_first(head, 40);
    display(head);

    head = add_last(head, 50);
    display(head);

    head = delete_first(head);
    display(head);

    head = delete_last(head);
    display(head);

    free_list(head);
    return 0;
}