#include <iostream>
#include <set>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

int startNode = 12345678,endNode;
const int len = 8;
int exparr[10];

void init(){
    int tmp = 1;
    for (int i = 7; i >= 0; --i) {
        exparr[i] = tmp;
        tmp *= 10;
    }
}

int arr2Int(int arr[]){
    int num = 0;
    for (int i = 0; i < len; ++i) {
        num += arr[i] * exparr[i];
    }
    return num;
}

int* int2Arr(int n){
    int *arr;
    arr = (int *)malloc(sizeof(int)*len);
    for (int i = 0; i < len; ++i) {
        arr[i] = n / exparr[i];
        n %= exparr[i];
    }
    return arr;
}

int move(int* stateArr,int op){
    int tmpArr[10];
    int ret;
    switch (op){
        case 0:
            for (int i = 0; i < len; ++i) {
                tmpArr[i] = stateArr[len - i - 1];
            }
            ret = arr2Int(tmpArr);
            break;
        case 1:
            tmpArr[0] = stateArr[3];
            tmpArr[len-1] = stateArr[4];
            for (int j = 1; j <= 3; ++j) {
                tmpArr[j] = stateArr[j - 1];
            }
            for (int k = 4; k < len - 1; ++k) {
                tmpArr[k] = stateArr[k + 1];
            }
            ret = arr2Int(tmpArr);
            break;
        case 2:
            for (int l = 0; l < len; ++l) {
                tmpArr[l] = stateArr[l];
            }
            tmpArr[1] = stateArr[6];
            tmpArr[2] = stateArr[1];
            tmpArr[5] = stateArr[2];
            tmpArr[6] = stateArr[5];
            ret = arr2Int(tmpArr);
            break;
    }
    return ret;
}



struct Node{
    int level,states;
    int op;
    Node(){}
    Node(int ll,int ss,int oop):level(ll),states(ss),op(oop){}
};
struct traceNode{
    int nextIndex;
    char op;
    traceNode(){}
    traceNode(int nn,char oop):nextIndex(nn),op(oop){}
};
traceNode trace[10000000];
char alphabet[3] = {'A','B','C'};
set <int> visit;
queue <Node> q;

void printTrace(int n){
    stack <char> stk;
    while (n > -1){
        stk.push(trace[n].op);
        n = trace[n].nextIndex;
    }
    int printnum = 1;
    while (!stk.empty()){
        if(printnum == 61) {
            printnum = 1;
            cout << endl;
        }
        cout << stk.top();
        stk.pop();
        printnum++;
    }
}

int main() {
    init();
    int a[10];
    for (int i = 0; i < len; ++i) {
        cin >> a[i];
    }
    endNode = arr2Int(a);

    int *endArr,*startArr;
    endArr = int2Arr(endNode);
    startArr = int2Arr(startNode);
    if(endNode == startNode){
        cout << 0 << endl;
        return 0;
    }

    int t = 0;
    trace[t] = traceNode(-1,'D');//下标查找,值为操作符
    q.push(Node(0,startNode,-1));
    visit.insert(startNode);


    Node tmpNode;
    int traceIndex = 0;
    while (!q.empty()){
        tmpNode = q.front();
        q.pop();
        traceIndex = tmpNode.op;
        for (int i = 0; i < 3; ++i) {

            int* currStatesArr = int2Arr(tmpNode.states);
            int tmpStates = move(currStatesArr,i);
            if(tmpStates == endNode){
                t++;
                cout << tmpNode.level + 1 << endl;
                trace[t] = traceNode(traceIndex,alphabet[i]);
                printTrace(t);
                return 0;
            }
            if(visit.count(tmpStates) == 0){
                t++;
                trace[t] = traceNode(traceIndex,alphabet[i]);
                q.push(Node(tmpNode.level + 1,tmpStates,t));
                visit.insert(tmpStates);
            }
        }
    }
    return 0;
}