/*
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;

const double EXP = 1e-7;
double A,B,C,D;
vector <double> ans;//注意此处
int judge(double x1, double x2){
    int flag = 0;
    if(x1 - x2 > EXP)
        flag = 1;// >
    if(x2 - x1 > EXP)
        flag = 2;// <
    if(abs(x1 - x2) <= EXP)
        flag = 3;// =
    return flag;

}

double eq(double x1){
    return A*x1*x1*x1 + B*x1*x1 + C*x1 + D;
}
// 1 -4.65 2.25 1.4
// -0.35 1.00 4.00
int main(){

    cin >> A >> B >> C >> D;

    int flag = 0;
    double temp1 = eq(-100);
    double temp3;
    for (int i = -2; i <= 100; ++i) {
        double x1 = i - 1,x2 = i;
        double temp2 = eq(x2);
        if(judge(temp2,0.0) == 3) {
            ans.push_back(x2);
//            temp1 = temp2;
//            continue;
        }
        flag = judge(temp1 * temp2, 0.0);
        if(flag == 2){
            while (x1 + EXP <= x2){
                double mid = (x1 + x2) / 2.0;
                double tMid = eq(mid);
                temp3 = eq(x1);
                if(abs(tMid) <= EXP){
                    ans.push_back(mid);
                    break;
                }
                int tflag = judge(temp3*tMid,0.0);
                if(tflag == 1){
                    x1 = mid;
                }
                if(tflag == 2){
                    x2 = mid;
                }
            }
        }
        if(ans.size() == 3)
            break;
        temp1 = temp2;
    }
    printf("%.2lf %.2lf %.2lf\n",ans[0],ans[1],ans[2]);
}*/





#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;

const double EXP = 1e-3;
double A,B,C,D;
vector <double> ans;//注意此处
int judge(double x1, double x2){
    int flag = 0;
    if(x1 - x2 > EXP)
        flag = 1;// >
    if(x2 - x1 > EXP)
        flag = 2;// <
    if(abs(x1 - x2) <= EXP)
        flag = 3;// =
    return flag;

}

double eq(double x1){
    return A*x1*x1*x1 + B*x1*x1 + C*x1 + D;
}
// 1 -4.65 2.25 1.4
// -0.35 1.00 4.00
int main(){

    cin >> A >> B >> C >> D;

    int flag = 0;
    double temp1 = eq(-100);
    double temp3;
    for (int i = -100; i <= 100; ++i) {
        double x1 = i - 1,x2 = i;
        double temp2 = eq(x2);
        if(judge(temp2,0.0) == 3) {
            ans.push_back(x2);
            temp1 = temp2;
            continue;
        }
        flag = judge(temp1 * temp2, 0.0);
        if(flag == 2){
            while (x1 + EXP <= x2){
                double mid = (x1 + x2) / 2.0;
                double tMid = eq(mid);
                temp3 = eq(x1);

                //此处值得注意: 当某些数,计算他的函数值是大于精度值的,在这个if判断中,不满足。但是到了下面f(x1) * f(x2) 就有可能等于0;
                // 比如精度exp = 0.001;当f(x1) = 0.0011时认为f(x1) 是不等于 0 的,但是f(x2) = ±0.01 此时f(x1) * f(x2) = ±0.0001 < exp 此时认为f(x1)*f(x2) = 0;
                // 那么必然得到f(x1) = 0 或者 f(x2) = 0;但此时分别计算f(x1)或f(x2)是不等于 0 的。就容易导致2分查找进入死循环!!!!!
                if(abs(tMid) <= EXP){
                    ans.push_back(mid);
                    break;
                }
                int tflag = judge(temp3*tMid,0.0);
                if(tflag == 1){
                    x1 = mid;
                }
                if(tflag == 2){
                    x2 = mid;
                }
                if(tflag == 3){
                    ans.push_back(mid);
                    break;
                }
            }
        }
        if(ans.size() == 3)
            break;
        temp1 = temp2;
    }
    printf("%.2lf %.2lf %.2lf\n",ans[0],ans[1],ans[2]);
}
