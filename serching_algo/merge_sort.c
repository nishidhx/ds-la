#include <stdio.h>
#include <stdlib.h>

 // n + log(n);
void merge(int arr[], int low, int mid, int high) {
    int temp[high - low + 1];
    int i = low;
    int j = mid + 1;
    int k = 0;
    
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            k++;
            i++;
        }else {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int i = 0, k = low; k <= high; i++, k++) {
        arr[k] = temp[i];
    }

}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low)/2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
    
        merge(arr, low, mid, high);
    }
}

void main() {
    int arr[8] = {2, 3, 5, 1, 4, 2, 3, 2};

    mergeSort(arr, 0, 7);
    for (int i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }
}