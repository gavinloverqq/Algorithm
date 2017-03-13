#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int trangel[110][110],dp[110][110];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> trangel[i][j];
            dp[i][j] = 0;
        }
    }

    for (int l = 0; l < n + 10; ++l) {
        dp[n+1][l] = 0;
    }
    for (int k = n; k >= 1; --k) {
        for (int i = 1; i <= k; ++i) {
            dp[k][i] = max(dp[k+1][i],dp[k+1][i + 1]) + trangel[k][i];
        }
    }
    cout << dp[1][1] << endl;
    return 0;
}