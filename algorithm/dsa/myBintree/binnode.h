#pragma once

#include <iostream>

#define BinNodePosi(T) BinNode<T>*
#define stature(p) ((p)?(p)->height : -1)//空树高度为-1

template <typename T>struct BinNode{
    T data;
    BinNodePosi(T) parent;
    BinNodePosi(T) lc;
    BinNodePosi(T) rc;
    int height;

    BinNode():parent(NULL),lc(NULL),rc(NULL),height(0){}
    BinNode(T e,BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL,BinNodePosi(T) rc = NULL,int h = 0):
            data(e),parent(p),lc(lc),rc(rc),height(h){}

    int size();//统计当前节点为根的子树规模
    BinNodePosi(T) insertAsLC(T const&);
    BinNodePosi(T) insertAsRC(T const&);
};
