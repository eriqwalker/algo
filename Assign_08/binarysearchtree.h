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
    void Insert(const T &x);       //inserts note with x value
    bool Search(const T &x) const; //searches for node with x value
    bool Remove(const T &x);       //removes node with x value

private:
    void _Insert(Node<T> *&, const T &);       //private insert called by public insert
    bool _Search(Node<T> * , const T &) const; //private search called by public search
    void _Remove(Node<T> *&, const T &);       //private remove called by public remove
    bool _Leaf  (Node<T> *node) const;         //private function for determining if something is a leaf
};


//Public functions
//calls the private insert, adding the root as an argument
template <class T> void BinarySearchTree<T>::Insert(const T &x)       {        _Insert(this->root, x); }
//calls the private search, adding the root as an argument
template <class T> bool BinarySearchTree<T>::Search(const T &x) const { return _Search(this->root, x); }
//calls search, if found, calls the private remove and return true
template <class T> bool BinarySearchTree<T>::Remove(const T &x)       { 
    if (Search(x)) {
        _Remove(this->root, x);
        return true;
    }
    return false;
}

//Private functions
//if the node is null then it adds a node in that position with value x
//otherwise is finds its way down the tree to the right spot where it is
//null and can then be added
template <class T> void BinarySearchTree<T>::_Insert(Node<T> *&node, const T &x) {
    if (node == nullptr) node = new Node<T>(x);
    else {
        if (x > node->data) _Insert(node->right, x);
        if (x < node->data) _Insert(node->left , x);
    }
}

//searches the tree for a node with value x. if it's found and it is a
//leaf then it returns true, otherwise if the node doesn't exist or isn't
//a leaf then it returns false
template <class T> bool BinarySearchTree<T>::_Search(Node<T> *node, const T &x) const {
    if (node == nullptr) return false;
    if (x > node->data)  return _Search(node->right, x);
    if (x < node->data)  return _Search(node->left , x);
    if (_Leaf(node)) return true;
    return false;
}

//finds its way to the node that needs to be removed and then sets it to
//nullptr, I added the if x == node->data just incase somehow a number
//that shouldn't have made its way here, it wouldn't remove something
//that wasn't there or something that it wasn't supposed to
template <class T> void BinarySearchTree<T>::_Remove(Node<T> *&node, const T &x) {
    if (x >  node->data)  _Remove(node->right, x);
    if (x <  node->data)  _Remove(node->left , x);
    if (x == node->data)  node = nullptr;
}

//just checks to see if the node has any kids. if no kids then it is 
//a leaf and returns true
template <class T> bool BinarySearchTree<T>::_Leaf(Node<T> *node) const {
    if (node->right == nullptr 
     && node->left  == nullptr) return true;
    return false;
}

#endif // End of BINARYSEARCHTREE_H_
