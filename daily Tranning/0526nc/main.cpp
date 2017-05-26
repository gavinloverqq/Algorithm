#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, k, v;
    while(cin >> n){
        map <int, int> m;
        for (int i = 0; i < n; ++i) {
            cin >> k >> v;
            if(m.count(k) > 0){
                m[k] += v;
                continue;
            }
            m.insert({k, v});
//            if(!m[k]){
//                m[k] = v;
//            } else {
//                m[k] += v;
//            }
        }
        for (auto p : m) {
            cout << p.first << " " << p.second << endl;
        }
    }
    return 0;
}