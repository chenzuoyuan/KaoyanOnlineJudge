/*题目描述：
需要的时候，就把一个个大小差一圈的筐叠上去，使得从上往下看时，边筐花色交错。这个工作现在要让计算机来完成，得看你的了。 
输入描述:
输入是一个个的三元组，分别是，外筐尺寸n（n为满足0<n<80的奇整数），中心花色字符，外筐花色字符，后二者都为ASCII可见字符；
输出描述:
输出叠在一起的筐图案，中心花色与外筐花色字符从内层起交错相叠，多筐相叠时，最外筐的角总是被打磨掉。叠筐与叠筐之间应有一行间隔。

输入
11 B A
5 @ W
输出
AAAAAAAAA 
ABBBBBBBBBA
ABAAAAAAABA
ABABBBBBABA
ABABAAABABA
ABABABABABA
ABABAAABABA
ABABBBBBABA
ABAAAAAAABA
ABBBBBBBBBA
 AAAAAAAAA 

 @@@ 
@WWW@
@W@W@
@WWW@
 @@@ 

*/

#include <stdio.h>
int main(){
    int outPutBuf[82][82];
    char a,b;
    int n;
    bool firstCase=true;
    while(scanf("%d %c %c",&n,&a,&b)==3){
        if(firstCase==true){
            firstCase=false;
        }
        else printf("\n");
        for(int i=1,j=1;i<=n;i+=2,j++){
            int x=n/2+1,y=x;
            x-=j-1;y-=j-1;
            char c=j%2==1?a:b;
            for(int k=1;k<=i;k++){
                outPutBuf[x+k-1][y]=c;
                outPutBuf[x][y+k-1]=c;
                outPutBuf[x+i-1][y+k-1]=c;
                outPutBuf[x+k-1][y+i-1]=c;
            }
        }
        if(n!=1){
            outPutBuf[1][1]=' ';
            outPutBuf[n][1]=' ';
            outPutBuf[1][n]=' ';
            outPutBuf[n][n]=' ';
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                printf("%c",outPutBuf[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
