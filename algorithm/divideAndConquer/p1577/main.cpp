#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define ll long long
#define eps 1e-4
using namespace std;
int N, K;
double A[10005];



int check(double m){
    ll sum = 0;
    for (int i = 0; i < N; ++i) {//double向下取整，以及除法的向下取整，四舍五入
        sum += A[i] / m;
    }
    return (sum < K) ? 1 : 0;
}


int main() {
    cin >> N >> K;
    double r = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        r = max(r, A[i]);
    }

    double l = 0, ans = r;
    while (l + eps < r){
        double m = (l + r) / 2.0;
        if(check(m)){
            r = m - eps;
        } else {
            l = m;
        }
    }

//    printf("%.2f\n", floor(l * 100) / 100.0);



    char* str = (char*)calloc(8,sizeof(char)); // 临时存储输出答案
    sprintf(str,"%.3lf",l); //输出三位小数，防止四舍五入
    str[strlen(str)-1] = 0; //强制删除最后一位
    printf("%s",str);



    return 0;
}