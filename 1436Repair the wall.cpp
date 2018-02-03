/*
题目描述：
Long time ago , Kitty lived in a small village. The air was fresh and the scenery was very beautiful. The only thing that troubled her is the typhoon. 
When the typhoon came, everything is terrible. It kept blowing and raining for a long time. And what made the situation worse was that all of Kitty's walls were made of wood. 
One day, Kitty found that there was a crack in the wall. The shape of the crack is 
a rectangle with the size of 1×L (in inch). Luckly Kitty got N blocks and a saw(锯子) from her neighbors. 
The shape of the blocks were rectangle too, and the width of all blocks were 1 inch. So, with the help of saw, Kitty could cut down some of the blocks(of course she could use it directly without cutting) and put them in the crack, and the wall may be repaired perfectly, without any gap. 
Now, Kitty knew the size of each blocks, and wanted to use as fewer as possible of the blocks to repair the wall, could you help her ? 
输入描述:
The problem contains many test cases, please process to the end of file( EOF ).
Each test case contains two lines.
In the first line, there are two integers L(0<L<1000000000) and N(0<=N<600) which 
mentioned above.
In the second line, there are N positive integers. The i th integer Ai(0<Ai<1000000000 ) means that the i th block has the size of 1×Ai (in inch).
输出描述:
For each test case , print an integer which represents the minimal number of blocks are needed.
If Kitty could not repair the wall, just print "impossible" instead.
       
输入
5 3
3 2 1
5 2
2 1
输出
2
impossible
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
struct block{
    int Ai;
    bool operator < (const block &B) const{
        return Ai>B.Ai;
    }
}buf[1002];
int main(){
    int L,N;
    while(scanf("%d%d",&L,&N)!=EOF){
        int La=0;
        int num=0;
	    for(int i=0;i<N;i++){
            scanf("%d",&buf[i].Ai);
        }
        sort(buf,buf+N);
        for(int i=0;i<N;i++){
            La=buf[i].Ai+La;
            num++;
            if(La>=L) break;
        }
        if(La>=L) printf("%d\n",num);
		else printf("impossible\n");
    }
    return 0;
}
