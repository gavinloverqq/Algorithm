#include <iostream>
#include <cstring>
using namespace std;
/**
 * n种花,总共摆成m盆,每种花有a[i]盆,问摆花的方案数目。
 */
int main() {
    int n,m;
    cin >> n >> m;
    int a[110];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int dp[110];
//    memset(dp,0, sizeof(0));//开始忘记了初始化,结果在本地测试没有问题,但是提交后,结果错误。以后遇到这种问题应该马上想到是没有初始化造成的
    for (int l = 1; l <= m; ++l) {
        dp[l] = 0;
    }
    dp[0] = 1;//第一次此处的初始化不对,第一次初始化为0了,实际上考虑第0个物品,摆0盆时
    for (int j = 1; j <= n; ++j) {
        for (int i = m; i >= 0; --i) {
            for (int k = 1; k <= a[j]; ++k) {
                if(i >= k)
                    dp[i] = (dp[i] + dp[i-k])%1000007;
            }
        }
    }

    //参考多重背包的思路,改写失败!
/*    int dp[1000];
    memset(dp,0, sizeof(dp));
    dp[0] = 1;
    int a;
    int c[1000],w[1000];
    int num = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        for (int j = 1; j <= a; j = j*2) {
            c[num] = j;
            w[num] = j;
            num++;
            a -= j;
        }
        if(a > 0){
            c[num] = a;
            w[num] = a;
            num++;
        }
    }
    for (int k = 1; k < num; ++k) {
        for (int i = m; i >= c[k]; --i) {
            dp[i] = dp[i] + dp[i-c[k]];
        }
    }*/
    cout << dp[m];
    return 0;
}