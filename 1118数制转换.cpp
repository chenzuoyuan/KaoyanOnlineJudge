/*
题目描述:
    求任意两个不同进制非负整数的转换（2进制～16进制），所给整数在long所能表达的范围之内。     不同进制的表示符号为（0，1，...，9，a，b，...，f）或者（0，1，...，9，A，B，...，F）。
输入描述:
    输入只有一行，包含三个整数a，n，b。a表示其后的n 是a进制整数，b表示欲将a进制整数n转换成b进制整数。a，b是十进制整数，2 =< a，b <= 16。
    数据可能存在包含前导零的情况。
输出描述:
    可能有多组测试数据，对于每组数据，输出包含一行，该行有一个整数为转换后的b进制数。输出时字母符号全部用大写表示，即（0，1，...，9，A，B，...，F）。

输入
15 Aab3 7
输出
210306
*/

#include <stdio.h>
#include <string.h>
int main(){
    int a,b;
    char str[40];
    while(scanf("%d%s%d",&a,str,&b)!=EOF){
        int tmp=0,lenth=strlen(str),c=1;
        for(int i=lenth-1;i>=0;i--){
            int x;
            if(str[i]>='0' && str[i]<='9'){
                x=str[i]-'0';
            }
            else if(str[i]>='a' && str[i]<='z'){
                x=str[i]-'a'+10;
            }
            else{
                x=str[i]-'A'+10;
            }
            tmp+=x*c;
            c*=a;
        }
        char ans[40],size=0;
        do{
            int x=tmp%b;
            ans[size++]=(x<10) ? x+'0':x-10+'A';
            tmp/=b;
        }while(tmp);
        for(int i=size-1;i>=0;i--){
            printf("%c",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
