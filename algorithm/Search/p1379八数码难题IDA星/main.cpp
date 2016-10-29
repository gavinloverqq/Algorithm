/*#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

const int len = 9;
string start,end = "123804765";
int exp[10];
int visited[900000];
int limit = -1;
const int sMax = 100;

void exparr(){
    int num = 1;
    for (int i = len - 1; i >= 0; --i) {
        exp[i] = num;
        num *= 10;
    }
}


//计算阶乘
int factorial[100];

void init(){

    exparr();
    cin >> start;
    int tmp = 1;
    for (int j = 1; j < 10; ++j) {
        tmp *= j;
        factorial[j] = tmp;
    }
}

//康托展开
//给定一个排列,返回是第几个排列
int cantor(int arr[]){
    int MinNum = 0,crrIndex = 0;
    int ans = 0;

    //计算阶乘
//    int factorial[40000],tmp = 1;
//    for (int j = 1; j < n; ++j) {
//        tmp *= j;
//        factorial[j] = tmp;
//    }

    //康托展开
    while (crrIndex < len) {
        MinNum = 0;
        for (int i = crrIndex + 1; i < len; ++i) {
            if (arr[crrIndex] > arr[i])
                MinNum++;
        }
        ans += MinNum * factorial[len - crrIndex - 1];
        crrIndex++;
    }
    return ans + 1;

}

//康托逆展开
//给定一个数crrIndex,返回这个数的排列
int* inverseCantor(int crrIndex){
    int used[10];
//    memset(used,0, sizeof(used));
    for (int k = 0; k < len; ++k) {
        used[k] = -1;
    }
    crrIndex--;

    int *ans = (int *)malloc(sizeof(int)*10);
    //计算阶乘
//    int factorial[400000],tmp = 1;
//    for (int j = 1; j < n; ++j) {
//        tmp *= j;
//        factorial[j] = tmp;
//    }

    factorial[0] = 1;//避免除0;到了最后一个数,crrIndex肯定为0,因此minIndex = 0,num = 1;然后看前面哪个数没用过,直接拿来用就行了

    int minIndex = 0;
    int num = 0;
    for (int i = 0; i < len; ++i) {
        minIndex = crrIndex / factorial[len - i - 1];
        num = minIndex;//此处为何加1为何不加1
        for (int j = 0; j < len; ++j) {
            if(1 == used[j] && num >= j)
                num++;
        }
        ans[i] = num;
        used[num] = 1;
        crrIndex = crrIndex % factorial[len - i - 1];
    }
    return ans;
}


int str2Num(string s){//字符串变数字
    int ret = 0;
    for (int i = 0; i < len; ++i) {
        ret += (s[i] - '0') * exp[i];
    }
    return ret;
}

int arr2Num(int *arr){//数组变数字
    int num = 0;
    for (int i = 0; i < len; ++i) {
        num += arr[i] * exp[i];
    }
    return num;
}

int* num2Str(int n){//数字边数组
    int* arr;
    arr = (int*)malloc(sizeof(int)*10);
    int index = 0;
    while (index < len){
        arr[index] = n/exp[index];
        n = n%exp[index];
        index++;
    }
    return arr;
}

int move(int i,int *arr){//返回移动后的状态
    int zeroIndex = 0,ret = -1;
    for (int j = 0; j < len; ++j) {
        if(0 == arr[j]){
            zeroIndex = j;
            break;
        }
    }
    switch (i){
        case 1://上
            if(zeroIndex > 2){
                swap(arr[zeroIndex],arr[zeroIndex-3]);
                ret = cantor(arr);
                swap(arr[zeroIndex],arr[zeroIndex-3]);
            }
            break;
        case 2://下
            if(zeroIndex < 6){
                swap(arr[zeroIndex],arr[zeroIndex+3]);
                ret = cantor(arr);
                swap(arr[zeroIndex],arr[zeroIndex+3]);
            }
            break;
        case 3://左
            if(zeroIndex % 3 != 0){
                swap(arr[zeroIndex],arr[zeroIndex-1]);
                ret = cantor(arr);
                swap(arr[zeroIndex],arr[zeroIndex-1]);
            }
            break;
        case 4://右
            if(zeroIndex % 3 != 2){
                swap(arr[zeroIndex],arr[zeroIndex+1]);
                ret = cantor(arr);
                swap(arr[zeroIndex],arr[zeroIndex+1]);
            }
            break;
    }
    return ret;
}

int calculateF(int *arr){
    int sum = 0;
    int final[10] = {1,2,3,8,0,4,7,6,5};
    for (int i = 0; i < len; ++i) {
        if(arr[i] != final[i] && final[i] != 0)
            sum++;
    }
    return sum;
}

bool dfs(int n,int *arr){
    if(n == limit){
        if(calculateF(arr) == 0)
            return true;
    }
    if(n + calculateF(arr) > limit)
        return false;
    for (int i = 1; i <= 4; ++i) {
        int tmp = move(i,arr);
        if(tmp > 0 && visited[tmp] == 0){
            visited[tmp] = 1;
            if(dfs(n + 1, inverseCantor(tmp))){
                return true;
            }
            visited[tmp] = 0;//还原
        }
    }
    return false;
}

//   283104765
int main() {

    init();
    int startNum;
    int startArr[10];

    for (int i = 0; i < len; ++i) {
        startArr[i] = start[i] - '0';
    }
    startNum = cantor(startArr);
    visited[startNum] = 1;
    limit = calculateF(startArr);

    while (limit < sMax && !dfs(1,startArr))
        limit++;
    cout << limit - 1<< endl;

    return 0;
}*/
/*
#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

const int len = 9;
string start,endstr = "123804765";
int exp[10];
const int sMax = 100;

void exparr(){
    int num = 1;
    for (int i = len - 1; i >= 0; --i) {
        exp[i] = num;
        num *= 10;
    }
}

//计算阶乘
int factorial[100];

void init(){

    exparr();
    cin >> start;
    int tmp = 1;
    for (int j = 1; j < 10; ++j) {
        tmp *= j;
        factorial[j] = tmp;
    }
}

//康托展开
//给定一个排列,返回是第几个排列
int cantor(int arr[]){
    int MinNum = 0,crrIndex = 0;
    int ans = 0;

    //计算阶乘
//    int factorial[40000],tmp = 1;
//    for (int j = 1; j < n; ++j) {
//        tmp *= j;
//        factorial[j] = tmp;
//    }

    //康托展开
    while (crrIndex < len) {
        MinNum = 0;
        for (int i = crrIndex + 1; i < len; ++i) {
            if (arr[crrIndex] > arr[i])
                MinNum++;
        }
        ans += MinNum * factorial[len - crrIndex - 1];
        crrIndex++;
    }
    return ans + 1;

}

//康托逆展开
//给定一个数crrIndex,返回这个数的排列
int* inverseCantor(int crrIndex){
    int used[10];
//    memset(used,0, sizeof(used));
    for (int k = 0; k < len; ++k) {
        used[k] = -1;
    }
    crrIndex--;

    int *ans = (int *)malloc(sizeof(int)*10);
    //计算阶乘
//    int factorial[400000],tmp = 1;
//    for (int j = 1; j < n; ++j) {
//        tmp *= j;
//        factorial[j] = tmp;
//    }

    factorial[0] = 1;//避免除0;到了最后一个数,crrIndex肯定为0,因此minIndex = 0,num = 1;然后看前面哪个数没用过,直接拿来用就行了

    int minIndex = 0;
    int num = 0;
    for (int i = 0; i < len; ++i) {
        minIndex = crrIndex / factorial[len - i - 1];
        num = minIndex;//此处为何加1为何不加1
        for (int j = 0; j < len; ++j) {
            if(1 == used[j] && num >= j)
                num++;
        }
        ans[i] = num;
        used[num] = 1;
        crrIndex = crrIndex % factorial[len - i - 1];
    }
    return ans;
}

int move(int i,int *arr){//返回移动后的状态
    int zeroIndex = 0,ret = -1;
    for (int j = 0; j < len; ++j) {
        if(0 == arr[j]){
            zeroIndex = j;
            break;
        }
    }
    switch (i){
        case 1://上
            if(zeroIndex > 2){
                swap(arr[zeroIndex],arr[zeroIndex-3]);
                ret = cantor(arr);
                swap(arr[zeroIndex],arr[zeroIndex-3]);
            }
            break;
        case 2://下
            if(zeroIndex < 6){
                swap(arr[zeroIndex],arr[zeroIndex+3]);
                ret = cantor(arr);
                swap(arr[zeroIndex],arr[zeroIndex+3]);
            }
            break;
        case 3://左
            if(zeroIndex % 3 != 0){
                swap(arr[zeroIndex],arr[zeroIndex-1]);
                ret = cantor(arr);
                swap(arr[zeroIndex],arr[zeroIndex-1]);
            }
            break;
        case 4://右
            if(zeroIndex % 3 != 2){
                swap(arr[zeroIndex],arr[zeroIndex+1]);
                ret = cantor(arr);
                swap(arr[zeroIndex],arr[zeroIndex+1]);
            }
            break;
    }
    return ret;
}

struct Node{
    int level;
    int value;
    int whoVisited;
    Node(){}
    Node(int l,int v,int isV = 0):level(l),value(v),whoVisited(isV){}
};

queue <Node> qFront;
queue <Node> qBack;
Node visited[400000];
//   283104765   123084765
//   283104765 // 4   234678105 //11

int main() {
    init();
    int startNum;
    int startArr[10];

    for (int i = 0; i < len; ++i) {
        startArr[i] = start[i] - '0';
    }
    startNum = cantor(startArr);

    int endArr[10];
    for (int j = 0; j < len; ++j) {
        endArr[j] = endstr[j] - '0';
    }
    int endNum = cantor(endArr);

    qFront.push(Node(0,startNum,1));
    qBack.push(Node(0,endNum,2));
    visited[startNum] = Node(0,startNum,1);
    visited[endNum] = Node(0,endNum,2);
    Node tmpFront,tmpBack;

    //对初始值的处理,如果没有这段代码,下面的代码是有问题的,对一开始的状态直接默认不能走到,然后就开始移动,因此如果没有下面这段初始处理,那么就会输出2
    if(startNum == endNum){
        cout << 0 << endl;
        return 0;
    }

    while (!qFront.empty() && !qBack.empty()){


        tmpBack = qBack.front();

        if(qFront.size() < qBack.size()){
            tmpFront = qFront.front();
            qFront.pop();

            int *arr = inverseCantor(tmpFront.value);
            for (int i = 1; i <= 4; ++i) {
                int canMove = move(i,arr);
                if(visited[canMove].whoVisited == 2){
                    cout << tmpFront.level + 1 + visited[canMove].level << endl;
                    return 0;
                }
                if(canMove > 0 && visited[canMove].whoVisited == 0){
                    qFront.push(Node(tmpFront.level+1,canMove,1));
                    visited[canMove] = Node(tmpFront.level+1,canMove,1);
                }
            }
        } else {
            tmpBack = qBack.front();
            qBack.pop();

            int *arr = inverseCantor(tmpBack.value);
            for (int i = 1; i <= 4; ++i) {
                int canMove = move(i,arr);
                if(visited[canMove].whoVisited == 1){
                    cout << tmpBack.level + 1 + visited[canMove].level << endl;
                    return 0;
                }
                if(canMove > 0 && visited[canMove].whoVisited == 0){
                    qBack.push(Node(tmpBack.level+1,canMove,2));
                    visited[canMove] = Node(tmpBack.level+1,canMove,2);
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}*/


/*
#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

const int len = 9;
string start,endstr = "123804765";
int exp[10];
int visited[900000];
int limit = -1;
const int sMax = 100;
int f;

void exparr(){
    int num = 1;
    for (int i = len - 1; i >= 0; --i) {
        exp[i] = num;
        num *= 10;
    }
}


//计算阶乘
int factorial[100];

void init(){
    exparr();
    cin >> start;
    int tmp = 1;
    for (int j = 1; j < 10; ++j) {
        tmp *= j;
        factorial[j] = tmp;
    }
}

//康托展开
//给定一个排列,返回是第几个排列
int cantor(int arr[]){
    int MinNum = 0,crrIndex = 0;
    int ans = 0;

    //计算阶乘
//    int factorial[40000],tmp = 1;
//    for (int j = 1; j < n; ++j) {
//        tmp *= j;
//        factorial[j] = tmp;
//    }

    //康托展开
    while (crrIndex < len) {
        MinNum = 0;
        for (int i = crrIndex + 1; i < len; ++i) {
            if (arr[crrIndex] > arr[i])
                MinNum++;
        }
        ans += MinNum * factorial[len - crrIndex - 1];
        crrIndex++;
    }
    return ans + 1;

}

//康托逆展开
//给定一个数crrIndex,返回这个数的排列
int* inverseCantor(int crrIndex){
    int used[10];
//    memset(used,0, sizeof(used));
    for (int k = 0; k < len; ++k) {
        used[k] = -1;
    }
    crrIndex--;

    int *ans = (int *)malloc(sizeof(int)*10);
    //计算阶乘
//    int factorial[400000],tmp = 1;
//    for (int j = 1; j < n; ++j) {
//        tmp *= j;
//        factorial[j] = tmp;
//    }

    factorial[0] = 1;//避免除0;到了最后一个数,crrIndex肯定为0,因此minIndex = 0,num = 1;然后看前面哪个数没用过,直接拿来用就行了

    int minIndex = 0;
    int num = 0;
    for (int i = 0; i < len; ++i) {
        minIndex = crrIndex / factorial[len - i - 1];
        num = minIndex;//此处为何加1为何不加1
        for (int j = 0; j < len; ++j) {
            if(1 == used[j] && num >= j)
                num++;
        }
        ans[i] = num;
        used[num] = 1;
        crrIndex = crrIndex % factorial[len - i - 1];
    }
    return ans;
}



int calculateF1(int *arr){
    int sum = 0;
    int final[10][2] = {{1,1},{0,0},{0,1},{0,2},{1,2},{2,2},{2,1},{2,0},{1,0}};
    for (int i = 0; i < len; ++i) {
        if(0 == arr[i])
            continue;
        int n = arr[i];
        sum += abs(i/3 - final[n][0]) + abs(i%3 - final[n][1]);
    }
    return sum;
}

int calculateF(int *arr){
    int sum = 0;
    int final[10] = {1,2,3,8,0,4,7,6,5};
    for (int i = 0; i < len; ++i) {
        if(arr[i] != final[i] && final[i] != 0)
            sum++;
    }
    return sum;
}

int move(int i,int *arr){//返回移动后的状态
    int zeroIndex = 0,ret = -1;
    for (int j = 0; j < len; ++j) {
        if(0 == arr[j]){
            zeroIndex = j;
            break;
        }
    }
    switch (i){
        case 1://上
            if(zeroIndex > 2){
                swap(arr[zeroIndex],arr[zeroIndex-3]);
                f = calculateF(arr);
                ret = cantor(arr);
                swap(arr[zeroIndex],arr[zeroIndex-3]);
            }
            break;
        case 2://下
            if(zeroIndex < 6){
                swap(arr[zeroIndex],arr[zeroIndex+3]);
                f = calculateF(arr);
                ret = cantor(arr);
                swap(arr[zeroIndex],arr[zeroIndex+3]);
            }
            break;
        case 3://左
            if(zeroIndex % 3 != 0){
                swap(arr[zeroIndex],arr[zeroIndex-1]);
                f = calculateF(arr);
                ret = cantor(arr);
                swap(arr[zeroIndex],arr[zeroIndex-1]);
            }
            break;
        case 4://右
            if(zeroIndex % 3 != 2){
                swap(arr[zeroIndex],arr[zeroIndex+1]);
                f = calculateF(arr);
                ret = cantor(arr);
                swap(arr[zeroIndex],arr[zeroIndex+1]);
            }
            break;
    }
    return ret;
}

struct Node{
    int level;
    int value;
    int f;
    Node(){}
    Node(int l,int v,int ff):level(l),value(v),f(ff){}
};
bool operator < (Node a,Node b){
    return a.f > b.f;
}

priority_queue <Node> q;



int main() {
    init();
    int startNum;
    int startArr[10];

    for (int i = 0; i < len; ++i) {
        startArr[i] = start[i] - '0';
    }
    startNum = cantor(startArr);

    int endArr[10];
    for (int j = 0; j < len; ++j) {
        endArr[j] = endstr[j] - '0';
    }
    int endNum = cantor(endArr);

    q.push(Node(0,startNum,0 + calculateF(startArr)));
    visited[startNum] = 1;
    Node tmp;
    while (!q.empty()){
        tmp = q.top();
        q.pop();
        int *tmpArr = inverseCantor(tmp.value);
        for (int i = 1; i <= 4; ++i) {
            int canMove = move(i,tmpArr);
            if(canMove == endNum){
                cout << tmp.level + 1 << endl;
                return 0;
            }
            if(canMove > 0 && visited[canMove] == 0){
                q.push(Node(tmp.level+1,canMove,tmp.level + 1 + f));
                visited[canMove] = 1;
            }
        }
    }
    cout << -1 << endl;

    return 0;
}*/



#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <set>
using namespace std;

string strStart,strEnd = "123804765";
set <string> strSet;

struct Node{
    int level;
    string value;
    Node(){}
    Node(int l,string v):level(l),value(v){}
};

queue <Node> q;

string move(string s,int op){
    int zeroIndex = 0;
    for (int i = 0; i < s.length(); ++i) {
        if(s[i] == '0'){
            zeroIndex = i;
            break;
        }
    }
    string tmp = s;
    switch (op){
        case 0:
            if(zeroIndex > 2){
                swap(tmp[zeroIndex],tmp[zeroIndex-3]);
            }
            break;
        case 1:
            if(zeroIndex < 6){
                swap(tmp[zeroIndex],tmp[zeroIndex+3]);
            }
            break;
        case 2:
            if(zeroIndex % 3 != 0){
                swap(tmp[zeroIndex],tmp[zeroIndex-1]);
            }
            break;
        case 3:
            if(zeroIndex % 3 != 2){
                swap(tmp[zeroIndex],tmp[zeroIndex+1]);
            }
            break;
    }
    return tmp;
}



int main(){
    cin >> strStart;
    if(strStart == strEnd)
        cout << 0 << endl;
    q.push(Node(0,strStart));
    strSet.insert(strStart);
    Node tmp;
    string strTmp;
    while (!q.empty()){
        tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            strTmp = move(tmp.value,i);
            if(strTmp == tmp.value)
                continue;
            if(strTmp == strEnd){
                cout << tmp.level+1 << endl;
                return 0;
            }
            if(strSet.count(strTmp) == 0){
                q.push(Node(tmp.level + 1,strTmp));
                strSet.insert(strTmp);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}