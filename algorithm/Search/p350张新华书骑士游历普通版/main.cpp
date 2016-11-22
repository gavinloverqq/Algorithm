#include <iostream>

using namespace std;

//一个有意思的事情:就是下面两种走法结果竟然不同,走的方向都是一致的
/*
5 5 3
19 20 19 12 19
20 13 18 3 18
19 4 15 8 11
14 9 6 17 2
5 16 1 10 7
*/

int n,x,y;
int G[100][100];

int dx[10] = {0,1,2,2,1,-1,-2,-2,-1};
int dy[10] = {0,-2,-1,1,2,2,1,-1,-2};

bool dfs(int num,int i,int j){
    if(num == n*n){
        return true;
    }
    for (int k = 1; k <= 8; ++k) {
        int cx = i + dx[k];
        int cy = j + dy[k];
        if(cx > 0 && cy > 0 && cx <= n && cy <= n && G[cx][cy] == 0){
            G[cx][cy] = num + 1;//考虑此处的回溯,一旦走到当前点之后无法走到下一点,就需要回溯。要把当前点的状态前清除掉
            if(!dfs(num+1,cx,cy)) {
                G[cx][cy] = 0;
                continue;
            }
            return true;
        }
    }
    return false;
}
int main() {
    cin >> n >> x >> y;
    G[x][y] = 1;
    dfs(1,x,y);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
5 5 3
25 4 17 12 23
16 11 24 3 8
5 18 9 22 13
10 15 20 7 2
19 6 1 14 21
*/
/*
int n,x,y;
int G[100][100];

int dx[10] = {0,1,2,2,1,-1,-2,-2,-1};
int dy[10] = {0,-2,-1,1,2,2,1,-1,-2};

int main(){
    cin >> n >> x >> y;
    int next = 0,num = 1;
    int cx = x,cy = y;
    int s[100];
    G[x][y] = 1;
    while (1){
        if(num == n*n)
            break;
        next++;
        if(next > 8){//走到这一步证明当前的路已经走不通了,需要回溯,并清除上一步的状态!
            next = s[num];
            num--;//
            G[cx][cy] = 0;
            cx -= dx[next];
            cy -= dy[next];

        } else {
            cx += dx[next];
            cy += dy[next];
            if(cx > 0 && cy > 0 && cx <= n && cy <= n && G[cx][cy] == 0){
                num++;
                s[num] = next;
                G[cx][cy] = num;
                next = 0;
            } else {
                cx -= dx[next];
                cy -= dy[next];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}*/
