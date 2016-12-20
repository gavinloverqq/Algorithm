#include <iostream>

using namespace std;

int a[11] = {0,2,5,8,6,4,6,8,3,9,1};
int n = 10;
void siftup(int i){//传入参数是节点编号
    while (i/2 > 0 && a[i] < a[i/2]){
        swap(a[i],a[i/2]);
        i = i/2;
    }
}
void siftdown(int i){
    int tmp,flag = 0;
    while(i*2 <= n) {
        if(a[i] > a[i * 2]) {
            tmp = i * 2;
            if (i * 2 + 1 <= n && a[tmp] > a[2 * i + 1]) {
                tmp = 2 * i + 1;
            }
            swap(a[i], a[tmp]);
            i = tmp;
        } else {
            tmp = i;
            if (i * 2 + 1 <= n && a[i] > a[2 * i + 1]) {
                tmp = 2 * i + 1;
            }
            swap(a[i], a[tmp]);
            //第一次忘记退出,如果a[i]比两个子孩子都大,那么就退出
            if(i == tmp)
                break;
            else
                i = tmp;
        }
    }
}

int main() {
    int t = n;
    for (int j = 1; j <= t; ++j) {
        cout << a[j] << " ";
    }
    cout << endl;

    for (int i = n/2; i > 0; --i) {
        siftdown(i);
    }

    while (n > 1){
        swap(a[1],a[n]);
        n--;
        siftdown(1);
    }
    for (int j = 1; j <= t; ++j) {
        cout << a[j] << " ";
    }
    return 0;
}