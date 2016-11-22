#include <iostream>

using namespace std;

int N,M;
int a[110],dp[10010],ans = 0;
int book[110];

//搜索失败
void dfs(int n){
    if(n == M){
        ans++;
        return;
    }
    for (int i = 1; i <= N; ++i) {
        if(book[i] == 0){
            book[i] = 1;
            dfs(a[i] + n);
            book[i] = 0;

        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }
    dfs(0);
    cout << ans << endl;
//    dp[0] = 1;
//    for (int j = 1; j <= N; ++j) {
//        for (int i = M; i >= 0; --i) {
//            dp[i] += dp[i - a[j]];//递推方程:dp[i] = dp[i] + dp[i-a[j]],前j个数凑到i这个数字,要么不要a[j],方案数:用前j-1个数抽成dp[i],要么前j-1个数凑成dp[i-a[j]]
//        }
//    }
//    cout << dp[M] << endl;
    return 0;
}