#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 1<<30
using namespace std;

//使用数组数据会爆,主要是用来锻炼一下多重背包的写法
/*
int dp[200000];
int p[50000],a[50000];
int main() {
    int N,M;
    cin >> N >> M;
    int num  = 1;
    int pp,aa;
    for (int i = 1; i <= M; ++i) {
        cin >> pp >> aa;
        for (int j = 1; j <= aa; j = j * 2) {
            p[num] = pp * j;
            a[num] = j;
            num++;
            aa -= j;
        }
        if(aa > 0){
            p[num] = pp * aa;
            a[num] = aa;
            num++;
        }
    }
    for (int k = 1; k < num; ++k) {
        for (int i = 200000; i >= p[k]; --i) {
            dp[i] = max(dp[i],dp[i - p[k]] + a[k]);
        }
    }
    for (int l = 0; l <= 200000; ++l) {
        if(N == dp[l]) {
            cout << l << endl;
            return 0;
        }
    }
    return 0;
}*/



//直接使用贪心
/*

struct Node{
    int p,a;
    Node(){}
    Node(int pp,int aa):p(pp),a(aa){}
};
bool operator < (Node a,Node b){
    return a.p < b.p;
}
Node cow[5010];
int main(){
    int N,M;
    cin >> N >> M;
    for (int i = 1; i <= M; ++i) {
        cin >> cow[i].p >> cow[i].a;
    }
    sort(cow+1,cow+M+1);
    int num = 0,cost = 0;
    for (int j = 1; j <= M; ++j) {
        if(N - num >= cow[j].a){
            cost += cow[j].p * cow[j].a;
            num +=cow[j].a;
        } else {
            cost += cow[j].p * (N - num);
            break;
        }
    }
    cout << cost << endl;
}*/

//本题数据规模不大,可以使用桶排序
//也是对贪心的一种启发,可以使用桶排序来解决一部分贪心问题
int main(){
    int N,M,ret;
    int ans[1050];
    memset(ans,0, sizeof(ans));
    cin >> N >> M;
    int p,a;
    for (int i = 0; i < M; ++i) {
        cin >> p >> a;
        ans[p] += a; 
    }
    for (int j = 0; j < 1050 && N > 0; ++j) {
        if (N < ans[j]) ans[j] = N;
        ret += ans[j] * j;
        N -= ans[j];
    }
    cout << ret <<endl;
}