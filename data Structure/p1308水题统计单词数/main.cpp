#include <iostream>
#include <string>
using namespace std;


int total = 0,first = 0;
string start,add;

void toLower(string &s){
    for (int i = 0; i < s.length(); ++i) {
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] =s[i] - 'A' + 'a';
    }
}

int main() {
    cin >> start;
    toLower(start);
    int flag = 1,index = 0;
    while (cin >> add){
        if(add == "1")
            break;
        toLower(add);
        if(add == start){
            total++;
            if(flag){
                flag = 0;
                first = index;
            }
        }
        index++;
    }
    if(total)
        cout << total << " " << first << endl;
    else
        cout << -1 << endl;
    return 0;
}