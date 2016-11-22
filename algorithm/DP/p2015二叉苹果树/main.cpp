#include <iostream>
#include <vector>
using namespace std;
int N,M;
struct Node{
    int d,v;
    Node(){}
    Node(int dd,int vv):d(dd),v(vv){}
};
vector < vector<Node> > G;
int dp[5][110][110];
int visited[110];
int dfsDP(int son,int father){
    int ans = 0;
    for (int i = G[son].size() - 1; i >= 0;i--) {
        int nNode = G[son][i].d;
        if(nNode == father)
            continue;
        ans += dfsDP(nNode,son) + 1;
        for (int j = 0 ;j <= min(M,ans); ++j) {//考虑此处的逆序为什么不行
//        for (int j = min(M,ans) ;j >= 0; --j) {
            for (int k = j; k > 0; --k) {
                dp[i][son][j] = max(dp[i+1][son][j],dp[i+1][son][j-k] + max(dp[0][nNode][k-1],max(dp[1][nNode][k-1],dp[2][nNode][k-1])) + G[son][i].v);
            }
        }
    }
    return ans;
}
int main() {
    cin >> N >> M;
    G.clear();
    G.resize(N+10);
    for (int i = 1; i < N; ++i) {
        int s,d,v;
        cin >> s >> d >> v;
        G[s].push_back(Node(d,v));
        G[d].push_back(Node(s,v));
    }
    dfsDP(1,-1);
    cout << max(dp[0][1][M],max(dp[1][1][M],dp[2][1][M])) << endl;
    return 0;
}



/*

#include<iostream>
#include<cstdio>
using namespace std;
struct node
{
    int l,r,v;
}tree[1001];
int flag[101];
int f[101][101];
int n,q;
int gen;
void ecs()
{
    int i,x,y,m;
    for (i=1;i<n;i++)
    {
        int p=0;
        scanf("%d%d%d",&x,&y,&m);
        for (int j=1;j<=n;j++)
            if (tree[j].l==y||tree[j].r==y) p=1;   //因为这道题给的两个点之间前后顺序是不一定的，所以首先判断其中一点
        //是不是其他节点的子节点，若是，则将其作为另一节点的父亲，反之则为儿子节点。
        if (p==0)
        {
            if (tree[x].l==0) tree[x].l=y;
            else if (tree[x].r==0) tree[x].r=y;
            tree[y].v=m;
            flag[y]=1;
        }
        else
        {
            if (tree[y].l==0) tree[y].l=x;
            else if (tree[y].r==0) tree[y].r=x;
            tree[x].v=m;
            flag[x]=1;
        }
    }
    for (i=1;i<=n;i++)
        if (flag[i]==0) {gen=i;break;}
}
void dfs(int i,int j)
{
    int k;
    if (j==0) f[i][j]=0;
    else if (tree[i].r==0&&tree[i].l==0) f[i][j]=tree[i].v;
    else
    {
        f[i][j]=0;
        for (k=0;k<j;k++)
        {
            if (f[tree[i].l][k]==0) dfs(tree[i].l,k);
            if (f[tree[i].r][j-k-1]==0) dfs(tree[i].r,j-k-1);
            f[i][j]=max(f[i][j],f[tree[i].l][k]+f[tree[i].r][j-k-1]+tree[i].v);
        }
    }
}
int main()
{
    int ans;
    scanf("%d%d",&n,&q);
    ecs();
    dfs(gen,q+1);
    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i < 4; ++i) {
            cout << f[j][i] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i <= n; ++i) {
        cout << tree[i].v << " ";
    }
//    printf("%d",f[gen][q+1]);//q+1是因为将价值赋值给了父节点与子节点的子节点，所以最后是q+1
}*/
