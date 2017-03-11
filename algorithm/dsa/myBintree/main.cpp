#include <iostream>
//#include "binnode.h"
#include "bintree.h"
using namespace std;


void createTree(BinTree<int>& tree,BinNodePosi(int)& rt){
    if(tree.size() == 0){
        int data;
        cin >> data;
        rt = tree.insertAsRoot(data);
    } else {
        int ldata,rdata;
        cin >> ldata >> rdata;
        if(ldata != 0){
            rt->lc = tree.insertAsLC(rt->lc, ldata);
            createTree(tree, rt->lc);
        }
        if(rdata != 0) {
            rt->rc = tree.insertAsRC(rt->rc, rdata);
            createTree(tree, rt->rc);
        }
    }
}

void preOrder(const BinTree<int>& tree,BinNodePosi(int) rt){
    if(rt != NULL) {
        cout << rt->data << endl;
        preOrder(tree, rt->lc);
        preOrder(tree, rt->rc);
    }
}

int main() {

//    BinTree<int> Tree;
//    BinNodePosi(int) treeRt;
//    createTree(Tree,treeRt);
//    preOrder(Tree,treeRt);
    return 0;
}