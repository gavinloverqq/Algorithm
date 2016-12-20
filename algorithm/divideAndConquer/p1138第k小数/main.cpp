#include <iostream>

using namespace std;
//int n,k,a[10010] = {0,1, 3, 3, 7, 2, 5, 1, 2, 4, 6};
int n,k,a[10010];
//3 2 2 3 如何运行的
int partition(int l,int r){
    int i = l,j = r;
    int value = a[l];
    i++;
    while (1){
        while (a[i] < value && i < r) i++;//等于号要不要 6 6 5 4 3 6 8 问题
        while (a[j] > value ) j--;
        if(i >= j){
            swap(a[l],a[j]);
            break;
        } else {
            swap(a[i],a[j]);
        }
    }
    return j;
}

int qSort(int l, int r,int k){
    if(l == r){
        return a[l];
    }
    int m = partition(l,r);
    int j = m - l + 1;
    if(k <= j)
        return qSort(l,m,k);
    else
        return qSort(m+1,r,k-j);
}
/*void qSort(int l,int r){
    if(l < r){
        int m = partition(l,r);
        qSort(l,m-1);
        qSort(m+1,r);
    }
}*/
/*
 10 3
 1 3 3 7 2 5 1 2 4 6
*/
 int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
//    n = 10,k = 3;
    if(k <= 0 || k > n){
        cout << "NO RESULT" << endl;
        return 0;
    }
    qSort(1,n,k);
    for (int j = 1; j <= n; ++j) {
        cout << a[j] << " ";
    }
    return 0;
}