#include <stdio.h>

void insertion_sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}



int binary_search(int arr[], int n, int target) {
    int low = 0, high = n - 1, mid;

    while(low <= high) {
        mid = low + (high - low)/2;
        if (arr[mid] == target) {
            return mid;
        }else if (arr[mid] > target) {
            high = mid - 1;
        }else if (arr[mid] < target) {
            low = mid + 1;
        }
    }

    return -1;

}


int binary_search_first(int arr[], int n, int target) {
    int low = 0, high = n - 1, mid;
    int ans = -1;

    while(low <= high) {
        mid = low + (high - low)/2;
        if (arr[mid] == target) {
            ans = mid;
            high = mid - 1;
        }else if (arr[mid] > target) {
            high = mid - 1;
        }else if (arr[mid] < target) {
            low = mid + 1;
        }
    }

    return ans;

}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int binary_search_last(int arr[], int n, int target) {
    int low = 0, high = n - 1, mid;
    int ans = -1;

    while(low <= high) {
        mid = low + (high - low)/2;
        if (arr[mid] == target) {
            ans = mid;
            low = mid + 1;
        }else if (arr[mid] > target) {
            high = mid - 1;
        }else if (arr[mid] < target) {
            low = mid + 1;
        }
    }

    return ans;

}

int main() {
    int arr[12] = {1, 223,24,2,22, 3, 4, 5, 660, 75, 8, 9};

    bubble_sort(arr, 12);

    for (int i = 0; i < 12; i++) {
        printf("%d ", arr[i]);
    }
    return 1;
}