#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <cstring>
#define ll long long
using namespace std;

string Sstart,Send = "123804765";
const int strLen = 9;
int fn;

//状态由字符串转化成数组;
int startNum[110],endNum[110];
void turn(string S){
    for (int i = 0; i < S.length(); ++i) {
        startNum[i+1] = S[i] - '0' + 1;//排列从下标1开始,并且每个数加1,变成123456789
    }
}

//计算阶乘
int factorial[100];

void init(){

    int tmp = 1;
    for (int j = 1; j < 10; ++j) {
        tmp *= j;
        factorial[j] = tmp;
    }

    cin >> Sstart;
    turn(Send);
    for (int i = 0; i < Sstart.length(); ++i) {
        endNum[i+1] = startNum[i+1];
    }
    turn(Sstart);
}

//康托展开
//给定一个排列,返回是第几个排列
int cantor(int arr[],int n){
    int MinNum = 0,crrIndex = 1;
    int ans = 0;

    //计算阶乘
//    int factorial[40000],tmp = 1;
//    for (int j = 1; j < n; ++j) {
//        tmp *= j;
//        factorial[j] = tmp;
//    }

    //康托展开
    while (crrIndex < n) {
        MinNum = 0;
        for (int i = crrIndex + 1; i <= n; ++i) {
            if (arr[crrIndex] > arr[i])
                MinNum++;
        }
        ans += MinNum * factorial[n - crrIndex];
        crrIndex++;
    }
    return ans + 1;

}

//康托逆展开
//给定一个数crrIndex,返回这个数的排列
int ans[110];
int tmpAns[110];
void inverseCantor(int n,int crrIndex){
    int used[400000];
    memset(used,0, sizeof(used));
    crrIndex--;

    //计算阶乘
//    int factorial[400000],tmp = 1;
//    for (int j = 1; j < n; ++j) {
//        tmp *= j;
//        factorial[j] = tmp;
//    }

    factorial[0] = 1;//避免除0;到了最后一个数,crrIndex肯定为0,因此minIndex = 0,num = 1;然后看前面哪个数没用过,直接拿来用就行了

    int minIndex = 0;
    int num = 0;
    for (int i = 1; i <= n; ++i) {

        minIndex = crrIndex / factorial[n-i];
        num = minIndex + 1;
        for (int j = 1; j <= n; ++j) {
            if(1 == used[j] && num >= j)
                num++;
        }
        ans[i] = num;
        tmpAns[i] = num;
        used[num] = 1;
        crrIndex = crrIndex % factorial[n-i];
    }
}


int calculateF(){
    int num = 0;
    int tmpans[11] = {0,2,3,4,9,1,5,8,7,6};
    for (int i = 1; i <= 9; ++i) {
        if(ans[i] != tmpans[i] && ans[i] != 1)
            num++;
    }
    return num;
}

int move(int op){

    int zeroIndex = 0;
    for (int i = 1; i <= 9; ++i) {
        if(1 == ans[i]) {
            zeroIndex = i;
            break;
        }
    }
    int tmpIndex = 0;
    int tmpCantorMove;

    if(zeroIndex > 3 && 1 == op){
        tmpIndex = zeroIndex - 3;
        swap(ans[tmpIndex],ans[zeroIndex]);
        fn = calculateF();
        tmpCantorMove = cantor(ans, 9);
        swap(ans[tmpIndex],ans[zeroIndex]);
        return tmpCantorMove;
    }
    if(zeroIndex <= 6 && 2 == op){
        tmpIndex = zeroIndex + 3;
        swap(ans[tmpIndex],ans[zeroIndex]);
        fn = calculateF();
        tmpCantorMove = cantor(ans, 9);
        swap(ans[tmpIndex],ans[zeroIndex]);
        return tmpCantorMove;
    }
    if( ((zeroIndex % 3) != 1) && 3 == op){
        tmpIndex = zeroIndex - 1;
        swap(ans[tmpIndex],ans[zeroIndex]);
        fn = calculateF();
        tmpCantorMove = cantor(ans, 9);
        swap(ans[tmpIndex],ans[zeroIndex]);
        return tmpCantorMove;
    }
    if( ((zeroIndex % 3) != 0) && 4 == op){
        tmpIndex = zeroIndex + 1;
        swap(ans[tmpIndex],ans[zeroIndex]);
        fn = calculateF();
        tmpCantorMove = cantor(ans, 9);
        swap(ans[tmpIndex],ans[zeroIndex]);
        return tmpCantorMove;
    }
    return -1;
}

struct Node{
    int num;
    int key;
    int f;
    Node(){}
    Node(int n,int k,int ff):num(n),key(k),f(ff){}
};

bool operator < (Node a,Node b){
    return a.f > b.f;
}

int visited[400000];
int main() {
    init();
    int startCantor = cantor(startNum,9);//初始状态
    int endCantor = cantor(endNum,9);//目标状态

    priority_queue <Node> q;
    inverseCantor(9,startCantor);//更新了ans;

    fn = calculateF();
    q.push(Node(1,startCantor,fn));
    visited[startCantor] = 1;
    int ret = 0;
    Node tmp;
    while (!q.empty()){
        tmp = q.top();
        q.pop();
        inverseCantor(9,tmp.key);//更新了ans;
        ret++;
        for (int i = 1; i <= 4; ++i) {
            int tmpCantor = move(i);
            if(tmpCantor > 0) {
                if (endCantor == tmpCantor) {
                    cout << tmp.num << endl;
                    return 0;
                }
                if (0 == visited[tmpCantor]) {
                    q.push(Node(tmp.num+1,tmpCantor,fn));
                    visited[tmpCantor] = 1;
                }
            }
        }
    }
    return 0;
}