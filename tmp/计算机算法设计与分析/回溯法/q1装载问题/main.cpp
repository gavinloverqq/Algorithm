#include <iostream>

using namespace std;
/*

int c1 = 50,c2 = 50;
int n = 3,w[4] = {0,20,40,40};
int bestw = ~(1 << 30);

void dfs(int level,int cw){
    if(level > n){
        if(cw <= c1)
            bestw = max(bestw,cw);
    } else {
        for (int i = 0; i < 2; ++i) {
            cw += i*w[level];
            dfs(level+1,cw);
        }
    }
}

int main() {
    dfs(1,0);
    cout << bestw << endl;
    return 0;
}*/

int T,M;
int w[110],v[110];
int bestv = ~(1 << 30);
int remainv[110];
int ans[110],best[110];
void dfs(int level,int cw,int cv){
    if(level > M){
        if(bestv < cv){
            bestv = cv;
            //解空间的回溯
            for (int i = 1; i <= M; ++i) {
                best[i] = ans[i];
            }
        }
        return;
    } else {
        for (int i = 0; i < 2; ++i) {
            cw += i*w[level];
            cv += i*v[level];
            ans[level] = i;
            if(cw <= T && cv + remainv[level+1] > bestv)//可行性剪枝与最优性剪枝
                dfs(level+1,cw,cv);
        }
    }
}

int main(){
    cin >> T >> M;
    for (int i = 1; i <= M; ++i) {
        cin >> w[i] >> v[i];
    }

    //考虑到第k个物品时,剩下物品的价值总和
    int tmp = 0;
    for (int j = M; j > 0; --j) {
        tmp += v[j];
        remainv[j] = tmp;
    }
    remainv[M+1] = 0;

    dfs(1,0,0);

    cout << bestv << endl;
    //解空间的回溯
    for (int k = 1; k <= M; ++k) {
        if(best[k])
            cout << k <<" ";
    }

    return 0;
}