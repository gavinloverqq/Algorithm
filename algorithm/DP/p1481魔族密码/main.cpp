#include <iostream>
#include <string>
using namespace std;

string words[2020];
int dp[2020];
bool check(int i,int j){
    int len1 = words[i].length();
    int len2 = words[j].length();
//    if(len2 < len1)
//        return false;
    int len = min(len1,len2);
    for (int k = 0; k < len; ++k) {
        if(words[i][k] != words[j][k]) {
            return false;
        }
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> words[i];
    }
    //第一次少写了这句,导致wa,没写这句在第 i 个句子接不上前面任何一个句子时就错了
    for (int k = 1; k <= n; ++k) {
        dp[k] = 1;
    }
    int passwd = 1;
    for (int j = 2; j <= n; ++j) {
        for (int i = j - 1; i >= 1; --i) {
            if(check(i,j)){//要考虑全都接不上的情况,都接不上要令dp[j] = 1;
                dp[j] = max(dp[j],dp[i] + 1);
                passwd = max(passwd,dp[j]);
            }
        }
    }
    cout << passwd << endl;
    return 0;
}