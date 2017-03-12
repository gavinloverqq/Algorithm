#include <iostream>
#include <stack>
using namespace std;

struct Node{
    int data;
    Node* lChild;
    Node* rChild;
};

void createTree(Node* &Tree){
    int data;
    cin >> data;
    if(data == -1){
        Tree = NULL;
    } else {
        Tree = (Node*)malloc(sizeof(Node));
        Tree->data = data;
        createTree(Tree->lChild);
        createTree(Tree->rChild);
    }
}

void preOrder(Node* Tree){
    if(Tree == NULL)
        return;
    printf("%d ",Tree->data);
    preOrder(Tree->lChild);
    preOrder(Tree->rChild);
}

void inOrder(Node* Tree){
    if(Tree == NULL)
        return;
    inOrder(Tree->lChild);
    printf("%d ",Tree->data);
    inOrder(Tree->rChild);
}

void postOrder(Node* Tree){
    if(Tree == NULL)
        return;
    postOrder(Tree->lChild);
    postOrder(Tree->rChild);
    printf("%d ",Tree->data);
}


void foo(stack <Node*> &S,Node* Tree){
    while (Tree != NULL) {
        printf("%d ", Tree->data);
        S.push(Tree->rChild);
        Tree = Tree->lChild;
    }
}
void preOrder2(Node* Tree){
    stack <Node*> S;
    foo(S,Tree);
    while (!S.empty()){
        Node* tmp = S.top();
        S.pop();
        foo(S,tmp);
    }
}

void inFoo(stack <Node*> &S,Node* Tree){
    while (Tree != NULL){
        S.push(Tree);
        Tree = Tree->lChild;
    }

}
void inOrder2(Node* Tree){
    stack <Node*> S;
    while (1){
        inFoo(S,Tree);
        if(S.empty())break;
        Tree = S.top();
        S.pop();
        printf("%d ",Tree->data);
        Tree = Tree->rChild;
    }
}



struct NodeWithPa{
    int data;
    NodeWithPa* lChild;
    NodeWithPa* rChild;
    NodeWithPa* parent;
};

void createTreeWithParent(NodeWithPa* & TreePa,NodeWithPa*  parent){
    int data;
    cin >> data;
    if(data == -1) {
        TreePa = NULL;
    } else {
        TreePa = new NodeWithPa;
        TreePa->parent = parent;
        TreePa->data = data;
        createTreeWithParent(TreePa->lChild,TreePa);
        createTreeWithParent(TreePa->rChild,TreePa);
    }
}

NodeWithPa* Root = new NodeWithPa;

//此节点是否是右孩子
bool IsRChild(NodeWithPa* position){
    return position != Root && position->parent->rChild == position;
}

bool IsLChild(NodeWithPa* position){
    return position != Root && position->parent->lChild == position;
}

//找出position节点的直接后继
NodeWithPa* Succ(NodeWithPa* position){
    if(position->rChild){
        position = position->rChild;
        while (position != NULL){
            position = position->lChild;
        }
    } else {
        while (IsRChild(position))
            position = position->parent;
        position = position->parent;
    }
    return position;
}

//测试查找中序遍历的某个节点的直接后继
void preOrderpa(NodeWithPa* t){
    if(t == NULL)
        return;

    if(t->data == 13){

        NodeWithPa* tmp = Succ(t);
        if(tmp) {
            cout << endl << t->data << " zhi jie hou ji: ";
            cout << tmp->data << endl;
        } else
            cout << "NULL" << endl;
    }
    preOrderpa(t->lChild);
    printf("%d ",t->data);
    preOrderpa(t->rChild);
}

void postOderpa(){

}


// 15 11 8 -1 -1 14 13 -1 -1 -1 20 -1 -1

int main() {
//    Node* tree;
//    createTree(tree);
//    cout << "先序遍历" << endl;
//    preOrder(tree);
//    cout << endl;
//    preOrder2(tree);
//    cout << endl << "中序遍历" << endl;
//    inOrder(tree);
//    cout << endl;
//    inOrder2(tree);
//    cout << endl << "后序遍历" << endl;
//    postOrder(tree);


    createTreeWithParent(Root,NULL);
    preOrderpa(Root);

    return 0;
}