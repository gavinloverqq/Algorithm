#include <iostream>

using namespace std;
int n,k;

int ans = 0;
void dfs(int lev,int a,int x){//分数lev,剩下的数a,当前枚举的数x
    if(lev == k+1 && a == 0){
        ans++;
        return;
    }
    if(lev > k || x > a)
        return;
    for (int i = x; i <= a; ++i) {
        dfs(lev + 1,a - i,i);
    }
}

void dp1(){
    int f[210][10][210];//f(i,j,k):数i划分为j份,最大为k的方案数;
    for (int i = 0; i < 210; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int l = 0; l < 210; ++l) {
                f[i][j][l] = 0;
            }
        }
    }
    f[0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            for (int l = 0; l <= i; ++l) {
                for (int m = 0; m <= l; ++m) {
                    f[i][j][l] = f[i][j][l] + f[i-l][j-1][m];
                }
            }
        }
    }
    for (int i = 1;  i <= n; ++ i) {
        ans += f[n][k][i];
    }
}


void dp2(){
    int f[210][10];//f(i,j) 为i划分为j份 f(i,j) = f(i-1,j-1) + f(i-j,j)//分两种,i划分为j份,最小的一份若为1,则把它拿掉为f(i-1,j-1);若最小的一份大于1,则每一份都拿掉1为f(i-j,j)
    for (int l = 0; l < 210; ++l) {
        for (int i = 0; i < 10; ++i) {
            f[l][i] = 0;
        }
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= min(i,k); ++j) {
            f[i][j] = f[i-1][j-1] + f[i-j][j];
        }
    }
    ans = f[n][k];
}


int main() {
    cin >> n >> k;
//    dfs(1,n,1);
//    dp1();
    dp2();
    cout << ans << endl;
    return 0;
}