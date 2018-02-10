/*
题目描述: 
图片：http://uploadfiles.nowcoder.com/images/20150421/39_1429598902788_btree.jpg
    如上所示，由正整数1，2，3……组成了一颗特殊二叉树。我们已知这个二叉树的最后一个结点是n。现在的问题是，结点m所在的子树中一共包括多少个结点。     比如，n = 12，m = 3那么上图中的结点13，14，15以及后面的结点都是不存在的，结点m所在子树中包括的结点有3，6，7，12，因此结点m的所在子树中共有4个结点。
输入描述:
    输入数据包括多行，每行给出一组测试数据，包括两个整数m，n (1 <= m <= n <= 1000000000)。
输出描述:
    对于每一组测试数据，输出一行，该行包含一个整数，给出结点m所在子树中包括的结点的数目。

输入
3 12
输出
4

参考算法：http://uploadfiles.nowcoder.net/images/20160502/811262_1462158822151_072774B6B658B3603E1AA7198722775C

*/

#include <stdio.h>
#include <math.h>
using namespace std;
int main(){
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF){
        int ans;
        int k=int(log(n*1.0/m)/log(2.0))+1;
        int tmp=n-pow(2,k-1)*m+1;
        if(tmp>pow(2,k-1)){
            ans=pow(2,k)-1;
        }
        else{
            ans=pow(2,k-1)-1+tmp;
        }
        printf("%d",ans);
    }
    return 0;
}
