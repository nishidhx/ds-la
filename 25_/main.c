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

// create a dynamic array and reverse the actual array instead of printing the reverse of the array
// I solved by two pointer Approach -> same did by sir but used while loop
// while loop code
/**
    int i = 0, j = number_of_elements - 1;

    while 
    
    

*/

int pr4() {
    int number_of_elements;
    printf("Enter number of elements: ");
    scanf("%d", &number_of_elements);

    int *arr = malloc(number_of_elements * sizeof(int));

    for (int i = 0; i < number_of_elements; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }

    // Reverse the array
    for (int i = 0; i < number_of_elements / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[number_of_elements - 1 - i];
        arr[number_of_elements - 1 - i] = temp;
    }

    printf("Reversed array: ");
    for (int i = 0; i < number_of_elements; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


// pr5 -> create the dynamic array and count how many are even and odd.
int isEven(int number) {
    return (number & 1) == 0;
}

int pr5() {
    int number_of_elements, e_c = 0, o_c = 0;
    printf("Enter number of elements: ");
    scanf("%d", &number_of_elements);

    int *arr = malloc(number_of_elements * sizeof(int));

    for (int i = 0; i < number_of_elements; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
        if (isEven(arr[i])) {
            e_c++;
        }else {
            o_c++;
        }
    }

    printf("even count: %d, odd count: %d", e_c, o_c);
    return 0;
}

// create a dynamic array and take avg of the array use calloc
int pr6() {
    int number_of_elements, e_c = 0, o_c = 0, avg = 0;
    printf("Enter number of elements: ");
    scanf("%d", &number_of_elements);

    int *arr = calloc(number_of_elements, sizeof(int));

    for (int i = 0; i < number_of_elements; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
        avg += arr[i];
    }

    printf("Aveerage: %d", avg/number_of_elements);

    return 0;

}

// create a dynamic array using calloc print array first without init and after init
int pr7() {
    int number_of_elements;
    printf("Enter number of elements: ");
    scanf("%d", &number_of_elements);

    int *arr = calloc(number_of_elements, sizeof(int));

    for (int i = 0; i < number_of_elements; i++) {
            printf("%d ", arr[i]);
    }

    for (int i = 0; i < number_of_elements; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < number_of_elements; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

// memory leak - free() function
// dangling pointer - that pointer variable we store an address of the a component which don't exist.
/**
    what is dangling Pointer ?
    free(arr);
    arr = NULL;
*/

int main() {

    pr7();
}