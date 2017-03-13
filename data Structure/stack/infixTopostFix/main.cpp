#include <iostream>
#include <stack>
#include <map>
using namespace std;

int calculatorPriority(char ch){
    int ret = 0;
    switch (ch){
        case '+':
            ret = 1;
            break;
        case '-':
            ret = 1;
            break;
        case '*':
            ret = 2;
            break;
        case '/':
            ret = 2;
            break;
        case '(':
            ret = 3;
            break;
        case ')':
            ret = 4;
            break;
        default:
            break;
    }
    return ret;
}

struct Node{
    char c;
    int p;
    Node(){}
    Node(char ch,int ip):c(ch),p(ip){}
};

// input:a+b*c+(d*e+f)*g@
// output:a b c * + d e * f + g * +

int main() {
    char c;
//    map <char,int> m;
    stack < Node > s;
    while (~scanf("%c",&c)){
        if(c == '@')
            break;
        int p = calculatorPriority(c);
//        m[c] = p;
        switch (p){
            case 0:
                printf("%c ",c);
                break;
            case 1:
            case 2:
            case 3:
                while (!s.empty() && s.top().p >= p){
                    if(s.top().p == 3)//遇到 ( 时,不能移除,跳出当前小循环,把操作符入栈
                        break;
                    printf("%c ",s.top().c);
                    s.pop();
                }
                s.push(Node(c,p));
                break;
            case 4:
                while (s.top().c != '('){
                    printf("%c ",s.top().c);
                    s.pop();
                }
                s.pop();
                break;
            default:
                break;

        }
    }
    while (!s.empty()){
        printf("%c ",s.top().c);
        s.pop();
    }
    return 0;
}