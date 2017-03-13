#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
int n,v;
string name[110];
int arr[110][110],dp[110][110];
map <string,int> city;

int main() {

    cin >> n >> v;
    string sa,sb;
    for (int i = 1; i <= n; ++i) {
        cin >> sa;
        city[sa] = i;//hash
        name[i] = sa;
    }
    for (int j = 0; j < v; ++j) {
        cin >> sa >> sb;
        arr[city[sa]][city[sb]] = 1;
        arr[city[sb]][city[sa]] = 1;
    }
    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if(dp[i][j]){
//                for (int k = max(i,j) + 1; k <= n; ++k) {
//                    if (arr[i][k] == 1) {
//                        dp[k][j] = max(dp[k][j], dp[i][j] + 1);
//                    }
//                }
//                for (int k = max(i,j) + 1; k <= n; ++k) {
//                    if(arr[j][k] == 1){
//                        dp[i][k] = max(dp[i][k],dp[i][j] + 1);
//                    }
//                }
                for (int k = max(i,j) + 1; k <= n; ++k) {
                    if (arr[i][k] == 1) {
                        dp[k][j] = max(dp[k][j], dp[i][j] + 1);
                    }
                    if(arr[j][k] == 1){
                        dp[i][k] = max(dp[i][k],dp[i][j] + 1);
                    }
                }
            }
        }
    }
    int ans = -1;
    for (int l = 1; l <= n; ++l) {
        if(arr[l][n] == 1){
            ans = max(ans,dp[l][n]);
            ans = max(ans,dp[n][l]);
        }
    }
    if(ans <= 1){
        cout << 1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}
