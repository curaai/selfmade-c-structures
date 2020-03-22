#pragma once 

#include "linkedlist.h"
#include <functional>


template <typename T>
class Node
{
public:
    Node(T item, Node<T>* left, Node<T>* right)
        : item(item), left(left), right(right) {}
    ~Node()
    {
    }
public:
    bool isLeaf(void) {return left == nullptr && right == nullptr; }
    int height(void) 
    {
        if(isLeaf())   
            return 0;
        else 
        {
            int leftH = 0;
            int rightH = 0;
            if(left != nullptr)
                leftH = left->height();
            if(right != nullptr)
                rightH = left->height();
            int h = leftH >= right ? leftH : rightH;
            return h+1;
        }
    }
public:
    T item;
    Node<T>* left;
    Node<T>* right;
};


template <template<typename T> class N=Node,  typename T=int>
class BinaryTree
{
public:
    BinaryTree(T data) {
        root = new N<T>(data, nullptr, nullptr);
        count = 1;
    }
    BinaryTree(N<T>* subRoot)
    {
        root = subRoot;
        std::function<void(N<T>* n)> go;
        go = [&](N<T>* n) -> void
        {
            if(n->isLeaf())
                count++;
            else if(n->left != nullptr)
                go(n->left);
            else if(n->right != nullptr)
                go(n->right);
        };
        go(root);
    }
    ~BinaryTree() {
        remove(root);
    }

    void remove(N<T>* l)
    {
        if(l == nullptr)
            return;
        if(l->left)
            remove(static_cast<N<T>*>(l->left));
        if(l->right)
            remove(static_cast<N<T>*>(l->right));
        delete l;
        count--;
    }

    void rmLeft(N<T>* n)
    {
        auto left = n->left;
        if(left)
            remove(left);
    }

    void rmRight(N<T>* n)
    {
        auto right = n->right;
        if(right)
            remove(right);
    }

    void merge(N<T>* n, N<T>* left, N<T>* right)
    {
        if(left->isLeaf() && right->isLeaf()) {
            n->left = left;
            n->right = right;
        }
    }

    N<T>* setLeft(N<T>* n, T data)
    {
        n->left = new N<T> (data, nullptr, nullptr);
        count++;
        return static_cast<N<T>*>(n->left);
    }
    N<T>* setRight(N<T>* n, T data)
    {
        n->right = new N<T> (data, nullptr, nullptr);
        count++;
        return static_cast<N<T>*>(n->right);
    }

    LinkedList<T>* preorder(void)
    {
        std::function<void(N<T>*, LinkedList<T>*)> go;
        go = [&go](N<T>* n, LinkedList<T>* t) -> void
        {
            if(n != nullptr) {
                t->add(n->item);
                go(static_cast<N<T>*>(n->left), t);
                go(static_cast<N<T>*>(n->right), t);
            }
        };
        auto list = new LinkedList<T>;
        go(root, list);
        return list;
    }
    LinkedList<T>* inorder(void)
    {
        std::function<void(N<T>*, LinkedList<T>*)> go;
        go = [&go](N<T>* n, LinkedList<T>* t) -> void
        {
            if(n != nullptr) {
                go(static_cast<N<T>*>(n->left), t);
                t->add(n->item);
                go(static_cast<N<T>*>(n->right), t);
            }
        };
        auto list = new LinkedList<T>;
        go(root, list);
        return list;
    }
    LinkedList<T>* postorder(void)
    {
        std::function<void(N<T>*, LinkedList<T>*)> go;
        go = [&go](N<T>* n, LinkedList<T>* t) -> void
        {
            if(n != nullptr) {
                go(static_cast<N<T>*>(n->left), t);
                go(static_cast<N<T>*>(n->right), t);
                t->add(n->item);
            }
        };
        auto list = new LinkedList<T>;
        go(root, list);
        return list;
    }

public:
    N<T>* root;
    int count=0;
};
