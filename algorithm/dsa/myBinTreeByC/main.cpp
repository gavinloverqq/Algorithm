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
    if(position->rChild){//如果有右孩子,必然在直接后继的右子树中
        position = position->rChild;
        while (position->lChild){//右子树的最左节点
            position = position->lChild;
        }
    } else {//否则,直接后继应该在 将当前节点包含于其左子树的最低祖先
        while (IsRChild(position))//找到最低祖先的左子树(如果当前节点是右子树,那么就要上浮,知道变成左子树)
            position = position->parent;
        position = position->parent;
    }
    return position;
}

//测试查找中序遍历的某个节点的直接后继
void inOrderpa(NodeWithPa* t){
    if(t == NULL)
        return;

//    if(t->data == 13){
//
//        NodeWithPa* tmp = Succ(t);
//        if(tmp) {
//            cout << endl << t->data << " zhi jie hou ji: ";
//            cout << tmp->data << endl;
//        } else
//            cout << "NULL" << endl;
//    }
    inOrderpa(t->lChild);
    printf("%d ",t->data);
    inOrderpa(t->rChild);
}

void inOrderpaV2(NodeWithPa* t){
    bool flag = false;
    while (1){
        if(!flag && t->lChild){
            t = t->lChild;
        } else {
            printf("%d ", t->data);

            if (t->rChild) {
                t = t->rChild;
                flag = false;
            } else {
                t = Succ(t);
                if (!t)
                    break;
                flag = true;
            }
        }
    }
}


void postOrderpaV1(NodeWithPa* t){
    if(t){
        postOrderpaV1(t->lChild);
        postOrderpaV1(t->rChild);
        printf("%d ",t->data);
    }
}

void postFoo(stack <NodeWithPa*>& s,NodeWithPa* t){
//    顺着左边一直走到最低点的最边上
    while (t){
        s.push(t);
        int a = t->data;
        if(t->lChild){
            t = t->lChild;
        } else if(t->rChild){
            t = t->rChild;
        } else
            break;
    }

}
void postOrderpaV2(NodeWithPa* t){
    stack <NodeWithPa*> s;
    postFoo(s, t);
    while (!s.empty()){
        t = s.top();
        s.pop();
        printf("%d ",t->data);
        if(t->parent && t->parent->rChild && !IsRChild(t)){//小心重复进栈问题
            t = t->parent->rChild;
            postFoo(s, t);
        }
    }
}

/*void postFoo(stack <NodeWithPa*>& s,NodeWithPa* t){
    while (NodeWithPa* x = s.top()){
        if(x->lChild){
            if(x->rChild)
                s.push(x->rChild);
            s.push(x->lChild);
        } else {
            s.push(x->rChild);
        }
    }
    s.pop();

}

void postOrderpaV2(NodeWithPa* t){
    stack <NodeWithPa*> s;
//    postFoo(s, t);
    s.push(t);
    while (!s.empty()){
        if(s.top() != t->parent)
            postFoo(s,t);
        t = s.top();
        s.pop();
        printf("%d ",t->data);
    }
}*/

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
    inOrderpa(Root);
    cout << endl;
    inOrderpaV2(Root);
    cout << endl;
    postOrderpaV1(Root);
    cout << endl;
    postOrderpaV2(Root);



    return 0;
}