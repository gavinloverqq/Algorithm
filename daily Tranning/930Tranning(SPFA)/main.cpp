#include <iostream>
#include <queue>
#include <vector>
#define INF 1 << 30
using namespace std;

struct Node{
    int d,w;
    Node(){}
    Node(int dd,int ww):d(dd),w(ww){}
};

int main() {
    int v,e;
    cin >> v >> e;
    vector <Node> G[50];
    int s,d,w;
    for (int i = 0; i < e; ++i) {
        cin >> s >> d >> w;
        G[s].push_back(Node(d,w));
    }
    int dist[100],book[100],num[100];
    for (int j = 0; j <= v; ++j) {
        dist[j] = INF;
//        book[j] = 0;
        num[j] = 0;
    }
    dist[1] = 0;
    queue <Node> q;
    q.push(Node(1,0));
    while (!q.empty()){
        Node tmp = q.front();
//        if (0 == book[tmp.d])
//            book[tmp.d] = 1;
        q.pop();
        for (int i = 0; i < G[tmp.d].size(); ++i) {
            if(dist[G[tmp.d][i].d] > dist[tmp.d] + G[tmp.d][i].w){
//            if(0 == book[G[tmp.d][i].d] && dist[G[tmp.d][i].d] > dist[tmp.d] + G[tmp.d][i].w){
                dist[G[tmp.d][i].d] = dist[tmp.d] + G[tmp.d][i].w;
                num[G[tmp.d][i].d]++;
                if(num[G[tmp.d][i].d] >= v){
                    cout << "fuquan" << endl;
                    break;
                }
                q.push(Node(G[tmp.d][i].d,dist[G[tmp.d][i].d]));
            }
        }
    }
    for (int k = 1; k <= v; ++k) {
        cout << dist[k] << " ";
    }
    return 0;
}