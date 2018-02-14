/*
题目描述:
输入两个正整数，求其最大公约数。
输入描述:
测试数据有多组，每组输入两个正整数。
输出描述:
对于每组输入,请输出其最大公约数。

输入
49 14
输出
7
*/

#include <stdio.h>
int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        printf("%d\n",gcd(a,b));
    }
    return 0;
}
