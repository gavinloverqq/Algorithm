#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main() {
    char c;
    int x = 0;
    stack <int> s;
    while (~scanf("%c",&c)){
        if(c == '@')
            break;
        if(c == '.'){
            s.push(x);
            x = 0;
            continue;
        }
        if(c >= '0' && c <= '9'){
            x = x * 10 + c - '0';
        } else {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            switch (c){
                case '+':
                    s.push(a + b);
                    break;
                case '-':
                    s.push(a - b);
                    break;
                case '*':
                    s.push(a * b);
                    break;
                case '/':
                    s.push(a / b);
                    break;
                default:
                    break;
            }
        }
    }
    cout << s.top() << endl;
    return 0;
}