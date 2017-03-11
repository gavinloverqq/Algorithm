#include "binnode.h"


template <typename T>
int BinNode<T>::size(){
    return 1 + lc->size() + rc->size();
}

//均假设插入之前在插入位置都为空
template <typename T>
BinNodePosi(T) BinNode<T>::insertAsLC(T const& e){
    return lc = new BinNode(e,this);
}

template <typename T>
BinNodePosi(T) BinNode<T>::insertAsRC(T const& e){
    return rc = new BinNode(e,this);
}
