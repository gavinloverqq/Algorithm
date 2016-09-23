#include <iostream>
#include <vector>
#include <queue>
#define INF 1<<30
using namespace std;

struct Node{
    int d,w;
    Node(){}
    Node (int dd,int ww):d(dd),w(ww){}
};
bool operator < (Node a,Node b){
    return a.w > b.w;
}
int main() {
    int v,e;
    cin >> v >> e;
    vector < vector<Node> > vNode;
    vNode.clear();
    vNode.resize(v+10);
    for (int i = 0; i < e; ++i) {
        int s,d,w;
        cin >> s >> d >> w;
        vNode[s].push_back(Node(d,w));
    }
    int dist[100],book[100];
    for (int j = 1; j <= v; ++j) {
        dist[j] = INF;
        book[j] = 0;
    }
    dist[1] = 0;
    priority_queue <Node> pq;//放入节点编号以及对应的距离初始节点的距离
    pq.push(Node(1,0));
    while (!pq.empty()){
        Node nTmp;int iTmp;
        nTmp = pq.top();
        pq.pop();
        iTmp = nTmp.d;
//        if(0 == book[iTmp]) book[iTmp] = 1;//此种写法有错误,应该为下面的写法
        if(1 == book[iTmp]) continue; book[iTmp] = 1;
        for (int i = 0; i < vNode[iTmp].size(); ++i) {
            if(0 == book[vNode[iTmp][i].d] && dist[vNode[iTmp][i].d] > dist[iTmp] + vNode[iTmp][i].w){
                dist[vNode[iTmp][i].d] = dist[iTmp] + vNode[iTmp][i].w;
                pq.push(Node(vNode[iTmp][i].d,dist[vNode[iTmp][i].d]));
            }
        }
    }
    for (int k = 1; k <= v; ++k) {
        cout << dist[k] << " ";
    }
    cout << endl;
    return 0;
}