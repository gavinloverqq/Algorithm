#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll b,p,k,power,tmp,pp;

    cin >> b >> p >> k;
    tmp = b,power = 1,pp = p;
    while (p){
        if(p & 1)
            power = (power * tmp) % k;
        tmp = (tmp * tmp) % k;
        p = p >> 1;
    }
    cout << b << "^" << pp << " mod " << k << "=" << power << endl;
    return 0;
}