/* This program is finding the greatest common divisor of two natural numbers (not including 0) entered from the keyboard */
#include<stdio.h>

int gcd(int x, int y);

int main(){
	int x, y, n;

	printf("Enter two natural numbers separated by commas：");
	scanf("%d,%d", &x, &y);

	n = gcd(x, y);

	printf("The greatest common divisor of %d and %d is %d\n", x, y, n);

	return 0;
}

int gcd(int x, int y){
	int n, r;

	printf("gcd(%d, %d)\n", x, y);

	if(y != 0){
		r  = x%y;
		n = gcd(y, r);
	}

	else
		n = x;

	return n;
}
