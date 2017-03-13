#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;


int main() {
    char ch;
    stack <char> s;
    while (~scanf("%c",&ch)){
        if(ch == '@')
            break;
        if(ch == '(')
            s.push(ch);
        else if(ch == ')'){
            if(!s.empty()) {
                s.pop();
            }
            else{
                printf("NO\n");
                return 0;
            }
        }
    }
    if(s.empty())
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}