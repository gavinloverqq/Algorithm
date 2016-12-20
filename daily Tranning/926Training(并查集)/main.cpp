#include <iostream>

using namespace std;

int par[10];

int getPar(int a){
    if(par[a] != a){
        par[a] = getPar(par[a]);
    }
    return par[a];
}
int merge(int a,int b){
    par[getPar(a)] = getPar(b);
}
int main() {
    for (int i = 0; i < 10; ++i) {
        par[i] = i;
    }

    cout << "Hello, World!" << endl;
    return 0;
}