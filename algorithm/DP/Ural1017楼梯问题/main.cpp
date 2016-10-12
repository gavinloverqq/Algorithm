#include <iostream>
#define ll long long
using namespace std;
int n;
ll dp[550][550];//dp(i,j):i个砖块,最大高度为j;
int main() {
    cin >> n;
//    dp[0][0] = 1;
    //这个初始化比较难想到
    for (int m = 0; m <= n; ++m) {
        dp[m][m] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            for (int k = 1; k < j; ++k) {
                dp[i][j] += dp[i-j][k];
            }
        }
    }
    ll ans = 0;
    for (int l = 2; l < n; ++l) {//l<n体现了至少要有2层楼梯!
        ans += dp[n][l];
    }
    cout << ans << endl;
    return 0;
}