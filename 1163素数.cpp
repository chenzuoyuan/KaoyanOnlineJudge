/*
题目描述:
输入一个整数n(2<=n<=10000)，要求输出所有从1到这个整数之间(不包括1和这个整数)个位为1的素数，如果没有则输出-1。
输入描述:
输入有多组数据。
每组一行，输入n。
输出描述:
输出所有从1到这个整数之间(不包括1和这个整数)个位为1的素数(素数之间用空格隔开，最后一个素数后面没有空格)，如果没有则输出-1。

输入
100
输出
11 31 41 61 71
*/

#include <stdio.h>
int prime[10000];
int primeSize;
bool mark[10001];
void init(){
    for(int i=1;i<=10000;i++){
        mark[i]=false;
    }
    primeSize=0;
    for(int i=2;i<=10000;i++){
        if(mark[i]==true) continue;
        prime[primeSize++]=i;
        for(int j=i*i;j<=10000;j+=i){
            mark[j]=true;
        }
    }
}
int main(){
    init();
    int n;
    while(scanf("%d",&n)!=EOF){
        bool isOutput=false;
        for(int i=0;i<primeSize;i++){
            if(prime[i]<n && prime[i]%10==1){
                if(isOutput==false){
                    isOutput=true;
                    printf("%d",prime[i]);
                }
                else printf(" %d",prime[i]);
            }
        }
        if(isOutput==false){
            printf("-1\n");
        }
        else printf("\n");
    }
    return 0;
}
