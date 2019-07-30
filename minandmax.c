/*　This program is finding the minimum and maximum among the values of integer type array given by argument */ 
   

#include<stdio.h>

int min(int *d, int num);
int max(int *d, int num);

int main(){
    int data[] = {4, 5, 1, 2, 7, 10, 8};
	
    printf("min：%d\n", min(data, (int)sizeof(data)/sizeof(int)));
    printf("max：%d\n", max(data, (int)sizeof(data)/sizeof(int)));
	
    return 0;
}

int min(int *d, int num){
	int i, n;

	n = d[0];

	for(i = 0; i < num; i++){
		if(n > d[i])
			n = d[i];
	}

	return n;
}

int max(int *d, int num){
	int i, n;

	n = d[0];

	for(i = 0; i < num; i++){
		if(n < d[i])
			n = d[i];
	}

	return n;
}
