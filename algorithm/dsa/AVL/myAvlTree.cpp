#include <iostream>

#define HEIGHT(p)    ( (p==NULL) ? -1 : (((Node *)(p))->height) )

using namespace std;

struct Node{
    int key;
    int height;
    Node* left;
    Node* right;
};

typedef Node* AVLTree;

// 返回某个节点的高度
int NodeHeight(Node* tree){
    return (tree ? tree->height : -1);// 空树高度为-1
}

// 中序遍历
void inorder(AVLTree tree){
    if(tree){
        inorder(tree->left);
        cout << tree->key << " ";
        inorder(tree->right);
    }
}

// 递归的搜索
Node* avlTreeSearch(AVLTree tree, int key){
    if(tree == NULL || key == tree->key){
        return tree;
    }
    if(key > tree->key){
        return avlTreeSearch(tree->right, key);
    } else {
        return avlTreeSearch(tree->left, key);
    }
}

Node* LL(AVLTree tree){

    Node* p = tree->left;
    tree->left = p->right;
    p->right = tree;

    tree->height = max(HEIGHT(tree->left), HEIGHT(tree->right)) + 1;// 注意高度更新的顺序
    p->height = max(HEIGHT(p->left), tree->height) + 1;
    return p;
}

Node* RR(AVLTree tree){

    Node* p = tree->right;
    tree->right = p->left;
    p->left = tree;

    tree->height = max(HEIGHT(tree->left), HEIGHT(tree->right)) + 1;
    p->height = max(HEIGHT(p->left), tree->height) + 1;

    return p;
}

Node* LR(AVLTree tree){
    tree->left = RR(tree->left);
    return LL(tree);
}
Node* RL(AVLTree tree){
    tree->right = LL(tree->right);
    return RR(tree);
}


Node* avlTreeInsert(AVLTree tree, int key){
    if(tree == NULL){
        tree = (Node*)malloc(sizeof(Node));
        if(tree == NULL){
            cout << "create error" << endl;
            return NULL;
        } else {
            tree->right = NULL;
            tree->left = NULL;
            tree->key = key;
            tree->height = 0;
        }
    } else if (key > tree->key){
        tree->right = avlTreeInsert(tree->right, key);
        if(HEIGHT(tree->right) - HEIGHT(tree->left) == 2){
            if(key > tree->right->key)
                tree = RR(tree);
            else
                tree = RL(tree);
        }
    } else if (key < tree->key){
        tree->left = avlTreeInsert(tree->left, key);
        if(HEIGHT(tree->left) - HEIGHT(tree->right) == 2){
            if(key < tree->left->key)
                tree = LL(tree);
            else
                tree = LR(tree);
        }
    } else {
        cout << "重复节点" << endl;
    }

    tree->height = max(HEIGHT(tree->left), HEIGHT((tree->right))) + 1;

    return tree;
}

// 找到当前子树中的最小值节点
Node* minNode(AVLTree tree){
    while (tree->left){
        tree = tree->left;
    }
    return tree;
}

Node* avlTreeDelete(AVLTree tree, int key){
    // 根为空 或者 没有要删除的节点，直接返回NULL。
    if (tree==NULL)
        return NULL;

    if (key < tree->key)        // 待删除的节点在"tree的左子树"中
    {
        tree->left = avlTreeDelete(tree->left, key);
        // 删除节点后，若AVL树失去平衡，则进行相应的调节。
        if (HEIGHT(tree->right) - HEIGHT(tree->left) == 2)
        {
            Node *r =  tree->right;
            if (HEIGHT(r->left) > HEIGHT(r->right))
                tree = RL(tree);
            else
                tree = RR(tree);
        }
    }
    else if (key > tree->key)// 待删除的节点在"tree的右子树"中
    {
        tree->right = avlTreeDelete(tree->right, key);
        // 删除节点后，若AVL树失去平衡，则进行相应的调节。
        if (HEIGHT(tree->left) - HEIGHT(tree->right) == 2)
        {
            Node *l =  tree->left;
            if (HEIGHT(l->right) > HEIGHT(l->left))
                tree = LR(tree);
            else
                tree = LL(tree);
        }
    }
    else    // tree是对应要删除的节点。
    {
        // tree的左右孩子都非空
        if ((tree->left) && (tree->right))
        {
            Node* p = minNode(tree->right);
            tree->key = p->key;
            tree->right = avlTreeDelete(tree->right, p->key);
        }
        else
        {
            Node *tmp = tree;
            tree = tree->left ? tree->left : tree->right;
            free(tmp);
        }
    }

    return tree;
}

int main(){
    int arr[]= {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9};
    AVLTree Root= (Node*)malloc(sizeof(Node));
    Root->right = NULL;
    Root->left = NULL;
    Root->height = 0;
    Root->key = arr[0];
    for (int i = 1; i < 16; ++i) {
        Root = avlTreeInsert(Root, arr[i]);
        inorder(Root);
        cout << endl;
    }

    for (int i = 6; i < 16; ++i) {
        Root = avlTreeDelete(Root, arr[i]);
        inorder(Root);
        cout << endl;
    }

    return 0;
}