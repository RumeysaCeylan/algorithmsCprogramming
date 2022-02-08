#include <stdio.h>
#include <stdlib.h>

int max(); //to find max floor
void initialize(); //Initial values for floors 0 and 1
int ballNumber(); //to find minimum ball dropping number
int main(){

    int n ,m;
    scanf("%d%d",&n,&m); // take inputs as floor and ball numbers
    printf ("%d", ballNumber(n,m)); //print the minimum ball numbers that is used 
    return 0;

}


void initialize(int n,int m,int arr[m+1][n+1]){ //Initial values for floors 0 and 1

int a,b;
	
    for (a = 1; a <= m; a++){  //efficiency :  O(n)
	    arr[a][1] = 1;  //if the floor is only one then only 1 ball is used
		arr[a][0] = 0; //if the floor is zero then no ball is used

    }
    
    for(b = 1; b <= n; b++) arr[1][b] = b; 
	// If the number of balls is one, as many balls as the number of floors are used.

 
}


int max(int number1, int number2) { //finds the maximum value
  if(number1>number2)
     return number1;
  else 
     return number2;
 }

int ballNumber(int n, int m){  //efficiency : O(n^3)  time complexity : O(mn^2) space : O(mn)
//to find minimum ball dropping number

   if(n==0||n==1){  //if the floor is only one or zero then the ball is used as the number of floors
   	return n;   
   } 
   else if(m==1){//If there is only one ball, it will be used as much as the number of floors
       return n;  //because the ball tries them all one by one.
   	
   }
   else if(m==0){ //If there is no ball then there is no function.
   	return 0;
   }
   

else{
   
    int arr[m+1][n+1];  //a table is created for the floor and the balls used
    int temp;  // a temprorary variable
    int i,j,k;
	int total; 

   initialize(n,m,arr); //take initial values for floors 0 and 1
    
    for (i = 2; i <= m; i++){ //efficiency : O(n^3)  time complexity : O(mn^2) space : O(mn)

        for (j = 2; j <= n; j++){//after floor 1,the balls used for all floors are compared

            arr[i][j] = 2147483647; //Equals to the maximum value that an integer value can take

            for (k = 1; k <= j; k++){
//The highest number of balls used in a floor and the entire lower floor of that floor is looked at. 
                temp = 1 + max(arr[i-1][k-1], arr[i][j-k]);

                if (temp < arr[i][j])
//when it comes to the upper floor, it assigns the number of balls used to it
                    arr[i][j] = temp;

            }
        }
    }

    total=arr[m][n]; //finally returns the minimum number of balls used on the floor where the ball broke
	
    return total;
	}
}

