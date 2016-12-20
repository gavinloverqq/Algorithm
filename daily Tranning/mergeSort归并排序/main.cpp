#include <iostream>

using namespace std;
int arr[10] = {3,7,2,3,5,1,9,7,10,6};
int b[10];

void mergeS(int s1[],int s2[],int l,int m,int r){
//    int i = l,j = m + 1,index = l;
//    for (int k = l; k <= m; ++k) {
//        while (s1[k] > s1[j] && j <= r)
//            s2[index++] = s1[j++];
//        s2[index++] = s1[k];
//    }
//    //假如 l- m 都比 m+1 - r中的小
//    while (j <= r)
//        s2[index++] = s1[j++];

    int i = l,j = m + 1,k = l;
    while (i <= m && j <= r){
        if(s1[i] <= s1[j]){// =????????
            s2[k++] = s1[i++];
        } else {
            s2[k++] = s1[j++];
        }
    }
    if(i > m){
        for (int n = j; n <= r; ++n) {
            s2[k++] = s1[n];
        }
    } else {
        for (int n = i; n <= m; ++n) {
            s2[k++] = s1[n];
        }
    }
}

void mergeSort(int l,int r){
    if(l < r) {
        int m = (l + r) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        mergeS(arr,b,l,m,r);

        for (int i = l; i <= r; ++i) {
            arr[i] = b[i];
        }
    }
}


//void mergeSort(int l,int r){
//    while (l <= r) {
//        int m = (l + r) / 2;
//        mergeSort(l, m);
//        mergeSort(m + 1, r);
//        mergeS(arr,b,l,m,r);
//
//        for (int i = l; i <= r; ++i) {
//            arr[i] = b[i];
//        }
//    }
//}

int main() {

    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    mergeSort(0,9);
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}