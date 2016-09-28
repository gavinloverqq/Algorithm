#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;


/**
 * 本题是个好题,每个物品烹调的时候不同的顺序会有不同的价值,调换前后两个物品得到的价值可能会变化,因此直接用背包来解是不能得出问题的解的,
 * 因为普通的背包无法表示前后两个物品交换的情况,而且普通的背包物品顺序是不影响价值的,调换与否不影响结果,或者物品根本无法调换顺序
 * 因此此题需要预处理,先将物品按最可能获得最优的情况排好序,排好序后即可用01背包的实现,即每个物品只有取或者不取两种状态
 */

int T,n;
int a[55],b[55],c[55];
ll dp[1001000];
struct Node {
    int a,b,c;
    Node(){}
    Node(int aa,int bb,int cc):a(aa),b(bb),c(cc){}
};
Node nNode[55];
bool operator < (Node x,Node y){
    return (ll)x.c * y.b < (ll)y.c * x.b;
}
int main() {
    cin >> T >> n;
    for (int l = 1; l <= n; ++l) {
        cin >> nNode[l].a;
    }
    for (int m = 1; m <= n; ++m) {
        cin >> nNode[m].b;
    }
    for (int q = 1; q <= n; ++q) {
        cin >> nNode[q].c;
    }
    sort(nNode+1,nNode+1+n);

    memset(dp,0, sizeof(dp));
    for (int j = 1; j <= n; ++j) {
        for (int i = T; i >= 0; --i) {
            if(i + nNode[j].c <= T){
                dp[i + nNode[j].c] = max(dp[i] + (ll)nNode[j].a - (ll)(i + nNode[j].c) * (ll)nNode[j].b,dp[i + nNode[j].c]);
            }
        }
    }
    ll maxn = 0;
    for (int k = 0; k <= T; ++k) {
        maxn = max(maxn,dp[k]);
    }
    cout << maxn << endl;

//    memset(dp,0, sizeof(dp));
//    dp[0] = 0;
//    for (int j = 1; j <= n; ++j) {
//        for (int i = T; i >= nNode[j].c; --i) {
//            dp[i] = max(dp[i],dp[i - nNode[j].c] + (ll)nNode[j].a - (ll)(i) * (ll)nNode[j].b);
//        }
//    }
//    ll maxn = 0;
//    for (int k = 0; k <= T; ++k) {
//        maxn = max(maxn,dp[k]);
//    }
//    cout << maxn << endl;
    return 0;
}