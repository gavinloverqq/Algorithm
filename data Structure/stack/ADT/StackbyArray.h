//
// Created by 万昆 on 17/3/5.
//

#ifndef ADT_STACKBYARRAY_H
#define ADT_STACKBYARRAY_H


typedef int ElementType;
struct Node;
typedef struct Node* Stack;


bool IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElement);
void ClearStack(Stack S);
void MackEmpty(Stack S);
void Push(Stack S,ElementType x);
void Pop(Stack S);
ElementType Top(Stack S);


#define EmptyTOS (-1)
#define MinStackSize (5)


struct Node{
    int Capacity;
    int TopOfStack;
    ElementType* Array;
};
#endif //ADT_STACKBYARRAY_H
