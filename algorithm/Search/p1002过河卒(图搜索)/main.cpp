#include <iostream>

using namespace std;
int n,m,hx,hy;
long long G[25][25];
int dx[9] = {0,1,1,2,2,-2,-2,-1,-1};
int dy[9] = {0,2,-2,1,-1,1,-1,2,-2};
int nx[3] = {0,1,0};
int ny[3] = {0,0,1};
long long sum = 0;
bool dfs(int i,int j){
    if(i == n && j == m){
        sum++;
        return true;
    }
    for (int k = 1; k <= 2; ++k) {
        int cx = i + nx[k];
        int cy = j + ny[k];
        if(cx <= n && cy <= m && G[cx][cy] == 0){
            G[cx][cy] = 1;
            dfs(cx,cy);
            G[cx][cy] = 0;
        }
    }
}

//20 20 4 0
//56477364570
//57050531010
int main() {
    cin >> n >> m >> hx >> hy;

//    dfs(0,0);

    for (int i = 0; i <= 8; ++i) {
        G[dx[i]+hx][dy[i]+hy] = -1;
    }
    for (int k = 0; k <= m; ++k) {
        if(G[0][k] < 0)
            break;
        G[0][k] = 1;
    }
    for (int l = 0; l <= n; ++l) {
        if(G[l][0] < 0)
            break;
        G[l][0] = 1;
    }
    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= m; ++i) {
            if(G[j][i] < 0) continue;
            if(G[j-1][i] >= 0 && G[j][i-1] >= 0)
                G[j][i] = G[j-1][i] + G[j][i-1];
            else if(G[j-1][i] >= 0)
                G[j][i] = G[j-1][i];
            else if(G[j][i-1] >= 0)
                G[j][i] = G[j][i-1];
            else
                G[j][i] = 0;
        }
    }
//    for (int i1 = 1; i1 <= m; ++i1) {
//        for (int i = 1; i <= n; ++i) {
//            cout << G[i1][i] << " ";
//        }
//        cout << endl;
//    }
    cout << G[n][m] << endl;
    return 0;
}