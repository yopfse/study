/* 15818991
   情報テクノロジー
   大石夏奈子
   */

#include<stdio.h>

int min(int *d, int num);
int max(int *d, int num);

int main(){
    int data[] = {4, 5, 1, 2, 7, 10, 8};
	
    printf("最小値：%d\n", min(data, (int)sizeof(data)/sizeof(int)));
    printf("最大値：%d\n", max(data, (int)sizeof(data)/sizeof(int)));
	
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
