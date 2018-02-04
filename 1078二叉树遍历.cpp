/*
题目描述:
二叉树的前序、中序、后序遍历的定义： 前序遍历：对任一子树，先访问跟，然后遍历其左子树，最后遍历其右子树； 中序遍历：对任一子树，先遍历其左子树，然后访问根，最后遍历其右子树； 后序遍历：对任一子树，先遍历其左子树，然后遍历其右子树，最后访问根。 给定一棵二叉树的前序遍历和中序遍历，求其后序遍历（提示：给定前序遍历与中序遍历能够唯一确定后序遍历）。
输入描述:
两个字符串，其长度n均小于等于26。
第一行为前序遍历，第二行为中序遍历。
二叉树中的结点名称以大写字母表示：A，B，C....最多26个结点。
输出描述:
输入样例可能有多组，对于每组测试样例，
输出一行，为后序遍历的字符串。

输入
ABC
BAC
FDXEAG
XDEFAG
输出
BCA
XEDGAF
*/

#include <stdio.h>
#include <string.h>
struct Node{
    Node *lchild;
    Node *rchild;
    char c;
}Tree[50];
int loc;
Node *creat(){
    Tree[loc].lchild=Tree[loc].rchild=NULL;
    return &Tree[loc++];
}
char str1[30],str2[30];
void postOrder(Node *T){
    if(T->lchild!=NULL){
        postOrder(T->lchild);
    }
    if(T->rchild!=NULL){
        postOrder(T->rchild);
    }
    printf("%c",T->c);
}
Node *build(int s1,int e1,int s2,int e2){
    Node* ret=creat();
    ret->c=str1[s1];
    int rootIdx;
    for(int i=s2;i<=e2;i++){
        if(str2[i]==str1[s1]){
            rootIdx=i;
            break;
        }
    }
    if(rootIdx!=s2){
        ret->lchild=build(s1+1,s1+(rootIdx-s2),s2,rootIdx-1);
    }
    if(rootIdx!=e2){
        ret->rchild=build(s1+(rootIdx-s2)+1,e1,rootIdx+1,e2);
    }
    return ret;
}
int main(){
    while(scanf("%s",str1)!=EOF){
        scanf("%s",str2);
        loc=0;
        int L1=strlen(str1);
        int L2=strlen(str2);
        Node *T=build(0,L1-1,0,L2-1);
        postOrder(T);
        printf("\n");
    }
    return 0;
}
