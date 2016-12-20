#include <iostream>

using namespace std;
bool com(int a,int b){//sort默认是从小到大的
    return a > b;
}
int main() {
    int a[10] = {5,4,2,7,8,31,35,7,9,3};
    sort(a,a+10,com);//sort对数组用注意范围,加上总的数组的大小
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << " ";
    }
    cout << "Hello, World!" << endl;
    return 0;
}