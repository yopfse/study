 /* This program is solution of problem that Finding Missing Cards in AOJ */

#include<iostream>
using namespace std;

int main(){
	int cards[4][13];
	int n, m;
	char c;
	
	for(int i = 0; i < 13; i++){
		for(int j = 0; j < 4; j++)
			cards[j][i] = 0;
	}

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> c;
		cin >> m;

		if(c == 'S')
			cards[0][m-1] = 1;

		else if(c == 'H')
			cards[1][m-1] = 1;

		else if(c == 'C')
			cards[2][m-1] = 1;

		else
			cards[3][m-1] = 1;
	}

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 13; j++){
			if(cards[i][j] == 0){
				if(i == 0)
					cout << "S " << j+1 << endl;

				else if(i == 1)
					cout << "H " << j+1 << endl;

				else if(i == 2)
					cout << "C " << j+1 << endl;

				else 
					cout << "D " << j+1 << endl;

			}
		}
	}
}
		
