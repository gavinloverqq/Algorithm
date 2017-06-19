#include <iostream>

using namespace std;
int a[1005][1005], dp[1005];
int R;
int main() {
    cin >> R;
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> a[i][j];
        }
    }

    int sum = 0;

    for (int i = R; i > 0; --i) {
        for (int j = 1; j <= R; ++j) {
            dp[j] = max(dp[j], dp[j+1]) + a[i][j];
            sum = max(dp[j], sum);
        }
    }

    cout << sum << endl;
    return 0;
}