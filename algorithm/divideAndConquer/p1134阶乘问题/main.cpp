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
        tmp %= 2000000;//为啥此处100000000不能换成10或者100或者1000
    }
    cout << (tmp % 10) << endl;
    return 0;
}