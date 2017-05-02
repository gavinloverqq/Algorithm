#include <iostream>
using namespace std;

bool book[10];
int out[10];

void dfs(int step){
    if(step > 5){
        for (int i = 1; i <= 5; ++i) {
            cout << out[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= 5; ++i) {
        if(book[i] == 0){
            book[i] = 1;
            out[step] = i;
            dfs(step + 1);
            book[i] = 0;
        }
    }

}

void dfs_2(int step){
    if(step > 5){
        for (int i = 1; i <= 5; ++i) {
            cout << out[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = step; i <= 5; ++i) {
        swap(out[step], out[i]);
        dfs_2(step + 1);
        swap(out[step], out[i]);
    }
}


int main() {
//    dfs(1);

    for (int i = 0; i < 10; ++i) {
        out[i] = i;
    }
    dfs_2(1);
    return 0;
}