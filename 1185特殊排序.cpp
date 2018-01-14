/*题目描述：
输入一系列整数，将其中最大的数挑出，并将剩下的数进行排序。
输入：
输入第一行包括1个整数N，1<=N<=1000，代表输入数据的个数。
接下来的一行有N个整数。
输出：
可能有多组测试数据，对于每组数据，
第一行输出一个整数，代表N个整数中的最大值，并将此值从数组中去除，将剩下的数进行排序。
第二行将排序的结果输出。

样例输入：
4
1 3 4 2
样例输出：
4
1 2 3
*/ 

#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
    int n;
    int buf[1001];
    while(scanf("%d",&n)!=EOF&&n>=1&&n<=1000){
        for(int i=0;i<n;i++){
            scanf("%d",&buf[i]);
        }
		sort(buf,buf+n);
        
        printf("%d\n",buf[n-1]);
        
        if(n==1){
            printf("-1\n");
        }else{
            for(int i=0;i<n-1;i++){
                if(i==n-2){
                    printf("%d\n",buf[i]);
                }else{
                    printf("%d ",buf[i]);
                }
            }
        }
    }
    return 0;
}
