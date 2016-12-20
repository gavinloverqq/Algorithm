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
//            if(eMid > 0)
//                l = mid;
//            else
//                r = mid;
        }
        printf("%.3lf\n",mid);
    }
    return 0;
}



/*int main() {
    double mid;
    while (cin >> x >> y >> c) {
        double l = 0, r = min(x, y);
        while (1) {
             mid = (l + r) / 2;
            double eMid = eq(mid);
            if(abs(eMid - 1.0) <= EXP)
                break;
            if(eMid > 1.0){
                r = mid;
            } else {
                l = mid;
            }
        }
        printf("%.3lf\n",mid);
    }
    return 0;
}*/




/*WA
int main() {
    double mid;
    while (cin >> x >> y >> c) {
        double l = 0, r = min(x, y);
        int Case = 100;
        while (Case--) {
            mid = (l + r) / 2;
            double eMid = eq(mid);
            if (eMid > 1.0 + EXP) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        printf("%.3lf\n",l);
    }
    return 0;
}*/

//WA
/*int main() {
    double mid;
    while (cin >> x >> y >> c) {
        double l = 0, r = min(x, y);
        while (l + EXP <= r) {
            mid = (l + r) / 2;
            double eMid = eq(mid);
            if (eMid > 1.0 + EXP) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        printf("%.3lf\n",mid);
    }
    return 0;
}*/


/*WA
int main() {
    while (cin >> x >> y >> c) {
        double l = 0, r = min(x, y);
        while (1) {
            double mid = (l + r) / 2;
            double eMid = eq(mid);
            if (abs(eMid - 1.0) <= EXP) {
                a = mid;
                break;
            }
            if (eMid > 1.0 + EXP) {
                r = mid;
            }
            if (eMid + EXP < 1.0) {
                l = mid;
            }
        }
        printf("%.3lf\n",a);
    }
    return 0;
}*/

//WA
/*int main() {
    while (cin >> x >> y >> c) {
        double l = 0, r = min(x, y);
        while (EXP <= r - l) {
            double mid = (l + r) / 2;
            double eMid = eq(mid);
            if (abs(eMid - 1.0) <= EXP) {
                a = mid;
                break;
            }
            if (eMid > 1.0 + EXP) {
                r = mid;
            }
            if (eMid + EXP < 1.0) {
                l = mid;
            }
        }
        printf("%.3lf\n",a);
    }
    return 0;
}*/

/*
 * WA
int main() {
    double mid;
    while (cin >> x >> y >> c) {
        double l = 0, r = min(x, y);
        while (1) {
            mid = (l + r) / 2;
            double eMid = eq(mid);
            if(abs(eMid - 1.0) <= EXP)
                break;
            if(eMid > 1.0){
                r = mid;
            } else {
                l = mid;
            }
        }
        printf("%.3lf\n",mid);
    }
    return 0;
}*/


