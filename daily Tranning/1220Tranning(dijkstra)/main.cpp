#include <iostream>

using namespace std;
/*
dijkstra算法
        * intput:
6 9
1 2 1
1 3 12
2 3 9
2 4 3
3 5 5
4 3 4
4 5 13
4 6 15
5 6 4
output:
0  1  8  4 13 17

*/
int G[100][100];
int n,m;
const int MAX = 1 << 30;
int main() {
    cin >> n >> m;
    int dist[100],book[100];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            G[i][j] = MAX;
            G[i][i] = 0;
            dist[i] = MAX;
            book[i] = 0;
        }
    }
    int s,d,v;
    for (int k = 0; k < m; ++k) {
        cin >> s >> d >> v;
        G[s][d] = v;
        G[d][s] = v;
    }

    for (int i = 1; i <= n; ++i) {
        dist[i] = G[1][i];
    }
    book[1] = 1;
    for (int l = 0; l < n - 1; ++l) {
        int minNode = MAX,minDist = MAX;
        for (int i = 1; i <= n; ++i) {
            if(book[i] == 0){
                if(dist[i] < minDist){
                    minDist = dist[i];
                    minNode = i;
                }
            }
        }
        book[minNode] = 1;

//错误写法
//        for (int j = 1; j <= n; ++j) {
//            if(book[j] == 0){
//                if(dist[j] > G[1][minNode] + G[minNode][j]){
//                    dist[j] = G[1][minNode] + G[minNode][j];
//                }
//            }
//        }
        for (int j = 1; j <= n; ++j) {
            if(book[j] == 0){
                if(dist[j] > dist[minNode] + G[minNode][j]){
                    dist[j] = dist[minNode] + G[minNode][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "Hello, World!" << endl;
    return 0;
}