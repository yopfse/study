/* This program is Generating real random numbers from 0 to 4 as many as specified by the command line argument, and similarly writes them to the file specified by the command line argument */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double getDouble(void);
double *makeData(int n);
void writeData(char *fname, double *data, int n);
void check_argnum(int min, int max, int arg_num, char *cmd);
void print_usage(char *cmd);

int main(int argc, char **argv) {
    double *data;
    int num;

    check_argnum(3, 3, argc, argv[0]);
    srand((unsigned)time(NULL));
    num = atoi(argv[1]);
    data = makeData(num);
    writeData(argv[2], data, num);

    return 0;
}

double getDouble(void){
	double n;

	n = ((double)rand()/(double)RAND_MAX)*4;

	return n;
}

double *makeData(int n){
	int i;
	double *d;

	d = calloc((n), sizeof(double));;
	
	for(i = 0; i < n; i++)
		d[i] = getDouble();

	return d;
}

void writeData(char *fname, double *data, int n){
	FILE *fp;
	int i;

	if((fp = fopen(fname, "w")) == NULL){
		printf("File cannot be opened\n");
		exit (1);
	}

	for(i = 1; i <= n; i++)
		fprintf(fp, "%d,%lf\n", i, data[i-1]);

	fclose(fp);
}

void print_usage(char *cmd){
	printf("Usage\n");
	printf("%s 'input_file'\n", cmd);
}

void check_argnum(int min, int max, int arg_num, char *cmd){
	if(arg_num < min || arg_num > max){
		printf("Too %s arguments!\n", (arg_num < min) ? "few": "many");
		print_usage(cmd);

		exit(1);
	}
}
