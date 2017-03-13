#include <iostream>
#include <string>

using namespace std;

struct Node{
    int a,d,key;
    Node(){}
    Node(int add,int del){
        a = add,d = del;
        key = min(a,d);
    }
};
Node alphabet[2010];
int dp[2010][2010];

int main() {
    int n,m;
    string str;
    cin >> n >> m >> str;
    char ch;
    int add,del;
    for (int i = 0; i < n; ++i) {
        cin >> ch >> add >> del;
        alphabet[ch - '0'] = Node(add,del);
    }


/*  想一下这种做法错在哪里!!!以及对照题解做出正解
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            if(str[j] == str[i]){
                if(j - 2 >= i){
                    dp[i][j] = dp[i+1][j-1];//边界
                }
            } else{
                dp[i][j] = min(
                        dp[i+1][j] + min(alphabet[str[i] - '0'].a,alphabet[str[i] - '0'].d),
                        dp[i][j-1] + min(alphabet[str[j] - '0'].a,alphabet[str[j] - '0'].d)
//                dp[i+1][j] + alphabet[str[i] - '0'].key,
//                dp[i][j-1] + alphabet[str[j] - '0'].key
                );
            }
        }
    }*/

    //正解,我的常用解法
/*    for (int i = m-1; i >= 0; --i) {
        for (int j = i + 1; j < m; ++j) {
            if(str[j] == str[i]){
//                if(j - 2 >= i){
//                    dp[i][j] = dp[i+1][j-1];//边界
//                }
                dp[i][j] = dp[i+1][j-1];//边界
            } else{
                dp[i][j] = min(
                        dp[i+1][j] + min(alphabet[str[i] - '0'].a,alphabet[str[i] - '0'].d),
                        dp[i][j-1] + min(alphabet[str[j] - '0'].a,alphabet[str[j] - '0'].d)
//                dp[i+1][j] + alphabet[str[i] - '0'].key,
//                dp[i][j-1] + alphabet[str[j] - '0'].key
                );
            }
        }
    }*/

/*    for (int l = 1; l < m; ++l) {
        for (int i = 0; i < m; ++i) {
            int j = i + l;
            if(j < m){
                if(str[i] == str[j])
                    dp[i][j] = dp[i+1][j-1];
                else{
                    dp[i][j] = min(
                            dp[i+1][j] + min(alphabet[str[i] - '0'].a,alphabet[str[i] - '0'].d),
                            dp[i][j-1] + min(alphabet[str[j] - '0'].a,alphabet[str[j] - '0'].d)
                    );
                }
            }
        }
    }*/
    for (int l = 1; l < m; ++l) {
        for (int i = 0; i + l< m; ++i) {
            int j = i + l;
            if(str[i] == str[j])
                dp[i][j] = dp[i+1][j-1];
            else {
                dp[i][j] = min(
                        dp[i + 1][j] + min(alphabet[str[i] - '0'].a, alphabet[str[i] - '0'].d),
                        dp[i][j - 1] + min(alphabet[str[j] - '0'].a, alphabet[str[j] - '0'].d)
                );
            }
        }
    }

    cout << dp[0][m-1] << endl;
    return 0;
}

/*
 2 6
iiiici
c 9 853
i 771 344

 9
 */