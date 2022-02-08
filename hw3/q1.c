#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

//Returns the element placed first in the queue
int peek() {
   return intArray[front];
}
//checks is queue empty or not
int isEmpty() {
	if(itemCount==0)
   return 1;
return 0;
}
//checks is queue full or not
int isFull() {
	if(itemCount==MAX)
	return 1;
	
   return 0;
}
//insert data in to the queue
void push(int data) {

   if(!isFull()) {
	
      if(rear == MAX-1) {
         rear = -1;            
      }       

      intArray[++rear] = data;
      itemCount++;
   }
}
//remove data in to the queue
int pop() {
   int data = intArray[front++];
	
   if(front == MAX) {
      front = 0;
   }
	
   itemCount--;
   return data;  
}
//This function produces a graph using the breadth first search algorithm.
//if the graph creates a cycle, it is checked whether it is an odd number of edges or not.
int oddCycle(int n,int arr[][n],int src){ //efficiency analysis : worst case O(n) running time O(n+m)
	int color[n];
	int i;
	color[src]=1; //first vertex is gray
	for(i=1;i<n;i++){
		color[i]=-1; //every edge is white
	}

	push(src);
	while(!isEmpty()){ //if queue is not empty then 
		int u = peek(); //take first index -->first vertex
		
		int temp=pop();
		if(arr[u][u]==1)//if it is visited
			return 1;
		int v;
		for(v=0;v<n;++v){ 
			if(arr[u][v]&&color[v]==-1){//if it is not visited,add the queue
				color[v]=1-color[u];
				push(v);
			}
			else if(arr[u][v]&&color[v]==color[u]) //checks it is odd cycle
				return 1;
		}
	}
	
	
	
	return 0;
}
int main(int argc, char *argv[]) {
	int n,i,j;
	scanf("%d",&n);
	int arr[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&arr[i][j]);
	
	int control=oddCycle(n,arr,0);
	if(control){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	
	return 0;
}
