#include <iostream>
#include <bitset>
using namespace std;

int main() {

    int c = 0;
    //求-1
    for (int i = 0; i < sizeof(int)*8; ++i) {
        c += (1 << i);
    }
    cout << c << endl;//输出:-1 (里面每一位都是1)

    //求int最大值
    int d = 0;
    for (int j = 0; j < sizeof(int)*8-1; ++j) {
        d += (1 << j);
    }
    cout << d << endl;//输出:2147483647 (第一位是0,后面都为1)

    //求int最小值
    cout << ~d << endl;
    int e = 0;
    e += (1 << (sizeof(int)*8-1));//1左移0位为1;所以是从0开始计数,因此要减一;
    cout << e << endl;//输出-2147483648 (第一位是1,其他都为0,也就是'-0',这个数没有反码和原码)

    //1左移0位
    int f = 0;
    cout << (1 << 0) << endl;//1左移0位为1;所以是从0开始计数,因此要减一;

    //正数取反
    int a = 3;
    //取反后的二进制表示
    cout <<bitset <sizeof(int)*8> (~a) << endl;//输出:11111111111111111111111111111100
    //取反后的十六进制表示
    cout << hex << ~a << endl;//输出:fffffffc
    //取反后的十进制表示
    cout << dec << ~a << endl;//输出:-4

    int b = 0x7fffffff;//直接得到正数最大与负数最大
    cout << dec << b <<" " << ~b << endl;//输出:2147483647 -2147483648
    return 0;
}