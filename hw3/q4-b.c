#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int a = m - l + 1;
    int b = r - m;
  
  
    int left[a], right[b];
    //create temp arrays 
    
    /* Copy data to temp arrays left[] and right[] */
    for (i = 0; i < a; i++)
        left[i] = arr[l + i];
    for (j = 0; j < b; j++)
        right[j] = arr[m + 1 + j];
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < a && j < b) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
  
    //Copy the remaining elements of left[]
    while (i < a) {
        arr[k] = left[i];
        i++;
        k++;
    }
  
//Copy the remaining elements of right[]
    while (j < b) {
        arr[k] = right[j];
        j++;
        k++;
    }
}
  
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)// efficiency analysis best case :O(nlogn) worst case: O(nlogn)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
  
       // Sort half of first and second
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}

int checkTruth(int arr[], int size,int x)
{
    int i,j; 
    for (i = 0; i < size; i++) 
    	for(j=0;j<size;j++){
    		if(i==j) continue;//indix cannot be same 
    	if(arr[i]+arr[j]==x)//if two index sum is equal the last input then it is true
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
	
	
	mergeSort(arr, 0, n - 1);
    if(checkTruth(arr,n,x)) printf("YES\n");
    else printf("NO\n");
	
	
	return 0;
}
