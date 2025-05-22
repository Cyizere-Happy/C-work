// Quick Sort
#include <stdio.h>

// a function for swapping firstof all has to be defined
void swap(int *a, int *b){
	int temp = *a;
	*a= *b;
	*b = temp;
}
//a function that is going to return the pivot of the array
int partition( int arr[], int lb , int ub){
	 int pivot = arr[lb];
	 int start = lb;
	 int end = ub;
	
	
	 while(start < end){
	 	
	 	while(arr[start] <= pivot){
	 		start++;
		 }
		
		 while(arr[end] > pivot){
		 	end--;
		 }
		
		 if(start < end){
		 	swap(&arr[start], &arr[end]);
		 }	
	 }
	
	 swap(&arr[lb], &arr[end]);//proper positioning after sorting
	 return end;
	
}
void quicksort(int arr[], int lb, int ub){
	if(lb < ub){
    int loc = partition(arr, lb, ub);
    quicksort (arr, lb, loc-1);
    quicksort (arr,loc +1, ub);
	}
}
void print_array(int arr[], int size){
	for(int i= 0; i <size; i++){
		printf("the sorted array is : %d\n",arr[i]);
		printf("\n");
	}
	
}
int main(){
	int arr[] = {7,6,10,5,9,2,1,15,7};
	int size = sizeof(arr) / sizeof(arr[0]);
	
	
    quicksort(arr, 0, arr[size-1]);
    printf("Sorted array : \n");
    print_array(arr, size);
    return 0;
		
}


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


//Merge sort
#include <stdio.h>

// Merge function to merge two sorted halves
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0; // Initial index of left subarray
    int j = 0; // Initial index of right subarray
    int k = left; // Initial index of merged subarray
    // Merge the temp arrays back into the original array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// MergeSort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        // Sort the first half
        mergeSort(arr, left, mid);
        // Sort the second half
        mergeSort(arr, mid + 1, right);
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}
// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
// Driver code
int main() {
    int arr[] = {8, 4, 5, 2, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Original array:\n");
    printArray(arr, size);
    mergeSort(arr, 0, size - 1);
    printf("Sorted array:\n");
    printArray(arr, size);
    return 0;
} 