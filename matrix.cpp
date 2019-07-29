/* This program is which reads a n×m matrix A and a m×1 vector b, and prints their product Ab */

#include<iostream>
using namespace std;

int main(){
	int n, m, l;
	int a[100][100], b[100][100]; 
	long c[100][100];

	cin >> n;
	cin >> m;
	cin >> l;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	}

	for(int i = 0; i < m; i++){
		for(int j = 0; j < l; j++)
			cin >> b[i][j];
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < l; j++)
			c[i][j] = 0;
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < l; j++){
			for(int k = 0; k < m; k++)
				c[i][j] += a[i][k]*b[k][j];
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < l; j++){
			cout << c[i][j];

			if(j == l-1)
				cout << endl;

			else
				cout << " ";
		}
	}

}


