/*************************************************************************
    > File Name: memoryleak.c
    > Author: wy7980
    > Mail: wy7980@gmail.com 
    > Created Time: 2015-10-23
 ************************************************************************/
#include<comb.h>
#include<stdio.h>
#include<malloc.h>
void fun()
{
	int *p=(int *)malloc(3*sizeof(int));
	p[2]=2;
	p[3]=3;
	free(p);
}
int main()
{
	int i=0;
	mksymbol_int(i);
	if(i){
	int *p=(int *)malloc(2*sizeof(int));	
	p[1]=2;
	p[2]=3;
	}
	fun();
	return 0;
}
