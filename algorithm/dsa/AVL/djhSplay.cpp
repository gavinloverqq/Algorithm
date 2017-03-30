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

};

Node* Splay(Node* tree){
    if(!tree)
        return NULL;
    Node* p;
    Node* g;
    while ((p->parent) && (g->parent)){
        
    }
}

Node* search(Node* tree, int data){

}

Node* insertNode(Node* tree, int data){

}

Node* removeNode(Node* tree, int data){

}


int main(){

}