#include <iostream>

using namespace std;
/**
 * 功能:手动实现优先队列(最小堆)
 * 函数:pop(),push(),top(),creatPQ()
 * 数组下标从1开始
 */
int h[100],n;
void siftup(int i){
    int flag = 0,t;
    if(i == 1) return;
    while (flag == 0 && i / 2 > 0){
        if(h[i] < h[i / 2]){
            swap(h[i],h[i / 2]);
            i = i / 2;
        } else
            flag = 1;
    }
}
void siftdown(int i){
    int flag = 0,t;
    while (flag == 0 & i * 2 <= n){
        if (h[i] > h[i * 2]){
            swap(h[i],h[i * 2]);
            t = i * 2;
        } else
            t = i;
        if(i * 2 + 1 <= n && h[t] > h[2 * i + 1]){
            swap(h[t],h[2 * i + 1]);
            t = 2 * i + 1;
        }
        if(t != i){
            i = t;
        } else
            flag = 1;
    }
}
void creatPQ(){
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    int t = n / 2;
    while (t > 0){
        siftdown(t);
        t--;
    }
}
void pop(){
    swap(h[1],h[n]);
    n--;
    siftdown(1);
}
int top(){
    return h[1];
}
void push(int i){
    n++;
    h[n] = i;
    siftup(i);
}
int main() {
    creatPQ();
    int loop = 100;
    int t;
    cin >> t;
    push(t);
    cout << top() << endl;
    pop();
    //从大到小排序
    int tn = n;
    while (n > 0){
        swap(h[1],h[n]);
        n--;
        siftdown(1);
    }
    for (int i = 1; i <= tn; ++i) {
        cout << h[i] << " ";
    }
    return 0;
}