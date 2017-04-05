#include <iostream>

using namespace std;


long long fibarr[100000];

long long fib(int n){
    if(n == 1 || n == 2){
        return 1;
    }
    if(fibarr[n] > 0){
        return fibarr[n];
    }
    return fibarr[n] = fib(n-1) + fib(n-2);

}


int main() {
    int n;
    long long fn = 1, f1 = 1;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}