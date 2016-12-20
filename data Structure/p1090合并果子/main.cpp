#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 1<<30
using namespace std;

/*
 * STL实现
int n;
struct Node{
    int a;
    Node(){}
    Node(int aa):a(aa){}
};
bool operator < (Node a,Node b){
    return a.a > b.a;
}
int main() {
    cin >> n;
    priority_queue < Node >  pq;
    Node tmp;
    for (int i = 1; i <= n; ++i) {
        cin >> tmp.a;
        pq.push(tmp);
    }
    if (1 == n) cout << tmp.a;
    int a,b,sum = 0;
    while (pq.size() > 1){
        a = pq.top().a;
        pq.pop();
        b = pq.top().a;
        pq.pop();
        sum += a+b;
        pq.push(Node(a+b));
    }
    cout << sum << endl;
    return 0;
}*/

int main(){
    int n,a[10010];
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    int b[10010],sum  = 0;
    int head = 1,tail = n,start = 1,end = 0;
    if (1 == n) cout << a[1];
    while (tail > head){
        int tmp[5];
        tmp[1] = a[head];
        tmp[2] = a[head+1];
        tmp[3] = INF,tmp[4] = INF;
        for (int i = 0;end >= start && i < 2;i++){
            tmp[3+i] = b[head + i];
//            tmp4 = b[head+1];
        }
        if(tmp[3] > tmp[2]){
            sum += tmp[1] + tmp[2];
            b[++end] = sum;
            head += 2;
        }
        if(tmp[1] > tmp[4]){
            sum += tmp[2] + tmp[3];
            b[++end] = sum;
            start += 2;
        }
        if(((tmp[1] < tmp[3] && tmp[3] < tmp[2]) || (tmp[3] < tmp[1] && tmp[1] < tmp[4]))){
            sum += tmp[1] + tmp[3];
            b[++end] = sum;
            start++;
            head++;
        }
    }
    if(start <= end && head <= tail){
        sum += a[head] + b[start];
    }
    cout << sum << endl;

}