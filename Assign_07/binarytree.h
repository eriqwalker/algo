/*
 * Eriq Walker
 * z1908120
 * CSCI-340-2
 * 
 * I certify that this is my own work and where appropriate an extension
 *  of the starter code provided for the assignment.
 * 
 * */


#ifndef H_BINARYTREE
#define H_BINARYTREE

#include "node.h"

//Side enum
typedef enum { left_side, right_side } SIDE;

//returning a random side
SIDE rnd() {
    return rand()%2 ? right_side : left_side;
}


template <typename T> class BinaryTree{

public:
    BinaryTree();                                      // default constructor
    unsigned     getSize() const;                      // returns size of tree
    unsigned     getHeight() const;                    // returns height of tree
    virtual void Insert(const T&);                     // inserts node in tree
    void         Inorder(void (*)(const T&));          // inorder traversal of tree

protected:
    Node<T> *root;                                      // root of tree

private:
    unsigned _getSize  (Node<T> *)  const;               // private version of getSize()
    unsigned _getHeight(Node<T> *)  const;               // private version of getHeight()
    void     _Insert   (Node<T> *&, const T&);           // private version of Insert()
    void     _Inorder  (Node<T> *, void (*)(const T&));  // private version of Inorder()
};

//Public functions
//each calls the private variation and does what the name suggests
template <class T>          BinaryTree<T>::BinaryTree()        { root = nullptr;          }
template <class T> unsigned BinaryTree<T>::getSize() const     { return _getSize(root);   }
template <class T> unsigned BinaryTree<T>::getHeight() const   { return _getHeight(root); }
template <class T> void     BinaryTree<T>::Insert(const T& x)  { return _Insert(root, j); }
template <class T> void     BinaryTree<T>::Inorder(void(*x)(const T&)) { _Inorder(root, k); }

//Private functions

//gets the size of the tree, and if the tree is empty it returns 0
template <class T> unsigned BinaryTree<T>::_getSize(Node<T> *N) const {
    if (N == nullptr) return 0;
    else return(_getSize(N->left)+1+_getSize(N->right));
}

//gets the height of the tree, and if the tree is empty it returns 0
template <class T> unsigned BinaryTree<T>::_getHeight(Node<T> *N) const {
    if (N == nullptr) return 0;
    
    int x = _getHeight(N->left);
    int y = _getHeight(N->right);
    
    if (x > y) return (x+1);
    return (y+1);
}

//insrts a node, if the tree is empty ir creates a new node as the root
template <class T> void BinaryTree<T>::_Insert(Node<T> *&N, const T& x) {
    if (N == nullptr) N = new Node<T>(j);
    else {
        SIDE s = rnd();
        if (s == left_side) _Insert(N->left, j);
        else _Insert(N->right, j);
    }
}

//inorder traversing the tree, if tree is empty it returns right away
template <class T> void BinaryTree<T>::_Inorder(Node<T> *N, void (*order)(const T&)) {
    if (N == nullptr) return;
    _Inorder(N->left, order);
    order(N->data);
    _Inorder(N->right, order);
}

#endif // End of H_BINARYTREE
