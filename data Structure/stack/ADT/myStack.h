//
// Created by 万昆 on 17/3/4.
//

#ifndef ADT_MYSTACK_H
#define ADT_MYSTACK_H

typedef int ElementType;

struct Node;
typedef struct Node* pNode;
typedef pNode myStack;

bool isEmpty(myStack S);
myStack createStack(void);
void clearStack(myStack S);
void push(ElementType x,myStack S);
ElementType top(myStack S);
void pop(myStack S);


struct Node{
    ElementType value;
    pNode Next;
};
#endif //ADT_MYSTACK_H
