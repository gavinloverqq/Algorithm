/*
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    unsigned long long ret = 1,tmp = 1;
    for (int i = 1; i <= n; ++i) {
        tmp *= i;
        while (tmp % 10 == 0)//把数的最后位的零去掉
            tmp /= 10;
        tmp %= 1000000;//为啥此处100000000不能换成10或者100或者1000
    }
    cout << (tmp % 10) << endl;
    return 0;
}*/


#include <iostream>
#define ll long long
using namespace std;
const int divnum[5]={0,6,2,8,4};
const int d[10]={1, 1, 2, 6, 4, 4, 4, 8, 4, 6};
int main(){
    ll n;
    cin >> n;
    ll tmp = 0;
    ll m = n%10;
    while (n){
        n /= 5;
        tmp += n;
    }
    tmp %= 4;
    cout << m << " " << tmp << endl;
    ll ret = d[0] * 6 % 10 % divnum[tmp];
    cout << ret << endl;
}





//hdu1066
/*#include<iostream>
#include<cstring>
using namespace std;
const int d[10]={1, 1, 2, 6, 4, 4, 4, 8, 4, 6};
const int divnum[5]={0,6,2,8,4};
char s[200];
int a[200];
void div()
{
    int i,l=0;
    for(i=a[0];i>0;i--)
    {
        a[i-1]=a[i-1]+(a[i]%5)*10;
        a[i]=a[i]/5;
        if(l==0&&a[i]!=0)l=i;
    }
    a[0]=l;
}
int doit()
{
    if(a[0]==1)
    {
        int num=d[a[1]];
        if(a[1]>4)
            return divnum[num/2];
        else
            return num;
    }
    else
    {
        int num;
        num=d[a[1]];
        int t;
        t=a[3]*100+a[2]*10+a[1];
        t=(t/5)%4;
        div();
        num=num*doit()*6;
        num=num%10;
        while(t--)num=divnum[num/2];
        return num;
    }
}
int main()
{
    while(cin>>s)
    {
        a[0]=strlen(s);
        for(int i=1;i<=a[0];i++)
            a[i]=s[a[0]-i]-48;
        int num=doit();
        cout<<num<<endl;
    }
}*/

/*
#include <iostream>
using namespace std;

#define MAXN 10000
char c[MAXN];

int lastdigit(char* buf){

    const int mod[20]={1,1,2,6,4,2,2,4,2,8,4,4,8,4,6,8,8,6,8,2};
    int len=strlen(buf),a[MAXN],i,c,ret=1;

    if (len==1)
        return mod[buf[0]-'0'];
    for (i=0;i<len;i++)
        a[i]=buf[len-1-i]-'0';
//    for (;len;len-=!a[len-1]){
//        ret=ret*mod[a[1]%2*10+a[0]]%5;
//        for (c=0,i=len-1;i>=0;i--)
//            c=c*10+a[i],a[i]=c/5,c%=5;
//    }
    while(len)
    {
//        ret=ret*mod[a[1]%2*10+a[0]]%5;
        ret=ret*mod[(a[1]*10+a[0])%20]%5;
        //大数除法。c为余数,
        //每算一次
        for(c=0,i=len-1;i>=0;i--)
        {
            c=c*10+a[i];
            a[i]=c/5;
            c%=5;
        }
        len -= !a[len-1];
    }
    return ret+ret%2*5;
}

int main(){
    while(cin>>c){
        int result=lastdigit(c);
        cout<<result<<endl;
    }
    return 0;

}*/


