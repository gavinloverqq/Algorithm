#include <iostream>

using namespace std;

int n,a[25],dp[100100];

int main() {
    cin >> n;
    int maxN = 0,sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
        maxN = max(maxN,a[i]);
    }
    for (int j = 1; j <= n; ++j) {
        for (int i = sum-maxN; i >= a[j]; --i) {
            dp[i] = max(dp[i],dp[i-a[j]] + a[j]);
        }
    }
        cout << dp[sum - maxN] - (sum - dp[sum - maxN]) << endl;
    return 0;
}