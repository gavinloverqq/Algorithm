//同一个类重载了两次运算符错误问题!!!
/*
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

double totdist,costOil,oil2Distance,price4Oil,totCost;
int n;

struct gasTation{
    double dist,p;
    int i;
    gasTation(){}
    gasTation(double dd, double pp,int ii):dist(dd),p(pp),i(ii){}

    bool operator() (gasTation a,gasTation b){
        return a.p > b.p;
    }
};

bool comp (gasTation a,gasTation b){
    return a.dist < b.dist;
}

gasTation station[110];

priority_queue <gasTation,vector <gasTation>, gasTation()>  pq;
int main() {
//    cin >> totdist >> costOil >> oil2Distance >> price4Oil >> n;
    station[0] = gasTation(0,costOil,0);//初始点
    double d,p;
    for (int i = 1; i <= n; ++i) {
        cin >> d >> p;
        station[i] = gasTation(d,p,i);
    }
    sort(station,station + n + 1,comp);
    double rule = costOil * oil2Distance;
    gasTation tmp = station[0];
    int longerStation = 0;
    double startDist = 0;
    for (int j = 0; j <= n; ++j) {
        for (int i = tmp.i; i <= n; ++i) {
            if(station[i].dist <= tmp.dist + rule){
                pq.push(station[i]);
                longerStation = i;
            }
        }
        if(pq.empty()){//有待判断终点问题
            cout << "No Solution" << endl;
            return 0;
        }
        if(tmp.p > pq.top()){
            totCost += (pq.top().dist - startDist) / oil2Distance * tmp.p;
            tmp = pq.top();
            startDist = tmp.dist;
        } else {
            if(startDist + rule >= totdist){
                totCost += (totdist - startDist) / oil2Distance * tmp.i;
                printf("%.2lf\n",totdist + 0.5);
                return 0;
            }
            totCost += rule / oil2Distance * tmp.i;
            startDist = rule + tmp.dist;
            tmp = station[longerStation];
        }
        while (!pq.empty())
            pq.pop();
    }
    return 0;
}*/
/***********************************************
本题使用贪心法
每次到的加油站为一个独立状态。从当前加油站往后看,只有3种情况:
 1、加满油往后走不能达到任何加油站:无解
 2、加满油所能到达的后面加油站有邮费低于当前加油站的:加恰好到达那个加油站的油
 3、加满油所能到达的所有加油站邮费均高于当前加油站:在当前加油站加满油,跑到最后一个加油站再补加一次油(递归),同时在补加油的加油站起点要选到后面一点,因为到补加油站邮箱还有便宜的油
************************************************/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;

double totdist,costOil,oil2Distance,price4Oil,totCost;
int n;

struct gasTation{
    double dist,p;
    int i;
    gasTation(){}
    gasTation(double dd, double pp,int ii):dist(dd),p(pp),i(ii){}
};

bool operator < (gasTation a,gasTation b){
    return a.p > b.p;
}

bool comp (gasTation a,gasTation b){
    return a.dist < b.dist;
}

gasTation station[110];

priority_queue <gasTation>  pq;
int main() {
    cin >> totdist >> costOil >> oil2Distance >> price4Oil >> n;
    station[0] = gasTation(0,price4Oil,0);//初始点
    double d,p;
    for (int i = 1; i <= n; ++i) {
        cin >> d >> p;
        station[i] = gasTation(d,p,i);
    }
    sort(station,station + n + 1,comp);
    station[n+1] = gasTation(totdist,1000000000,n + 1);//初始点
    double rule = costOil * oil2Distance;
    gasTation tmp = station[0];
    int longerStation = 0;
    double startDist = 0;
    for (int j = 0; j <= n + 3; ++j) {
        int tmpMinStation = 0,flag = 0;
        for (int i = tmp.i + 1; i <= n + 1; ++i) {
            if(station[i].dist > tmp.dist + rule)
                break;
            pq.push(station[i]);
            longerStation = i;
            if(tmp.p > station[i].p && flag == 0){
                tmpMinStation = i;
                flag = 1;
            }
        }
        if(pq.empty()){//无解
            cout << "No Solution" << endl;
            return 0;
        }

        if(tmp.p > pq.top().p){

            totCost += (station[tmpMinStation].dist - startDist) / oil2Distance * tmp.p;
//            tmp = pq.top();
            tmp = station[tmpMinStation];
            startDist = tmp.dist;
        } else {
            if(startDist + rule >= totdist){
                totCost += (totdist - startDist) / oil2Distance * tmp.p;
                printf("%.2lf\n",totCost);
                return 0;
            }
            totCost += rule / oil2Distance * tmp.p;
            startDist = rule + tmp.dist;
            longerStation = pq.top().i;
            tmp = station[longerStation];
        }
        while (!pq.empty())
            pq.pop();
    }
}