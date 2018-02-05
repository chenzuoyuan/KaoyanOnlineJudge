/*
题目描述:
判断两序列是否为同一二叉搜索树序列
输入描述:
开始一个数n，(1<=n<=20) 表示有n个需要判断，n= 0 的时候输入结束。
接下去一行是一个序列，序列长度小于10，包含(0~9)的数字，没有重复数字，根据这个序列可以构造出一颗二叉搜索树。
接下去的n行有n个序列，每个序列格式跟第一个序列一样，请判断这两个序列是否能组成同一颗二叉搜索树。
输出描述:
如果序列相同则输出YES，否则输出NO
示例1
输入
2
567432
543267
576342
0
输出
YES
NO
*/

#include <stdio.h>
#include <string.h>
struct Node{
    Node *lchild;
    Node *rchild;
    int c;
}Tree[110];
int loc;
Node *creat(){
    Tree[loc].lchild=Tree[loc].rchild=NULL;
    return &Tree[loc++];
}
char str1[25],str2[25];
int size1,size2;
char *str;
int *size;
void postOrder(Node *T){
    if(T->lchild!=NULL){
        postOrder(T->lchild);
    }
    if(T->rchild!=NULL){
        postOrder(T->rchild);
    }
    str[(*size)++]=T->c+'0';
}
void inOrder(Node *T){
    if(T->lchild!=NULL){
        inOrder(T->lchild);
    }
    str[(*size)++]=T->c+'0';
    if(T->rchild!=NULL){
        inOrder(T->rchild);
    }
}
Node *Insert(Node *T,int x){
    if(T==NULL){
        T=creat();
        T->c=x;
        return T;
    }
    else if(x<T->c)
        T->lchild=Insert(T->lchild,x);
    else if(x>T->c)
        T->rchild=Insert(T->rchild,x);
    return T;
}
int main(){
    int n;
    char tmp[12];
    while(scanf("%d",&n)!=EOF && n!=0){
        loc=0;
        Node *T=NULL;
        scanf("%s",tmp);
        for(int i=0;tmp[i]!=0;i++){
            T=Insert(T,tmp[i]-'0');
        }
        size1=0;
        str=str1;
        size=&size1;
        postOrder(T);
        inOrder(T);
        str1[size1]=0;
        while(n--!=0){
            scanf("%s",tmp);
            Node *T2=NULL;
            for(int i=0;tmp[i]!=0;i++){
                T2=Insert(T2,tmp[i]-'0');
            }
            size2=0;
            str=str2;
            size=&size2;
            postOrder(T2);
            inOrder(T2);
            str2[size2]=0;
            puts(strcmp(str1,str2)==0 ? "YES":"NO");
        }
    }
    return 0;
}
