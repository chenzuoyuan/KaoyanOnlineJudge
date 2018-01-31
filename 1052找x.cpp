/*题目描述
输入一个数n，然后输入n个数值各不相同，再输入一个值x，输出这个值在这个数组中的下标（从0开始，若不在数组中则输出-1）。
输入描述:
测试数据有多组，输入n(1<=n<=200)，接着输入n个数，然后输入x。
输出描述:
对于每组输入,请输出结果。

输入
2
1 3
0
输出
-1
*/

#include <stdio.h>
int main(){
    int buf[200];
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&buf[i]);
        }
        int x,ans=-1;
        scanf("%d",&x);
        for(int i=0;i<n;i++){
            if(x==buf[i]){
                ans=i;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
