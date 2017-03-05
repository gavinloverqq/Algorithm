//
// Created by 万昆 on 17/3/5.
//

#include <cstdio>
#include <cstdlib>
#include "StackbyArray.h"

bool IsEmpty(Stack S){
    return S->TopOfStack == EmptyTOS;
}

int IsFull(Stack S){
    return S->TopOfStack == S->Capacity;
}

//创建一个空栈
void MakeEmpty(Stack S){
    S->TopOfStack = EmptyTOS;
}

Stack CreateStack(int MaxElement){
    Stack S;
    if(MaxElement < MinStackSize)
        perror("Stack is too small");

    S = (Stack)malloc(sizeof(Node));
    if(NULL == S)
        perror("out of space");

    S->Array = (ElementType*)malloc(MaxElement * sizeof(ElementType));
    if(NULL == S->Array)
        perror("out of space");

    S->Capacity = MaxElement;
    MakeEmpty(S);// ????
    return S;
}

//释放栈
void ClearStack(Stack S){
    if(S != NULL){
        free(S->Array);
        free(S);
    }
}

void Push(Stack S,ElementType x){
    if(IsFull(S))
        perror("full stack");
    else
        S->Array[++S->TopOfStack] = x;
}

void Pop(Stack S){
    if(IsEmpty(S))
        perror("Empty stack");
    else
        --S->TopOfStack;
}

ElementType Top(Stack S){
    if(IsEmpty(S)){
        perror("Empty stack");
        return -1;// -1 represent an illegal value;
    }
    else
        return S->Array[S->TopOfStack];
}
