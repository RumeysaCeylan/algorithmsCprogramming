#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
void initialize();
int leftShift();
int holding();
int countUnhappines();
void min_unHappines();
int main(){

        int n, k;
        scanf("%d", &n); //It is taken the number of passengers as input
 int i;
        int x[n];
	int people[n];
        // taking input of all the passengers' destinations.
        for(i = 0 ; i < n ; i++){
                scanf("%d%d", &people[i],&x[i]); //It is taken as input that people will get off at the bus stop and their queue.
        }
 		scanf("%d",&k);  //The number of stops at which the bus will stop is taken as an input.
     
       min_unHappines( n, k, x); //to find the bus station for minimum unhappiness
        
       
        return 0;
}

void initialize(int arr[],int size){ //this function initilize the arrays to zero
		int i;
 //efficiency  : O(n)
	for(i = 0; i < size; i++) {  //0 is assigned from the first index to the last index
		arr[i] = 0;
	}
}
int leftShift(int a){//Takes two numbers, left shifts the bits of the first operand,
	a=1<<a;  // the second operand decides the number of places to shift.
	return a;
}
int countUnhappines(int x[],int arr[],int j,int p;){
	
	
}
int holding(int temp[],int holdArr[],int n,int i){
	int counter=0;
	int j;
	 for(j = 0 ; j < n ; j++){ //The index is increased one by one from 0 to the total number of passengers to stop at the station.
        //efficiency O(n)                
                           if(leftShift(j) & i){ //for j shifted to the left and for i
                                
                                temp[counter] = holdArr[j];
                                //the array we hold is assigned to a temporary array variable
                                counter += 1;
                        
                        }
                        else{
                        	continue;
						}
                }
  return counter;
  
}
void min_unHappines(int n,int k,int x[]){
	int i,j;
 	int p;
 	
 	int id[n],last[n];
 	int control=INT_MAX;  //assume the first initial value in bus is very high
 	int s=0;
 	int holdArr[n];
 	initialize(holdArr,n); //initialize the array to zero
 	i = 1;
        while(i <n+1){ //The array we will process is assigned to another array for later. Keeping this array for later use
                holdArr[i - 1] =x[i-1];  //In this array, the stops that the passengers want to get off are kept.
                i++;  //go to next index
        }
 
        for( i = 1 ; i < leftShift(n) ; i++){ //efficiency : sum(i=1 to n sum(0 to n sum(0 to k  x))) = O(n^3)
                //It is looped by incrementing until n is shifted
                int arr[n] ;
                initialize(arr,n); //initialize the temprory array to 0
                
                int counter = 0;
                
               counter=holding(arr,holdArr,n,i); //the array with stall numbers is assigned to a temporary array
 					//counter is found
                
                if(counter == k){ // If the dimension is k only then we will look at the next calculations
                        int unhappiness = 0;
 
                        for( j = 0 ; j < n ; j++){ //The index is increased one by one from 0 to the total number of passengers to stop at the station.
                                
                                int minCnt = INT_MAX; //assume the first initial value in bus is very high
                                
                                for(p= 0 ; p < k ; p++){ //The index is increased one by one from 0 to the most stop number.
                                        
                                        int result = (x[j] - arr[p]) * (x[j] - arr[p]); // calculate the unhappiness 
                                        id[p]=arr[p];
                                        // If minimum value is greater than result than assign value to minCnt
                                        if(minCnt > result){
                                        	
                                                
                                                minCnt = result; //assign the lower result
                                        		
                                        }
                                        else{
                                        	continue;  //otherwise do nothing
										}
                                        
                                
                                }
                                
                                unhappiness += minCnt; //add the minCnt which is unhappiness result to the unhappiness variable
                        
                        }
 						if(control>unhappiness){
 							s=0;
 							 while(s<k){
                                	last[s]=id[s]; //assign the bus station which is stopable to the last array
                                	s+=1;
								}
								control=unhappiness;  // control the unhappiness number
						 }
						 else {
						 	continue; //otherwise do nothing
						 }
                        
                }
        }
        
        p=0;
		while(p<k){
        printf("%d ",last[p]); //print the result
		p++;	
		}
       
}
