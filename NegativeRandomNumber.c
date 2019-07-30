/* This program is which 10 integer random numbers in the range of -10 or more and 10 or less */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	int i;

	printf("乱数の生成\n");

	for(i = 0; i < 10; i++)
		printf("%d\n", rand()%21-10);

	return 0;
}
