#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node{
    int s,d,v;
    Node(){}
    Node(int ss,int dd,int vv):s(ss),d(dd),v(vv){}
};
bool operator < (Node a,Node b){
    return a.v > b.v;
}
vector < Node > Edge[100];

int par[5050];
void initPar(int n){
    for (int i = 0; i <= n; ++i) {
        par[i] = i;
    }
}
int getPar(int i){
    if(par[i] != i){
        par[i] = getPar(par[i]);
    }
    return par[i];
}
void mergePar(int a,int b){
    par[getPar(a)] = getPar(b);
}

int main() {
    int n,m,s,d,v;
    cin >> n >> m;
    priority_queue <Node> pq;
    for (int i = 0; i < m; ++i) {
        cin >> s >> d >> v;
        pq.push(Node(s,d,v));
    }
    initPar(n);
    Node tmp = pq.top();
    pq.pop();
    mergePar(tmp.s,tmp.d);
    int mstNode = tmp.s,sum = tmp.v;
    while (!pq.empty()) {
        tmp = pq.top();
        pq.pop();

        if(getPar(tmp.s) != getPar(tmp.d)){
            mergePar(tmp.d,tmp.s);
//            mergePar(mstNode,tmp.d);//傻逼错误啊!!!
            sum += tmp.v;
        }
    }

    cout << sum << endl;
    return 0;
}