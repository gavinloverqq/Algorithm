#include <iostream>

using namespace std;

// 单向链表的建立,与输出
/*struct Node{
    int iVal;
    Node* Next;
};

Node* createList(Node* List){
    List = (Node*)malloc(sizeof(Node));
    List->iVal = -1;
    List->Next = NULL;

    Node* curr;
    curr = List;
    while (1){
        int tVal;
        scanf("%d",&tVal);
        if(tVal == -1)
            break;
        Node* pNode = (Node*)malloc(sizeof(Node));
        curr->Next = pNode;
        pNode->Next = NULL;
        pNode->iVal = tVal;
        curr = pNode;
    }
    return List;
}

void printList(Node* List){
    while (List->Next != NULL){
        List = List->Next;
        printf("%d ",List->iVal);
    }
    printf("\n");
}

Node* test(Node* p){
    p = (Node*)malloc(sizeof(Node));
    p->iVal = 10;
    p->Next = NULL;
    return p;
}


int main() {
    Node* List;
    List = createList(List);
    printList(List);
    return 0;
}*/



//双向循环链表的建立与输出
/*
struct Node{
    int iVal;
    Node* prev;
    Node* next;
};

void creatList(Node*& List){
    int tVal;
    scanf("%d",&tVal);
    if(tVal == -1)
        return;
    List = new Node;
    List->iVal = tVal;
    List->next = NULL;
    List->prev = NULL;

    Node* curr = new Node;
    curr = List;

    while (1){
        scanf("%d",&tVal);
        if(tVal == -1)
            break;
        Node* pNode = new Node;
        curr->next = pNode;
        pNode->iVal = tVal;
        pNode->next = NULL;
        pNode->prev = curr;

        curr = pNode;
    }
    curr->next = List;
    List->prev = curr;
}

void frontPrint(Node* List){
    Node *curr = List;
    while (List->next != curr){
        cout << List->iVal << " ";
        List = List->next;
    }
    cout << List->iVal << " ";
    cout << endl;
}
void backPrint(Node* List){
    Node *curr = List;
    while (List->prev != curr){
        cout << List->iVal << " ";
        List = List->prev;
    }
    cout << List->iVal << " ";
    cout << endl;
}

int main(){
    Node* l;
    creatList(l);
    frontPrint(l);
    backPrint(l);
}*/
