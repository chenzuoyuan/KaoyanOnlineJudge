/*
题目描述:
写个算法，对2个小于1000000000的输入，求结果。 特殊乘法举例：123 * 45 = 1*4 +1*5 +2*4 +2*5 +3*4+3*5
输入描述:
两个小于1000000000的数
输出描述:
输入可能有多组数据，对于每一组数据，输出Input中的两个数按照题目要求的方法进行运算后得到的结果。

输入
123 45
输出
54
*/

#include <stdio.h>
int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        int buf1[20],buf2[20],size1=0,size2=0;
        while(a!=0){
            buf1[size1++]=a%10;
            a/=10;
        }
        while(b!=0){
            buf2[size2++]=b%10;
            b/=10;
        }
        int ans=0;
        for(int i=0;i<size1;i++){
            for(int j=0;j<size2;j++){
                ans+=buf1[i]*buf2[j];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
