#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1<<30
using namespace std;
/*
int N,M;
struct Node{
    int x,y,z;
    Node (int xx,int yy,int zz):x(xx),y(yy),z(zz){}
    Node (){}
};
bool operator < (Node a,Node b){
    return a.z < b.z;
}
Node G[200010];

int par[5050];

int getPar(int a){
    if(par[a] != a){
        par[a] = getPar(par[a]);
    }
    return par[a];
}
void merge(int a,int b){
    par[getPar(a)] = getPar(b);
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> G[i].x >> G[i].y >> G[i].z;
    }
    sort(G,G+M);
//    cout << G[0].x << G[0].y << G[0].z;
    for (int j = 1; j <= N; ++j) {
        par[j] = j;
    }
    int sum = 0;
    for (int k = 0; k < M; ++k) {
        if(getPar(G[k].x) != getPar(G[k].y)){
            merge(G[k].x,G[k].y);
            sum += G[k].z;
        }
    }
    int flag = 0;
    for (int l = 1; l <= N; ++l) {
        if(getPar(l) != getPar(1))
            flag = 1;
    }
    if(flag) {
        cout << "orz" << endl;
        return 0;
    }
    cout << sum << endl;
    return 0;
}*/

int N,M;

struct Node{
    int d,w;
    Node (){}
    Node (int dd,int ww):d(dd),w(ww){}
};
bool operator < (Node a,Node b){
    return a.w > b.w;
}
vector < vector<Node> > G;
int main(){
    cin >> N >> M;
    G.clear();
    G.resize(N+10);
    int s,d,w;
    for (int i = 0; i < M; ++i) {
        cin >> s >> d >> w;
        G[s].push_back(Node(d,w));
        G[d].push_back(Node(s,w));
    }
    int dist[5050],book[5050];
    for (int j = 0; j <= N; ++j) {
        dist[j] = INF;
        book[j] = 0;
    }
    dist[1] = 0;
    int sum = 0;
    priority_queue <Node> pq;
    pq.push(Node(1,dist[1]));
    while (!pq.empty()){
        Node temp = pq.top();
        pq.pop();
        if(book[temp.d] == 1)
            continue;
        book[temp.d] = 1;
        sum += temp.w;
        for (int i = 0; i < G[temp.d].size(); ++i) {
            if(dist[G[temp.d][i].d] > G[temp.d][i].w){
                dist[G[temp.d][i].d] = G[temp.d][i].w;
                if(book[G[temp.d][i].d] == 0)
                    pq.push(G[temp.d][i]);//堆优化优化的什么?哪些参数入队列?
            }
        }
    }
    for (int k = 1; k <= N; ++k) {
        if(dist[k] == INF){
            cout << "orz" << endl;
            return 0;
        }
    }
    cout << sum << endl;
}
