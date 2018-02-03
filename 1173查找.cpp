/*
题目描述:
输入数组长度 n 输入数组      a[1...n] 输入查找个数m 输入查找数字b[1...m]   输出 YES or NO  查找有则YES 否则NO 。
输入描述:
输入有多组数据。
每组输入n，然后输入n个整数，再输入m，然后再输入m个整数（1<=m,n<=100）。
输出描述:
如果在n个数组中输出YES否则输出NO。

输入
5
1 5 2 4 3
3
2 5 6
输出
YES
YES
NO
*/

#include <stdio.h>
int main(){
    int m,n; 
    int a[102];
    int b[102];
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%d",&b[i]);
        }
        for(int i=1;i<=m;i++){
            bool YES=0;
            for(int j=1;j<=n;j++){
                if(a[j]==b[i]){
                    printf("YES\n");
                    YES=1;
                    j=n;
                }
            }
            if(YES==0) printf("NO\n");
        }
    }
    return 0;
}
