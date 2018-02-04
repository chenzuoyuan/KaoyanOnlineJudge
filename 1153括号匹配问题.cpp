/*
题目描述：
    在某个字符串（长度不超过100）中有左括号、右括号和大小写字母；规定（与常见的算数式子一样）任何一个左括号都从内到外与在它右边且距离最近的右括号匹配。写一个程序，找到无法匹配的左括号和右括号，输出原来字符串，并在下一行标出不能匹配的括号。不能匹配的左括号用"$"标注,不能匹配的右括号用"?"标注.

输入：
    输入包括多组数据，每组数据一行，包含一个字符串，只包含左右括号和大小写字母，字符串长度不超过100。
    注意：cin.getline(str,100)最多只能输入99个字符！

输出：
    对每组输出数据，输出两行，第一行包含原始输入字符，第二行由"$","?"和空格组成，"$"和"?"表示与之对应的左括号和右括号不能匹配。

样例输入：
)(rttyy())sss)(
样例输出：
)(rttyy())sss)(
?            ?$
*/

#include <stdio.h>
#include <stack>
using namespace std;
stack<int> S;
char str[110];
char ans[110];
int main(){
	while(scanf("%s",str)!=EOF){
		int i;
		for(i=0;str[i]!=0;i++){
			if(str[i]=='('){
				S.push(i);
				ans[i]=' ';
			}
			else if(str[i]==')'){
				if(S.empty()==false){
					S.pop();
					ans[i]=' ';
				}
				else ans[i]='?';
			}
			else ans[i]=' ';
		}
		while(!S.empty()){
			ans[S.top()]='$';
			S.pop();
		}
		ans[i]=0;
		puts(str);
		puts(ans);
	}
	return 0;
}
