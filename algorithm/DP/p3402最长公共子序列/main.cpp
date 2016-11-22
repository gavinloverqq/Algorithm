#include <iostream>
#include <string>
using namespace std;
int n,m;

int dp[5010][5010];
string a,b;
int main() {
//    cin >> n >> m;
//    for (int i = 1; i <= n; ++i) {
//        cin >> a[i];
//    }
//    for (int j = 1; j <= m; ++j) {
//        cin >> b[j];
//    }
    cin >> a >> b;
    int n = a.length()-1,m = b.length()-1;

    //二维dp初始化的两种方式:1、i == j 的形式:f(i,i) 2、固定一个考虑另一个的如f(0,j),f(j,0)
    int ans = 0;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= m; ++i) {
            if(a[k-1] == b[i-1]){
                dp[k][i] = dp[k-1][i-1] + 1;
            } else {
                dp[k][i] = max(dp[k-1][i],dp[k][i-1]);
            }
            ans = max(ans,dp[k][i]);
        }
    }
    int sum = 0;
    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= m; ++i) {
//            if(ans == dp[j][i])
//                sum++;
            cout << dp[j][i] << " ";
        }
        cout << endl;
    }
    cout << ans << endl << sum << endl;
    return 0;
}