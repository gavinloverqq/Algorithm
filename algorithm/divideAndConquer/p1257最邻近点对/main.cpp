#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int n;
struct Point{
    double x,y;
    Point(){}
    Point(double xx,double yy):x(xx),y(yy){}
};
Point p[200020],tp[200020];

bool compx(Point a,Point b){
    if(a.x != b.x)
        return a.x < b.x;
    else
        return a.y < b.y;
}
bool compy(Point a,Point b){
    return a.y < b.y;
}

double dist(Point a,Point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double fun(int l, int r){
    if(l == r)
        return 1000000000000;
    if(l + 1 == r){
        return dist(p[l],p[r]);
    }

    int mid = (l + r) / 2;
    double d1 = fun(l,mid);
    double d2 = fun(mid,r);
    double d = min(d1,d2);
    double ans = 1000000000000;

    //AC
    int index = 0;
    for (int i = l; i <= r; ++i) {
        tp[index++] = p[i];
    }
    sort(tp,tp+index,compy);

    for (int j = 0; j < index; ++j) {
        int i = j + 1;
        while (i < index && tp[i].y - tp[j].y < d && tp[i].y - tp[j].y < ans){
            ans = min(ans,dist(tp[j],tp[i]));
            i++;
        }
    }

    //AC 且时间和上面相差不多
//    for (int i = l; i <= r; ++i) {
//        tp[i] = p[i];
//    }
//    sort(tp + 1 + l,tp + 1 + r,compy);
//
//    for (int j = l; j <= r; ++j) {
//        for (int i = j+1; i <= r; ++i) {
//            if (tp[i].y - tp[j].y < d && tp[i].y - tp[j].y < ans)
//                ans = min(ans,dist(tp[j],tp[i]));
//            else
//                break;
//        }
//    }

    //TLE 思考此处为啥TLE
//    for (int k = mid + 1; k <= r; ++k) {
//        tp[k] = p[k];
//    }
//    sort(tp+1+mid+1,tp+1+r,compy);
//
//    for (int i = l; i <= mid; ++i) {
//        for (int j = mid + 1; j <= r; ++j) {
//            if (fabs(p[i].y - tp[j].y) < d) {
//                ans = min(ans, dist(p[i], p[j]));
//            }
//        }
//    }

//思考此处为啥TLE
//    for (int i = l; i <= mid; ++i) {
//        for (int j = mid + 1; j <= r; ++j) {
//            if (fabs(p[i].y - p[j].y) <= d) {
//                ans = min(ans, dist(p[i], p[j]));
//            }
//        }
//    }
    return min(ans,d);
}

int main() {
//    cin >> n;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
//        cin >> p[i].x >> p[i].y;
        scanf("%lf %lf",&p[i].x,&p[i].y);
    }
    sort(p + 1,p + n + 1,compx);
    double ans = fun(1,n);
//    cout << ans << endl;
    printf("%.4f\n",ans);
    return 0;
}