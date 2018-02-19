/*
题目描述：
求正整数N(N>1)的质因数的个数。
相同的质因数需要重复计算。如120=2*2*2*3*5，共有5个质因数。
输入：
可能有多组测试数据，每组测试数据的输入是一个正整数N，(1<N<10^9)。
输出：
对于每组数据，输出N的质因数的个数。

样例输入：
120
样例输出：
5
提示：
注意：1不是N的质因数；若N为质数，N是N的质因数。
*/

#include <stdio.h>
bool mark[100001];
int prime[100001];
int primeSize;
void init(){
    primeSize=0;
    for(int i=2;i<=100000;i++){
        if(mark[i]==true) continue;
        prime[primeSize++]=i;
        if(i>=1000) continue;
        for(int j=i*i;j<=100000;j+=i){
            mark[j]=true;
        }
    }
}
int main(){
    init();
    int n;
    while(scanf("%d",&n)!=EOF){
        int ansPrime[30];
        int ansSize=0;
        int ansNum[30];
        for(int i=0;i<primeSize;i++){
            if(n%prime[i]==0){
                ansPrime[ansSize]=prime[i];
                ansNum[ansSize]=0;
                while(n%prime[i]==0){
                    ansNum[ansSize]++;
                    n/=prime[i];
                }
                ansSize++;
                if(n==1) break;
            }
        }
        if(n!=1){
            ansPrime[ansSize]=n;
            ansNum[ansSize++]=1;
        }
        int ans=0;
        for(int i=0;i<ansSize;i++){
            ans+=ansNum[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
