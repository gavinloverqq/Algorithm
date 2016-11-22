/*
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
bool vis[100];
char b[100][100];
int a[100],c[100];
int n;
void print()
{
    int i;
    for (i=65;i<65+n;i++) printf("%d ",a[i]);
    printf("\n");
    return ;
}

bool judge1()
{
    int i;
    for (i=n;i>0;i--)
        if (a[b[i][1]]!=-1 &&  a[b[i][2]]!=-1&& a[b[i][3]]!=-1  &&
            (a[b[i][1]]+a[b[i][2]]) % n !=a[b[i][3]] &&
            (a[b[i][1]]+a[b[i][2]]+1) % n !=a[b[i][3]]) return 0;
    return 1;
}

bool judge2()
{
    int i,k=0;
    for (i=n;i>1;i--){
        k=a[b[i][1]]+a[b[i][2]]+k;
        if (a[b[i][3]]!=k % n) return false;
        k/=n;
    }
    return true;
}
void DFS(int m)
{
    int i;
    if (!judge1()) return ;
    if (a[b[1][1]]+a[b[1][2]]>=n) return ;//等式第一列剪枝
    if (m>n){
        if(judge2()){print(); exit(0);}
        else return ;
    }
    else{
        for (i=n-1;i>=0;i--){
            if (vis[i]) {
                a[c[m]]=i;
                vis[i]=0;
                DFS(m+1);
                a[c[m]]=-1;
                vis[i]=1;
            }
        }
    }
}
int main()
{
    int k=1;
    bool h[100];
    memset(h,1,sizeof(h));
    memset(vis,1,sizeof(vis));
    memset(a,-1,sizeof(a));
    scanf("%d",&n);
    for (int j=1;j<4;j++)
        for (int i=1;i<=n;i++) {
            cin>>b[i][j];//b存字符串
        }
    for (int i=n;i>0;i--)
        for (int j=1;j<4;j++)
            if (h[b[i][j]]) {
                c[k++]=b[i][j];//逆序将等式放进来
                h[b[i][j]]=0;
            }
    DFS(1);
    // system ("PAUSE");
    return 0;
}*/

/*#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
int N;
string equ[3];
int alphabet2Num[30];
int right2Left[30];//存字母序号
int used[30];

*//*
8
ABDEBEHG
FGDBBAGB
EDEDCHGE
2 1 3 7 6 4 5 0
15
MFJCGKNDHBALEIO
EBIKIDBMAEELHBC
KGEAOHOJHFFIACJ
0 1 10 7 3 4 6 12 8 9 5 11 2 13 14
*//*

int str2Num(string s){
    int num = 0,tmp = 1;
    for (int i = s.length() - 1; i >= 0; --i) {
        num += alphabet2Num[s[i]-'A'] * tmp;
        tmp *= N;
    }
    return num;
}
//最后的转换也可能耗时间
bool check(){
    int num1,num2,num3;
    int tmp;
    num1 = str2Num(equ[0]);
    num2 = str2Num(equ[1]);
    num3 = str2Num(equ[2]);
    tmp = num1 + num2;
    return (tmp == num3);
}

//优化取模看是否能提高速度
bool check2(){
    //逐位测试
    for (int i = N-2; i >= 1; --i) {
        if(alphabet2Num[equ[0][i] - 'A'] != -1 && alphabet2Num[equ[1][i] - 'A'] != -1 && alphabet2Num[equ[2][i] - 'A'] != -1){
            if((alphabet2Num[equ[0][i] - 'A'] + alphabet2Num[equ[1][i] - 'A']) % N != alphabet2Num[equ[2][i] - 'A'] && (alphabet2Num[equ[0][i] - 'A'] + alphabet2Num[equ[1][i] - 'A'] + 1) % N != alphabet2Num[equ[2][i] - 'A'])
                return true;
        }
    }
    return false;
}

bool check3(){
    //逐位测试

    int flag = 0;
    if ((alphabet2Num[equ[0][N-1] - 'A'] + alphabet2Num[equ[1][N-1] - 'A']) % N == alphabet2Num[equ[2][N-1] - 'A']){
        flag = (alphabet2Num[equ[0][N-1] - 'A'] + alphabet2Num[equ[1][N-1] - 'A']) / N;
    }
    for (int i = N-2; i >= 1; --i) {
        if(alphabet2Num[equ[0][i] - 'A'] != -1 && alphabet2Num[equ[1][i] - 'A'] != -1 && alphabet2Num[equ[2][i] - 'A'] != -1){
            if((alphabet2Num[equ[0][i] - 'A'] + alphabet2Num[equ[1][i] - 'A'] + flag) % N != alphabet2Num[equ[2][i] - 'A'])
                return true;
            else{
                flag = (alphabet2Num[equ[0][i] - 'A'] + alphabet2Num[equ[1][i] - 'A'] + flag) / N;
            }
        } else
            return false;//这个地方必须要加else false 不然等式中间可能有些值不存在,但是前面有些值存在,所以前面的值可以计算,但是计算的时候进位就不对了
    }
    return false;
}

void dfs(int n){
    if(n >= N ){
        if(check()){
            for (int i = 0; i < N; ++i) {
                cout << alphabet2Num[i] << " ";
            }
            exit(0);
        }
        return;
    } else {
        if(n >= 3 && (alphabet2Num[equ[0][N-1] - 'A'] + alphabet2Num[equ[1][N-1] - 'A']) % N != alphabet2Num[equ[2][N-1] - 'A']){
            return;
        }
        if((alphabet2Num[equ[0][0] - 'A'] + alphabet2Num[equ[1][0] - 'A']) >= N)
            return;
        if(n >= 3 && check2())
            return;
        for (int i = N-1; i >= 0; --i) {
            if(used[i] == 0){
                used[i] = 1;
                alphabet2Num[right2Left[n]] = i;
                dfs(n+1);
                used[i] = 0;
                alphabet2Num[right2Left[n]] = -1;
            }
        }
    }
}

//200多ms的代码
int main(){
    cin >> N;
    for (int i = 0; i < 3; ++i) {
        cin >> equ[i];
    }
    int useAlphabet[30];
    for (int j = 0; j < N; ++j) {
        alphabet2Num[j] = -1;
        useAlphabet[j] = 0;
    }
    int index = 0;
    for (int k = N-1; k >= 0; --k) {
        for (int i = 0; i < 3; ++i) {
            if(useAlphabet[equ[i][k] - 'A'] == 0){
                useAlphabet[equ[i][k] - 'A'] = 1;
                right2Left[index++] = equ[i][k] - 'A';
            }
        }
    }
    dfs(0);
}*/



#include <cstdio>
#include <cstdlib>

int match[26], n;
char fa[27], fb[27], fs[27];
bool flag[27];

void dfs(int step, bool plus = false) {
    if (step == n) {
        if (!plus) {
            for (int k = 0; k < n; k++) {
                printf("%d ", match[k]);
            }
            exit(0);
        } else {
            return;
        }
    }
    for (int k = n-2-step; k >= 0; k--) {
        if (match[fa[k]] != -1 && match[fb[k]] != -1 && match[fs[k]] != -1 && (match[fa[k]] + match[fb[k]]) % n != match[fs[k]] && (1 + match[fa[k]] + match[fb[k]]) % n != match[fs[k]]) {
            return;
        }
    }
    int tmp = n-1-step;
    if (match[fa[tmp]] == -1) {
        for (int k = n-1; k >= 0; k--) {
            if (!flag[k]) {
                match[fa[tmp]] = k;
                flag[k] = true;
                dfs(step, plus);
                match[fa[tmp]] = -1;
                flag[k] = false;
            }
        }
    } else if (match[fb[tmp]] == -1) {
        for (int k = n-1; k >= 0; k--) {
            if (!flag[k]) {
                match[fb[tmp]] = k;
                flag[k] = true;
                dfs(step, plus);
                match[fb[tmp]] = -1;
                flag[k] = false;
            }
        }
    } else if (match[fs[tmp]] == -1) {
        int res = match[fa[tmp]] + match[fb[tmp]] + plus;
        for (int k = 0; k < n; k++) {
            if (match[k] == res%n) {
                return;
            }
        }
        match[fs[tmp]] = res % n;
        flag[match[fs[tmp]]] = true;
        dfs(step+1, res >= n);
        flag[match[fs[tmp]]] = false;
        match[fs[tmp]] = -1;
    } else {
        int res = match[fa[tmp]] + match[fb[tmp]] + plus;
        if (match[fs[tmp]] == res % n) {
            dfs(step+1, res >= n);
        }
    }
}

int main(void) {
    scanf("%d\n%s\n%s\n%s", &n, fa, fb, fs);
    for (int k = 0; k < n; k++) {
        match[k] = -1;
        fa[k] -= 'A';
        fb[k] -= 'A';
        fs[k] -= 'A';
    }
    dfs(0);
    return 0;
}