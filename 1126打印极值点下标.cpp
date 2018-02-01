/*
题目描述：
在一个整数数组上，对于下标为i的整数，如果它大于所有它相邻的整数， 或者小于所有它相邻的整数，则称为该整数为一个极值点，极值点的下标就是i。 
输入描述:
第一行是此数组的元素个数k(4<k<80)，第二行是k个整数，每两个整数之间用空格分隔。
输出描述:
每个案例输出为n行：每行对应于相应数组的所有极值点下标值，下标值之间用空格分隔。

输入
10
10 12 12 11 11 12 23 24 12 12
输出
0 7
*/ 

#include <stdio.h>
int main(){
    int k,j;
    int buf[82];
    int point[82];
    while(scanf("%d",&k)!=EOF){
        if(k<=4) break;
        j=0;
        for(int i=0;i<k;i++){
            scanf("%d",&buf[i]);
        }
        for(int i=0;i<k;i++){
            int left=i-1,right=i+1;
            if(left<0 && buf[right]!=buf[i]){
                point[j++]=i;
            }
            else if(buf[left]<buf[i] && buf[right]<buf[i] || buf[left]>buf[i] && buf[right]>buf[i]){
                point[j++]=i;
            }
            else if(right>k-1 && buf[left]!=buf[i]){
                point[j++]=i;
            }
        }
        for(int i=0;i<j;i++){
        	printf("%d",point[i]);
        	if(i!=j-1)
				printf(" ");
			else
			    printf("\n");
		}
    }
    return 0;
}
