#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

const int MAXN=200001;
using namespace std;
struct SplayTree
{
    struct ST_Node
    {
        ST_Node *left,*right,*father;
        int value,weight;
    }*root;
    int SC;
    ST_Node SE[MAXN];
    void ZIG(ST_Node *x)
    {
        ST_Node *y=x->father;
        // x->right
        y->left = x->right;
        if (x->right)
            x->right->father=y;
        // y->father
        x->father = y->father;
        if (y->father)
        {
            if (y==y->father->left)
                y->father->left = x;
            else
                y->father->right = x;
        }
        // y
        x->right = y;
        y->father = x;
    }
    void ZAG(ST_Node *x)
    {
        ST_Node *y=x->father;
        // x->left
        y->right = x->left;
        if (x->left)
            x->left->father=y;
        // y->father
        x->father = y->father;
        if (y->father)
        {
            if (y==y->father->left)
                y->father->left = x;
            else
                y->father->right = x;
        }
        // y
        x->left = y;
        y->father = x;
    }
    void Splay(ST_Node *x,ST_Node *y)
    {
        while (x->father != y)
        {
            if (x->father->father == y)
            {
                if (x->father->left == x)
                    ZIG(x);
                else
                    ZAG(x);
            }
            else if (x->father->father->left == x->father)
            {
                if (x->father->left == x)
                {
                    ZIG(x->father);
                    ZIG(x);
                }
                else
                {
                    ZAG(x);
                    ZIG(x);
                }
            }
            else
            {
                if (x->father->right == x)
                {
                    ZAG(x->father);
                    ZAG(x);
                }
                else
                {
                    ZIG(x);
                    ZAG(x);
                }
            }
        }
        if (y==0)
            root=x;
    }
    void insert(int value)
    {
        ST_Node **p=&root,*y=0;
        for (;;)
        {
            if (!*p)
            {
                *p=SE+ (++SC);
                (*p)->left = (*p)->right = 0;
                (*p)->value = value;
                (*p)->weight = 1;
                (*p)->father = y;
                Splay(*p,0);
                break;
            }
            y=*p;
            if (value == (*p)->value)
            {
                (*p)->weight ++;
                Splay(*p,0);
                break;
            }
            else if (value < (*p)->value)
                p=&(*p)->left;
            else
                p=&(*p)->right;
        }
    }
    ST_Node* join(ST_Node *a,ST_Node *b)
    {
        if (a) a->father=0;
        if (b) b->father=0;
        if (!b)    return a;
        if (!a) return b;
        ST_Node *c=a;
        for (;c->right;c=c->right);
        Splay(c,0);
        c->right=b;
        b->father=c;
        return c;
    }
    void remove(ST_Node *x)
    {
        Splay(x,0);
        root=join(x->left,x->right);
    }
    void delmin(int &min,int &cnt)
    {
        ST_Node *x=root;
        for (;x->left;x=x->left);
        min=x->value; cnt=x->weight;
        remove(x);
    }
}Splay;


int main(){

}
