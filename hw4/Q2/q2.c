#include <stdio.h>
#include <stdlib.h>
int len(); //to find the length of string
int interleaving(); // to obtain z
//efficiency : O(n)

int main(int argc, char *argv[]) {

	char x[20],y[20],z[20];
	scanf("%s%s%s",x,y,z); //takes inputs as string 
	int a =interleaving(x,y,z);
	if(a==1){ //if z can be obtained then function returns 1
	  printf("YES");	
	} 
	else{//if z cannot be obtained then function returns 0
	 printf("NO");	
	}
	return 0;
}

int len(char *str){ 
//A function to find the length of string
	int i=0;
	for(;str[i]!='\0';++i);
	
	return i;
}
int interleaving(char x[],char y[],char z[]){ // A function to obtain z
	int i=0,j=0,k;
	
	  // efficiency : O(n)-->sum(k=0 to len(z) 3)
	  for(k=0;k!=len(z);k++){  //check up to the last index of z
    	if(y[j]==z[k]){ //z can be obtained if any index of y is in the array z
    		if (j<len(y)) //if j is greater than y then it goes out of its index. 
            j++;   //so when j is greater than the length of z it does not provide here
		}
      
        else if(x[i]==z[k]){ //z can be obtained if any index of x is in the array z
        	if (i < len(x))  //if i is greater than z then it goes out of its index. 
		       i++;	//so when i is greater than the length of z it does not provide here
           	
		}
         
        else   // If any index of x or y is not equal to any index of z, then z cannot be obtained.
            return 0;
    
    }
    
    if (i<len(x) ){ //if i is less than the length of x then not all indexes could be used
    	return 0;
	}
        
    else if(j<len(y)) //if j is less than the length of y then not all indexes could be used
	  return 0;
 
    return 1;
 
}
