/*
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

//const int maxn = 4777;// 2000多ms
const int maxn =14997;// 2000多ms
//const int maxn = 7777; //2000多ms
//const int maxn = 90001;  // 3000多ms
int snow[100005][6];
//vector < int > Hash[maxn + 10];
vector < vector<int>  > Hash;
//判断同hash值得snow的两个雪花是否是同一个
*/
/*bool check(int h,int s){
    int flag = 0;
    for (int i = 0; i < 6; ++i) {
        flag = 0;
        for (int j = 0; j < 6; ++j) {
            int ti = i + j;
            if(ti >= 6 ){
                ti = ti - 6;
            }
            if(snow[h][ti] == snow[s][j]){
                flag++;
            }
        }
        if(flag == 6)
            return true;
    }
    for (int i = 0; i < 6; ++i) {
        flag = 0;
        for (int j = 0; j < 6; ++j) {
            int ti = i - j;
            if(ti < 0 ){
                ti = ti + 6;
            }
            if(snow[h][ti] == snow[s][j]){
                flag++;
            }
        }
        if(flag == 6)
            return true;
    }
    return false;
}*//*

bool check(int a,int b){
    for (int i = 0; i < 6; ++i) {
        if ((snow[a][0] == snow[b][i] &&
            snow[a][1] == snow[b][(i+1)%6] &&
                snow[a][2] == snow[b][(i+2)%6] &&
                snow[a][3] == snow[b][(i+3)%6] &&
                snow[a][4] == snow[b][(i+4)%6] &&
                snow[a][5] == snow[b][(i+5)%6])
            ||
                (snow[a][0] == snow[b][i] &&
                 snow[a][1] == snow[b][(i+5)%6] &&
                 snow[a][2] == snow[b][(i+4)%6] &&
                 snow[a][3] == snow[b][(i+3)%6] &&
                 snow[a][4] == snow[b][(i+2)%6] &&
                 snow[a][5] == snow[b][(i+1)%6])
                )
            return true;
    }
    return false;
}
int main(){
    int n;
//    cin >> n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
//            cin >> snow[i][j];
            scanf("%d",&snow[i][j]);
        }
    }
    Hash.clear();
    Hash.resize(maxn +10);
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < 6; ++j) {
            sum += snow[i][j];
        }
        sum %= maxn;
        for (int k = 0; k < Hash[sum].size(); ++k) {
            if(check(Hash[sum][k],i)){
                cout << "Twin snowflakes found." << endl;
                return 0;
            }
        }
        Hash[sum].push_back(i);
    }
    cout << "No two snowflakes are alike." << endl;
    return 0;
}


*/

/*#include<stdio.h>
#include<string.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#include<iostream>
using namespace std;

#define NN 15000 // 14997 + 3
#define NL 100
#define L 6
typedef struct{
    int a[L];
}item;

item snow[NN][NL];
int m[NN];

int hash(item SNOW){
    int i;
    int key = 0;
    for (i = 0; i < 6; i++){
        key += SNOW.a[i];
    }
    key %= 14997;
    return key;
}

int cmp(item x, item y){
    int st, i, j;
    for (st = 0; st < 6; st++){// 右移
        for (i = st, j = 0; j < 6; j++, i = (i + 1) % 6){
            if(x.a[i] != y.a[j]) break;
        }
        if(j == 6) return 1;
    }
    for (st = 0; st < 6; st++){// 左移
        for (i = st, j = 0; j < 6; j++, i = (i + 5) % 6){
            if(x.a[i] != y.a[j]) break;
        }
        if(j == 6) return 1;
    }
    return 0;
}
int main() {
    int i, j, pos, n;
    item SNOW;
    scanf("%d", &n);
    memset(m, 0, sizeof(m));
    for (i = 1; i <= n; i++){
        for (j = 0; j < 6; j++){
            scanf("%d", &SNOW.a[j]);
        }
        pos = hash(SNOW);
        for (j = 0; j < m[pos]; j++){
            if(cmp(SNOW, snow[pos][j])){
                puts("Twin snowflakes found.");
                return 0;
            }
        }
        snow[pos][m[pos]] = SNOW;
        m[pos]++;
    }
    puts("No two snowflakes are alike.");
    return 0;
}*/


#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1200010;
const int H = 1200007;

struct Node
{
    int num[6];
    int next;
};
Node node[N];
int cur;
int hashTable[H];

void initHash()
{
    cur = 0;
    for (int i = 0; i < H; ++i) hashTable[i] = -1;
}

unsigned int getHash(int* num)
{
    unsigned int hash = 0;
    for (int i = 0; i < 6; ++i)
    {
        hash += num[i];
    }
    return hash % H;
}

bool cmp(int* num1, int* num2)
{
    for (int i = 0; i < 6; ++i)
    {
        if (num1[i] != num2[i]) return false;
    }
    return true;
}

void insertHash(int* num, unsigned int h)
{
    for (int i = 0; i < 6; ++i) node[cur].num[i] = num[i];
    node[cur].next = hashTable[h];
    hashTable[h] = cur;
    ++cur;
}

bool searchHash(int* num)
{
    unsigned h = getHash(num);
    int next = hashTable[h];
    while (next != -1)
    {
        if (cmp(num, node[next].num)) return true;
        next = node[next].next;
    }
    insertHash(num, h);
    return false;
}

int main()
{
    int num[2][12];
    int n;
    bool twin = false;
    initHash();
    scanf("%d", &n);
    while (n--)
    {
        for (int i = 0; i < 6; ++i)
        {
            scanf("%d", &num[0][i]);
            num[0][i + 6] = num[0][i];
        }
        if (twin) continue;
        for (int i = 0; i < 6; ++i)
        {
            num[1][i + 6] = num[1][i] = num[0][5 - i];
        }
        for (int i = 0; i < 6; ++i)
        {
            if (searchHash(num[0] + i) || searchHash(num[1] + i))
            {
                twin = true;
                break;
            }
        }
    }
    if (twin) printf("Twin snowflakes found.\n");
    else printf("No two snowflakes are alike.\n");
    return 0;
}