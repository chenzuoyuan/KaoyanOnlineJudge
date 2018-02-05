/*
题目描述:
输入一系列整数，建立二叉排序数，并进行前序，中序，后序遍历。
输入描述:
输入第一行包括一个整数n(1<=n<=100)。
接下来的一行包括n个整数。
输出描述:
可能有多组测试数据，对于每组数据，将题目所给数据建立一个二叉排序树，并对二叉排序树进行前序、中序和后序遍历。
每种遍历结果输出一行。每行最后一个数据之后有一个空格。
输入中可能有重复元素，但是输出的二叉树遍历序列中重复元素不用输出。

输入
5
1 6 5 9 8
输出
1 6 5 9 8 
1 5 6 8 9 
5 8 9 6 1 
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
void postOrder(Node *T){
    if(T->lchild!=NULL){
        postOrder(T->lchild);
    }
    if(T->rchild!=NULL){
        postOrder(T->rchild);
    }
    printf("%d ",T->c);
}
void inOrder(Node *T){
    if(T->lchild!=NULL){
        inOrder(T->lchild);
    }
    printf("%d ",T->c);
    if(T->rchild!=NULL){
        inOrder(T->rchild);
    }
}
void preOrder(Node *T){
    printf("%d ",T->c);
    if(T->lchild!=NULL){
        preOrder(T->lchild);
    }
    if(T->rchild!=NULL){
        preOrder(T->rchild);
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
    while(scanf("%d",&n)!=EOF){
        loc=0;
        Node *T=NULL;
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            T=Insert(T,x);
        }
        preOrder(T);
        printf("\n");
        inOrder(T);
        printf("\n");
        postOrder(T);
        printf("\n");
    }
    return 0;
}
