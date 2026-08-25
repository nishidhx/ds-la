#include <stdio.h>
#include <stdlib.h>

/** Dynamic Memory Allocation */

// first program of dynamic memory allocation
int pr1(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *ptr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Enter element: %d: ", i);
        scanf("%d", &ptr[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }

    return 0;

}

// sum of elements from the dynamic array
int pr2() {
    int number_of_elements, sum = 0;
    printf("Enter number of elements: ");
    scanf("%d", &number_of_elements);

    int *arr = malloc(number_of_elements * sizeof(int));

    for (int i = 0; i < number_of_elements; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("Sum: %d", sum);
    return 0;
}

// create a dynamic array and find out the max element
int pr3() {
    int number_of_elements, max = -99999;
    printf("Enter number of elements: ");
    scanf("%d", &number_of_elements);

    int *arr = malloc(number_of_elements * sizeof(int));

    for (int i = 0; i < number_of_elements; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    printf("max: %d", max);
    return 0;
}


int main() {

    pr3();
}