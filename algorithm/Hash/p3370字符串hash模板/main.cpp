#include <iostream>
#include <string>

using namespace std;
const int Max = 1000000;
string Hash[Max + 100];

int getHash(string s){
    int seed = 31;
    int hashNum = 0;
    int i = 0;
    while (s[i]){
        hashNum = (hashNum * seed + s[i]) % Max;//此处串一旦hash溢出则有可能爆负数,因此要取模,也可以不取模,看下面的hash算法
        i++;
    }
    return (hashNum % Max);
}

//改进版,避免溢出得到负数,然后Segmentation fault
int getHash2(string s){
    int seed = 31;
    int hashNum = 0;
    int i = 0;
    while (s[i]){
        hashNum = hashNum * seed + s[i];
        i++;
    }
    hashNum = hashNum & 0x7FFFFFFF;
    return (hashNum % Max);
}

void Insert(string s){
    int tmp = getHash2(s);
    while (Hash[tmp] != "" && Hash[tmp] != s){
        tmp++;
        if(tmp >= Max)
            tmp = 0;
    }
    Hash[tmp] = s;
}

bool Find(string s){
    int tmp = getHash2(s);
    while (Hash[tmp] != "" && Hash[tmp] != s){
        tmp++;
        if(tmp >= Max)
            tmp = 0;
    }
    return Hash[tmp] == s;
}



int main() {
    int n;
    cin >> n;
    int ans = 0;
    string s;
    while (n--){
        cin >> s;
        if(!Find(s)) {
            ans++;
            Insert(s);
        }
    }
    cout << ans << endl;
    return 0;
}