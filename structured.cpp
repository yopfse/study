/* This program is solution of Structured Programming in AOJ */

#include<iostream>
using namespace std;

int main(){
	int n,count = 0,a;
	cin >> n;

	for(int i = 1; i <= n; i++){
	      
		if(i%3 == 0 || i%10 == 3 || i/10 == 3){
			cout << " ";
			cout << i;
		}
		
		else{
			a = i;
			while(a > 0){
				a /= 10;

				if(a%10 == 3){
					cout << " ";
					cout <<	i;
					break;
				}
			}
		}
	}
	cout << endl;
}


