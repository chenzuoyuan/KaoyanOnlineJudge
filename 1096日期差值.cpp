/*题目描述
有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天
输入描述:
有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD
输出描述:
每组数据输出一行，即日期差值

输入
20110412
20110422
输出
11
*/ 

#include <stdio.h>
#define ISYEAP(x) x%100!=0 && x%4==0 || x%400==0?1:0

int dayOfMonth[13][2]={
    0,0,
    31,31,
    28,29,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31
};

struct Date{
    int Day;
    int Month;
    int Year;
    void nextDay(){
        Day ++;
        if(Day>dayOfMonth[Month][ISYEAP(Year)]){
            Day=1;
            Month++;
            if(Month>12){
                Month=1;
                Year++;
            }
        }
    }
};

int buf[5001][13][32];
int Abs(int x){
    return x<0?-x:x;
}

int main(){
    Date tmp;
    int cnt=0;
    tmp.Day=1;
    tmp.Month=1;
    tmp.Year=0;
    while(tmp.Year!=5001){
        buf[tmp.Year][tmp.Month][tmp.Day]=cnt;
        tmp.nextDay();
        cnt++;
    }
    int d1,m1,y1;
    int d2,m2,y2;
    while(scanf("%4d%2d%2d",&y1,&m1,&d1)!=EOF){
        scanf("%4d%2d%2d",&y2,&m2,&d2);
        printf("%d\n",Abs(buf[y2][m2][d2]-buf[y1][m1][d1]+1));
    }return 0;
}
