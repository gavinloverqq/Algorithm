#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int T,n;
int a[55],b[55],c[55];
int main() {
    cin >> T >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    int dp[100100];
    memset(dp,0, sizeof(dp));
    for (int j = 1; j <= n; ++j) {
        for (int i = T; i >= c[j]; --i) {
            for (int k = c[j]; k <= i; ++k) {//当前菜不同的完成时间,结果会不同
                dp[i] = max(dp[i],dp[i-c[j]]+a[j]-k*b[j]);
            }
        }
    }
    cout << dp[T] << endl;
    return 0;
}