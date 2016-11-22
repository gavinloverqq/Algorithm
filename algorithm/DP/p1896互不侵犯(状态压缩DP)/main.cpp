#include <iostream>
#define ll long long
using namespace std;
const int MAXN = 550;//???????
int N,K;
int num[MAXN],s[MAXN];
int states = 0;
/**
 * 每一行有多少种可能的好状态使用2进制表示,例如N = 4时s[]表示同一行的状态s[]={0000,0001,0010,0100,1000,1001,1010,0101}
 * num[]存储对应状态的猛兽数目num[] = {0,1,1,1,1,2,2,2}
 *
 *
 */



//生成num以及s数组
void initState(){
    states = 0;
    for (int i = 0; i < (1 << N); ++i) {//共有2的N次方减1种可能的状态
        if(i & (i << 1))//判断状态是否合法。将原数右移一位做&运算为1表示冲突
            continue;
        int t = i;
        num[states] = 0;
        for (int j = t; j > 0; j = j>>1) {//统计1的个数
            num[states] += (t&1);
        }
        s[states++] = i;//保存这个状态
    }
}

ll f[15][110][MAXN];//f[i][j][k]第i行状态为k时,共放了j个猛兽
void dp(){
    ll ans = 0;
    int c,cc,mm,a,b;
    memset(f,0, sizeof(f));
    //初始化
    for (int i = 0; i < states; ++i) {
        int j = num[i];
        if(j <= K)
            f[1][j][i]++;
    }

    for (int i = 2; i < N; ++i) {
        for (int j = 0; j <= K; ++j) {
            for (int k = 0; k < states; ++k) {
                c = num[k];//当前状态放了多少个猛兽
                if(c > j)
                    continue;
                mm = j - c;//前 i-1 行放了mm个猛兽;
                for (int l = 0; l < states; ++l) {
                    cc = num[l];
                    if (cc > mm)
                        continue;
                    if(s[k] & s[l])
                        continue;
                    if(s[k] & (s[l] << 1))
                        continue;
                    if((s[k] << 1) & s[l])
                        continue;
                    f[i][j][k] += f[i-1][mm][l];
                }
            }
        }
    }

    ans = 0;
    int j;
    for (int m = 0; m < states; ++m) {
        c = num[m];
        if(c > K)
            continue;
        j = K - num[m];
        for (int i = 0; i < states; ++i) {
            if (num[i] > j)
                continue;
            if(s[m] & s[i])
                continue;
            if(s[m] & (s[i] << 1))
                continue;
            if((s[m] << 1) & s[i])
                continue;
            f[N][K][m] += f[N-1][j][i];
        }
        ans += f[N][K][m];
    }
//    printf("%lld",ans);
    cout << ans;

}

int main() {
    cin >> N >> K;
    initState();
//    cout << states ;
    dp();
    return 0;
}




