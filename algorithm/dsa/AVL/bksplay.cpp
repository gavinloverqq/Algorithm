#include <stdio.h>
#include <iostream>

using namespace std;

struct Node{
    int key;
    Node* lChild;
    Node* rChild;
    Node* parent;

    Node() = default;
    Node(int data, Node* l = NULL, Node* r = NULL, Node* p = NULL):key(data),lChild(l),rChild(r),parent(p){}
};

Node* Root;

void attachAsLChild(Node* tree, Node* son){
    tree->lChild = son;
    if(son)
        son->parent = tree;
}
void attachAsRChild(Node* tree, Node* son){
    tree->rChild = son;
    if(son)
        son->parent = tree;
}

Node*  search(Node* tree, int data, Node*& hot){

    if(tree == NULL || data == tree->key)
        return tree;
    hot = tree;
    if(tree->key < data)
        return search(tree->lChild, data, hot);
    else
        return search(tree->rChild, data, hot);
}

Node* Splay(Node* v){
    if(!v) return NULL;
    Node* p;
    Node* g;
    while ((p = v->parent) && (g = p->parent)){
        Node* gp = g->parent;
//        双旋
        if(p->lChild == v){
            if(g->lChild == p){
                attachAsLChild(g, p->rChild);
                attachAsLChild(p, v->rChild);
                attachAsRChild(p, g);
                attachAsRChild(v, p);
            } else {
                attachAsLChild(p, v->rChild);
                attachAsRChild(g, v->lChild);
                attachAsRChild(v, p);
                attachAsLChild(v, g);
            }
        } else {
            if(g->rChild == p){
                attachAsRChild(g, p->lChild);
                attachAsRChild(p, v->lChild);
                attachAsLChild(p, g);
                attachAsLChild(v, p);
            } else {
                attachAsRChild(p, v->lChild);
                attachAsLChild(g, v->rChild);
                attachAsLChild(v, p);
                attachAsRChild(v, g);
            }
        }
//        接到上面
        if(!gp)
            v->parent = NULL;
        else
            (g == gp->lChild) ? attachAsLChild(gp, v) : attachAsRChild(gp, v);
    }
    if(p = v->parent){
        if(p->lChild == v){
            attachAsLChild(p, v->rChild);
            attachAsRChild(v, p);
        } else {
            attachAsRChild(p, v->lChild);
            attachAsLChild(v, p);
        }
    }
    v->parent = NULL;
    return v;
}

Node* searchNode(Node* tree, int data, Node*& hot){
    Node* p = search(tree, data, hot);
    return Splay(p ? p : hot); // 到叶子节点的话，把最后访问的节点伸展到树根
}

Node* insertNode(Node* tree, int data){
    Node* hot = tree;
    Node* p = searchNode(tree, data, hot);
    if(!hot) {
        return Root = new Node(data);
    }
    if(data == p->key) return p;// 节点被伸展到树根
    if(data > p->key){
        p->parent = Root = new Node(data, p, p->rChild, NULL);
        if(p->rChild){
            p->rChild->parent = Root;
            p->rChild = NULL;
        }
    } else {
        p->parent = Root = new Node(data, p->lChild, p, NULL);
        if(p->lChild){
            p->lChild->parent = Root;
            p->lChild = NULL;
        }
    }
    return Root;
}

bool removeNode(Node* tree, int data){
    Node* hot = tree;
    Node* p = searchNode(tree, data, hot);
    Node* w = p;
    if(!hot) {
        Root = hot;
        return false;
    }
    if(!p->lChild){
        p = p->lChild;
        if(p)
            p->parent = NULL;
    } else if(!p->rChild){
        p = p->rChild;
        if(p)
            p->parent = NULL;
    } else {
        Node* l = p->lChild;
        l->parent = NULL;
        p->lChild = NULL;
        p = p->rChild;
        p->parent = NULL;
        Node* thot = p;
        Root = searchNode(p, w->key, thot);
        Root->lChild = l;
        l->parent = Root;
    }
    delete w;
    return true;
}

int main(){
    Root = NULL;
    insertNode(Root, 6);
    insertNode(Root, 5);
    insertNode(Root, 4);
    insertNode(Root, 3);
    insertNode(Root, 1);
    insertNode(Root, 2);

    Node* hot = Root;
    searchNode(Root, 2, hot);
    cout << Root->rChild->lChild->key << endl;
}