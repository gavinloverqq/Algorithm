#include <iostream>
#include <list>
#include <vector>
#include <sstream>
using namespace std;


int main() {
    stringstream Scin;
    string s = "12 104 13 7 9 83 71 35 42 28 31";
    Scin.str(s);
    vector < list <int> > vLst(10);
    int i;
    while (Scin >> i){
        int step1 = i % 10;
        vLst[step1].push_back(i);
    }


//    for (int k = 0; k < 10; ++k) {
//        while (!vLst[k].empty()){
//            int t = vLst[k].front();
//            vLst[k].pop_front();
//            cout << t << endl;
//        }
//    }

//    cout << "w" << endl;
    vector < list <int> > vLst2(10);
    for (int j = 0; j < 10; ++j) {
        while (!vLst[j].empty()){
            int t = vLst[j].front();
            vLst[j].pop_front();
            int step2 = t % 100;
            step2 /= 10;
            vLst2[step2].push_back(t);
        }
    }

//    for (int k = 0; k < 10; ++k) {
//        while (!vLst2[k].empty()){
//            int t = vLst2[k].front();
//            vLst2[k].pop_front();
//            cout << t << endl;
//        }
//    }

//    cout << "1" << endl;
    vLst.clear();
    for (int j = 0; j < 10; ++j) {
        while (!vLst2[j].empty()){
            int t = vLst2[j].front();
            vLst2[j].pop_front();
            int step2 = t % 1000;
            step2 /= 100;
            vLst[step2].push_back(t);
        }
    }
    for (int k = 0; k < 10; ++k) {
        while (!vLst[k].empty()){
            int t = vLst[k].front();
            vLst[k].pop_front();
            cout << t << endl;
        }
    }
    cout << "Hello, World!" << endl;
    return 0;
}