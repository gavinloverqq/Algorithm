#include <iostream>
//#include "myStack.h"
#include "StackbyArray.h"

using namespace std;

/*
int main() {
    myStack S;
    S = createStack();
    for (int i = 0; i < 10; ++i) {
        push(i + 2,S);
    }
    while (!isEmpty(S)){
        printf("%d ",top(S));
        pop(S);
    }
    return 0;
}*/


int main(){
    Stack S = (Stack)malloc(sizeof(Node));
    S = CreateStack(20);

    for (int i = 0; i < 20; ++i) {
        Push(S,i + 2);
    }
    while (!IsEmpty(S)){
        printf("%d ",Top(S));
        Pop(S);
    }
    return 0;
}