/*
题目描述:
读入两个小于10000的正整数A和B，计算A+B。需要注意的是：如果A和B的末尾K（不超过8）位数字相同，请直接输出-1。
输入描述:
测试输入包含若干测试用例，每个测试用例占一行，格式为"A B K"，相邻两数字有一个空格间隔。当A和B同时为0时输入结束，相应的结果不要输出。
输出描述:
对每个测试用例输出1行，即A+B的值或者是-1。

输入
1 2 1
11 21 1
108 8 2
36 64 3
0 0 1
输出
3
-1
-1
100
*/

#include <stdio.h>
#include <math.h>

int main() {
    int a,b,k;
    while(scanf("%d%d%d",&a,&b,&k) != EOF){
        if(a == 0 && b == 0) return 0;
        if(a % (int)pow(10,k) == b % (int)pow(10,k)) printf("-1\n");
        else printf("%d\n",a + b);
    }
}
