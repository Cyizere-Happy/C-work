//Insertion sort
#include <stdio.h>

void insertionsort(int arr[], int n) {
    for (int i = 1; i < n; i++) {  
        int key = arr[i];
        int j = i - 1;
        
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {5, 3, 4, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionsort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
