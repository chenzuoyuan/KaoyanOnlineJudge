/*
题目描述: 
输入两个不超过整型定义的非负10进制整数A和B(<=231-1)，输出A+B的m (1 < m <10)进制数。
输入描述:
输入格式：测试输入包含若干测试用例。每个测试用例占一行，给出m和A，B的值。
当m为0时输入结束。
输出描述:
输出格式：每个测试用例的输出占一行，输出A+B的m进制数。

输入
8 1300 48
2 1 7
0
输出
2504
1000
*/

#include <stdio.h>
int main(){
    long long a,b;
    int m;
    while(scanf("%d",&m)!=EOF){
        if(m==0) break;
        scanf("%lld%lld",&a,&b);
        a=a+b;
        int ans[50],size=0;
        do{
            ans[size++]=a%m;
            a/=m;
        }while(a!=0);
        for(int i=size-1;i>=0;i--){
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
