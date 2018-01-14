#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct E{
    int id;
    char name[9];
    int score;
}; 

bool cmp1(E a,E b){
    return a.id<b.id;
}
bool cmp2(E a,E b){
    int tmp=strcmp(a.name,b.name);
    if(tmp!=0) return tmp<0;
    else return a.id<b.id;
}
bool cmp3(E a,E b){
    if(a.score!=b.score) return a.score<b.score;
    else return a.id<b.id;
    }

int main(){
    int n,c;
    int Case=1;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        scanf("%d",&c);
        E *buf=new E[n];
        for(int i=0;i<n;i++){
            scanf("%d%s%d",&buf[i].id,&buf[i].name,&buf[i].score);
        }
        switch(c){
            case 1:sort(buf,buf+n,cmp1);break;
            case 2:sort(buf,buf+n,cmp2);break;
            case 3:sort(buf,buf+n,cmp3);break;
        }
        printf("Case %d:\n",Case++);
        for(int i=0;i<n;i++){
            printf("%06d %s %d\n",buf[i].id,buf[i].name,buf[i].score);
        }
    }
    return 0;
}
