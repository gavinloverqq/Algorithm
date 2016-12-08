#include <iostream>
#define LL long long
using namespace std;
const int bigPrimeNum = 277777;
LL arr1[300000],arr2[300000],Hash[bigPrimeNum + 10];
int Max = 300000;
int sum[bigPrimeNum + 10];

void Insert(LL num){
    int tmp = num % bigPrimeNum;
    while (Hash[tmp] != Max && Hash[tmp] != num){
        tmp++;
        if(tmp > bigPrimeNum)
            tmp = 0;
    }
    Hash[tmp] = num;
    sum[tmp]++;
}
int Find(LL num){
    int tmp = num % bigPrimeNum;
    while (Hash[tmp] != Max && Hash[tmp] != num){
        tmp++;
        if(tmp > bigPrimeNum)
            tmp = 0;
    }
    return sum[tmp];
}

int main() {
    int n;
    LL c;
    for (int k = 0; k < bigPrimeNum + 10; ++k) {
        Hash[k] = Max;
    }
    cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
        arr2[i] = arr1[i] + c;
        Insert(arr2[i]);
    }

    int ans = 0;
    for (int j = 0; j < n; ++j) {
        ans += Find(arr1[j]);
    }

    cout << ans << endl;
    return 0;
}