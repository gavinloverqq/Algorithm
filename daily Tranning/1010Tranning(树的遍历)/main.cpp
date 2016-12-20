#include <iostream>
#include <stack>
using namespace std;
//ABC##DE#G##F###
struct Node{
    char data;
    Node *lChild;
    Node *rChild;
};


void creatTree(Node *&Tree){
    char data;
    scanf("%c",&data);
    if('#' == data){
        Tree = nullptr;
        return;
    } else {
        Tree = (Node *) malloc(sizeof(Node));
        Tree->data = data;
        creatTree(Tree->lChild);
        creatTree(Tree->rChild);
    }
}

void preOrder1(Node *Tree){
    if(Tree != nullptr){
        cout << Tree->data <<" ";
        preOrder1(Tree->lChild);
        preOrder1(Tree->rChild);
    }
}
void visitAlongLeftBranch(stack < Node* > &S,Node *Tree){
    while (Tree != nullptr){
        cout << Tree->data <<" ";
        if(Tree->rChild != nullptr)
            S.push(Tree->rChild);
        Tree = Tree->lChild;
    }
}

void preOrder2(Node *Tree){
    stack < Node* > S;
    visitAlongLeftBranch(S,Tree);
    while (!S.empty()){
        Tree = S.top();
        S.pop();
        visitAlongLeftBranch(S,Tree);
    }
}


void inOrder1(Node *Tree){
    if( Tree != nullptr){
        inOrder1(Tree->lChild);
        cout << Tree->data << " ";
        inOrder1(Tree->rChild);
    }
}

/*
void goAlongLeftBranch(stack < Node* > &S,Node *Tree){
    while (Tree != nullptr){
        if(Tree->lChild == nullptr){
            cout << Tree->data << " ";
            if(Tree->rChild != nullptr)
                S.push(Tree->rChild);
            return;
        }
        S.push(Tree);
        Tree = Tree->lChild;
    }
}
*/

void goAlongLeftBranch(stack < Node* > &S,Node *Tree){
    while (Tree != nullptr){
        S.push(Tree);
        Tree = Tree->lChild;
    }
}

void inOrder2(Node *Tree){
    stack < Node* > S;
    goAlongLeftBranch(S,Tree);
    while (!S.empty()){
        Node* tmp = S.top();
        S.pop();
        cout << tmp->data << " ";
        goAlongLeftBranch(S,tmp->rChild);
    }
}

void postOrder1(Node *Tree){
    if(Tree != nullptr){
        postOrder1(Tree->lChild);
        postOrder1(Tree->rChild);
        cout << Tree->data << " ";
    }
}

void postOrder2(Node *Tree){

}

int main() {
    Node *treeRoot;
//    treeRoot = (Node*)malloc(sizeof(Node));
    creatTree(treeRoot);
    cout << "先序遍历1:";
    preOrder1(treeRoot);
    cout << endl << "先序遍历2:";
    preOrder2(treeRoot);
    cout << endl<< "中序遍历1:";
    inOrder1(treeRoot);
    cout << endl << "中序遍历2:";
    inOrder2(treeRoot);
    cout << endl << "后序遍历1:";
    postOrder1(treeRoot);
    cout << endl << "后序遍历2:";
    postOrder2(treeRoot);
    cout << endl;
    return 0;
}