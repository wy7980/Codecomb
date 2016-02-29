#include <comb.h>
#include <stdio.h>
#include <malloc.h>
int main(){


	int a[5]={1,2,3,4,5};
	int *p;
	p=a;
	int *q = (int *)malloc(5*sizeof(int));
	int *q2= (int *)malloc(5*sizeof(int));
	int *q3= (int *)malloc(5*sizeof(int));
	int i,j;
	mksymbol_int(i);
	mksymbol_int(j);
	if(i<10){
		a[i]=0;			
		if(j<8){
		q[j]=1;		
		p[j]=1;
		p[j]=a[i]+1;		
		}else{
		free(q3);
		}
	}
	free(q2);
	free(q2);
}

