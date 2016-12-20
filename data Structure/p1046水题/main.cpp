#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[11];
    for (int i = 0; i < 11; ++i)
        cin >> a[i];
    sort(a,a+10);
    cout << upper_bound(a,a+10,a[10]+30) - a << endl;
    return 0;
}