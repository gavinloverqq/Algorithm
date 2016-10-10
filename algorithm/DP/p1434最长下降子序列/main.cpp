#include <iostream>

using namespace std;
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
}