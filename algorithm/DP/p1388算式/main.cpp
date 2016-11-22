#include <iostream>
#include <algorithm>
using namespace std;
int num[20];
int sum(int i,int j){
    int ans = 0;
    for (int k = i; k <= j; ++k) {
        ans += num[k];
    }
    return ans;
}
int main() {
    int N,K;
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        cin >> num[i];
    }
    int dp[30][30];
    int maxn = 0;
    for (int l = 1; l <= N; ++l) {
        dp[l][0] = sum(1,l);
    }
    for (int j = 2; j <= N; ++j) {//前j个数字
        for (int i = 1; i <= j-1; ++i) {//一共有i个乘号
            maxn = 0;//
            for (int k = i; k <= j-1; ++k) {
                maxn = max(maxn,dp[k][i - 1] * sum(k+1,j));
            }
            dp[j][i] = maxn;
        }
    }
    cout << dp[N][K] << endl;
    return 0;
}