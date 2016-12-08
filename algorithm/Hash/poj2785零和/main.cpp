#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*
int arr[5000][5];
int a[17000000],b[17000000];
int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> arr[i][j];
        }
    }

    int index = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            a[index++] = arr[k][0] + arr[i][1];
        }
    }
    int index2 = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            b[index2++] = arr[k][3] + arr[i][2];
        }
    }

    sort(a,a + n*n);
    sort(b,b + n*n);

    int r = n * n - 1;
    for (int i = 0; i < index; ++i) {

        while (a[i] + b[r] > 0 && r >= 0)
            r--;
        if(r < 0)
            break;
        int tmp = r;
        while (a[i] + b[tmp] == 0 && tmp >= 0)
            ans++,tmp--;
    }

    cout << ans << endl;

    return 0;
}*/

/*

int arr[5000][5];
int a[17000000],b[17000000];

const int MAX = 1 << 29;
const int bigPrimeNum = 17777777;

int Hash[bigPrimeNum + 1000],sum[bigPrimeNum + 1000];

void Insert(int num){
    int tmp = (num + MAX) % bigPrimeNum;
    while (Hash[tmp] != MAX && Hash[tmp] != num){
        tmp++;
        if(tmp >= bigPrimeNum + 1000)
            tmp = 0;
    }
    Hash[tmp] = num;
    sum[tmp]++;
}

int Find(int num){
    int tmp = (num + MAX) % bigPrimeNum;
    while (Hash[tmp] != MAX && Hash[tmp] != num){
        tmp++;
        if(tmp >= bigPrimeNum + 1000)
            tmp = 0;
    }
    if(Hash[tmp] == MAX)
        return 0;
    else
        return sum[tmp];
}




int main(){
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
//            cin >> arr[i][j];
            scanf("%d",&arr[i][j]);
        }
    }

    for (int l = 0; l < bigPrimeNum + 1000; ++l) {
        Hash[l] = MAX;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            Insert(arr[k][0] + arr[i][1]);
        }
    }
//    int index2 = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            ans += Find(-(arr[k][3] + arr[i][2]));
        }
    }

    cout << ans << endl;

}*/

/*
int arr[5000][5];
int a[17000000],b[17000000];

const int MAX = 1 << 29;
const int bigPrimeNum = 17777777;
int head[bigPrimeNum + 1];

struct Node{
    int sum,value,next;
    Node(){}
    Node(int s,int v,int n):sum(s),value(v),next(n){}
};
Node Hash[17000000];
int tot = 0;

int calHash(int num){
    return (num + MAX) % bigPrimeNum;
}
void Insert(int num){
    int tmp = calHash(num);
    for (int i = head[tmp]; i != -1 ; i = Hash[i].next) {
        if(num == Hash[i].value){
            Hash[i].sum++;
            return;
        }
    }
    Hash[tot] = Node(1,num,head[tmp]);//记下冲突时,上次节点对应的下标head[tmp]
    head[tmp] = tot;//记录hash值为tmp的num 对应节点的下标
    tot++;
}
int Find(int num){
    int tmp = calHash(num);
    for (int i = head[tmp]; i != -1 ; i = Hash[i].next) {
        if(num == Hash[i].value){
            return Hash[i].sum;
        }
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
//            cin >> arr[i][j];
            scanf("%d",&arr[i][j]);
        }
    }
    memset(head,-1, sizeof(head));

    tot = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            Insert(arr[k][0] + arr[i][1]);
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            ans += Find(-(arr[k][3] + arr[i][2]));
        }
    }

    cout << ans << endl;

}*/




/*
int arr[5000][5];
int a[17000000],b[17000000];

const int MAX = 1 << 29;
const int bigPrimeNum = 17777777;

int Hash[bigPrimeNum + 1000],sum[bigPrimeNum + 1000];

void Insert(int num){
    int tmp = (num + MAX) % bigPrimeNum;
    int j = 0;
    while (Hash[tmp] != MAX && Hash[tmp] != num){
//        tmp++;
        tmp += 1 << j;
        if(tmp >= bigPrimeNum + 1000)
            tmp = 0;
        j++;
    }
    Hash[tmp] = num;
    sum[tmp]++;
}

int Find(int num){
    int tmp = (num + MAX) % bigPrimeNum;
    int j = 0;
    while (Hash[tmp] != MAX && Hash[tmp] != num){
//        tmp++;
        tmp += 1 << j;
        if(tmp >= bigPrimeNum + 1000)
            tmp = 0;
        j++;
    }
    if(Hash[tmp] == MAX)
        return 0;
    else
        return sum[tmp];
}




int main(){
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
//            cin >> arr[i][j];
            scanf("%d",&arr[i][j]);
        }
    }

    for (int l = 0; l < bigPrimeNum + 1000; ++l) {
        Hash[l] = MAX;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            Insert(arr[k][0] + arr[i][1]);
        }
    }
//    int index2 = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            ans += Find(-(arr[k][3] + arr[i][2]));
        }
    }

    cout << ans << endl;

}*/


int arr[5000][5];
int a[17000000],b[17000000];

const int MAX = 1 << 29;
const int bigPrimeNum = 17777777;

int Hash[bigPrimeNum + 1000],sum[bigPrimeNum + 1000];

void Insert(int num){
    int tmp = (num + MAX) % bigPrimeNum;
//    int j = 0;
    while (Hash[tmp] != MAX && Hash[tmp] != num){
//        tmp++;
//        tmp += 1 << j;
        tmp = (tmp + MAX) % bigPrimeNum;
//        if(tmp >= bigPrimeNum + 1000)
//            tmp = 0;
//        j++;
    }
    Hash[tmp] = num;
    sum[tmp]++;
}

int Find(int num){
    int tmp = (num + MAX) % bigPrimeNum;
    int j = 0;
    while (Hash[tmp] != MAX && Hash[tmp] != num){
//        tmp++;
//        tmp += 1 << j;
//        if(tmp >= bigPrimeNum + 1000)
//            tmp = 0;
//        j++;
        tmp = (tmp + MAX) % bigPrimeNum;
    }
    if(Hash[tmp] == MAX)
        return 0;
    else
        return sum[tmp];
}




int main(){
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
//            cin >> arr[i][j];
            scanf("%d",&arr[i][j]);
        }
    }

    for (int l = 0; l < bigPrimeNum + 1000; ++l) {
        Hash[l] = MAX;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            Insert(arr[k][0] + arr[i][1]);
        }
    }
//    int index2 = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            ans += Find(-(arr[k][3] + arr[i][2]));
        }
    }

    cout << ans << endl;


}
