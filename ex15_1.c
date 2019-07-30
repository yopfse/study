/* 15818991
   情報テクノロジー
   大石夏奈子
*/

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
