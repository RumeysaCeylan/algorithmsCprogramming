#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int seperate(int arr[], int low, int high) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the correct position of pivot found so far
  int j;
    for ( j= low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
// efficiency analysis best case :O(nlogn) worst case: O(n^2)
    if (low < high) 
    { 
        /* pi is seperating index, arr[p] is now 
        at right place */
        int pi = seperate(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

int checkTruth(int arr[], int size,int x) 
{ 
    int i,j; 
    for (i = 0; i < size; i++) 
    	for(j=0;j<size;j++){
    		if(i==j) continue; //indix cannot be same 
    	if(arr[i]+arr[j]==x) //if two index sum is equal the last input then it is true
        	return 1;
		
		}
        
   return 0;
} 
int main(int argc, char *argv[]) {
	int n,x;
	scanf("%d",&n);
	int i,arr[n];
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	scanf("%d",&x);
	quickSort(arr,0,n-1);
	if(checkTruth(arr,n,x)) printf("YES\n");
	else printf("NO\n");
	return 0;
}
