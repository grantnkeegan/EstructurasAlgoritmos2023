// Este archivo es para el nodo que utilizaremos con el árbol binario.
// Código del profesor.

#ifndef _BSTNODE_H_
#define _BSTNODE_H_

template <class T>
class BSTNode {
  public:
    T data;
    BSTNode<T> *left;
    BSTNode<T> *right;
    BSTNode();
    BSTNode(T value);
};

template <class T>
BSTNode<T>::BSTNode() : data{}, left{nullptr}, right{nullptr} {}

template <class T>
BSTNode<T>::BSTNode(T value) : data{value}, left{nullptr}, right{nullptr} {}


#endif // _BSTNODE_H_