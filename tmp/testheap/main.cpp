#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
int h[100];
int n;
//最小堆
void siftdown(int i){
    int flag = 0,t;
    while (flag == 0 && i * 2 <= n) {//< n +1?
        if(h[i] > h[2 * i]) {// ==??
            t = i * 2;
        } else {
            t = i;
        }
        if(i * 2 + 1 <= n && h[t] > h[2 * i + 1]){
            t = 2 * i + 1;
        }
        if(t != i){
            swap(h[t],h[i]);
            i = t;
        } else
            flag = 1;
    }
}
void siftup(int i){
    int flag = 0,t;
    if(i == 1)return;
    while (flag == 0 && i != 1 ){
        if(h[i] < h[i/2]){
            flag = 0;
            t = i / 2;
            swap(h[i],h[t]);
            i = t;
        } else {
            flag = 1;
        }
    }
}

//最大堆
void siftdown2(int i){
    int flag = 0,t;
    while (flag == 0 && i * 2 <= n) {//< n +1?
        if(h[i] < h[2 * i]) {// ==??
            t = i * 2;
        } else {
            t = i;
        }
        if(i * 2 + 1 <= n && h[t] < h[2 * i + 1]){
            t = 2 * i + 1;
        }
        if(t != i){
            swap(h[t],h[i]);
            i = t;
        } else
            flag = 1;
    }
}
void siftup2(int i){
    int flag = 0,t;
    if(i == 1)return;
    while (flag == 0 && i != 1 ){
        if(h[i] > h[i/2]){
            flag = 0;
            t = i / 2;
            swap(h[i],h[t]);
            i = t;
        } else {
            flag = 1;
        }
    }
}

int deleteMin(){
    int t = h[1];
    h[1] = h[n];
    n--;
    siftdown(1);
    return t;
}

void deleteMin2(){
    while (n > 0) {
        swap(h[1], h[n]);
        n--;
        siftdown2(1);
    }
}

int main() {
    n = 10;
    int a[11];
    srand(time(NULL));
    for (int i = 1; i <= 10; ++i) {
        a[i] = rand() % 100;
        cout << a[i] << " ";
    }
    cout << endl;
    //插入法建堆
    /*
    n = 0;
    for (int j = 1; j <= 10; ++j) {
        n++;
        h[n] = a[j];
        siftup(n);
    }
    */
    //原数组上建堆
    for (int l = 1; l <= 10; ++l) {
        h[l] = a[l];
    }
    //最小堆实现从小到大排序
//    for (int j = n/2; j > 0; --j) {
//        siftdown(j);
//    }
//    while (n > 0){
//        cout << deleteMin() << " ";
//    }
//    cout << endl;
    for (int j = n/2; j > 0; --j) {
        siftdown2(j);
    }
    //最大堆实现从小到大排序
    deleteMin2();
    for (int k = 1; k <= 10; ++k) {
        cout << h[k] << " ";
    }
    return 0;
}