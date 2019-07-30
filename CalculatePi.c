/* This program is calculating pi by Monte Carlo method */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double EstimateCircleArea(int r, int n);

int main(){
	int i;
	double r, pi[5]={0};

	srand((unsigned)time(NULL));

	printf("Enter the radius of the circle:");
	scanf("%lf", &r);

	for(i = 0; i < 100; i++)
		pi[0] += EstimateCircleArea(r, 100)/(r*r);

	pi[0] /= (double)100;

	for(i = 0; i < 100; i++)
		pi[1] += EstimateCircleArea(r, 1000)/(r*r);

	pi[1] /= (double)100;

	for(i = 0; i < 100; i++)
		pi[2] += EstimateCircleArea(r, 10000)/(r*r);

	pi[2] /= (double)100;

	for(i = 0; i < 100; i++)
		pi[3] += EstimateCircleArea(r, 100000)/(r*r);

	pi[3] /= (double)100;

	for(i = 0; i < 100; i++)
		pi[4] += EstimateCircleArea(r, 1000000)/(r*r);

	pi[4] /= (double)100;

	printf("Estimated value of pi by 100 points：%f\n", pi[0]);
	printf("Estimated value of pi by 1000 points：%f\n", pi[1]);
	printf("Estimated value of pi by 10000 points：%f\n", pi[2]);
	printf("Estimated value of pi by 100000 points：%f\n", pi[3]);
	printf("Estimated value of pi by 1000000 points：%f\n", pi[4]);
	
	return 0;
}

double EstimateCircleArea(int r, int n){
	double x, y;
	int count, i;

	for(i = 0, count = 0; i < n; i++){
		x = (double)rand()/(RAND_MAX)*r;
		y = (double)rand()/(RAND_MAX)*r;

		if(x*x+y*y < r*r)
			count++;
	}

	return (double)count/n*r*r*4.0;
}
