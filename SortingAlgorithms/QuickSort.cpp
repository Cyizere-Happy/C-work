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