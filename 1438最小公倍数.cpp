/*
题目描述: 
给定两个正整数，计算这两个数的最小公倍数。 
输入描述:
输入包含多组测试数据，每组只有一行，包括两个不大于1000的正整数.
输出描述:
对于每个测试用例，给出这两个数的最小公倍数，每个实例输出一行。
       
输入
10 14
输出
70
*/

#include <stdio.h>
int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);//另一种写法：return b!=0 ? gcd(b,a%b):a;
}
int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        printf("%d\n",a*b/gcd(a,b));
    }
    return 0;
}
