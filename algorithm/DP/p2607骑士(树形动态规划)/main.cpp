#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct Node{
    int person,value;
    Node(int pp,int vv):person(pp),value(vv){}
    Node(){}
};
vector < vector<Node> > G;

int f[1000100][2];
int visited[1000100];
void dfsDp(int n){
    if(!visited[n]){
        visited[n] = 1;
        for (int i = 0; i < G[n].size(); ++i) {
            if(!visited[G[n][i].person]){
                dfsDp(G[n][i].person);
                f[n][0] += max(f[G[n][i].person][0],f[G[n][i].person][1] + G[n][i].value);
                f[n][1] += f[G[n][i].person][0];
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    G.clear();
    G.resize(N+10);
    int p,v;
    for (int i = 1; i <= N; ++i) {
        cin >> v >> p;
        G[i].push_back(Node(p,v));
//        f[p][1] = v;
    }
    int ret = -1;
    for (int j = 1; j <= N; ++j) {
        memset(visited,0, sizeof(visited));
        for (int k = 0; k <= N; ++k) {
            f[k][1] = 0;
            f[k][0] = 0;
        }
        f[j][1] = G[j][0].value;
        dfsDp(j);
        for (int i = 1; i <= N; ++i) {
            cout << f[i][0] << " " << f[i][1] << endl;
        }
        cout << endl;
        ret = max(ret,max(f[j][1],f[j][0]));
    }
//    dfsDp(1);
    cout << ret << endl;
    return 0;
}