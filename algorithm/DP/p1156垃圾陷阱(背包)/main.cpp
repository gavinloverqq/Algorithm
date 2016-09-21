#include <iostream>
#define INF 1<<30
using namespace std;

int main() {
    int v,e;
    int g[100][100];
    int a,b,c;
    cin >> v >> e;
    for (int i = 0; i <= v; ++i) {
        for (int j = 0; j <= v; ++j) {
            g[i][j] = INF;
            g[i][i] = 0;
        }
    }
    for (int k = 0; k < e; ++k) {
        cin >> a >> b >> c;
        g[a][b] = c;
//        g[b][a] = c;
    }
    int dist[100],book[100];
    for (int m = 1; m <= v; ++m) {
        book[m] = 0;
        dist[m] = g[1][m];
    }
    book[1] = 1;
    for (int l = 1; l < v; ++l) {
        int minD = INF;int currNode;
        for (int i = 1; i <= v; ++i) {
            if(book[i] != 1 && minD > dist[i]){
                minD = dist[i];
                currNode = i;
            }
        }
        book[currNode] = 1;
        for (int j = 1; j <= v; ++j) {
            if(book[j] != 1 && dist[j] > dist[currNode] + g[currNode][j]){
                dist[j] = dist[currNode] + g[currNode][j];
            }
        }
    }
    for (int n = 1; n <= v; ++n) {
        cout << dist[n] <<" ";
    }
    cout << endl;
    return 0;
}