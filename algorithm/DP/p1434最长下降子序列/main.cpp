#include <iostream>
#include <algorithm>
#define REP(I, START, END) for(int I = START; I <= END; I++)
using namespace std;

/*
int R,C;
int G[110][110],dp[110][110];

//方向向量
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

//记忆化搜索
int searchDp(int i,int j){
    if(dp[i][j] > 0)
        return dp[i][j];
    int ans = 1;
    for (int k = 0; k < 4; ++k) {
        int cx = i + dx[k],cy = j + dy[k];
        if(cx >= 0 && cx <= R && cy >= 0 && cy <= C && G[i][j] < G[cx][cy]){
            ans = max(ans,searchDp(cx,cy) + 1);
        }
    }
    dp[i][j] = ans;
    return ans;
}

int main() {
    cin >> R >> C;
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            cin >> G[i][j];
        }
    }
    int ans = 1;
    for (int k = 1; k <= R; ++k) {
        for (int i = 1; i <= C; ++i) {
            ans = max(ans,searchDp(k,i));
        }
    }
    cout << ans << endl;
    return 0;
}*/


int R,C;
const int MAXN = 105;
//方向向量
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

struct Node{
    int x,y,height;
    Node(){}
    Node(int xx,int yy,int hh):x(xx),y(yy),height(hh){}
};
//各个点按照高度排序
bool operator < (Node a,Node b){
    //下面这种判断也是很不错的判断方式!
//    if(a.height != b.height) return a.height > b.height;
//    if(a.x != b.x) return a.x > b.x;
//    return a.y > b.y;
    return a.height > b.height;
}
Node G[MAXN * MAXN];
int dp[MAXN][MAXN],a[MAXN][MAXN];
int main(){
    cin >> R >> C;
    int index = 0;
    REP(i,1,R)
        REP(j,1,C){
            cin >> a[i][j];
            G[index++] = Node(i,j,a[i][j]);
            dp[i][j] = 1;
        }
    sort(G,G + index);//高到低排序
    int ans = 1;
    REP(i,0,(index - 1)){
        REP(j,0,3){//其实此处能体现出LIS的依赖关系,当前点只与周围的4个点相关,因此只要考虑这4个点。而最朴素的LIS中dp[i]则可由前1到i-1中所有的点都相关
            int cx = G[i].x + dx[j],cy = G[i].y + dy[j];
            if(cx >= 0 && cx <= R && cy >= 0 && cy <= C && G[i].height < a[cx][cy]){
                dp[G[i].x][G[i].y] = max(dp[G[i].x][G[i].y],dp[cx][cy]+1);
            }
        }
        ans = max(ans,dp[G[i].x][G[i].y]);
    }
    cout << ans << endl;
}

