#include <iostream>
#include <vector>
#include <queue>
#define INF 1 << 30
using namespace std;

//并查集
/*
int par[20];
int getPar(int a){
    if (par[a] != a){
        par[a] = getPar(par[a]);
    }
    return par[a];
}
void merge(int a,int b){
    par[getPar(a)] = getPar(b);
}

struct Node{
    int s,d,w;
    Node(){}
    Node(int ss,int dd,int ww):s(ss),d(dd),w(ww){}
};
bool operator < (Node a,Node b){
    return a.w < b.w;
}

int main(){
    int v,e;
    cin >> v >> e;
    for (int i = 0; i <= v; ++i) {
        par[i] = i;
    }
    vector < Node > G;
    int s,d,w;
    for (int j = 1; j <= e; ++j) {
        cin >> s >> d >> w;
        G.push_back(Node(s,d,w));
    }
    sort(G.begin(),G.begin()+e);
//    for (int k = 0; k < e; ++k) {
//        cout << G[k].s << " " << G[k].d << " " << G[k].w <<" "<< endl;
//    }
    int sum = 0;
    for (int k = 0; k < G.size(); ++k) {
        if(getPar(G[k].s) != getPar(G[k].d)){
            merge(G[k].s,G[k].d);
            sum += G[k].w;
        }
    }
    cout << sum << endl;
}*/

struct Node{
    int d,w;
    Node(){}
    Node(int dd,int ww):d(dd),w(ww){}
};
bool operator < (Node a,Node b){
    return a.w > b.w;
}

int main(){
    int v,e;
    cin >> v >> e;
    vector < Node > G[100];
    int s,d,w;
    for (int j = 1; j <= e; ++j) {
        cin >> s >> d >> w;
        G[s].push_back(Node(d,w));
        G[d].push_back(Node(s,w));//注意此处必须要加上这句否则是有向图,最小生成树是无向图???!!!
    }
    int sum = 0,dist[100],book[100];
    priority_queue <Node> pq;
    for (int k = 0; k <= v; ++k) {
        dist[k] = INF;
        book[k] = 0;
    }
    dist[1] = 0;
    pq.push(Node(1,dist[1]));
    while (!pq.empty()){
        Node temp = pq.top();
        pq.pop();
        if(book[temp.d] == 1)
            continue;
        book[temp.d] = 1;
        sum += temp.w;
        for (int i = 0; i < G[temp.d].size(); ++i) {
            if(dist[G[temp.d][i].d] > G[temp.d][i].w) {
//                if(book[G[temp.d][i].d] == 0 && dist[G[temp.d][i].d] > G[temp.d][i].w) {
                dist[G[temp.d][i].d] = G[temp.d][i].w;
            if (book[G[temp.d][i].d] == 0)
                pq.push(G[temp.d][i]);
            }
        }
    }
    cout << sum << endl;
}
