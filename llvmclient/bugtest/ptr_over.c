/*************************************************************************
    > File Name: pointer_overflow.c
    > Author: wy7980
    > Mail: wy7980@gmail.com 
    > Created Time: 2015-09-22
 ************************************************************************/
#include<malloc.h>
#include<stdio.h>
#include<comb.h>
int main()
{
	int *p;
	int i=0;
	p=(int *)malloc(3*sizeof(int));
	mksymbol_int(i);
	p[0]=1;
	p[1]=2;
	p[2]=3;
	p[3]=4;
	if(i==6){
		printf("value : %d\n",p[i++]);
	}
	return 0;
}
