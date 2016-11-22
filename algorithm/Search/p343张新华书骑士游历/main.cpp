#include <iostream>

using namespace std;
/*
 * 解法一:dfs

int m,n;
struct direction{
    int x,y;
    direction(){}
    direction(int xx,int yy):x(xx),y(yy){}
};
direction dir[5] = {direction(0,0),direction(1,-2),direction(2,-1),direction(2,1),direction(1,2)};
int book[100][100];
bool dfs(int i,int j){
    if(i == m && j == n){
        return true;
    }
    for (int k = 1; k <= 4; ++k) {
        int cx = i + dir[k].x;
        int cy = j + dir[k].y;
        //可以优化:每次至少向右走1步,最多向上走两步,如果上面的剩余步数大于2倍的向右剩余步数则剪枝
//        if (book[cx][cy] == 0 && cx >= 1 && cy >= 1 && cx <= m && cy <= n){
        if(book[cx][cy] == 0 && ((n - cy) <=  (2 * (m - cx))) && cx >= 1 && cy >= 1 && cx <= m && cy <= n){
            book[cx][cy] = 1;
            if(dfs(cx,cy)){
                cout << k << " ";
                return true;
            }
        }
    }
    return false;
}
int main() {
    cin >> m >> n;
    if(!dfs(1,1)){
        cout << -1 << endl;
    }
    return 0;
}*/

//迭代回溯??
int main(){
    int step = 0,m,n;
    int dx[5] = {0,1,2,2,1};
    int dy[5] = {0,-2,-1,1,2};
    int s[100],x = 1,y = 1;
    int next = 0;
    cin >> m >> n;
    while (1){
        if(x == m && y == n){//如果到达B点,则退出
            break;
        }
        next++;//改变方向
        if(next > 4){//4个方向都试完,后退一步
            next = s[step];
            step--;
            x -= dx[next];
            y -= dy[next];
        } else {
            x += dx[next];
            y += dy[next];
            if(x > m || y < 1 || y > n){//越界退回
                x -= dx[next];
                y -= dy[next];
            } else {
                step++;
                s[step] = next;
                next = 0;
            }
        }
    }
    for (int i = 1; i <= step; ++i) {
        cout << s[i] << " ";
    }
}