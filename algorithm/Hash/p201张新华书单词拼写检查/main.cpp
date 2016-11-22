#include <iostream>
#include <string>
using namespace std;

const int maxN = 123357;//值域范围内1-2倍的大素数
int total = 0;
string str[maxN + 1];

int Hash(string s){
    int t,l,m;
    l = s.length();
    m = l/2;
    t = (s[0]-'a')*10000 + (s[m]-'a')*100 + (s[l-1]-'a');//取首,中,尾加权
    return t%maxN;
}

void insert(string s){
    int t = Hash(s);
    while (str[t] != "" && str[t] != s){//冲突
        t++;
        if(t == maxN)
            t = 0;
    }
    str[t] = s;
}

void find(string s){
    int t = Hash(s);
    while (str[t] != "" && str[t] != s){
        t++;
        if(t == maxN)
            t = 0;
    }
    if(str[t] == "")
        total++;
}
/*
5 3
apple
be
love
up
down
up
down
bee
1

 */

int main() {
    int n, m;
    string str;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        insert(str);
    }
    for (int j = 0; j < m; ++j) {
        cin >> str;
        find(str);
    }
    cout << total << endl;
    return 0;
}