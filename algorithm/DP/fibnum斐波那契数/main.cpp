#include <iostream>

using namespace std;
long long f[1000000];
long long fib(int n){
    if(f[n] > 0)
        return f[n];
    f[n] = fib(n-1) + fib(n-2);
    return f[n];
}

int main() {
    int n;
    cin >> n;
    f[1] = 1;
    f[2] = 1;
    cout << fib(n) << endl;
    return 0;
}