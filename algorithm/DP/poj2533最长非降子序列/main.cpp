#include <iostream>
#include <cstdio>

using namespace std;

int N,a[10010],dp[10010];


void DP1(){
    //第一次解法
    /*for (int j = 2; j <= N; ++j) {
        int ans = 1;//初始化的时候注意不要初始化为0!!!//此处的变量要考虑未经循环时的情况//更极端的:不要使用这种变量
        for (int i = 1; i < j; ++i) {
            if(a[j] > a[i]){
                ans = max(ans,dp[i]+1);
            }
        }
        dp[j] = ans;
    }
    int ret = 0;
    for (int k = 1; k <= N; ++k) {
        ret = max(ret,dp[k]);
    }
    cout << ret << endl;*/

    //第二次解法:简洁一点的编码
    int ret = 1;
    for (int j = 2; j <= N; ++j) {
        for (int i = 1; i < j; ++i) {
            if(a[j] > a[i]){
                dp[j] = max(dp[j],dp[i]+1);
            }
        }
        ret = max(ret,dp[j]);
    }
    cout << ret << endl;
}

int S[10010]; // S[i] = t 表示考虑前1到x个数中最大长度为i的子序列,结尾字符下标为t;
int Bsearch(int i,int l,int r){
    while(l <= r){
        int mid = (l+r)/2;
        if(a[i] > S[mid])
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

void DP4(){
    S[1] = a[1];
    int maxIndex = 1;
    for (int i = 2; i <= N; ++i) {
        if(a[i] > S[maxIndex]){
            S[++maxIndex] = a[i];
        } else {
            int tmpIndex = Bsearch(i,1,maxIndex);
            S[tmpIndex] = a[i];
        }
    }
    cout << maxIndex << endl;

}

int main() {
    //初始化
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
        dp[i] = 1;
    }
    DP4();
    return 0;
}





#include <iostream>
#include <cstdio>

using namespace std;

int N,a[10010],dp[10010];


void DP1(){
    //第一次解法
    /*for (int j = 2; j <= N; ++j) {
        int ans = 1;//初始化的时候注意不要初始化为0!!!//此处的变量要考虑未经循环时的情况//更极端的:不要使用这种变量
        for (int i = 1; i < j; ++i) {
            if(a[j] > a[i]){
                ans = max(ans,dp[i]+1);
            }
        }
        dp[j] = ans;
    }
    int ret = 0;
    for (int k = 1; k <= N; ++k) {
        ret = max(ret,dp[k]);
    }
    cout << ret << endl;*/

    //第二次解法:简洁一点的编码
    int ret = 1;
    for (int j = 2; j <= N; ++j) {
        for (int i = 1; i < j; ++i) {
            if(a[j] > a[i]){
                dp[j] = max(dp[j],dp[i]+1);
            }
        }
        ret = max(ret,dp[j]);
    }
    cout << ret << endl;
}

int S[10010]; // S[i] = t 表示考虑前1到x个数中最大长度为i的子序列,结尾字符下标为t;
int Bsearch(int i,int l,int r){
    while(l <= r){
        int mid = (l+r)/2;
        if(a[i] > S[mid])
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

void DP4(){
    S[1] = a[1];
    int maxIndex = 1;
    for (int i = 2; i <= N; ++i) {
        if(a[i] > S[maxIndex]){
            S[++maxIndex] = a[i];
        } else {
            int tmpIndex = Bsearch(i,1,maxIndex);
            S[tmpIndex] = a[i];
        }
    }
    cout << maxIndex << endl;

}


void DP2(){
    S[1] = 1;
    int maxIndex = 1;
    for (int i = 2; i <= N; ++i) {
        if(a[i] > a[S[maxIndex]]){
            maxIndex++;
            S[maxIndex] = i;
        } else {

            int flag = 1;
//                for (int j = 1; j <= maxIndex; ++j) {//第一次这里写错!应该逆序判断!!!
            for (int j = maxIndex; j >= 1; --j) {
                if (a[i] > a[S[j]]){
                    dp[i] = j+1;
                    S[j+1] = i;
                    flag = 0;
                    break;//然后此处写错,找到后要及时break否则后面的值会跟着修改
                }
            }
            if(flag) {
                dp[i] = 1;
                S[1] = i;
            }
        }
    }
    cout << maxIndex << endl;
}

void DP3(){
    S[1] = 1;
    int maxIndex = 1;
    for (int i = 2; i <= N; ++i) {
        if(a[i] > a[S[maxIndex]]){
            S[++maxIndex] = i;
        } else {
            S[Bsearch(i,1,maxIndex)] = i;
        }
    }
    cout << maxIndex << endl;
}

int main() {


    //初始化
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
        dp[i] = 1;

    }
    DP4();
    return 0;
}