#include <iostream>

using namespace std;

struct Node{
    int value = 0;
    Node* Next;
};

using List = Node*;
using Position = Node*;

int IsEmpty(List l){
    return l->Next == NULL;
}

int IsLast(Position p,List l){
    return p->Next == NULL;
}

Position Find(int x,List l){
    if(!IsEmpty(l)){
        Position t = l->Next;
        while (t->value != x && t != NULL){
            t = t->Next;
        }
        return t;
    } else
        return NULL;//链表为空
}

Position FindPrevious(int x,List l){
    Position t = l->Next;
    while (t->Next->value != x && t->Next != NULL){
        t = t->Next;
    }

    if(t != NULL)
        return t;
    else
        return l;
}

void Delete(int x,List l){
    Position p = FindPrevious(x,l);
    if(p != NULL){
        if(p->Next->Next == NULL){
            p->Next = NULL;
        } else{
            Position t = p->Next->Next;
            free(p->Next);
            p->Next = t;
        }
    }
}

void Insert(int x,List l,Position p){
    Position t = p->Next;
//    Node now;
//    now.value = x;
//    now.Next = t;
//    p->Next = &now;
    Position now = (Node*)malloc(sizeof(Node));//声明一个指向结构的指针,并不创建改结构,只是预分配出了足够的空间以容纳可能会使用的内存
    now->value = x;
    now->Next = t;
    p->Next = now;
}

void DeleteList(List l){
    Position p = l->Next;
    l->Next = NULL;//遗漏这行
    while (p != NULL){
        Position t = p->Next;
        free(p);//free(p)是p指向的地址没变,当改地址处的数据此时已经无定义了
        p = t;
    }
}

void PrintList(List l){
    Position t = l->Next;
    while (t != NULL){
        printf("%d\n",t->value);
        t = t->Next;
    }
}

int main() {
    List l = (Node*)malloc(sizeof(Node));
    l->Next = NULL;
    Insert(1,l,l);
    Insert(2,l,l->Next);
    Insert(3,l,l->Next->Next);
    PrintList(l);
    Delete(2,l);
    PrintList(l);.
//    cout << "Hello, World!" << endl;
    return 0;
}