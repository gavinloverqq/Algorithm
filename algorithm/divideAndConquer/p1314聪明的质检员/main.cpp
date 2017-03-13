
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
#include <iostream>
#include <algorithm>
#include <cstdio>
#define lson l,m,rt << 1
#define rson m + 1,r,rt << 1 | 1
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

struct intervalNode{
    long long sumIndex,sumVal;
    intervalNode(){}
    intervalNode(long long si,long long sv):sumIndex(si),sumVal(sv){}
    friend intervalNode operator + (intervalNode a,intervalNode b){
        return intervalNode(a.sumIndex + b.sumIndex,a.sumVal + b.sumVal);
    }
};

intervalNode SUM[200020 * 4];

void pushUp(int rt){
    SUM[rt].sumIndex = SUM[rt << 1].sumIndex + SUM[rt << 1 | 1].sumIndex;
    SUM[rt].sumVal = SUM[rt << 1].sumVal + SUM[rt << 1 | 1].sumVal;
}
void build(int w,int l,int r,int rt){
    if(l == r){
        if(mine[l].w >= w)
            SUM[rt] = intervalNode(1,mine[l].v);
        else
            SUM[rt] = {0,0};
        return;
    }
    int m = (l + r) >> 1;
    build(w,lson);
    build(w,rson);
    pushUp(rt);
}
intervalNode query(int L,int R,int l,int r,int rt){
    if(L <= l && r <= R){
        return SUM[rt];
    }
    int m = (l + r) >> 1;
    intervalNode ret(0,0);
    if(L <= m)
        ret = ret + query(L,R,lson);
    if(R > m)
        ret = ret + query(L,R,rson);
    return ret;
}


long long calculatorY(int w){
    long long sumY = 0;
    build(w,1,n,1);
    for (int i = 0; i < m; ++i) {
        intervalNode tmp = query(range[i].l,range[i].r,1,n,1);
        sumY += tmp.sumVal * tmp.sumIndex;
    }
    return sumY;
}

int main() {
//    cin >> n >> m >> s;
    scanf("%d %d %lld",&n,&m,&s);
    int minW = 1 << 30,maxW = -1;
    int w,v;
    for (int i = 1; i <= n; ++i) {
//        cin >> w >> v;
        scanf("%d %d",&w,&v);
        mine[i] = mineNode(w,v,i);
        minW = min(minW,w);
        maxW = max(maxW,w);
    }

    int t1,t2;
    for (int j = 0; j < m; ++j) {
//        cin >> t1 >> t2;
        scanf("%d %d",&t1,&t2);
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


*/

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