#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <cstring>
#define ll long long
using namespace std;


//问题1:第一次错误的使用一个自增变量企图记录搜索的层数,但是每一层有多个节点,每个节点应该搜多次,此时自增变量依然会自增,应该在每个节点中记录节点所在层数!
//问题2:第一次错误:双重循环里使用了break,导致没有结束循环,因此wa,应该使用return!!!!
//开始的代码写的很渣,很多冗余代码。
//发现一个bug:在debug时,队列,双端队列等使用pop操作,在watch窗口pop掉的看起来都是最后一个元素,但是程序实际运行起来又是按照真正的pop运行的

string Sstart,Send = "123804765";
const int strLen = 9;

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


int move(int op){
    int zeroIndex;
    for (int i = 1; i <= 9; ++i) {
        if(1 == ans[i]) {
            zeroIndex = i;
            break;
        }
    }
    int tmpIndex,flag = 0;
    int tmpCantorMove;

    if(zeroIndex > 3 && 1 == op){
        tmpIndex = zeroIndex - 3;
        flag = 1;
    }
    if(zeroIndex <= 6 && 2 == op){
        tmpIndex = zeroIndex + 3;
        flag = 1;
    }
    if( ((zeroIndex % 3) != 1) && 3 == op){
        tmpIndex = zeroIndex - 1;
        flag = 1;
    }
    if( ((zeroIndex % 3) != 0) && 4 == op){
        tmpIndex = zeroIndex + 1;
        flag = 1;
    }
    if(flag){
        swap(ans[tmpIndex],ans[zeroIndex]);
        tmpCantorMove = cantor(ans, 9);
        swap(ans[tmpIndex],ans[zeroIndex]);
        return tmpCantorMove;
    } else {
        return -1;
    }
}
struct Node{
    int num;
    int key;
    Node(){}
    Node(int n,int k):num(n),key(k){}
};

int visited[400000];
int main() {

    init();
    int startCantor = cantor(startNum,9);//初始状态
    int endCantor = cantor(endNum,9);//目标状态

    queue <Node> q;
    q.push(Node(1,startCantor));
    visited[startCantor] = 1;
    Node tmp;

    while (!q.empty()){
        tmp = q.front();
        q.pop();
        inverseCantor(9,tmp.key);//更新了ans;
        for (int i = 1; i <= 4; ++i) {
            int tmpCantor = move(i);
            if(tmpCantor > 0 && 0 == visited[tmpCantor]) {
                if (endCantor == tmpCantor) {
                    cout << tmp.num << endl;
                    return 0;
                }
                q.push(Node(tmp.num+1,tmpCantor));
                visited[tmpCantor] = 1;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
