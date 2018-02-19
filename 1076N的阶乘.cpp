/* 
题目描述：
 输入一个正整数N，输出N的阶乘。
输入：
正整数N(0<=N<=1000)
输出：
 输入可能包括多组数据，对于每一组输入数据，输出N的阶乘

样例输入：
4
5
15
样例输出：
24
120
1307674368000
*/

#include <stdio.h>
#include <string.h>
struct bigInteger{
    int digit[1000];
    int size;
    void init(){
        for(int i=0;i<1000;i++) digit[i]=0;
        size=0;
    }
    void set(int x){
        init();
        do{
            digit[size++]=x%10000;
            x/=10000;
        }while(x!=0);
    }
    void output(){
        for(int i=size-1;i>=0;i--){
            if(i!=size-1) printf("%04d",digit[i]);
            else printf("%d",digit[i]);
        }
        printf("\n");
    }
    bigInteger operator * (int x) const {
        bigInteger ret;
        ret.init();
        int carry=0;
        for(int i=0;i<size;i++){
            int tmp=x*digit[i]+carry;
            carry=tmp/10000;
            tmp%=10000;
            ret.digit[ret.size++]=tmp;
        }
        if(carry!=0){
            ret.digit[ret.size++]=carry;
        }
        return ret;
    }
}a;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        a.init();
        a.set(1);
        for(int i=1;i<=n;i++){
            a=a*i;
        }
        a.output();
    }
    return 0;
}
