#include <iostream>

using namespace std;

/**
 * 描述:给n个数,分成两堆,求最小重量差
 * input:
5
5 8 13 27 14
output: 3
 */

int n,a[35],sum = 0,ans = 1 << 30;

void dfs(int dep,int now){
    if(dep == n){
        if(ans > abs(now - (sum - now)))
            ans = abs(now - (sum - now));
        return;
    }
    dfs(dep + 1,now + a[dep]);
    dfs(dep + 1,now);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    dfs(1,0);
    cout << ans << endl;
    return 0;
}