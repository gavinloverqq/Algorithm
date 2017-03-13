#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10000000;
struct Node{
    int d,v;
    Node(){}
    Node(int dd,int vv):d(dd),v(vv){}
};
//Node G[100];
vector < Node > G[100];

struct dNode{
    int key,value;
    dNode(){}
    dNode(int kk,int vv):key(kk),value(vv){}
};
dNode dist[100];

int n;//dist的大小
void siftup(int i){
    while (i / 2 >= 1 && dist[i].value < dist[i/2].value){
        dNode tmp = dist[i];
        dist[i] = dist[i/2];
        dist[i/2] = tmp;
        i = i/2;
    }
}
void siftdown(int i){
    int index = i;
    dNode tmp;
    while (1){
        if(i * 2 <= n && dist[index].value > dist[i*2].value){
            index = 2 * i;
        }
        if(i * 2 + 1 <= n && dist[index].value > dist[2*i+1].value){
            index = 2 * i + 1;
        }
        if(index == i)
            break;
        tmp = dist[i];
        dist[i] = dist[index];
        dist[index] = tmp;
        i = index;
    }
}
void swapNode(dNode &a,dNode &b){//第一次错,错在没使用 & 引用
    dNode t = a;
    a = b;
    b = t;
}

void pri(){
    for (int i = 1; i <= n; ++i) {
        cout << dist[i].key << " " << dist[i].value << " | ";
    }
    cout << endl;
}
int main() {
    int v,e;
    cin >> v >> e;
    int s,ed,w;
    for (int i = 0; i < e; ++i) {
        cin >> s >> ed >> w;
        G[s].push_back(Node(ed,w));
    }
    n = v;
    int dt[100];
    for (int j = 1; j <= v; ++j) {
        dist[j] = dNode(j,MAX);
        dt[j] = MAX;
    }
    for (int k = 0; k < G[1].size(); ++k) {
        dist[G[1][k].d] = dNode(G[1][k].d,G[1][k].v);
        dt[G[1][k].d] = G[1][k].v;
    }
    dt[1] = 0;
    for (int m = n/2; m >= 1; --m) {
        siftdown(m);
    }
    int book[100];
    book[1] = 1;
    for (int l = 0; l < v; ++l) {
        int indexMin = -1;
        while (n >= 1){
            pri();
            if(book[dist[1].key] == 1){
                swapNode(dist[1],dist[n]);
                n--;//第一次错,错在放到了siftdown后面,如果放后面,经过siftdown,堆顶不会变化。
                siftdown(1);
            } else {
                indexMin = dist[1].key;
                break;
            }
        }
        if(indexMin == -1)
            break;
        book[indexMin] = 1;

        for (int i = 0; i < G[indexMin].size(); ++i) {
            if(dt[G[indexMin][i].d] > dt[indexMin] + G[indexMin][i].v){
                dt[G[indexMin][i].d] = dt[indexMin] + G[indexMin][i].v;
                n++;
                dist[n] = dNode(G[indexMin][i].d,dt[G[indexMin][i].d]);
                siftup(n);
            }
        }
        pri();
    }
    for (int i = 1; i <= v; ++i) {
        cout << dt[i] << " ";
    }
    cout << "Hello, World!" << endl;
    return 0;
}