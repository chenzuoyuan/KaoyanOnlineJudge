#include <stdio.h>
int P[201];

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=200;i++){
            P[i]=0;
        }
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            P[x]++;
        }
        for(int i=1;i<=200;i++){
            if(P[i]==1){
                printf("BeiJu\n");
            }
            if(P[i]>=2){
                printf("%d\n",P[i]-1);
            }
        }
    }
    return 0;
}
