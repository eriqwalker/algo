/*
 * Eriq Walker
 * z1908120
 * CSCI-340-2
 * 
 * I certify that this is my own work and where appropriate an extension
 *  of the starter code provided for the assignment.
 * 
 * */
#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "binarytree.h"
#include "node.h"

template <typename T>
class BinarySearchTree : public BinaryTree<T> {
public:
    void Insert(const T &x);
    bool Search(const T &x) const;
    bool Remove(const T &x);

private:
    void _Insert(Node<T> *&, const T &);
    bool _Search(Node<T> * , const T &) const;
    void _Remove(Node<T> *&, const T &);
    bool _Leaf  (Node<T> *node) const;
};


//Public functions
template <class T> void BinarySearchTree<T>::Insert(const T &x)       {        _Insert(this->root, x); }
template <class T> bool BinarySearchTree<T>::Search(const T &x) const { return _Search(this->root, x); }
template <class T> bool BinarySearchTree<T>::Remove(const T &x)       { 
    if (Search(x)) {
        _Remove(this->root, x);
        return true;
    }
    return false;
}

//Private functions
template <class T> void BinarySearchTree<T>::_Insert(Node<T> *&node, const T &x) {
    if (node == nullptr) node = new Node<T>(x);
    else {
        if (x > node->data) _Insert(node->right, x);
        if (x < node->data) _Insert(node->left , x);
    }
}

template <class T> bool BinarySearchTree<T>::_Search(Node<T> *node, const T &x) const {
    if (node == nullptr) return false;
    if (x > node->data)  return _Search(node->right, x);
    if (x < node->data)  return _Search(node->left , x);
    if (_Leaf(node)) return true;
    return false;
}

template <class T> void BinarySearchTree<T>::_Remove(Node<T> *&node, const T &x) {
    if (x >  node->data)  _Remove(node->right, x);
    if (x <  node->data)  _Remove(node->left , x);
    if (x == node->data)  node = nullptr;
}

template <class T> bool BinarySearchTree<T>::_Leaf(Node<T> *node) const {
    if (node->right == nullptr 
     && node->left  == nullptr) return true;
    return false;
}














#endif // End of BINARYSEARCHTREE_H_
