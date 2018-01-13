#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
    int n;
    int buf[1001];
    while(scanf("%d",&n)!=EOF&&n>=1&&n<=1000){
        for(int i=0;i<n;i++){
            scanf("%d",&buf[i]);
        }
		sort(buf,buf+n);
        
        printf("%d\n",buf[n-1]);
        
        if(n==1){
            printf("-1\n");
        }else{
            for(int i=0;i<n-1;i++){
                if(i==n-2){
                    printf("%d\n",buf[i]);
                }else{
                    printf("%d ",buf[i]);
                }
            }
        }
    }
    return 0;
}
