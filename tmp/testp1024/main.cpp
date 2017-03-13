#include <stdio.h>
double a,b,c,d;

double f(double x){
    return a*x*x*x + b*x*x +c*x+d;
}
int main() {
    double eps = 1e-6;
    double ans[3];
    double start = -100;
    double end = 100;
    double l = start;
    double r = l+1;
    int  i = 0;
    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
    while(l < end && i<3){
        double fl = f(l);//左端点的函数值
        double fr = f(r);//右端点的函数值
        if((fl*fr)<= eps){//fl*fr<=0
            double lx = l,rx = r;
            while((rx - lx)>eps){//二分求解
                double mid = (lx + rx)/2.0;
                double flx = f(lx),frx=f(rx);
                double  fm = f(mid);
                if((flx*fm)>eps&&(frx*fm)<-eps)
                    lx = mid;
                else if((flx*fm)<-eps&&(frx*fm)>eps)
                    rx = mid;
                else{
                    if(flx>-eps&&flx<eps) {
                        ans[i++] = lx;
                        break;
                    }else if(frx>-eps&&frx<eps)
                        break;
                    else {
                        ans[i++] = mid;
                        break;
                    }

                }
            }
            if((rx-lx)<eps){
                ans[i++] = (lx+rx)/2.0;
            }

        }
        l++;
        r=l+1;
    }
    for (int j = 0; j < 3 ; ++j) {
        printf("%.2f ",ans[j]);
    }

    return 0;
}