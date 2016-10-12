#include <iostream>
#define ll long long
using namespace std;

ll b,p,k,ans = 1;
ll powb(ll a,ll n,ll k){
    if(1 == n){
        return a % k;//这里忘记写%k
    }
    if(0 == n){//第一次这里忘记写!
        return 1;
    }
//    return powb(a,n >> 1,k) * powb(a,n - (n>>1),k) % k;//注意此处的优化!!!
    if(n % 2){
        return powb((a%k)*(a%k)%k,n >> 1,k) * a % k;//此处的递归优化也可以看出,一部分需要多次递归的可以优化传入参数,从而减少不必要的递归
    } else
        return powb((a%k)*(a%k)%k,n >> 1,k);
}



int main() {
    cin >> b >> p >> k;
    ll pp = p,bb = b;
//    ll x = 1;
//    while (p){
//        if(p&1){
//            ans = ans * b % k;
//        }
//        p >>= 1;
//        b = b * b % k;
//    }
    ans = powb(b,p,k);
    cout << bb << "^" << pp << " mod "<< k << "=" << ans<< endl;
    return 0;
}