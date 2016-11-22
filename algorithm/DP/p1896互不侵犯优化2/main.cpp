#include<iostream>
#include<cstdio>
using namespace std;
int n,k,m,f[20][522][110],t[1100];
int check(int x,int y)
{
    if((x&y)!=0)return 0;
    if((x&(x<<1))>0)return 0;
    if((x&(y<<1))>0)return 0;
    if((y&(y<<1))>0)return 0;
    if((y&(x<<1))>0)return 0;
    return 1;
}
int main()
{
    cin>>n>>k;
    m=(1<<n)-1;
    f[0][0][0]=1;
    for(int i=1;i<=m;i++)
        t[i]=t[i>>1]+(i&1);
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int w=0;w<=m;w++)
                if(check(w,j)==1)
                {
                    for(int kk=t[j]+t[w];kk<=k;kk++)
                        f[i][j][kk]=f[i][j][kk]+f[i-1][w][kk-t[j]];
                }
    int sum=0;
    for(int i=0;i<=m;i++)
        sum+=f[n][i][k];
    cout<<sum;
}