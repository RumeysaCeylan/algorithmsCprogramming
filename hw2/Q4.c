#include<stdio.h>
//RumeysaCeylan
struct task{
	char id;
	int deadline;
	int profit;
	
};
void swap(int *xp, int *yp)//Swaps two values
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void swapChar(char *s,char*p){//Swaps two strings
	char temp= *s;
	*s=*p;
	*p=temp;
	
}
void minDeadline(int n,struct task arr[n]){ //this function puts in order to values by deadline
	 int i, j;
   for (i = 0; i < n-1; i++)       //T(n)=SUM(0 TO N-2(SUM(1 TO N-i-1)1) = (n^2-n)=O(N^2)
       for (j = 1; j < n-i-1; j++) 
           if (arr[j].deadline> arr[j+1].deadline){ //if deadline is bigger,then the importance is less
           	swap(&arr[j].deadline, &arr[j+1].deadline);//replace the indexes in order to importance
           	swap(&arr[j].profit, &arr[j+1].profit);
           	swapChar(&arr[j].id,&arr[j+1].id);
		   }
              
}

void BForceAlgorithm(int n,struct task t[n]){
	int tasks[n];
	minDeadline(n,t);
	int i,j,k=0;
	for(i=0;i<n;i++){//T(n)=SUM(0 TO N(SUM(0 TO N-i)2) = (2*(n^2+3n+2))/2=O(N^2)
		for(j=0;j<n-i,k<n;j++){ //enters every index of given tasks
			if((t[j].deadline==t[j+1].deadline)){ //if deadline are same then looks at the profit
				
				if((t[j].profit<t[j+1].profit)){  //if profit is smaller, then the other id must be taken
					/*swap(&t[j].deadline, &t[j+1].deadline);
           			swap(&t[j].profit, &t[j+1].profit);
           			swapChar(&t[j].id,&t[j+1].id);*/
           			tasks[k]=t[j+1].id;
           			j++;
           			k++;
			   	}
			
           		else{ //if profit is bigger, then that index should be taken
           			tasks[k]=t[j].id;
           			k++;
           			j++;
				   }
				   
			}
			else{
				tasks[k]=t[j].id;
				
				k++;
				
				
			}
			
		}
	}
	
	for(i=0;i<n;i++){
	
		printf("%c ",tasks[i]);
	}
	
}

int main() {
   
  
   int n,i;
   scanf("%d",&n);
	struct task t[100];
	for(i=0;i<n;i++){ //takes input from user 
		scanf("%s",&t[i].id);
		scanf("%d",&t[i].deadline);
		scanf("%d",&t[i].profit);
	}

   BForceAlgorithm(n,t);
   
   
   
    return 0;
}
