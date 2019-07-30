/* This program is calculating factorial */
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define BUFSIZE 256

int factorial(int n);
int getValue(void);
void getInput(char msg[], char n[]);
int isInt(char n[]);

int main(){
	int n;

	n = getValue();

	printf("The factorial of %d is %d\n", n, factorial(n));

	return 0;
}

int factorial(int n){
	if(n > 1)
		return n*factorial(n-1);

	else
		return 1;
}

int getValue(){
	int n;
	char buf[BUFSIZE];

	while(1){
		getInput("Enter an integer value to calculate factorial：", buf);

		n = atoi(buf);
		if(!isInt(buf))
			printf("%s is not an integer value\n", buf);

		else
 			break;
	}

	return n;
}

void getInput(char msg[], char n[]){
	printf("%s", msg);
	gets(n);
}

int isInt(char n[]){
	int len, i;

	len = strlen(n);

	if(n[0] == '-')
		return 0;

	if(n[0] == '.')
		return 0;

	for(i = 0; i < len; i++){
		if(isalpha(n[i]))
			return 0;

		else if(n[i] == '.'){
			if(n[i+1] != '0')
				return 0;
		}
	}

	return 1;
}
