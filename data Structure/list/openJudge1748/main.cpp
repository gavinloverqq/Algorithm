#include <iostream>
#include <list>
#include <vector>
using namespace std;

/*int main() {
    int n,m;
    while (cin >> n >> m) {
        if(0 == m && 0 == n)
            break;
        list<int> iLst;
        for (int i = 1; i <= n; ++i) {
            iLst.push_back(i);
        }
//    auto p = iLst.begin();
        list<int>::iterator p = iLst.begin();
        while (iLst.size() > 1) {

            for (int i = 1; i < m; ++i) {
                ++p;
                if (p == iLst.end()) {
                    p = iLst.begin();
                }
            }
            iLst.erase(p);
//            cout << *p << " ";
            ++p;
            if (p == iLst.end()) {
                p = iLst.begin();
            }
        }
        cout << iLst.front() << endl;
    }
    return 0;
}*/

/*int main(){
    int n, m;
    cin >> n >> m;
    vector <int> v;
    for (int i = 1; i <= n; ++i) {
        v.push_back(i);
    }
    vector <int>::iterator p = v.begin();
    while (v.size() > 1){
        for (int i = 1; i < m; ++i) {
            ++p;
            if(p == v.end())
                p = v.begin();
        }
        cout << *p << " ";
        p = v.erase(p);
        if(p == v.end())
            p = v.begin();
    }
    cout << v.front() << endl;
}*/

int main() {
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    for (int i = 1; i <= n; ++i) {
        a[i] = i;
    }
    int idx = 1;
    int len = n;
    for (int j = 1; j <= n; ++j) {
//    while (len > 1){
        idx = (idx + m - 1) % len;
        if (idx == 0)
            idx = len;
        cout << a[idx] << " ";

        for (int i = idx; i <= len - 1; ++i) {
            a[i] = a[i + 1];
        }
        --len;
    }
}