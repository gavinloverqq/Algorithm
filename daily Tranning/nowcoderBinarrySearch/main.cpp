#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    freopen("/Users/wankun/Desktop/Algorithm/daily Tranning/nowcoderBinarrySearch/data.in","r",stdin);
    int n,l,arr[2000],b[2000];
    while (cin >> n >> l) {
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            b[i] = arr[i];
        }
        sort(arr, arr + n);

        int m = 0;
        for (int j = n - 1; j >= 1; --j) {
            m = max(m, arr[j] - arr[j - 1]);
        }
        int e = max(arr[0] - 0,l - arr[n-1]);
        if(e/1.0 >= m/2.0){
            printf("%.2f\n", e/1.0);
            continue;
        }
        printf("%.2f\n", m / 2.0);
    }
}



//二分查找
//        vector<int> A;
//int getPos(vector<int> A, int n, int val) {
//    int l = 0,r = n -1;
//    while (l <= r){
//        int mid = (l + r) / 2;
//        if(val == A[mid]){
//            while (mid >= 1 && val == A[mid - 1])
//                mid--;
//            return mid;
//        }
//        if(val < A[mid]){
//            r = mid - 1;
//        }
//        if(val > A[mid]){
//            l = mid + 1;
//        }
//    }
//    return -1;
//
//}
////
//int main() {
//
//    int n,val;
//    cin >> n;
//    int tmp;
//    for (int i = 0; i < n; ++i) {
//        cin >> tmp;
//        A.push_back(tmp);
//    }
//    cin >> val;
//    cout << getPos(A,n,val) << endl;
//    return 0;
//}


//寻找字符串中的重复字符
/*

char findFirstRepeat(string A, int n) {
    // write code here
    int book[600];
    for (int i = 0; i < 600; ++i) {
        book[i] = 0;
    }
    for (int j = 0; j < n; ++j) {
        if(book[A[j]] == 0){
            book[A[j]] = 1;
        } else {
            return A[j];
        }
    }
}
int main(){
    string a;
    int n;
    cin >> a;
    n = a.length();
    cout << findFirstRepeat(a,n);
}*/




//懂二进制(小米)
// 1999 2299
// 7
/*
int main(){
    int n,m;
    cin >> n >> m;
//    bit_xor
    int ret = n ^ m;

    int t = 0;
    while (ret > 0){
        ret = ret & (ret - 1);
        t++;
    }
    cout << t <<endl;
}*/
