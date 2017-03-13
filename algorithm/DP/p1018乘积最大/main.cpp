#include <iostream>
#include <string>
using namespace std;
string num;
long long ans[50][10],arr[50][50];//i位数插j乘号
//需要重新写!!!!

/*long long cal(int i,int j){
    int index = i+j-1;
    long long ret = 0,exp = 1;
    while (j--){
        ret += (num[index--] - '0')* exp;
        exp *= 10;
    }
    return ret;
}*/

long long cal(int i,int j){
    long long ret = 0;
    for (; i <= j ; ++i) {
        ret = ret * 10 + (num[i] - '0');
    }
    return ret;
}
int main() {
    int n,k;
    cin >> n >> k >> num;

//    memset(ans,-1, sizeof(ans));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = cal(i,j);
        }
    }

    for (int m = 0; m < n; ++m) {
        ans[m][0] = arr[0][m];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 1;j <= k; ++j) {//为何写成j <= min(i-1,k)会出错?
            for (int l = 0; l < i; ++l) {
                if(ans[l][j-1] > 0)
                    ans[i][j] = max(ans[i][j],ans[l][j-1] * arr[l+1][i]);
            }
        }
    }
    cout << ans[n-1][k] << endl;
    return 0;
}