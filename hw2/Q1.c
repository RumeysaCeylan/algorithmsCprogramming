#include <stdio.h>
#include <stdlib.h>
//RumeysaCeylan
int main(int argc, char *argv[]) {
	int sum=0;
	int i,j,m,n=0;
	int a=0,b=0;
	int empty=1;
	int num[100];
	while(scanf("%d",&num[n])!=EOF){//takes input until all data over
		
		n++;
	}
	int arrN[n];
	int arrP[n];
	int index=n-1;
	for(i=0;i<n;i++){ //convert all numbers to negative
		num[i]=-num[i];
		
	}
	//T(n)=SUM(0 TO N (1)(SUM 0 TO N-1(SUM(N-1 TO N)))=(n^2+2n-1)=O(N^2)
	while(index>=0){ //index will start to look at the end of the array
		
		for(j=index;j<n;j++){ //start to convert positive every index step by step
			num[j]=-num[j];
			
	
		for(m=0;m<n;m++){ //then summarize the negative and positive indexes
				//printf("%d ",arr[m]);
			sum+=num[m];
			}
			//printf("= %d\n",sum);
			if(sum!=0) { //if total is not 0 then the numbers cannot seperated
			sum=0;
			continue;
			}
			else{ //if total is 0 then seperate negative and positive indexes 
				
				for(m=0;m<n;m++){
					if(num[m]<0){
						empty=0;
						arrN[a]=-num[m]; //seperated first group
						a++;
					}
					else{
						empty=0;
					  arrP[b]=num[m]; //seperated second group
					  b++;
					}
			
				}
				index=-1;//if index is smaller than 0 then the numbers checked 
				break;
			}
		}
		index--;//if index is smaller than 0 then the numbers checked
	}
	if(empty){ //this block checks the numbers seperable or not
		printf("there numbers cannot be seperated as two groups\n");
	}
	for(i=0;i<a;i++){ //prints first group
		
		printf("%d ",arrN[i]);
		
	}
	printf("\n");
	for(i=0;i<b;i++){//prints second group
		printf("%d ",arrP[i]);
		
	}
	
	return 0;
}
