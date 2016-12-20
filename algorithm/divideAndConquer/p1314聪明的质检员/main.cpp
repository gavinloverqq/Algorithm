#include <iostream>
#include <algorithm>
using namespace std;

struct interval{
    int l,r;
    interval(){}
    interval(int ll,int rr):l(ll),r(rr){}
};
interval range[200020];
struct mineNode{
    int w,v,index;
    mineNode(){}
    mineNode(int ww,int vv,int ii):w(ww),v(vv),index(ii){}
};
bool operator < (mineNode a,mineNode b){
    return a.w < b.w;
}
mineNode mine[200020];
int n,m;
long long s;
long long prefixSum[200020];// i 前面满足条件的物品的个数
long long prefixSumValue[200020]; // i 前面满足条件的物品的价值总和

long long calculatorY(int w){
    //预处理出前缀和
    int idx = 0;
    long long tmpSum = 0;
    for (int j = 1; j <= n; ++j) {
        if(mine[j].w >= w){
            idx++;
            tmpSum += mine[j].v;
        }
        prefixSum[j] = idx;
        prefixSumValue[j] = tmpSum;
    }

    long long sigma = 0,sigmav = 0,sumY = 0;
    for (int i = 0; i < m; ++i) {//遍历所有区间
        sigma = prefixSum[range[i].r] - prefixSum[range[i].l - 1];//注意此处的-1
        sigmav = prefixSumValue[range[i].r] - prefixSumValue[range[i].l - 1];
        sumY += sigma * sigmav;
    }
    return sumY;
}



int main() {
    cin >> n >> m >> s;
    int minW = 1 << 30,maxW = -1;
    int w,v;
    for (int i = 1; i <= n; ++i) {
        cin >> w >> v;
        mine[i] = mineNode(w,v,i);
        minW = min(minW,w);
        maxW = max(maxW,w);
    }

    int t1,t2;
    for (int j = 0; j < m; ++j) {
        cin >> t1 >> t2;
        range[j] = interval(t1,t2);
    }

    int l = minW,r = maxW + 1;
    int mid;
    long long y,ans = 100000000000000;

    while (l <= r){
        mid = (l + r) / 2;
        y = calculatorY(mid);

        //注意此处的处理
        ans = min(ans,abs(y - s));

        if(y == s) break;
        if(y > s){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}




/*
 * 10 10 1475400
23954 25180
18805 2701
17195 5663
7044 13659
8139 30927
19774 25516
7472 4572
5999 6166
1185 13621
10414 26521
2 10
4 7
5 8
1 6
2 7
1 3
2 7
3 4
1 6
1 10


 27196
 */