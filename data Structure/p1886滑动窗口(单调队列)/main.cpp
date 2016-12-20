#include <iostream>
//#include <deque>
#include <cstdio>
using namespace std;
struct Node{
    int index,value;
    Node(){}
    Node(int i,int v):index(i),value(v){}
};
int num[1000100];
Node qNode[1000010];
Node pNode[1000010];
int main() {
    int head = 0,tail = 0;
    int n,k;
    int id = 1;
    while (~scanf("%d%d",&n,&k)) {
//    while (cin >> n >> k){
//    scanf("%d%d",&n,&k);
        for (int i = 1; i <= n; ++i) {
//            cin >> num[i];
            scanf("%d",&num[i]);
        }


//STL实现
//    deque <Node> dq;
//    Node tmp;
//    for (int j = 1; j <= n; ++j) {
//        tmp = Node(j,num[j]);
//        while (!dq.empty() && dq.back().value >= num[j])
//            dq.pop_back();
//        dq.push_back(tmp);
//        while (!dq.empty() && dq.front().index < j - k +1)
//            dq.pop_front();
//        if(j > k-1)
//            cout << dq.front().value << " ";
//    }
//    cout << endl;
//
////    deque <Node> dq;
////    Node tmp;
//    dq.clear();
//    for (int j = 1; j <= n; ++j) {
//        tmp = Node(j,num[j]);
//        while (!dq.empty() && dq.back().value <= num[j])
//            dq.pop_back();
//        dq.push_back(tmp);
//        while (!dq.empty() && dq.front().index < j - k +1)
//            dq.pop_front();
//        if(j > k-1)
//            cout << dq.front().value << " ";
//    }
//    cout << endl;
//



        head = 1;
        tail = 0;
        for (int l = 1; l <= n; ++l) {
            Node tmp(l, num[l]);
            while (tail >= head && qNode[tail].value >= num[l])
                --tail;
            ++tail;
            qNode[tail] = tmp;
            while (qNode[head].index < l - k + 1)
//            while (tail >= head && qNode[head].index < l - k + 1)
                ++head;
            if (l > k - 1)
                cout << qNode[head].value << " ";
        }
        cout << endl;

        head = 1;
        tail = 0;

        for (int l = 1; l <= n; ++l) {
            Node tmp(l, num[l]);
            while (tail >= head && pNode[tail].value <= num[l])
                --tail;
            ++tail;
            pNode[tail] = tmp;
            while (pNode[head].index < l - k + 1)
//            while (tail >= head && pNode[head].index < l - k + 1)
                ++head;
            if (l > k - 1)
                cout << pNode[head].value << " ";
        }
        cout << endl;

    }

    return 0;
}

