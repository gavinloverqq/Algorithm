#include <iostream>
#include <string>
using namespace std;

string str[20010];
const int MAX = 19997;
int ans = 0;

void Insert(string s){
    int seed = 31;
    int hashNum = 0;
    for (int i = 0; i < s.length(); ++i) {
        hashNum = (hashNum * seed + s[i]) % MAX;
    }
    while (str[hashNum] != "" && str[hashNum] != s){
        if(hashNum >= MAX)
            hashNum = 0;
        hashNum++;
    }
    if(str[hashNum] == s)
        ans++;
    str[hashNum] = s;
}

int main() {
    int n,m = 0;
    string s;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        Insert(s);
    }
    cout << n - ans << endl;
    return 0;
}