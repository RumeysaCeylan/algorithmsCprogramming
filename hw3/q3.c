#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	int v1,v2;
	int result=0,result2=0;
	
	scanf("%d%d",&v1,&v2);
	int k=log2(v1); //n=2^k
	int A[k+1][k+1];
	A[0][0]=1;//A0=[1] matrices
	int x,i,j;
	for( x=1;x<k+1;x+=x){//efficiency analysis :O(n^3)
        for( i=0;i<x;i++){//here create the matrix
            for( j=0;j<x;j++){
                A[i+x][j]=A[i][j];
                A[i][j+x]=A[i][j];
                A[i+x][j+x]=-A[i][j];
            }
        }
    }
	for( i=0;i<k+1;i++){
        for( j=0;j<k+1;j++){//efficiency analysis :O(n^2)
        	//printf("%d ",A[i][j]*(v1+v2));
        	
            result+=A[i][j]*(v1+v2); //A(k)*(v1+v2)
 			result2+=A[i][j]*(v1-v2);//A(k)*(v1-v2)
        }
      
    }

	
    	printf("%d\n%d\n",result,result2); //print results
	
	return 0;
}
