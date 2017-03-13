#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdio>
using namespace std;
int a[10010],n,k;
//
//int partition(int l,int r){
//    int i = l,j = r,key = a[l];
//    i++;
//    while (1){
//        while (a[i] < key && i <= r) i++;
//        while (a[j] > key && j >= l) j--;
//        if(i < j){
//            swap(a[i],a[j]);
//        } else {
//            swap(a[l],a[j]);
//            break;
//        }
//    }
//    return j;
//}

int Random(int l,int r){
    srand((unsigned)time(NULL));
    int num = rand()%(r - l) + l;
    return num;
}

int partition(int l,int r){
    int i = l,j = r,key = a[l];
    i++;
    while (1){
        while (a[i] < key && i <= r) i++;
        while (a[j] > key && j >= l) j--;
        if(i >= j){
            break;
        }
        swap(a[i],a[j]);
    }
    swap(a[j],a[l]);
    return j;
}

int randPartition(int l,int r){
    int i = Random(l,r);
    swap(a[i],a[l]);
    return partition(l,r);
}

void qSort(int l, int r){
    if(l < r) {
        int m = randPartition(l, r);
        qSort(l, m - 1);
        qSort(m + 1, r);
    }
}
//int kMin(int k,int l ,int r){
//    int m = partition(l,r);
//    if(k == m){
//        return a[k];
//    }
//    if(r >= l) {
//        if (k < m) {
//            return kMin(k, l, m - 1);
//        } else {
//            return kMin(k, m + 1, r);
//        }
//    }
//
//}
/*
10 3
1 3 3 7 2 5 1 2 4 6
*/
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
//        cin >> a[i];
        scanf("%d",&a[i]);
    }
    qSort(1,n);
//    sort(a + 1,a + n + 1);
    int index = 1,tmp = a[1],flag = 0;
    for (int j = 1; j <= n; ++j) {
        if(a[j] > tmp){
            tmp = a[j];
            index++;
        }
        if(index == k){
            cout << a[j] << endl;
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        cout << "NO RESULT" << endl;
    }
//    cout << kMin(k,1,n) << " ";
//    cout << "Hello, World!" << endl;
    return 0;
}