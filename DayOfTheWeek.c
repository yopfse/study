/* This program is find the day of the week of the day entered */
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define BUFSIZE 128

int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
char day_of_week[7][10]={
	"sunday","monday","tuesday", "wednesday", "thursday","friday", "saturday"};

void getInput(char msg[], char n[]);
int getYear(void);
int isInt(char n[]);
int getMonth(void);
int getDay(int y, int m);
int getDays(int y, int m);
int isLeapYear(int y);
int getDayOfWeekForFirstDay(int y);
int countDays(int y, int m, int d);
int getDayOfWeek(int dow, int days);

int main(){
	int year, month, day, dow, dow_first, days_in_year;
	
	year = getYear();
	printf("Year：%d\n", year);
	month = getMonth();
	printf("Month：%d\n", month);
	day = getDay(year, month);
	printf("Day：%d\n", day);
	dow_first = getDayOfWeekForFirstDay(year);
	printf("The day of 1/1, %d is %s\n", year, day_of_week[dow_first]);
	days_in_year = countDays(year, month, day);
	printf("%d/%d, %d　is the %dth day of the year\n",　month, day, year, days_in_year);
	dow = getDayOfWeek(dow_first, days_in_year);
	printf("The day is %s\n", day_of_week[dow]);

	return 0;
}

void getInput(char msg[], char n[]){
	printf("%s", msg);
	gets(n);
}

int getYear(void){
	char buf[BUFSIZE];
	int year;

	getInput("Enter the year (2000 or later)：", buf);
	
	year = atoi(buf);

	while(!isInt(buf) || year < 2000){
		getInput("Enter an integer value of 2000 or more：", buf);
		year = atoi(buf);
	}

	return year;
}

int getMonth(void){
	char buf[BUFSIZE];
	int month;

	getInput("Enter the month：", buf);
	
	month = atoi(buf);

	while(!isInt(buf) || (month <= 0 || month >= 13)){
		getInput("Enter the month as an integer from 1 to 12：", buf);
		month = atoi(buf);
	}

	return month;
}

int getDay(int y, int m){
	char buf[BUFSIZE];
	int day;

	getInput("Enter the day：", buf);
	
	day = atoi(buf);

	while(!isInt(buf) || (day <= 0 || day >= getDays(y, m))){
		printf("For %d, %d,", m, y);

		if(getDays(y, m) == 30)
			getInput("enter an integer from 1 to 30：", buf);

		else if(getDays(y, m) == 31)
			getInput("enter an integer from 1 to 31：", buf);

		else if(getDays(y, m) == 28)
			getInput("enter an integer from 1 to 28：", buf);

		else
			getInput("enter an integer from 1 to 29：", buf);

		day = atoi(buf);
	}

	return day;

}

int getDays(int y, int m){
	int day;

	if(isLeapYear(y)) day = 29;
	
	else day = days[m-1]; 

	return day;
}

int getDayOfWeekForFirstDay(int y){
	y--;
	return (y+y/4-y/100+y/400+(13*13+8)/5+1)%7;
}

int isLeapYear(int y){
	int flag;

	if(y%100 == 0 && y%400 == 0)
		flag = 1;

	else if(y%100 == 0 || y%4 != 0)
		flag = 0;

	else
		flag = 1;

	return flag;
}

int countDays(int y, int m, int d){
	int sum=0,year = 0, i;
/*
	if(y > 2001)
		year = y-2001;

	for(i = 0; i < year; i++){
		if(isLeapYear(year+i))
			sum += 366;

		else
			sum += 365;
	}
*/
	for(i = 1; i < m; i++)
		sum += getDays(y, i);

	sum += d;

	return sum;
}

int getDayOfWeek(int dow, int days){
	return days%7+dow-1;
}

int isInt(char n[]){
	int len, i, num;

	len = strlen(n);
	num = atoi(n);

	for(i = 0; i < len; i++){
		if(isalpha(n[i]))
			return 0;

		else if(n[i] == '.'){
			printf("%s is not integer\n", n);
			return 0;
		}	
	}

	return 1;
}
				
