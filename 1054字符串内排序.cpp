/*题目描述
输入一个字符串，长度小于等于200，然后将输出按字符顺序升序排序后的字符串。
输入描述:
测试数据有多组，输入字符串。
输出描述:
对于每组输入,输出处理后的结果。

示例1
输入
bacd
输出
abcd
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    char buf[201];
    for(int i=0;i<201;i++){
        gets(buf[i]);
    }
        sort(buf,buf+n);
        for(int 0;i<201;i++){
            printf("%s",buf[i]);
        }

}
