#include<stdio.h>
#include<stdlib.h>

int switch_();
int shedule();
void initialize();

int main() {
  
int i,j;
int m,n;

scanf("%d%d",&n,&m); //take the number of steps and number of workers as input
int steps;
int arr[m][n]; //set the size of the array
for(i=0;i<m;i++){
	for(j=0;j<n;j++){
		arr[i][j]=0;  //initialize the array to 0 
	}
}
for(i=0;i<m;i++){
	scanf("%d",&steps); //take the each workers' step as an input
	for(j=0;j<steps;j++){ // increase to the number of steps
		scanf("%d",&arr[i][j]); //find for the each worker , which steps can handle
	}
}

int stepsHandle[n];
  
int x=switch_(n,m,arr, stepsHandle); //switch hands one to another
  
// print schedules
	for(i = 0; i < n; i++) {
		printf("%d ", stepsHandle[i]); //print the result
	}
 printf("with %d switches \n", x); //print the how many switching

  
  
 return 0;
}
void initialize(int size,int arr[]){  //initialize the array to 0
	int i;

	for(i = 0; i < size; i++) { //efficiency : O(n)
		arr[i] = 0;
	}
}
int shedule(int maxSq,int index,int *s,int worker){ //to find sheduling
	int i;
	for(i = 0; i < maxSq; i++) { //from zero to largest sequence lenght
		s[index++] = worker; //transfer the possible shedule of the workers to the array held with the pointer
	} //updating the worker
  return index;
}

/*
proof :

select the specific worker for whom the longest sequential task sequence and the seq with this task number are the longest.
Suppose your current task number is x, and you have found the value x, 
then the next first task number will be x + t + 1. 
 The process is repeated until all tasks are finished and the process begins with task number 1.
 Each time the sequence is interrupted, it means that the transition has occurred.
*/
/*
when we start with a task number and find a sequential sequence of tasks for each employee, 
if we choose any of them the switching will occur instead of the current switching number instead of max row 1+
we have 
A1(1,2,5)
A2(1,2,3,4)
first choose A1(1,2) then A2(3,4)
lastly 
A1(5) ---> switch 2


*/
int switch_(int n,int m,int arr[][n], int *s) { //ttime complexity O(1)
	int i, j;
	int s_Number = 0;
	int index = 0;
	int first; 
	int positionEnd[m];	//keeps up to index of workers last step
	initialize(m,positionEnd); 
  
	for(first=1;first < n+1;) { //efficiency : O(n^3)
	// initialize task number to select the longest sequence of tasks and increase until n+1
	
		int maxSq = 0; // holds largest sequence length
		int lastsqMax = -1; // holds largest sequence last task number
		int worker = -1; // worker selected for longest available sequence
		
		for(i = 0; i < m; i++) { //The index is increased one by one from 0 to the number of workers
			int lenght = 0;
			for(j = positionEnd[i]; j < n - 1; j++) {  //It increases one by one from ooan values ??to n-1 th index until the last steps of its workers.
				if(arr[i][j] == 0) { //if the array is 0 then the steps of that worker are finished
				break;
				}
				if(arr[i][positionEnd[i]] == first) {//The case where the index of a row of the array and the step of the worker on that row is equal to the task number is checked.
						if(lenght == 0) {//if the length is zreo then increase it

					lenght++;
						if(maxSq < lenght) { //if the largest sequence length is lower than lenght then equate the lenght to it
							maxSq = lenght;
							lastsqMax = first; //equate the largest sequence last task number to task number
							worker = i + 1;// 1 based selected worker
						}
				}
					if(arr[i][j] + 1 == arr[i][j + 1]) { //When we look at the situation where the sequence continues

				lenght++;
							if(maxSq < lenght) { //if the largest sequence length is lower than lenght then equate the lenght to it
								maxSq = lenght;
								lastsqMax = arr[i][j + 1];//equate the largest sequence last task number to the  worker's next step
								worker = i + 1; // 1 based selected worker
							}
				
				} else { 
					//If the sequence is not continuing, end it.
				break;
			}
		} else { 
				break;
			}
		}		
  }
  

	index=shedule(maxSq,index,s,worker); //to find sheduling

	for(i = 0; i < m; i++) {
		for(j = positionEnd[i]; j < m; j++) {
			if(arr[i][j] == 0) {  //if the array is 0 then the steps of that worker are finished
		break;
		}
		positionEnd[i] = j; //assign the next start index to every worker for choosing longest task sequence
		if(arr[i][j] > lastsqMax) { //choose task sequence for every worker
		
			break;
			}
		}
	}
  
	first = lastsqMax + 1; // next start task number
	s_Number=s_Number+1; // calculate the switching number
  }	

  
   return s_Number-1; //switching number
}










