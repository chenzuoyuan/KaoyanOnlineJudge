/*
题目描述
输入N个学生的信息，然后进行查询。
输入描述:
输入的第一行为N，即学生的个数(N<=1000)
接下来的N行包括N个学生的信息，信息格式如下：
01 李江 男 21
02 刘唐 男 23
03 张军 男 19
04 王娜 女 19
然后输入一个M(M<=10000),接下来会有M行，代表M次查询，每行输入一个学号，格式如下：
02
03
01
04
输出描述:
输出M行，每行包括一个对应于查询的学生的信息。
如果没有对应的学生信息，则输出“No Answer!”
示例1
输入
4
01 李江 男 21
02 刘唐 男 23
03 张军 男 19
04 王娜 女 19
5
02
03
01
04
03
输出
02 刘唐 男 23
03 张军 男 19
01 李江 男 21
04 王娜 女 19
03 张军 男 19
*/

#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct Student{
    char no[100];
    char name[100];
    int age;
    char sex[5];
    bool operator < (const Student &A) const{
        return strcmp(no,A.no)<0;
    }
}buf[1000];

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%s%s%s%d",buf[i].no,buf[i].name,buf[i].sex,&buf[i].age);
        }
        sort(buf,buf+n);
        int t;
        scanf("%d",&t);
        while(t--!=0){
            int ans=-1;
            char x[30];
            scanf("%s",x);
            int top=n-1,base=0;
            while(top>=base){
                int mid=(top+base)/2;
                int tmp=strcmp(buf[mid].no,x);
                if(tmp==0){
                    ans=mid;
                    break;
                }
                else if(tmp>0) top=mid-1;
                else base=mid+1;
            }
            if(ans==-1){
                printf("No Answer!\n");
            }
            else printf("%s %s %s %d\n",buf[ans].no,buf[ans].name,buf[ans].sex,buf[ans].age);
        }
    }
    return 0;
}
