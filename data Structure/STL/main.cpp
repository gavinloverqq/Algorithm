#include <iostream>
#include <vector>
#include <numeric>//accumulate需要
#include <algorithm>

using namespace std;

void testVector(){

/********** 创建 *********/

    //不指定大小;
    vector <int> v;

    //指定大小
    vector <double> v2(10);

    //指定大小并初始化
    vector <double> v3(10,8.6);

    //尾部插入;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    //下标访问
    for (int j = 0; j < v.size(); ++j) {
        cout << v[j] << " ";
    }
    cout << endl;

    //迭代器访问
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end() ; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    //reverse
    reverse(v.begin(),v.end());
    for (it = v.begin(); it != v.end() ; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    //sort
    sort(v.begin(),v.end());
    for (it = v.begin(); it != v.end() ; ++it) {
        cout << *it << " ";
    }
    cout << endl;
    reverse(v.begin(),v.end());


}

int main() {
    testVector();
    cout << "Hello, World!" << endl;
    return 0;
}