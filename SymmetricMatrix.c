/* This program is Reading numbers from a text file with the following format and save it as a symmetric matrix in a two-dimensional array: 
   1.The first line of the file describes the number of lines (= number of columns) of the symmetric matrix. 
   2.In the second and subsequent lines of the file, for elements in the upper triangular part of the symmetric matrix, information of elements whose values are not 0 is described in order of line number, column number, and value, one for each line.

attention: ・Specify input file name with command line argument.
           ・Each value is separated by one space, and all diagonal components are 0.
   */

#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 512

int **read_matrix(char *fname, int *s);
void check_argnum(int min, int max, int arg_num, char *cmd);
void print_usage(char *cmd);

int main(int argc, char* argv[]){
	int **m, size, i, j;

	check_argnum(2, 2, argc, argv[0]);
	m = read_matrix(argv[1], &size);
	printf("  ");
	for(i = 0; i < size; i++)
		printf(" %2d", i + 1);
	printf("\n");
	for(i = 0; i < size; i++){
		printf("%2d", i+1);
		for(j = 0; j < size; j++)
			printf(" %2d", m[i][j]);
		printf("\n");
	}

	return 0;
}

int **read_matrix(char *fname, int *s){
	int i, j, k, n, **m;
	FILE *fp;
	char buf[1024];

	if((fp = fopen(fname, "r")) == NULL){
		printf("File cannot be opened\n");
		exit (1);
	}

	fgets(buf, sizeof(buf), fp);
	sscanf(buf, "%d", s);

	m = calloc((*s), sizeof(int *));

	for(k = 0; k < *s; k++)
		m[k] = calloc((*s), sizeof(int));

	if(m == NULL){
		printf("Memory cannot be reserved\n");
		exit (1);
	}

	while(!feof(fp)){
		fgets(buf, sizeof(buf), fp);
		sscanf(buf, "%d %d %d", &i, &j, &n);
		m[i][j] = n;
		m[j][i] = n;
	}

	fclose(fp);

	return m;
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
