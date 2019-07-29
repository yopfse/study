#include<iostream>
#include<string>
#include<cctype>
#include<stdlib.h>
using namespace std;

int main(){
	char c;

	while(1){
		c = getchar();
		
		if(islower(c))
			putchar(toupper(c));

		else if(isupper(c))
			putchar(tolower(c));

		else if(c == ' ')
			cout << " ";
		
		else
			cout << c;

		if(c == '\n')
			break;
	}
}



