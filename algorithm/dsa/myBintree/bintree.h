#pragma once

#include "binnode.h"

template <typename T> class BinTree{
    int _size;
    BinNodePosi(T) _root;
    virtual int updateHeight(BinNodePosi(T) x);//更新节点高度
    void updateHeightAbove(BinNodePosi(T) x);//更新节点及以上所有节点的高度

public:
    BinTree():_size(0),_root(NULL){}
    ~BinTree(){if(0 < _size) remove(_root);}
    int size() const { return _size;}
    bool empty() const { return !_root;}
    BinNodePosi(T) root() const { return _root;}
    BinNodePosi(T) insertAsRoot (T const& e);//e作为根插入
    BinNodePosi(T) insertAsLC (BinNodePosi(T) x,T const& e);//e作为x的左孩子(原无)插入
    BinNodePosi(T) insertAsRC (BinNodePosi(T) x,T const& e);//e作为x的右孩子(原无)插入
    BinNodePosi(T) attachAsLC (BinNodePosi(T) x,BinTree<T>* &t);//t作为x的左子树接入
    BinNodePosi(T) attachAsRC (BinNodePosi(T) x,BinTree<T>* &t);//t作为x的右子树接入

    int remove(BinNodePosi(T) x);//删除x节点的子树,并返回规模

};
