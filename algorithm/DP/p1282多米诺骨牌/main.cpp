#include <iostream>
#include <cstring>
using namespace std;


//用搜索实现失败
/*void dfs(int m){
    if (m == n){
        cout << ((num > n/2) ? (n - num) : num) << endl;
        return;
    } else {
        sum - a[m]
    }
}*/

int main() {
    int n;
    int sum = 0,num;
    int a[1100],b[1100],dp[6000],trace[6000];
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        sum += a[i] + b[i];
    }
    num = (sum + 1)/2;//向上取整
    memset(dp,0, sizeof(dp));
//    for (int j = 1; j <= n; ++j) {
//        for (int i = num; i >= 0; --i) {
//            if(i >= a[j] && i >= b[j]){
//                dp[i] = max(dp[i - a[j]],dp[i-b[j]]+1);
//            }
//            else if(i >= a[j]){
//                dp[i] = dp[i - a[j]];
//            }
//            else if(i >= b[j]){
//                dp[i] = dp[i - b[j]] + 1;
//            }
//        }
//    }
    for (int j = 1; j <= n; ++j) {
        for (int i = sum; i >= 0; --i) {
            dp[i + a[j]] = dp[j];
            dp[i + b[j]] = dp[j]+1;
        }
    }

    cout << (dp[num]>n/2 ? (n-dp[num]) : dp[num]) << endl;
    return 0;
}