#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

struct Node{
    int T,F,H;
    Node(){}
    Node(int t,int f,int h):T(t),F(f),H(h){}

    friend bool operator < (Node a,Node b){
        return a.T < b.T;
    }
};


int main() {
    int D,G;//D 井深度,G垃圾数量
    Node N[110];
    cin >> D >> G;
    int T,F,H;
    for (int i = 1; i <= G; ++i) {
        cin >> T >> F >> H;
        N[i] = Node(T,F,H);
    }
    sort(N+1,N+G);
//    for (int k = 1; k <= G; ++k) {
//        cout << N[k].T <<" "<<N[k].F<<" "<<N[k].H<<endl;
//    }
    int num = 1;int life = 10;
    for (int k = 1; k <= G; ++k) {
        if(N[k].T <= life){
            life += N[k].F;
            num = k;//饿死
        } else {
            break;
        }
    }
//    cout << num;
    int dp[110];int dpLife = 10;
    memset(dp,0, sizeof(dp));
    int i;
    dp[0] = 10;
//    for (int j = 1; j <= num; ++j) {
//        for (i = dpLife; i >= N[j].T; --i) {
//            if(dp[i - N[j].T] > dp[i] + N[j].H){
//                dp[i] = dp[i - N[j].T];
//                dpLife += N[j].F;
//            } else {
//                dp[i] = dp[i] + N[j].H;
//            }
//        }
//        if(dp[i] >= D) {cout << i << endl;
//            return 0;
//        }
//    }
    for (int j = 1; j <= G; ++j) {
        for (i = D; i >= 0; --i) {
            if(dp[i] < N[j].T) continue;
            if(i + N[j].H >= D){cout << N[j].T << endl;
                return 0;
            }
            dp[i + N[j].H] = max(dp[i + N[j].H] ,dp[i]);
            dp[i] += N[j].F;
        }
    }
    cout << life << endl;
    return 0;
}