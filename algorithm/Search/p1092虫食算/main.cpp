/*
#include <iostream>
#include <string>
using namespace std;
int N;
string equ[1],equ[2],equ[3];
//int alpha2Num[30] = {1,0,3,4,2};//下标是字母序,值是对于数字
int alpha2Num[30];//下标是字母序,值是对于数字
int used[30];
*/
/*
8
ABDEBEHG
FGDBBAGB
EDEDCHGE
2 1 3 7 6 4 5 0
*//*

int str2Num(string s){
    int num = 0,tmp = 1;
    for (int i = s.length() - 1; i >= 0; --i) {
        num += alpha2Num[s[i]-'A'] * tmp;
        tmp *= N;
    }
    return num;
}

bool check(){
    int num1,num2,num3;
    int tmp;
    num1 = str2Num(equ[1]);
    num2 = str2Num(equ[2]);
    num3 = str2Num(equ[3]);
    tmp = num1 + num2;
    return (tmp == num3);
}

void dfs(int n){
    if(n >= N){
        if(check()){
            for (int i = 0; i < N; ++i) {
                cout << alpha2Num[i] << " ";
            }
        }
        return;
    } else {
        for (int i = 0; i < N; ++i) {
            if(used[i] == 0){
                used[i] = 1;
                alpha2Num[i] = n;
                dfs(n+1);
                used[i] = 0;
            }
        }
    }
}

int main() {
    cin >> N >> equ[1] >> equ[2] >> equ[3];
    dfs(0);
    return 0;
}*/

/*#include <iostream>
#include <string>
using namespace std;
int N;
string equ[1],equ[2],equ[3];
//int alpha2Num[30] = {1,0,3,4,2};//下标是字母序,值是对于数字
int alpha2Num[30];//下标是字母序,值是对于数字
int used[30];

*//*
8
ABDEBEHG
FGDBBAGB
EDEDCHGE
2 1 3 7 6 4 5 0
15
MFJCGKNDHBALEIO
EBIKIDBMAEELHBC
KGEAOHOJHFFIACJ
0 1 10 7 3 4 6 12 8 9 5 11 2 13 14
*//*

//注意搜索之后状态的还原
//注意加法进位之后处理

int str2Num(string s){
    int num = 0,tmp = 1;
    for (int i = s.length() - 1; i >= 0; --i) {
        num += alpha2Num[s[i]-'A'] * tmp;
        tmp *= N;
    }
    return num;
}

bool check(){
    int num1,num2,num3;
    int tmp;
    num1 = str2Num(equ[1]);
    num2 = str2Num(equ[2]);
    num3 = str2Num(equ[3]);
    tmp = num1 + num2;
    return (tmp == num3);
}

bool check2(){
    //逐位测试
    int tmp1[30],tmp2[30],tmp3[30];//算式中每一位对应的数字
    for (int i = 0; i < N; ++i) {
        tmp1[i] = alpha2Num[equ[1][i]-'A'];
        tmp2[i] = alpha2Num[equ[2][i]-'A'];
        tmp3[i] = alpha2Num[equ[3][i]-'A'];
    }
    for (int j = N - 1; j >= 0; --j) {
        if(tmp1[j] != -1 && tmp2[j] != -1 && tmp3[j] != -1){
//            if((tmp1[j] + tmp2[j]) % N != tmp3[j] && (tmp1[j] + tmp2[j]) % N != (tmp3[j] - 1))
            if(j == N-1 && (tmp1[j] + tmp2[j]) % N != tmp3[j])
                return true;
            if(j == 0 && (tmp1[j] + tmp2[j]) > N - 1)
                return true;
            if((tmp1[j] + tmp2[j]) % N != tmp3[j] && (tmp1[j] + tmp2[j] + 1) % N != (tmp3[j]))
                return true;
        }
    }
    return false;
}
void dfs(int n){
    if(n >= N){
        if(check()){
            for (int i = 0; i < N; ++i) {
                cout << alpha2Num[i] << " ";
            }
        }
        return;
    } else {
        for (int i = 0; i < N; ++i) {
//            if(n >= 3 && check2()) {
//                return;
//            }
            if(used[i] == 0 ){
                used[i] = 1;
                alpha2Num[i] = n;
                if(check2()) {
                    alpha2Num[i] = -1;
                    used[i] = 0;
                    continue;
                }
                dfs(n+1);
                alpha2Num[i] = -1;
                used[i] = 0;
            }
        }
    }
}

int main() {
    cin >> N >> equ[1] >> equ[2] >> equ[3];
    for (int i = 0; i < 30; ++i) {
        alpha2Num[i] = -1;
    }
    dfs(0);
    return 0;
}*/
/*

#include <iostream>
#include <string>
using namespace std;
int N;
string equ[3];
int alpha2Num[30];//下标是字母序,值是对于数字
int used[30];


int str2Num(string s){
    int num = 0,tmp = 1;
    for (int i = s.length() - 1; i >= 0; --i) {
        num += alpha2Num[s[i]-'A'] * tmp;
        tmp *= N;
    }
    return num;
}

bool check(){
    int num[3];
    int tmp;
    for (int i = 0; i < 3; ++i) {
        num[i] = str2Num(equ[i]);
    }
    return (num[1] + num[0] == num[3]);
}

void dfs(int n,int m){
    if(n < 0){
        if(check())
            for (int i = 0; i < N; ++i) {
                cout << alpha2Num[i] << " ";
            }
        return;
    } else {//自右至左
//        for (int j = 0; j < 2; ++j) {
            for (int i = 0; i < N; ++i) {
                if(used[i] == 0){
                    alpha2Num[equ[0][n] - 'A'] = i;
                    used[i] = 1;
                    for (int j = 0; j < N; ++j) {
                        if(used[j] == 0){
                            alpha2Num[equ[1][n] - 'A'] = j;
                            used[j] = 1;
                            int tmp = m + alpha2Num[equ[1][n] - 'A'] + alpha2Num[equ[0][n] - 'A'];
                            int ansEqu = tmp % N;
                            if(alpha2Num[equ[2][n] - 'A'] == -1 && used[ansEqu] == 0) {
                                used[ansEqu] = 1;
                                alpha2Num[equ[2][n] - 'A'] = ansEqu;
                                dfs(n-1,tmp == ansEqu ? 0 : 1);
                                used[ansEqu] = 0;
                                alpha2Num[equ[2][n] - 'A'] = -1;
                            } else {
                                if(alpha2Num[equ[2][n] - 'A'] == ansEqu && used[ansEqu] == 1){
                                    dfs(n-1,tmp == ansEqu ? 0 : 1);
                                    used[ansEqu] = 0;
                                    alpha2Num[equ[2][n] - 'A'] = -1;
                                }
//                            else{
//                                for (int i = 0; i < 3; ++i) {
//
//                                }
//                                continue;
//                            }
                            }
                            used[alpha2Num[equ[1][n] - 'A']] = 0;
                            alpha2Num[equ[1][n] - 'A'] = -1;
                        }
                    }
                    alpha2Num[equ[0][n] - 'A'] = -1;
                    used[i] = 0;
                }


            }


    }
}


int main(){
    cin >> N;
    for (int i = 0; i < 3; ++i) {
        cin >> equ[i];
    }
    for (int j = 0; j < 30; ++j) {
        alpha2Num[j] = -1;
    }
    dfs(N-1,0);
}*/


//对于这种bool dfs()还是没掌握的很好,比如dfs最底下是应该return true还是false ,还有
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
int N;
string equ[4];
//int alpha2Num[30] = {1,0,3,4,2};//下标是字母序,值是对于数字
int alpha2Num[30];//下标是字母序,值是对于数字
int used[30];
int searchStr[30];

/*
8
ABDEBEHG
FGDBBAGB
EDEDCHGE
2 1 3 7 6 4 5 0
15
MFJCGKNDHBALEIO
EBIKIDBMAEELHBC
KGEAOHOJHFFIACJ
0 1 10 7 3 4 6 12 8 9 5 11 2 13 14
*/


//注意搜索之后状态的还原
//注意加法进位之后处理

int str2Num(string s){
    int num = 0,tmp = 1;
    for (int i = s.length() - 1; i >= 0; --i) {
        num += alpha2Num[s[i]-'A'] * tmp;
        tmp *= N;
    }
    return num;
}

bool check(){
    int num1,num2,num3;
    int tmp;
    num1 = str2Num(equ[1]);
    num2 = str2Num(equ[2]);
    num3 = str2Num(equ[3]);
    tmp = num1 + num2;
    return (tmp == num3);
}

bool check2(){
    //逐位测试
    if(alpha2Num[equ[1][N-1] - 'A'] != -1 && alpha2Num[equ[3][N-1] - 'A'] != -1 && alpha2Num[equ[2][N-1] - 'A'] != -1){
        if((alpha2Num[equ[1][N-1] - 'A'] + alpha2Num[equ[2][N-1] - 'A']) % N != alpha2Num[equ[3][N-1] - 'A'])
            return true;
    }
    if(alpha2Num[equ[1][0] - 'A'] != -1 && alpha2Num[equ[3][0] - 'A'] != -1 && alpha2Num[equ[2][0] - 'A'] != -1){
        if((alpha2Num[equ[1][0] - 'A'] + alpha2Num[equ[2][0] - 'A']) >= N)
            return true;
    }
    for (int i = 1; i < N-1; ++i) {
        if(alpha2Num[equ[1][i] - 'A'] != -1 && alpha2Num[equ[3][i] - 'A'] != -1 && alpha2Num[equ[2][i] - 'A'] != -1){
            if((alpha2Num[equ[1][i] - 'A'] + alpha2Num[equ[2][i] - 'A']) % N != alpha2Num[equ[3][i] - 'A']  &&  (alpha2Num[equ[1][i] - 'A'] + alpha2Num[equ[2][i] - 'A'] + 1) % N != alpha2Num[equ[3][i] - 'A'])
                return true;
        }
    }
    return false;
}
bool dfs(int n){
    if(n >= N){
        if(check()){
            for (int i = 0; i < N; ++i) {
                cout << alpha2Num[i] << " ";
            }
            exit(0);
        }
        return false;
    } else {
        if(check2())
            return false;
        for (int i = 0; i < N; ++i) {
            if(used[searchStr[n]] == 0 ){
                used[searchStr[n]] = 1;
                alpha2Num[searchStr[n]] = i;
                if(dfs(n+1))//为什么要判断真,如果写成if(!dfs(n+1))return false就是错的!,如果return false 则此次循环之后的可能性就遍历不了了
                    return true;
                alpha2Num[searchStr[n]] = -1;
                used[searchStr[n]] = 0;
            }
        }
    }
    return false;
}

int main() {
    cin >> N >> equ[1] >> equ[2] >> equ[3];
    bool alphabetUsed[30];
    for (int i = 0; i < 30; ++i) {
        alpha2Num[i] = -1;
        alphabetUsed[i] = 0;
    }
    int index  = 0;
    for (int j = N-1; j >= 0; --j) {
        for (int i = 1; i <= 3; ++i) {
           if(alphabetUsed[equ[i][j] - 'A'] == 0){
               alphabetUsed[equ[i][j] - 'A'] = 1;
               searchStr[index++] = equ[i][j] - 'A';
           }
        }
    }
    dfs(0);
    return 0;
}



