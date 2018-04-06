<<<<<<< HEAD
/*题目描述: 
=======
/*
题目描述: 
>>>>>>> be4136afe956a1db42a5093d6012701d8da66ca4
有一棵树，输出某一深度的所有节点，有则输出这些节点，无则输出EMPTY。该树是完全二叉树。
输入描述:
输入有多组数据。
每组输入一个n(1<=n<=1000)，然后将树中的这n个节点依次输入，再输入一个d代表深度。
输出描述:
输出该树中第d层得所有节点，节点间用空格隔开，最后一个节点后没有空格。

输入
4
1 2 3 4
2
输出
2 3
*/

#include <stdio.h>
#include <math.h>
using namespace std;
int main(){
    int n;
    int d;
    int a[1002];
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int k=int(log(n*1.0)/log(2.0));
        scanf("%d",&d);
<<<<<<< HEAD
        if(d>k){//if...else if的条件顺序错误会导致结果截然不同 
            printf("EMPTY\n"); 
=======
        if(d>k){//if...else if的条件顺序错误会导致结果截然不同
            printf("EMPTY\n");
>>>>>>> be4136afe956a1db42a5093d6012701d8da66ca4
        }
        else if(d<k){
            for(int i=(int)pow(2,d-1);i<(int)pow(2,d)-1;i++){
                printf("%d ",a[i]);
            }
            printf("%d\n",a[(int)pow(2,d)-1]);
        }
        else if(d=k){
            for(int i=(int)pow(2,d-1);i<n;i++){
                printf("%d ",a[i]);
            }
            printf("%d\n",a[n]);
        }
    }
    return 0;
}
