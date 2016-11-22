#include <iostream>

using namespace std;
int n,m,G[20][20];
int dx[5] = {0,1,2,2,1};
int dy[5] = {0,-2,-1,1,2};
int sum = 0;
void dfs(int x,int y){
    if(n == x && m == y){
        sum++;
        return;
    } else {
        for (int i = 1; i <= 4; ++i) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            //可以优化:每次至少向右走1步,最多向上走两步,如果上面的剩余步数大于2倍的向右剩余步数则剪枝
            if(cx >= 0 && cy >= 0 & cx <= n & cy <= m && G[cx][cy] == 0 && (m - cy) <= 2*(n - cx)){
                G[cx][cy] = 1;
                dfs(cx,cy);
                G[cx][cy] = 0;
            }
        }
    }
}
int main() {
    cin >> m >> n;
    G[0][0] = 1;
    dfs(0,0);
    cout << sum << endl;
    return 0;
}