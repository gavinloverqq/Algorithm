#include <iostream>

using namespace std;
int q,ans;

//给出q,找出最小的N,要求N的阶乘里含有q个零。q满足q = N/5 + N/(5^2) + N/(5^3) + ........
//N/5把所有含有5的因子去掉,其中含有5^2的项还会剩下一个5,再次统计5^2项有多少个,就计算出了第一次计算剩下的5.
//把上面的式子化开比较好理解1*2*3*。。。。。*5*。。。。。9*10(2*5)*。。。。。。(3*5)。。。(4*5)。。。(5*5)。。。。。。。。。。
int find(int q){
    int i = 0,j = 0,sum = 0;
    while (sum < q){
        i += 5;//只有5的倍数里含有5,枚举5的倍数
        j = 0;//统计当前这个i里有几个5的因子
        int t = i;
        while (t){
            if(t < 5)
                break;
            t /= 5;
            j++;
        }
        sum += j;//所有因子数加起来
    }
    return sum == q ? i : -1;
}


//按上面的公式计算
int findZero(int q){
    int i = 0;
    while (i < 5*q) {
        i += 5;
        int tmp = i;
        int count = 0;
        while (tmp){
            count += tmp/5;
            tmp /= 5;
        }
        if(count == q) {
            return i;
        }
    }
    return -1;
}


// 1, 5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125
long long findZeroP2388(int q){
    long long sum = 0,i;
    for (i = 0; i <= q; i += 5) {
        sum += (i/5+i/25+i/125+i/625+i/3125+i/15625+i/78125+i/390625+i/1953125+i/9765625+i/48828125)*5;
    }
    for (int j = q + 1; j < i; ++j) {
        sum -= (j/5+j/25+j/125+j/625+j/3125+j/15625+j/78125+j/390625+j/1953125+j/9765625+j/48828125);
    }
    return sum;
}

int findZeroP23881(int q){
    int sum = 0,count = 0;
    while (q > 4){
        int tmp = q;
        count = 0;
        while (tmp){
            count += tmp / 5;
            tmp /= 5;
        }
        sum += count;
        q--;
    }
    return sum;
}


int findHeadNum(int n){
    
}

int main() {


//    int i = 1;
//    while (i <=  1e8){
//        cout << i << ", ";
//        i *= 5;
//    }

    cin >> q;
//    int ans2 = findZeroP23881(q);
    cout << findZero(q) << endl;

    return 0;
}