#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN=1000000;
const int MAX=1000;
const int MQ=1000;
const int N=30;
//const int
int team[MAXN];
queue<int>que[MAX];
queue<int>bigQue;
void init(){
    while (!bigQue.empty()) {
        bigQue.pop();
    }
    for (int i = 0; i < MQ; i++) {
        while (!que[i].empty()) {
            que[i].pop();
        }
    }
}
int main()
{
    int nc(1);
    int teams;
    while(scanf("%d",&teams)==1&&teams){
        init();
        int n;
        memset(team,0,sizeof(team));
        for(int team_NO=0;scanf("%d",&n)==1;team_NO++) {
            for (int i=0;i<n;i++){
                int num;
                scanf("%d%*c",&num);
                team[num]=team_NO;
            }
        }
        printf("Scenario #%d\n",nc++);
        while(1){
            char cmd[N];
            scanf("%s",cmd);
            if(strcmp(cmd,"ENQUEUE")==0){
                int num;
                scanf("%d%*c",&num);
                if(que[team[num]].empty()){
                    bigQue.push(team[num]);
                }
                que[team[num]].push(num);
            }
            else if(strcmp(cmd,"DEQUEUE")==0){
                int whitch_team = bigQue.front();
                printf("%d\n", que[whitch_team].front());
                que[whitch_team].pop();
                if (que[whitch_team].empty()){
                    bigQue.pop();
                }
            }
            else{
                printf("\n");
                break;
            }
        }
    }
    return 0;
}
