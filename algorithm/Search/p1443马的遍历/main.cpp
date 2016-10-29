#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
int n,m,startX,startY;
int G[220][220];
struct Node{
    int x,y;
    int level;
    Node(){}
    Node(int xx,int yy,int l):x(xx),y(yy),level(l){}
};

int dx[10] = {0,1,2,2,1,-1,-2,-2,-1};
int dy[10] = {0,-2,-1,1,2,2,1,-1,-2};

queue <Node> q;

int main() {
    cin >> n >> m >> startX >> startY;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            G[i][j] = -1;
        }
    }
    q.push(Node(startX,startY,0));
    G[startX][startY] = 0;
    Node tmp;
    while (!q.empty()){
        tmp = q.front();
        q.pop();
        for (int i = 1; i <= 8; ++i) {
            int cx = tmp.x + dx[i];
            int cy = tmp.y + dy[i];
            if(cx > 0 && cy > 0 && cx <= n && cy <= m && G[cx][cy] == -1){
                q.push(Node(cx,cy,tmp.level+1));
                G[cx][cy] = tmp.level + 1;
            }
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= m; ++i) {
            printf("%-5d",G[k][i]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}