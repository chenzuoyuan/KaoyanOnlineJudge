/*
题目描述:
    堆栈是一种基本的数据结构。堆栈具有两种基本操作方式，push 和 pop。Push一个值会将其压入栈顶，而 pop 则会将栈顶的值弹出。现在我们就来验证一下堆栈的使用。
输入描述:
     对于每组测试数据，第一行是一个正整数 n，0<n<=10000(n=0 结束)。而后的 n 行，每行的第一个字符可能是'P’或者'O’或者'A’；如果是'P’，后面还会跟着一个整数，表示把这个数据压入堆栈；如果是'O’，表示将栈顶的值 pop 出来，如果堆栈中没有元素时，忽略本次操作；如果是'A’，表示询问当前栈顶的值，如果当时栈为空，则输出'E'。堆栈开始为空。
输出描述:
    对于每组测试数据，根据其中的命令字符来处理堆栈；并对所有的'A’操作，输出当时栈顶的值，每个占据一行，如果当时栈为空，则输出'E’。当每组测试数据完成后，输出一个空行。

输入
3
A
P 5
A
4
P 3
P 6
O 
A
输出
E
5

3

*/

#include <stdio.h>
#include <stack>
using namespace std;

int main(){	
    stack<int> S;
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0){
        while(!S.empty())
            S.pop();
        char str[100001];
        for(int i=0;i<n;i++){
            scanf("%s",&str[i]);
            if(str[i]=='A'){
                if(S.empty()){
                    printf("E\n");
                }
                else printf("%d\n",S.top());
            }
            else if(str[i]=='O'){
                if(!S.empty()){
                    S.pop();
                }
            }
            else if(str[i]=='P'){
                int tmp;
                scanf("%d",&tmp);
                S.push(tmp);
            }
        }
        printf("\n");
    }
    return 0;
}
