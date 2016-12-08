#include <iostream>
#include <set>
#include <string>
using namespace std;
/*
char G[20100][20100];
int n,m,K;

void colorGraph(int x,int y){
    //column
    int column = 1;
    while (column <= m)
        G[x][column++] = -1;
    //row
    int row = 1;
    while (row <= n)
        G[row++][y] = -1;
    //diagonal
//    row = x, column = y;
//    while (row <= n && column <= m)
//        G[row++][column++] = -1;
//    row = x, column = y;
//    while (row > 0 && column > 0)
//        G[row--][column--] = -1;
//    row = x, column = y;
//    while (row > 0 && column <= m)
//        G[row--][column++] = -1;
//    row = x, column = y;
//    while (row <= n && column > 0)
//        G[row++][column--] = -1;
}

int main() {
    cin >> n >> m >> K;
    int x,y,ans = 0;
    while (K--){
        cin >> x >> y;
        colorGraph(x,y);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(G[i][j] == 0)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
*/


/*int n,m,k,ans = 0;

struct  Node{
    int x,y;
    Node(int xx = 0,int yy = 0):x(xx),y(yy){}
    friend bool operator != (Node a,Node b){
        return (a.x != b.x && a.y != b.y);
    }
    friend bool operator == (Node a,Node b){
        return (a.x == b.x && a.y == b.y);
    }
};

Node Hash[50000000];//80000*500
const int bigPrimeNum = 47777777;

void Insert(int x,int y){
    int hashNum = (x * 131 + y * 31) % bigPrimeNum;
    while (Hash[hashNum] != Node(0,0) && Hash[hashNum] != Node(x,y)){
        hashNum++;
        if(hashNum > bigPrimeNum)
            hashNum = 0;
    }
    if(Hash[hashNum] == Node(x,y))
        return;
    else{
        Hash[hashNum] = Node(x,y);
        ans++;
        return;
    }
}

void colorGraph(int x,int y){
    //column
    int column = 1;
    while (column <= m)
        Insert(x,column++);
    //row
    int row = 1;
    while (row <= n)
        Insert(row++,y);
    //diagonal
    row = x, column = y;
    while (row <= n && column <= m)
        Insert(row++,column++);
    row = x, column = y;
    while (row > 0 && column > 0)
        Insert(row--,column--);
    row = x, column = y;
    while (row > 0 && column <= m)
        Insert(row--,column++);
    row = x, column = y;
    while (row <= n && column > 0)
        Insert(row++,column--);
}

int main(){
    cin >> n >> m >> k;
    int sum = n * m;
    int x,y,color = 0;
    while (k--){
        cin >> x >> y;
        colorGraph(x,y);
    }
    cout << sum - ans << endl;
}*/


/*
int n,m,k,ans = 0;
int Hashx[20777],Hashy[20777];

struct  Node{
    int x,y;
    Node(int xx = 0,int yy = 0):x(xx),y(yy){}
};

Node Hash[20000000];//2*20000*500
const int bigPrimeNum = 17777777;

bool HashInsert(int x,int y){
    int hashNum = (x * 11 + y) % bigPrimeNum;
    int j = 1;
    while (Hash[hashNum].x != 0 && Hash[hashNum].x != x && Hash[hashNum].y != y){
        hashNum += 1 << j;
        j++;
        if(hashNum > bigPrimeNum)
            hashNum = 0;
    }
    if(Hash[hashNum].x == x && Hash[hashNum].y == y)
        return false;
    else{
        Hash[hashNum] = Node(x,y);
        return true;
    }
}

bool Insert(int x,int y){
    return  (Hashx[x] != 1 && Hashy[y] != 1 && HashInsert(x,y));
}

void colorGraph(int x,int y){
    int row,column;
    //diagonal
    row = x, column = y;
    while (row <= n && column <= m) {
        if (Insert(row, column)){
            ans++;
        }
        row++;column++;
    }
    row = x, column = y;
    while (row > 0 && column > 0){
        if(Insert(row,column)) {
            ans++;
        }
        row--;column--;
    }
    row = x, column = y;
    while (row > 0 && column <= m) {
        if (Insert(row, column)) {
            ans++;
        }
        row--;column++;
    }
    row = x, column = y;
    while (row <= n && column > 0) {
        if (Insert(row, column)) {
            ans++;
        }
        row++;column--;
    }
}

Node queen[555];

int main(){
    cin >> n >> m >> k;
    int sum = n * m;
    int x,y,color = 0;
    int q = k;
    while (k--){
        cin >> x >> y;
        Hashx[x] = 1;
        Hashy[y] = 1;
        queen[k] = Node(x,y);
    }
    int col = 0,row = 0;
    for (int j = 0; j <= 500; ++j) {
        if(Hashx[j] == 1)
            row++;
        if(Hashy[j] == 1)
            col++;
    }
    for (int i = 0; i < q; ++i) {
        x = queen[i].x, y = queen[i].y;
        colorGraph(x,y);
    }
    ans += col * n + row * m - col * row;
    cout << sum - ans << endl;
}*/


/*
int n,m,k,ans = 0;
int Hashx[20777],Hashy[20777];

struct  Node{
    int x,y;
    Node(int xx = 0,int yy = 0):x(xx),y(yy){}
    friend bool operator < (Node a,Node b){
        if(a.x != b.x)
            return a.x < b.x;
        else
            return a.y < b.y;
    }
};
//Node Hash[20000000]xs;//2*20000*500
//const int bigPrimeNum = 17777777;

set <Node> sNode;
bool HashInsert(int x,int y){
    if(sNode.count(Node(x,y)) == 1){
        return false;
    } else {
        sNode.insert(Node(x,y));
        return true;
    }
}
*//*bool HashInsert(int x,int y){
    int hashNum = (x * 11 + y) % bigPrimeNum;
    int j = 1;
    while (Hash[hashNum].x != 0 && Hash[hashNum].x != x && Hash[hashNum].y != y){
        hashNum += 1 << j;
        j++;
        if(hashNum > bigPrimeNum)
            hashNum = 0;
    }
    if(Hash[hashNum].x == x && Hash[hashNum].y == y)
        return false;
    else{
        Hash[hashNum] = Node(x,y);
        return true;
    }
}*//*

bool Insert(int x,int y){
    return  (Hashx[x] != 1 && Hashy[y] != 1 && HashInsert(x,y));
}

void colorGraph(int x,int y){
    int row,column;
    //diagonal
    row = x, column = y;
    while (row <= n && column <= m) {
        if (Insert(row, column)){
            ans++;
        }
        row++;column++;
    }
    row = x, column = y;
    while (row > 0 && column > 0){
        if(Insert(row,column)) {
            ans++;
        }
        row--;column--;
    }
    row = x, column = y;
    while (row > 0 && column <= m) {
        if (Insert(row, column)) {
            ans++;
        }
        row--;column++;
    }
    row = x, column = y;
    while (row <= n && column > 0) {
        if (Insert(row, column)) {
            ans++;
        }
        row++;column--;
    }
}

Node queen[555];

int main(){
    cin >> n >> m >> k;
    int sum = n * m;
    int x,y,color = 0;
    int q = k;
    while (k--){
        cin >> x >> y;
        Hashx[x] = 1;
        Hashy[y] = 1;
        queen[k] = Node(x,y);
    }
    int col = 0,row = 0;
    for (int j = 0; j <= 500; ++j) {
        if(Hashx[j] == 1)
            row++;
        if(Hashy[j] == 1)
            col++;
    }
    for (int i = 0; i < q; ++i) {
        x = queen[i].x, y = queen[i].y;
        colorGraph(x,y);
    }
    ans += col * n + row * m - col * row;
    cout << sum - ans << endl;
}*/
/*


int x[501],y[501],h[20001];
int main()
{
    int n,m,k,i,j,ans,t;
    scanf("%d%d%d",&n,&m,&k);
    memset(h,0,sizeof(h));
    for (i=1;i<=k;i++) scanf("%d%d",&x[i],&y[i]);
    ans=0;
    for (i=1;i<=n;i++)
    {
        t=m;
        for (j=1;j<=k;j++)
            if (x[j]==i)
            {
                t=0;
                break;
            } else
            {
                if (h[y[j]]!=i)
                {
                    h[y[j]]=i;
                    t--;
                }
                if ((i+y[j]-x[j])>0 && (i+y[j]-x[j])<=m && h[i+y[j]-x[j]]!=i)
                {
                    h[i+y[j]-x[j]]=i;
                    t--;
                }
                if ((y[j]+x[j]-i)>0 && (y[j]+x[j]-i)<=m && h[y[j]+x[j]-i]!=i)
                {
                    h[y[j]+x[j]-i]=i;
                    t--;
                }
            }
        ans+=t;
    }
    printf("%d\n",ans);
    return 0;
}*/


int main(){
    unsigned int i = 0xFFFFFFFF;
    cout << i << endl;
    string s = "123056";
    int sum = 0;
    for (int j = 0; j < s.length(); ++j) {
        sum += s[j] - '0';
    }
    cout << sum << endl;

}