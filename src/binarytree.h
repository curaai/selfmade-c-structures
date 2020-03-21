#pragma once 

#include "linkedlist.h"


template <typename T> class BinaryTree;

template <typename T>
class Node
{
friend class BinaryTree<T>;
private:
    Node(T item, Node<T>* left, Node<T>* right)
        : item(item), left(left), right(right) {}
    ~Node()
    {
    }
public:
    Node<T>* getLeft(void) { return left; }
    Node<T>* getRight(void) { return right; }
    bool isLeaf(void) {return left == nullptr && right == nullptr; }
public:
    T item;
private:
    Node<T>* left;
    Node<T>* right;
};

template <typename T>
using node = Node<T>*;

template <typename T>
class BinaryTree
{
public:
    BinaryTree(T data) {
        root = new Node<T>(data, nullptr, nullptr);
    }
    ~BinaryTree() {
        remove(root);
    }

    void remove(Node<T>* l)
    {
        if(l == nullptr)
            return;
        if(l->left != nullptr)
            remove(l->left);
        if(l->right != nullptr)
            remove(l->right);
        delete l;
        count--;
    }

    void rmLeft(Node<T>* n)
    {
        auto left = n->getLeft();
        if(left != nullptr)
            remove(left);
    }

    void rmRight(Node<T>* n)
    {
        auto right = n->getRight();
        if(right != nullptr)
            remove(right);
    }

    void merge(Node<T>* n, Node<T>* left, Node<T>* right)
    {
        if(left->isLeaf() && right->isLeaf()) {
            n->left = left;
            n->right = right;
        }
    }

    Node<T>* setLeft(Node<T>* n, T data)
    {
        n->left = new Node<T> (data, nullptr, nullptr);
        count++;
        return n->getLeft();
    }
    Node<T>* setRight(Node<T>* n, T data)
    {
        n->right = new Node<T> (data, nullptr, nullptr);
        count++;
        return n->getRight();
    }

    LinkedList<T>* preorder(void)
    {
        std::function<void(Node<T>* n, LinkedList<T>* t)> go;
        go = [&go](Node<T>* n, LinkedList<T>* t) -> void
        {
            if(n != nullptr) {
                t->add(n->item);
                go(n->left, t);
                go(n->right, t);
            }
        };
        auto list = new LinkedList<T>;
        go(root, list);
        return list;
    }
    LinkedList<T>* inorder(void)
    {
        std::function<void(Node<T>* n, LinkedList<T>* t)> go;
        go = [&go](Node<T>* n, LinkedList<T>* t) -> void
        {
            if(n != nullptr) {
                go(n->left, t);
                t->add(n->item);
                go(n->right, t);
            }
        };
        auto list = new LinkedList<T>;
        go(root, list);
        return list;
    }
    LinkedList<T>* postorder(void)
    {
        std::function<void(Node<T>* n, LinkedList<T>* t)> go;
        go = [&go](Node<T>* n, LinkedList<T>* t) -> void
        {
            if(n != nullptr) {
                go(n->left, t);
                go(n->right, t);
                t->add(n->item);
            }
        };
        auto list = new LinkedList<T>;
        go(root, list);
        return list;
    }

public:
    Node<T>* root;
    int count=0;
};
