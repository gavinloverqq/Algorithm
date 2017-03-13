#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/*
int s[100],d[100],v[100];
const int MAX = 1 << 30;
int n,m;
int main() {
    cin >> n >> m;
    int st,ed,vl;
    for (int i = 0; i < m; ++i) {
        cin >> s[i] >> d[i] >> v[i];
    }

    int dist[100];
    for (int k = 1; k <= n; ++k) {
        dist[k] = MAX;
    }
    dist[1] = 0;
    for (int j = 0; j < n - 1; ++j) {
        for (int i = 0; i < m; ++i) {
            //错在这里,值得思考
            if(dist[s[i]] > dist[d[i]] + v[i])
                dist[s[i]] = dist[d[i]] + v[i];
        }
    }
    for (int l = 1; l <= n; ++l) {
        cout << dist[l] << " ";
    }
    cout << "Hello, World!" << endl;
    return 0;
}*/

struct Node{
    int s,d,v;
    Node(){}
    Node(int ss,int dd,int vv):s(ss),d(dd),v(vv){}
};
Node G[100];

int main(){
    int n,m;
    int s,d,v;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {

        G[i]
    }
}