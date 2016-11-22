#include <iostream>

using namespace std;
int m,n;
int G[110][110],book[110][110];

int zx[9] = {0,0,0,-1,-1,-1,1,1,1};//0下标不用
int zy[9] = {0,1,-1,-1,0,1,-1,0,1};

/*
5 5
0 0 1 0 0
0 1 0 1 1
0 1 0 0 0
0 1 0 1 0
1 0 1 0 0
 */


bool dfs(int i,int j){
//    book[1][1] = 1;
    if(m == i && n == j){
        return true;
    }
    for (int k = 1; k <= 8; ++k) {
        int cx = i + zx[k];
        int cy = j + zy[k];
        if(cx >= 1 && cx <= m && cy >= 1 && cy <= n && G[cx][cy] == 0 && book[cx][cy] == 0){
            book[cx][cy] = 1;
            if(dfs(cx,cy)){
                cout << cx << " " << cy << endl;
                return true;//如果此处不加???
            }
//            book[cx][cy] = 0;//代表可以重复走??
        }
    }
    return false;
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> G[i][j];
        }
    }
    book[1][1] = 1;
    if(dfs(1,1))//逆序搜即可顺序输出
        cout << 1 << " " << 1 << endl;
    else
        cout << "-1" << endl;
    return 0;
}