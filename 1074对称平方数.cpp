/*
题目描述： 
打印所有不超过n(n<256)的，其平方具有对称性质的数。

如11*11=121
输入： 
无任何输入数据
输出： 
输出具有题目要求的性质的数。如果输出数据不止一组，各组数据之间以回车隔开。
*/

#include <stdio.h>
#include <math.h>

int main() {
	int n;
	for(n=0; n < 256; n++) {
		int tmp = n * n;
		if(tmp > 100 && tmp < 1000 && tmp /100 == tmp % 10) printf("%d\n", n);
		else if(tmp >10000 && tmp < 100000  && tmp / 10000 == tmp % 10 && (tmp / 1000) % 10 == (tmp / 10) % 10) printf("%d\n", n);
	}
}
