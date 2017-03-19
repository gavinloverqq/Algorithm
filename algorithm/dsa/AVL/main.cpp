#include <iostream>

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

Node* createNode(int data, int height, Node* lChild, Node* rChild, Node* parent){
    return new Node(data,height,lChild,rChild,parent);
}

inline
int balanceFactor(const Node* position){
    int lHeight = (position->lChild == NULL) ? -1 : position->lChild->height;
    int rHeight = (position->rChild == NULL) ? -1 : position->rChild->height;
    return abs(lHeight - rHeight);
}
inline
bool IsRchild(Node* p){
    return (p != Root) && (p->parent->rChild == p);
}
inline
bool IsLchild(Node* p){
    return (p != Root) && (p->parent->lChild == p);
}
inline
Node*& fromParentTo(Node*& p){//加引用
    return ( (p == Root) ? Root : (IsLchild(p) ? p->parent->lChild : p->parent->rChild ));//TODO p is root ????
}
inline
Node* tallerChild(Node* position){
    int lHeight = (position->lChild == NULL) ? -1 : position->lChild->height;
    int rHeight = (position->rChild == NULL) ? -1 : position->rChild->height;
    return (lHeight > rHeight ? position->lChild : (\
            lHeight < rHeight ? position->rChild : (\
            IsLchild(position) ? position->lChild : position->rChild)));
}

void updateHeight(Node* position){//不用引用
    int lHeight = (position->lChild == NULL) ? -1 : position->lChild->height;
    int rHeight = (position->rChild == NULL) ? -1 : position->rChild->height;
    position->height = max(lHeight,rHeight) + 1;
}

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

Node*& searchNode(int data, Node*& tree,Node*& hot){
    if(tree == NULL || (data == tree->value))return tree;
    hot = tree;
    return searchNode(data,((data < tree->value) ? tree->lChild : tree->rChild),hot);
}


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

Node* removeAt(Node*& position){
    Node* hot = position->parent;
    Node* succ = NULL;
    Node* w = position;

    if(position->lChild == NULL){
        succ = position = position->rChild;
    } else if(position->rChild == NULL){
        succ = position = position->rChild;
    } else {
        w = Succ(w);
        swap(w->value,position->value);
        Node* u = w->parent;
        ((u == position) ? u->rChild : u->lChild ) = succ = w->rChild; // TODO
    }
    hot = w->parent;
    if(succ) succ->parent = hot;
    return succ;
}


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
    b->rChild = c;
    a->parent = b;
    c->parent = b;

    return b;
}


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
            g = parentPoint->parent;
//            g = fromParentTo(g) = rotateAt(tallerChild(tallerChild(g)));//TODO 重新接入原树
            break;
        } else {
            updateHeightAbove(g);
        }
    }
    return xx;
}

bool removeAvlNode(int data, Node*& tree){
    Node* hot = NULL;
    Node*& x = searchNode(data,tree,hot);
    if(x)
        removeAt(x);
    else
        return false;

    for (Node* g = hot; g; g = g->parent) {
        if(balanceFactor(g) > 1){
            Node* parentPoint = fromParentTo(g);
            Node* childPoint = rotateAt(tallerChild(tallerChild(g)));
            parentPoint = childPoint;
            g = parentPoint->parent;
//            g = fromParentTo(g) = rotateAt(tallerChild(tallerChild(g)));//TODO 重新接入原树
        }
        updateHeightAbove(g);
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
        insertAvlNode(arr[i],Root);
        preOrder(Root);
        cout << endl;
    }

    return 0;
}