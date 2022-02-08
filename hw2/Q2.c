#include <stdio.h>
#include <stdlib.h>
//RumeysaCeylan

void swap(int *x, int *y)
{ //Swaps two values
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
//A function to implement sort
void Sort(int arr[], int n)
{//T(n)=SUM(0 TO N-2(SUM(1 TO N-i-1)1) = (n^2-n)=O(N^2)
   int i, j;
   for (i = 0; i < n-1; i++){  //it checks for every index step by step
       for (j = 1; j < n-i; j++){//It checks from the 1st index to the end 
	   		 if (arr[j-1] > arr[j])// replaces if an index is less than the previous one
              swap(&arr[j], &arr[j-1]);
		} 
	}
}
 

void printArray(int arr[], int size) //Prints the output of sorted numbers
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 

int main()
{
    int num[100];

  int i = 0;

  
  while (scanf("%d",&num[i])!= EOF) { //takes input until all data over
	i++;	
  }
  
  
    Sort(num, i);
    
    printArray(num, i);
    return 0;
}

