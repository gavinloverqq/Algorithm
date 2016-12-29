#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    int d,v;
    Node(){}
    Node(int dd,int vv):d(dd),v(vv){}
};
bool operator < (Node a,Node b){
    return a.v > b.v;
}
const int INF = 1 << 30;
vector <Node> Edge[5050];


int main() {
    int n,m;
    cin >> n >> m;
    int s,d,v;
    for (int i = 0; i < m; ++i) {
        cin >> s >> d >> v;
        Edge[s].push_back(Node(d,v));
        Edge[d].push_back(Node(s,v));
    }
    int dist[5050],book[5050],sum = 0;
    for (int j = 1; j <= n; ++j) {
        dist[j] = INF;
        book[j] = 0;
    }
    dist[1] = 0;
    priority_queue <Node> pq;
    pq.push(Node(1,dist[1]));

    for (int k = 0; k < n; ++k) {
        Node tmp;
        while (!pq.empty()) {
            tmp = pq.top();
            pq.pop();
            if(book[tmp.d] == 0)
                break;
        }
        book[tmp.d] = 1;
        sum += tmp.v;

        for (int i = 0; i < Edge[tmp.d].size(); ++i) {
            if(book[Edge[tmp.d][i].d] == 0 && dist[Edge[tmp.d][i].d] > Edge[tmp.d][i].v){
                dist[Edge[tmp.d][i].d] = Edge[tmp.d][i].v;
                pq.push(Node(Edge[tmp.d][i].d,Edge[tmp.d][i].v));
            }
        }
    }

    cout << sum << endl;
    return 0;
}