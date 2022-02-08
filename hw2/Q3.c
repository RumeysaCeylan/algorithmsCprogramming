#include <stdio.h>
#include <stdlib.h>
//RumeysaCeylan
int len(char *str){ //A function to find the length of string
	int i=0;
	for(;str[i]!='\0';++i);
	
	return i+1;
}
int isPalindrome(char* str,int subNum,int k)
{	//This function checks is the substrings are palindrome or not
	int i=0,j;
 	for(j=k-subNum;j<subNum,j<k-1-i;j++){
		   		if(str[j]!=str[k-1-i]){ //if substring's reverse and itself are not equal 
		   			return 0;//then these are not palindrome
				   }
				   i++;
			   }
		return 1;
			
}
int countSubString(char *str){

	int n=len(str); //take the inputs length
	
	int count = 0;

 	int j,i,m,k;
 	int subNum=0;
 //	char temp[n];
 
   for(i=0;i<n;i++){ //T(n)=SUM(0 TO N-1(SUM(i+1 TO N)1) = (n^2-n)/2=O(N^2)
   	for(j=i+1;j<=n;j++){//O(N^2)
   		for(m=j,k=i;m-k>0;k++){
   		
   			subNum++;
   			
		   }
			if(subNum<2); //if words length smaller than two then it cannot be palindrome
		   else{

			   if(isPalindrome(str,subNum,k)){//check is palindrome or not
			   	count++; //if palindrome then add the counter
			  
			   }
		   }
  
		   subNum=0;
  
	   }
	    
   }  
   
    // return total palindromic substrings
    return count;
}

int main(int argc, char *argv[]) {
	 char str[1000];
     printf("Enter String : ");

	gets(str); //takes input the string from user 

   printf("%d",countSubString(str));
	  
	return 0;
}


