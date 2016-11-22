#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#define ll long long
using namespace std;
const int MAXN = 2000;
const int MAXK = 1100;

ll f[2][MAXN][MAXK],Ans;
int N,K;
int s[MAXN],num[MAXN];
int Next[MAXN*10],h[MAXN*10],st[MAXN],flag;

inline int getNum(int x){
    int t = 0;
    while (x>0){
        x = x&(x-1);//每执行一次将最右边的1置为0
        t++;
    }
    return t;
}
void DFS(int len,int now){
    if (len == N){
        ++s[0];
        s[s[0]] = now;
        num[s[0]] = getNum(now);
        return;
    }
    DFS(len+1,now << 1);//不放猛兽,最右位放置0
    if((now & 1) != 1){//当前最右为为0时可放置猛兽
        DFS(len+1,(now << 1)|1);//右移一位并把最后一位变成1
    }
}
void add(int one,int two){
    Next[++flag] = st[one];
    h[flag] = two;
    st[one] = flag;
}
void init(){
    cin >> N >> K;
    DFS(0,0);
    int s1,s2;//建图
    add(1,1);//第一个状态是0,从0到0时可以的
    for (int i = 1; i <= s[0]; ++i) {
        for (int j = i+1; j <= s[0]; ++j) {
            s1 = s[i],s2 = s[j];
            if( ((s2 << 1) & s1) || ((s2 >> 1) & s1) || (s1 & s2) )//判断s1状态与s2状态是否冲突
                continue;
            add(i,j),add(j,i);//不冲突即s1状态可以到s2状态,s2状态也可到s1状态
        }
    }
}

void DP(){
    f[0][1][0] = 1;//f(i,j,k) 考虑前i行,是第k个状态时,共放了j只猛兽//第一个状态就是0000
    int s1,s2,m = 1,dm;
    for (int i = 1; i <= N; ++i) {
        dm = m^1;//通过异或实现滚动数组下标m在0,1之间滚动//异或也是不带进位的二进制加法
        for (int a = 1; a <= s[0]; ++a) {//初始化
            for (int b = 0; b <= K; ++b) {
                f[m][a][b] = 0;//当前行全部初始化为0;
            }
        }
        for (int a = 1; a <= s[0]; ++a) {//状态
            for (int k = 0; k <= K-num[a]; ++k) {//怪兽个数
                for (int b = st[a]; b != 0; b = Next[b]) {//遍历从当前状态所能达到的所有状态
                    s2 = h[b];
                    f[m][a][k+num[a]] += f[dm][s2][k];
                }
            }
        }
        m = dm;
    }
    m = m^1;
    for (int i = 1; i <= s[0]; ++i) {
        Ans += f[m][i][K];
    }
    cout << Ans;
}


vector < vector <int> > G;

void init(){
    cin >> N >> K;
    s[0] = 0;
    //枚举出总状态数
    for (int i = 0; i < (1 << N); ++i) {
        if(i & (i << 1))
            continue;
        s[0]++;
        int t = i;
        num[s[0]] = 0;
        while (t){
            num[s[0]] += (t&1);
            t = t >> 1;
        }
        s[s[0]] = i;
    }

    int s1,s2;
    G.clear();
    G.resize(MAXN*10);
    for (int j = 1; j <= s[0]; ++j) {
        for (int i = j+1; i <= s[0]; ++i) {//为什么不从j开始循环,因为0到0时会push两次1-1,会造成错误!!!!
            s1 = s[j],s2 = s[i];
            if( ((s2 << 1) & s1) || ((s2 >> 1) & s1) || (s1 & s2) )//判断s1状态与s2状态是否冲突
                continue;
            G[i].push_back(j);//状态号
            G[j].push_back(i);
        }
    }
    G[1].push_back(1);//0到0,也就是说可以连续出现两次第一个状态,也就是两行都不放
}

void DP(){
    f[0][1][0] = 1;//f(i,j,k) 考虑前i行,是第k个状态时,共放了j只猛兽//第一个状态就是0000
    int m = 0,s1;
    for (int i = 1; i <= N; ++i) {
        m ^= 1;
        //初始化数组
        for (int j = 1; j <= s[0]; ++j) {
            for (int k = 0; k <= K; ++k) {
                f[m][j][k] = 0;
            }
        }
        for (int j = 1; j <= s[0]; ++j) {
            for (int k = 0; k <= K; ++k) {
                for (int l = 0; l < G[j].size(); ++l) {
                    s1 = G[j][l];
                    if(k - num[j] >= 0){
                        f[m][j][k] += f[m^1][s1][k-num[j]];
                    }
                }
            }
        }
    }

    Ans = 0;
    for (int n = 1; n <= s[0]; ++n) {
        Ans += f[m][n][K];
    }
    cout << Ans << endl;
}


int main() {
    init();
    DP();
    return 0;
}





