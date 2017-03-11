#include "bintree.h"

template <typename T>
int BinTree<T>::updateHeight(BinNode<T> *x) {
    return x->height = 1 + max(stature(x->lc),stature(x->rc));
}


//更新节点及以上所有节点的高度
template <typename T>
void BinTree<T>::updateHeightAbove(BinNodePosi(T) x) {
    while (x){
        updateHeight(x);
        x = x->parent;
    }
}

//作为跟插入,返回新插入的节点
template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRoot(T const &e) {
    _size = 1;
    return _root = new BinNode<T> (e);
}

//e作为x的左孩子(原无)插入,返回新插入的节点
template <typename T>
BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, T const &e) {
    _size++;
    x->insertAsLC(e);
    updateHeightAbove(x);
    return x->lc;
}

//e作为x的右孩子(原无)插入,返回新插入的节点
template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const &e) {
    _size++;
    x->insertAsRC(e);
    updateHeightAbove(x);
    return x->rc;
}

//t作为x的左子树接入
template <typename T>
BinNodePosi(T) BinTree<T>::attachAsLC (BinNodePosi(T) x,BinTree<T>* &t){
    if(x->lc = t->_root)//TODO t->root() 为什么不是?
        x->lc->parent = x;//接入
    _size += t->_size;//TODO t->size() ?
    updateHeightAbove(x);

//    释放原树
    t->_root = NULL;
    t->_size = 0;
//    release(t);
    t = NULL;

    return x;//返回接入位置
}

//t作为x的右子树接入
template <typename T>
BinNodePosi(T) BinTree<T>::attachAsRC (BinNodePosi(T) x,BinTree<T>* &t){
    if(x->rc = t->_root)//TODO t->root() 为什么不是?
        x->rc->parent = x;//接入
    _size += t->_size;//TODO t->size() ?
    updateHeightAbove(x);

//    释放原树
    t->_root = NULL;
    t->_size = 0;
//    release(t);
    t = NULL;

    return x;//返回接入位置
}


//子树删除
template <typename T>
int BinTree<T>::remove(BinNode<T> *x) {

}