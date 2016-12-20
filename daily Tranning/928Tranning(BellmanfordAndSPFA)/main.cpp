#include <iostream>
#include <set>
#define INF 1 << 30
using namespace std;
/**
 * 考虑点的给法不是正常的给出,而是一些离散的点
 * input:
6 8
1005 1020 5
1005 1015 7
1030 1040 10
1020 1030 8
1015 1030 3
1015 1040 1
1040 1050 9
1030 1050 4
 output: 0 7 5 10 8 14 
 */
int main() {
    int s[100],e[100],w[100],V,E;
    cin >> V >> E;
    set <int> st;
    for (int i = 1; i <= E; ++i) {
        cin >> s[i] >> e[i] >> w[i];
        st.insert(s[i]);
        st.insert(e[i]);
    }
    int book[2000],dist[2000];
    for (int j = 1; j <= 2000; ++j) {
        book[j] = 0;
        dist[j] = INF;
    }
    dist[1005] = 0;
    for (int k = 1; k < V; ++k) {
        for (int i = 1; i <= E; ++i) {
            if(dist[e[i]] > dist[s[i]] + w[i])
                dist[e[i]] = dist[s[i]] + w[i];
        }
    }
    int flag = 0;
    for (int m = 1; m <= E; ++m) {
        if(dist[e[m]] > dist[s[m]] + w[m])
            flag = 1;
    }
    if (flag){
        cout << "fuquanhuilu" << endl;
        return 0;
    }
    set <int>::iterator qst;
    for (qst = st.begin(); qst != st.end(); ++qst) {
//        cout << *qst <<endl;
        cout << dist[*qst] << " ";
    }
    return 0;
}