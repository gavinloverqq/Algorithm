#include <iostream>
#include <cmath>
//#include <stdio.h>
using namespace std;


struct Node{
    int value;
    int height;
    Node* lChild;
    Node* rChild;
    Node* parent;

    Node(){}
    Node(int v, int h = 0, Node* l = NULL, Node* r = NULL, Node* p = NULL):value(v),height(h),lChild(l),rChild(r),parent(p){}

    Node& operator = (const Node& n) = default;

};

Node* Root;
// 创建一个节点
Node* createNode(int data, int height, Node* lChild, Node* rChild, Node* parent){
    return new Node(data,height,lChild,rChild,parent);
}

// 求平衡因子
// 注意考虑左右子孩子是否为空，一旦为空，则position->lChild->height会引发未定义操作！！！
inline
int balanceFactor(const Node* position){
    int lHeight = (position->lChild == NULL) ? -1 : position->lChild->height;
    int rHeight = (position->rChild == NULL) ? -1 : position->rChild->height;
    return abs(lHeight - rHeight);
}

// 判断是否是左右孩子
inline
bool IsRchild(Node* p){
    return (p != Root) && (p->parent->rChild == p);
}
inline
bool IsLchild(Node* p){
    return (p != Root) && (p->parent->lChild == p);
}

// 找出当前节点属于其父节点的哪个分支，返回分支的引用，用于将子树接入。
// 注意p是root时的考虑！
inline
Node*& fromParentTo(Node*& p){//加引用
    return ( (p == Root) ? Root : (IsLchild(p) ? p->parent->lChild : p->parent->rChild ));//TODO p is root ????
}

// 找出当前节点高度更高的子树
inline
Node* tallerChild(Node* position){
    int lHeight = (position->lChild == NULL) ? -1 : position->lChild->height;
    int rHeight = (position->rChild == NULL) ? -1 : position->rChild->height;
    return (lHeight > rHeight ? position->lChild : (\
            lHeight < rHeight ? position->rChild : (\
            IsLchild(position) ? position->lChild : position->rChild)));
}

// 更新节点高度
void updateHeight(Node* position){//不用引用
    int lHeight = (position->lChild == NULL) ? -1 : position->lChild->height;
    int rHeight = (position->rChild == NULL) ? -1 : position->rChild->height;
    position->height = max(lHeight,rHeight) + 1;
}

// 递归的向上更新节点高度直到树根
void updateHeightAbove(Node* position){//不用引用
    while (position){
        updateHeight(position);
        position = position->parent;
    }
}


//Node*& searchNode(int data, Node*& tree,Node*& hot){
//    hot = tree;
//    if(tree == NULL){
//        cout << "empty Tree !" << endl;
//    }
//    Node* position = tree;
//    while (1){
//        if(position && data > position->value) {
//            hot = position;
//            position = position->rChild;
//        }
//        else if (position && data < position->value) {
//            hot = position;
//            position = position->lChild;
//        }
//        else{
//            return position;
//        }
//    }
//}

// 查找节点，并返回引用，注意hot节点为当前节点的父节点
Node*& searchNode(int data, Node*& tree,Node*& hot){
    if(tree == NULL || (data == tree->value))return tree;
    hot = tree;
    return searchNode(data,((data < tree->value) ? tree->lChild : tree->rChild),hot);
}

// 找出当前节点中序遍历的直接后继
Node* Succ(Node* position){
    if(position->rChild) {
        position = position->rChild;
        while (position->lChild) {//右子树的最左节点
            position = position->lChild;
        }
    } else {
        while (IsRchild(position)){
            position = position->parent;
        }
        position = position->parent;
    }
    return position;
}

// 删除
Node* removeAt(Node*& position,Node*& hot){
//    Node* hot = NULL;
    Node* succ = NULL;
    Node* w = position;

    if(position->lChild == NULL){
        succ = position = position->rChild;
    } else if(position->rChild == NULL){
        succ = position = position->lChild;
    } else {
        w = Succ(w);//找出后继
        swap(w->value,position->value);// 将待删除节点与直接后继节点交换值，然后删除直接后继节点
        Node* u = w->parent;
        if(u->lChild == w){ // 将节点接起来
            u->lChild = succ = w->rChild;
        } else {
            u->rChild = succ = w->rChild;
        }
//        ((u == position) ? u->rChild : u->lChild ) = succ = w->rChild; // TODO 如果后继节点是原节点的右儿子，则原节点是后继节点的父亲；否则后继节点与原节点距离较远。而后继结点只能出现在左子树上
    }
    hot = w->parent;
    if(succ) succ->parent = hot;
    
    delete w;
    return succ;
}

// 4 + 3 重构
// T1 a T2 b T3 c T4
Node* connect34(Node* a, Node* b, Node* c, Node* T1, Node* T2,Node* T3, Node* T4){
    a->lChild = T1;
    if(T1) T1->parent = a;
    a->rChild = T2;
    if(T2) T2->parent = a;
    updateHeight(a);

    c->lChild = T3;
    if(T3) T3->parent = c;
    c->rChild = T4;
    if(T4) T4->parent = c;
    updateHeight(c);

    b->lChild = a;
    
    a->parent = b;
    b->rChild = c;
    c->parent = b;
    updateHeight(b);// tianjia

    return b;
}


// 旋转
Node* rotateAt(Node* v){//孙辈节点
    Node* p = v->parent;
    Node* g = p->parent;

    if(IsLchild(p)){
        if(IsLchild(v)){// LL
            p->parent = g->parent;//向上连接
            return connect34(v, p, g, v->lChild, v->rChild, p->rChild, g->rChild);
        }
        else{// LR
            v->parent = g->parent;//向上连接
            return connect34(p, v, g, p->lChild, v->lChild, v->rChild, g->rChild);
        }
    }
    else{
        if(IsLchild(v)){// RL
            v->parent = g->parent;//向上连接
            return connect34(g, v, p, g->lChild, v->lChild, v->rChild, p->rChild);
        }
        else{// RR
            p->parent = g->parent;//向上连接
            return connect34(g, p, v, g->lChild, p->lChild, v->lChild, v->rChild);
        }
    }
}

Node* insertAvlNode(int data, Node*& tree){
    Node* hot = tree;
    Node*& x = searchNode(data,tree,hot);
    if(x) return x;
    
    Node* xx = x = new Node(data);
    x->parent = hot;
    for (Node* g = hot; g; g = g->parent) {
        if(balanceFactor(g) > 1){
            Node*& parentPoint = fromParentTo(g);
            Node* childPoint = rotateAt(tallerChild(tallerChild(g)));
            parentPoint = childPoint;
//            g = parentPoint->parent;
//            cout << "xxxxx" << endl;
//            fromParentTo(g) = rotateAt(tallerChild(tallerChild(g)));//TODO 重新接入原树
            break;
        } else {
            updateHeightAbove(g);
        }
    }
    updateHeightAbove(xx);
    return xx;
}

bool removeAvlNode(int data, Node*& tree){
    Node* hot = NULL;
    Node*& x = searchNode(data,tree,hot);
    if(x)
        removeAt(x, hot);
    else
        return false;

    for (Node* g = hot; g; g = g->parent) {
        if(balanceFactor(g) > 1){
            Node*& parentPoint = fromParentTo(g);
            Node* childPoint = rotateAt(tallerChild(tallerChild(g)));
            parentPoint = childPoint;
//            g = parentPoint->parent;
//            g = fromParentTo(g) = rotateAt(tallerChild(tallerChild(g)));//TODO 重新接入原树
        }
//        updateHeightAbove(g);
        updateHeight(g);
    }
    return true;
}

void preOrder(Node* tree){
    if(tree){
        preOrder(tree->lChild);
        printf("%d ",tree->value);
        preOrder(tree->rChild);
    }
}

int main(){

    int arr[16]= {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9};
    Root = createNode(arr[0],0,NULL,NULL,NULL);

    for (int i = 1; i < 16; ++i) {
        insertAvlNode(arr[i], Root);
        preOrder(Root);
        cout << endl;
    }

//    for (int j = 6; j >= 0; --j) { 
    for (int j = 0; j < 16; ++j) {
        removeAvlNode(arr[j], Root);
        preOrder(Root);
        cout << endl;
    }
    return 0;
}


//注意空节点的处理，
//引用与指针的取舍
//为什么删除节点是删除节点的直接后继