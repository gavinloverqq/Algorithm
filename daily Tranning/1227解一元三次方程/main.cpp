#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>

using namespace std;
const double eps = 1e-6;
double a,b,c,d,x;

double f(double x){
    return a*x*x*x + b*x*x + c*x + d;
}

//AC
/*int main() {
    cin >> a >> b >> c >> d;
    double l = -100.0, r = -99.0,fx,fm,mid;

    while (r <= 100.0){
        fx = f(l);
        fm = f(r);
        if(fx * fm <= 0) {
            double tl = l,tr = r;
            while (tr - tl > eps) {
                mid = (tl + tr) / 2.0;
                fm = f(mid);
                fx = f(tl);
                if(fm * fx > 0)
                    tl = mid;
                else
                    tr = mid;
            }
            if(fabs(mid - r) < eps)
                l++,r++;
            printf("%.2f ",mid);
        }
        r++;
        l++;
    }
    return 0;
}*/

/*WA
int main() {
    cin >> a >> b >> c >> d;
    double l = -100.0, r = -99.0,fx,fm,mid;

    while (r <= 100.0){
        fx = f(l);
        fm = f(r);
        if(fx * fm <= 0) {
            double tl = l,tr = r;
            while (tr - tl > eps) {
                mid = (tl + tr) / 2.0;
                fm = f(mid);
                fx = f(tl);
                if(fm * fx > eps)
                    tl = mid;
                else
                    tr = mid;
            }
            if(fabs(mid - r) < eps)
                l++,r++;
            printf("%.2f ",mid);
        }
        r++;
        l++;
    }
    return 0;
}*/

//wa
//1 10 -1 -10
//-10.00 -1.00 1.00
/*int main() {
    cin >> a >> b >> c >> d;
    double l = -100.0, r = -99.0,fx,fm,mid,tans = -110.0;

    while (r <= 100.0){
        fx = f(l);
        fm = f(r);
        if((fx * fm) <= eps) {//此处为什么是 <= eps 是因为此处是 <= 0,注意等于0是成立的,因此不是 <= -eps
            double tl = l,tr = r;
            while (tr - tl > eps) {
                mid = (tl + tr) / 2.0;//到了此处需要考虑边界,如果恰好左边界或者右边界就是方程的解,即f(l) = 0,或f(r) = 0;如何处理
                fm = f(mid);
                fx = f(tl);
                if(fm * fx > eps)
                    tl = mid;
                else if(fm * fx < -eps)
                    tr = mid;
                else // 如果此处 左边界 就是解,也可以满足此处 即fx = 0
                    break;
            }
//            fx = -0.00073249638262495864 fm = -0.00036622956417886599 时不满足下面的判断,但是满足fabs (fx * fm) < eps
            if(fabs(tl - r) < eps)//乘法的累计误差问题
                l++,r++;

            printf("%.2f ",mid);
        }
        r++;
        l++;
    }
    return 0;
}*/

//1 10 -1 -10
//-10.00 -1.00 1.00
//AC
int main() {
    cin >> a >> b >> c >> d;
    double l = -100.0, r = -99.0,fx,fm,mid,tans = -110.0;

    while (r <= 100.0){
        fx = f(l);
        fm = f(r);
        if((fx * fm) <= eps) {//此处为什么是 <= eps 是因为此处是 <= 0,注意等于0是成立的,因此不是 <= -eps
            double tl = l,tr = r;
            while (tr - tl > eps) {
                mid = (tl + tr) / 2.0;//到了此处需要考虑边界,如果恰好左边界或者右边界就是方程的解,即f(l) = 0,或f(r) = 0;如何处理
                fm = f(mid);
                fx = f(tl);
                if(fm * fx > eps)
                    tl = mid;
                else if(fm * fx < -eps)
                    tr = mid;
                else // 如果此处 左边界 就是解,也可以满足此处 即fx = 0
                    break;
            }
//            fx = -0.00073249638262495864 fm = -0.00036622956417886599 时不满足下面的判断,但是满足fabs (fx * fm) < eps
            if(fabs(tl - r) < eps)//乘法的累计误差问题
                l++,r++;

//            printf("%.2f ",mid);
            //用下面的代码解决重复输出问题,以及用 输出左边界,而不是输出中值解决,加入f(l) = 0的问题。思考为什么此处要把精度降为0.001
            if(fabs(tans - tl) > 0.001) {
                tans = tl;
                printf("%.2f ", tl);
            }
        }
        r++;
        l++;
    }
    return 0;
}



//double的二分查找关键在于:1、写的时候带3个样例去写:①、左值 ②、右值 ③、非法值(找不到的值) 2、double乘法的误差累计问题
/*
 *  形如下面的二分查找,目标值在左值上
 *  while (tr - tl > eps) {
                mid = (tl + tr) / 2.0;//到了此处需要考虑边界,如果恰好左边界或者右边界就是方程的解,即f(l) = 0,或f(r) = 0;如何处理
                fm = f(mid);
                fx = f(tl);
                if(fm * fx > eps)
                    tl = mid;
                else if(fm * fx < -eps)
                    tr = mid;
                else // 如果此处 左边界 就是解,也可以满足此处 即fx = 0
                    break;
            }

 */