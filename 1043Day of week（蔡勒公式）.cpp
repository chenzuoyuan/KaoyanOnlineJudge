/* 
题目描述
We now use the Gregorian style of dating in Russia. The leap years are years with number divisible by 4 but not divisible by 100, or divisible by 400. For example, years 2004, 2180 and 2400 are leap. Years 2004, 2181 and 2300 are not leap. Your task is to write a program which will compute the day of week corresponding to a given date in the nearest past or in the future using today’s agreement about dating.
输入描述:
There is one single line contains the day number d, month name M and year number y(1000≤y≤3000). The month name is the corresponding English name starting from the capital letter.
输出描述:
Output a single line with the English name of the day of week corresponding to the date, starting from the capital letter. All other letters must be in lower case.

Month and Week name in Input/Output:
January, February, March, April, May, June, July, August, September, October, November, December
Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday

输入
9 October 2001
14 October 2001
输出
Tuesday
Sunday
*/

#include <stdio.h>
#include <string.h>
char monthName[13][20]={
	"",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
}; 

int main(){
	int year,month,day;
	char s[20]; 
while(scanf("%d%s%d",&day,&s,&year)!=EOF)
{
	for(month=0;month<=12;month++){
		if(strcmp(s,monthName[month])==0){
			break;	
		}
	}
	if(month==1||month==2){//判断month是否为1或2　
		year--;
		month+=12;
	}
	int c=year/100;
	int y=year-c*100;
	int week=(c/4)-2*c+(y+y/4)+(13*(month+1)/5)+day-1;
	while(week<0){week+=7;}
	week%=7;
	switch(week)
	{
	case 1:printf("Monday\n");break;
	case 2:printf("Tuesday\n");break;
	case 3:printf("Wednesday\n");break;
	case 4:printf("Thursday\n");break;
	case 5:printf("Friday\n");break;
	case 6:printf("Saturday\n");break;
	case 0:printf("Sunday\n");break;
	}
}
return 0;
}
