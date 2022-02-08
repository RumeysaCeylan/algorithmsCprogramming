#include <stdio.h>
#include <stdlib.h>

int _max();
void longestSubsequence();
int reverse();
void print();
int main(int argc, char *argv[]) {
	int number;
	scanf("%d",&number); //take the size 
	int i,arr[number],a[number];
	for (i=0;i<number;i++){ //take as array input as much as given size
		scanf("%d",&arr[i]);
	}
	longestSubsequence(arr,number); //find the longest subs

	return 0;
}
void print(int arr[],int lastIndex){ //this function prints the longest subsequence 

	int i=lastIndex-2;
	printf("%d",arr[i+1]);
	while(i>=0){ //prints the longest and ascending subsequence from beginning to end
		printf(" %d",arr[i]);
		i--;
	}
	
	
}
int _max(int a,int b){ 
//this function finds the maximum value and returns it
	 if(a>b)
     return a;
  else 
     return b;
 }
 
 int reverse(int arr[],int increase[],int index,int n){
 	//this function reverse the array 
 		 int temp[n];
 		int k,j;
 		
	
	for(k=0;index>=0;k++){ 
		temp[k]=arr[index];//Arrays that we specify the indexes 
		index = increase[index];//that indicate the ascending order are temporarily assigned to an array.

	}
	for(j=0;j<k;j++){ //When it finds the correct array in ascending order, 
	//it is assigned to the main array.
		arr[j]=temp[j];
	}
	return k; //returns last index of longest sunsequence
}

void longestSubsequence(int arr[], int n){ //efficiency : O(n^2)
                                         //complexity : O(n^2)
                                         //space O(n)
        int lis[n]; // keeps correct indexes for longest subsequence as a list
        int increase[n];
        int i, j ;
		int temp;
        
        i=0;
        while(i<n){ //here initialize the values for the longest subsequence  
        	increase[i]=-1;
        	lis[i] = 1;// Initially, we assume that every index i of an array arr[] has a lis of one.
        	i++;
		}
            

        for (i = 1; i < n; i++){//efficiency : O(n^2)//complexity : O(n^2) //space O(n)
            for (j = 0; j <i; j++){
			if ((arr[j] < arr[i]) ){ //Parsing the array from left to right we look at each element at index i.
                	if( lis[i] < lis[j] + 1){//For every element j up until i (where j<i),
                    lis[i] = lis[j] + 1;
					// if the element at index i is greater than the element at index j and lis[i] <= lis[j] 
                      //then lis[i] = lis[j] + 1	
					 increase[i]=j;
                   }
                }
            }   
			   
        }
        
 	int max=lis[0];
 	int index=0;
 	i=1;
 	 while ( i <n){ //We pick the maximum all of all longest increase subsequence values
	  	 temp=_max(max,lis[i]);
        if (max<temp){ //if the maximum value is smaller than list that is index of longest subsequence 
        	max = temp; //then assign the max it
            index=i;
        	
		}
		i++;
	 }
	 int lastIndex=reverse(arr,increase,index,n); //convert array to ascending order
     print(arr,lastIndex); //print the longest increasing subsequence

 	
 }	

 	

