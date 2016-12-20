#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

const double EXP = 1e-6;
double x,y,a,c;
double eq(double a){
    return c / sqrt(x * x - a * a) + c / sqrt((y * y - a * a));
}

//wa
int main() {
    double mid;
    while (cin >> x >> y >> c) {
        double l = 0, r = min(x, y);
        while (r - l > EXP) {
            mid = (l + r) / 2;
            double eMid = eq(mid);
            if (eMid > 1.0 + EXP) {
                r = mid;
            }else if(eMid + EXP < 1.0){
                l = mid;
            } else
                break;
        }
        printf("%.3f\n",mid);
    }
    return 0;
}