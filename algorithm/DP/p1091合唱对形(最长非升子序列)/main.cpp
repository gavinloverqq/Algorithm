#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N,a[110],dp1[110],dp2[110];
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }
    for (int k = 0; k <= N; ++k) {
        dp1[k] = 1;
        dp2[k] = 1;
    }
    for (int j = 2; j <= N; ++j) {
        for (int i = j-1; i > 0; --i) {
            if(a[i] < a[j])
                dp1[j] = max(dp1[i] + 1,dp1[j]);
        }
    }
    dp2[N] = 1;
    for (int l = N-1; l > 0; --l) {
        for (int i = l + 1; i <= N; ++i) {
            if(a[l] > a[i])
                dp2[l] = max(dp2[l],dp2[i] + 1);
        }
    }
    int maxn = 1;
    for (int m = 1; m <= N; ++m) {
        maxn = max(maxn,dp1[m] + dp2[m]);
    }
    cout << N - maxn + 1 << endl;
    return 0;
}