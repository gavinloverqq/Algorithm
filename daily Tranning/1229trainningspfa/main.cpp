#include <iostream>
#include <vector>
#include <queue>
using namespace std;


/*

//bellmanford 每次循环需要遍历所有边,因此Node需要加上s,d,v。而不只是d,v。
//为什么只要遍历n-1次?

struct Node{
    int s,d,v;
    Node (){}
    Node (int ss,int dd,int vv):s(ss),d(dd),v(vv){}
};
vector < Node > edge;
int dist[100];
const int INF = 1 << 30;

int main() {
    int n,m,s,d,v;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> s >> d >> v;
        edge.push_back(Node(s,d,v));//有向图
    }

    int book[100];
    for (int j = 1; j <= n; ++j) {
        dist[j] = INF;
        book[j] = 0;
    }

    dist[1] = 0;

    for (int k = 1; k <= n - 1; ++k) {
        for (int i = 0; i < edge.size(); ++i) {
            Node tmp = edge[i];
            if(dist[tmp.d] > dist[tmp.s] + tmp.v)
                dist[tmp.d] = dist[tmp.s] + tmp.v;
        }
    }

    for (int l = 1; l <= n; ++l) {
        cout << dist[l] << " " << endl;
    }
    cout << "Hello, World!" << endl;
    return 0;
}*/


struct Node{
    int d,v;
    Node(){}
    Node (int dd,int vv):d(dd),v(vv){}
//    bool operator < (Node a){
//        return a.v < this->v;
//    }
};
vector < Node > edge[100];
int dist[100],book[100];
const int INF = 1 << 30;

int main(){
    int n,m,s,d,v;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> s >> d >> v;
        edge[s].push_back(Node(d,v));
    }

    for (int j = 0; j <= n; ++j) {
        dist[j] = INF;
        book[j] = 0;
    }
    book[1] = 1;
    dist[1] = 0;

    //此处之前写错,写成优先队列。其实此处每次是把节点距离变动的节点编号放入队列就行了,用book标记在队列里的节点编号,如果当前节点变动了,且book = 0,则入队
    queue <Node> pq;//每次存入更新了距离的节点
    pq.push(Node(1,0));

    //for (int k = 1; k < n; ++k) {
        while (!pq.empty()) {
            Node tmp = pq.front();
            pq.pop();
            book[tmp.d] = 0;

            for (int i = 0; i < edge[tmp.d].size(); ++i) {
                if (dist[edge[tmp.d][i].d] > dist[tmp.d] + edge[tmp.d][i].v) {
                    dist[edge[tmp.d][i].d] = dist[tmp.d] + edge[tmp.d][i].v;
                if(book[edge[tmp.d][i].d] == 0)
                    pq.push(Node(edge[tmp.d][i].d, dist[edge[tmp.d][i].d]));
                    book[edge[tmp.d][i].d] = 1;
                }
            }
        }
    //}

    for (int k = 1; k <= n; ++k) {
        cout << dist[k] << " " << endl;
    }

}