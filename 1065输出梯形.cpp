/*题目描述：
输入一个高度h，输出一个高为h，上底边为h的梯形。
输入：
一个整数h(1<=h<=1000)。
输出：
h所对应的梯形。

样例输入：
4
样例输出：
      ****
    ******
  ********
**********
*/

#include <stdio.h>

int main(){
	int h;
	while(scanf("%d",&h)!=EOF){
		int maxLine=h+(h-1)*2;
		for(int i=1;i<=h;i++){
			for(int j=1;j<=maxLine;j++){
				if(j<maxLine-h-(i-1)*2+1)
				    printf(" ");
				else
				    printf("*");
			}
			printf("\n");
		}
	}
	return 0;
} 
