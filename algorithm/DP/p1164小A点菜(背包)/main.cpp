#include <iostream>
#define INF 1<<30
using namespace std;

int main() {
    int N,M;
    int a[110];
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }
    int dp[10010];
    for (int k = 1; k <= M; ++k) {
//        dp[k] = -INF;//第一次这里写错了,考虑背包九讲中的初始化方法,与此题有什么区别??
        dp[k] = 0;
    }
    dp[0] = 1;
    for (int j = 1; j <= N; ++j) {
        for (int i = M; i >= a[j]; --i) {
            dp[i] = dp[i] + dp[i - a[j]];
        }
    }
    cout << dp[M] << endl;
    return 0;
}