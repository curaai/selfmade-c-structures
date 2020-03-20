#pragma once 

#include "linkedlist.h"


template <typename T>
class Node
{
friend class BinaryTree
private:
    Node(T item, Node<T>* left, Node<T>* right)
        : item(item), left(left), right(right) {}
    ~Node()
    {
    }
public:
    Node<T>* getLeft(void) { return left; }
    Node<T>* getLeft(void) { return left; }
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
    BinaryTree(T data) {
        root = new Node<T>(data, nullptr, nullptr);
    }
    ~BinaryTree() {
        remove(root);
    }

    static void remove(node l)
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

    void rmLeft(node n)
    {
        auto left = n->getLeft();
        if(left != nullptr)
            remove(left);
    }

    void rmRight(node n)
    {
        auto right = n->getRight();
        if(right != nullptr)
            remove(right);
    }

    void merge(node n, node left, node right)
    {
        if(left->isLeaf() && right->isLeaf()) {
            n->left = left;
            n->right = right;
        }
    }

    node setLeft(node n, T data)
    {
        n->left = new Node<T> (data, nullptr, nullptr);
        count++;
        return n->getLeft();
    }
    node setRight(node n, T data)
    {
        n->right = new Node<T> (data, nullptr, nullptr);
        count++;
        return n->getRight();
    }

    LinkedList<T>* preorder(void)
    {
        auto go = [](node n, LinkedList<T>* t) {
            if(n != nullptr) {
                t->add(n->item);
                go(n->left, t);
                go(n->right, t);
            }
        }
        auto list = new LinkedList<T>;
        go(root, list);
        return list;
    }
    LinkedList<T>* inorder(void)
    {
        auto go = [](node n, LinkedList<T>* t) {
            if(n != nullptr) {
                go(n->left, t);
                t->add(n->item);
                go(n->right, t);
            }
        }
        auto list = new LinkedList<T>;
        go(root, list);
        return list;
    }
    LinkedList<T>* postorder(void)
    {
        auto go = [](node n, LinkedList<T>* t) {
            if(n != nullptr) {
                go(n->left, t);
                go(n->right, t);
                t->add(n->item);
            }
        }
        auto list = new LinkedList<T>;
        go(root, list);
        return list;
    }

public:
    node root;
    int count=0;
};
