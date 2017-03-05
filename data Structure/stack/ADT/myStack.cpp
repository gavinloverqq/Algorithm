//
// Created by 万昆 on 17/3/4.
//
#include <cstdlib>
#include <cstdio>
#include "myStack.h"


bool isEmpty(myStack S){
    return (NULL == S->Next);
}

/*
 * create an empty stack
 *
 * */
myStack createStack(void){
    myStack S;
    S = (Node*)malloc(sizeof(Node));
    if(NULL == S)
        perror("out of space");
    S->Next = NULL;
    clearStack(S);
    return S;
}

void clearStack(myStack S){
    if(NULL == S)
        printf("must use createStack first");
    else
        while (!isEmpty(S)){
            pop(S);
        }
}

void push(ElementType x,myStack S){
    pNode newNode = (pNode)malloc(sizeof(Node));
    if(NULL == newNode)
        perror("out of space");
    else{
        newNode->value = x;
        newNode->Next = S->Next;
        S->Next = newNode;
    }
}

ElementType top(myStack S){
    if(!isEmpty(S))
        return S->Next->value;
    else {
        perror("this is a empty stack");
        return -1;// -1 represent a illegal value
    }
}

void pop(myStack S){
    if(!isEmpty(S)){
        pNode t = S->Next->Next;
        free(S->Next);
        S->Next = t;
    } else {
        perror("this is a empty stack");
    }

}