#include<iostream>
using namespace std;

int main(){
	int r, c;
	int a[100][100], b[101][101];

	cin >> r; 
	cin >> c;

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++)
			cin >> a[i][j];
	}

	for(int i = 0; i < r+1; i++){
		for(int j = 0; j < c+1; j++)
			b[i][j] = 0;
	}

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			b[i][j] = a[i][j];
			b[i][c] += a[i][j];
			b[r][j] += a[i][j];
		}
	}

	for(int i = 0; i < r; i++)
			b[r][c] += b[i][c];

	for(int i = 0; i < r+1; i++){
		for(int j = 0; j < c+1; j++){
			cout << b[i][j];

			if(j == c)
				cout << endl;

			else
				cout << " ";
		}
	}
}



