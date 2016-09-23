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
    sort(N+1,N+G+1);//此处第一次写错,总是wa10号点
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

    //思路一:每个状态依赖前一个状态
    // dp[i][j] : 表示考虑到第k个垃圾时,寿命为i,高度为j的时候,牛的生存状态
    //dp[i][j + N[k].H] = true 此垃圾能用
    //dp[i+N[k].F][j] = true 吃垃圾能吃
/*
    bool dp[6000][400] = {false};
    for (int l = 0; l < 6000; ++l) {
        for (int i = 0; i < 400; ++i) {
            dp[l][i] = false;
        }
    }
    dp[10][0] = true;
    for (int j = 1; j <= G; ++j) {
        for (int i = 6000-10; i >= N[j].T; --i) {
            for (int k = 2*D; k >= 0; --k) {
                if(dp[i][k]){
                    dp[i][k+N[j].H] = true;
                    dp[i+N[j].F][k] = true;
                    if(k + N[j].H >= D) {
                        cout << N[j].T << endl;
                        return 0;
                    }
                }
            }
        }
    }
*/

    //思路二:后一个结果依赖前一个
    //dp[j] : 表示高度为j时的寿命
    //dp[j+N[i].H] = max(dp[j],dp[j+N[i].H]) 不吃这个垃圾
    //dp[j] = dp[j] + N[i].F;
/*    int dp[110];
    memset(dp,0, sizeof(dp));
    dp[0] = 10;
    for (int j = 1; j <= G; ++j) {
        for (int i = D; i >= 0; --i) {
            if(dp[i] < N[j].T) continue;
            if(i + N[j].H >= D){cout << N[j].T << endl;
                return 0;
            }
            dp[i + N[j].H] = max(dp[i],dp[i + N[j].H]);
//            dp[i + N[j].H] = dp[i];
            dp[i] += N[j].F;
        }
    }*/

    //思路三:未实现,按照背包问题处理
//    int dp[1000];
//    memset(dp,0, sizeof(dp));
//    dp[0] = 10;
//    for (int j = 1; j <= G; ++j) {
//        for (int i = 20*D; i >= N[j].H; --i) {
//            if(dp[i] < N[j].T) continue;
//            dp[i] = max(dp[i] + N[j].F,dp[i - N[j].H]);
//            if(dp[i] >= N[j].T && i >= D){cout << N[j].T << endl;
//                return 0;
//            }
//        }
//    }

//思路三:未实现,按照背包问题处理
//    for (int l = 0; l < 2500; ++l) {
//        dp[l] = -1000000000;
//    }
//    dp[0] = 10;int tmp;
//    for (int j = 1; j <= G; ++j) {
//        for (int i = 2500; i >= 0; --i) {
////            tmp = dp[i];
////            if(i >= N[j].H)
//                if(i >= N[j].H && dp[i - N[j].H] >= 0 && dp[i] >= 0)
//                    dp[i] = max(dp[i] + N[j].F,dp[i - N[j].H]);
//                else if(i >= N[j].H && dp[i - N[j].H] >= 0 && dp[i] < 0)
//                    dp[i] = dp[i - N[j].H];
//                else if(dp[i] >= 0)
//                    dp[i] = dp[i] + N[j].F;
//                else
//                    dp[i] = -1000000000;
//            if(dp[i] < N[j].T) {continue;}
//            if(i >= D){cout << N[j].T << endl;
//                return 0;
//            }
//        }
//    }
    cout << life << endl;
    return 0;
}