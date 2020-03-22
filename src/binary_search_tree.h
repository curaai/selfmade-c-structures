#pragma once 

#include "binarytree.h"

template <typename T> 
class SearchNode : public Node
{
friend class BinarySearchTree<T>;

private:
    SearchNode(T item, Node<T>* left, Node<T>* right)
        : Node(item, left, right)
        , factor(0)
    {
    }
    ~SearchNode()
    {
    }
public:
    void balancing(void)
    {
        if(isLeaf())
            factor = 0;
        else
        {

        }

    }

public:
    // balanced factor
    int factor;
};

template <typename T>
class BinarySearchTree : public BinaryTree
{
public:
    BinarySearchTree(T data) : BinaryTree(data) {}
    ~BinarySearchTree() : ~BinaryTree() {}

    void insert(T data)
    {
        std::function<void(Node<T>* n, T data)> go;
        go = [this, &go](Node<T>* n, T data) -> void
        {
            if(n->isLeaf())
            {
                auto setFunc = n->item > data ? this->setLeft : this->setRight;
                setFunc(n, data);
            }
            else {
                auto getFunc = n->item > data ? n->getLeft : n->getRight;
                auto setFunc = n->item > data ? this->setLeft : this->setRight;
                if(getFunc()) 
                    go(getFunc(), data);
                else 
                    setFunc(n, data);
            }
        };
        go(root, data);
    }
    void remove(T data)
    {
        std::function<void(Node<T>* n, T data)> go;
        go = [this, &go](Node<T>* n, T data) -> void
        {
            if(n->isLeaf())
            {
                if(n->item != data)
                    throw std::invalid_argument("Cannot find data for remove");
                else 
                    remove(n);
            } 
            else {
                auto getFunc = n->item > data ? n->getLeft : n->getRight;
                auto setFunc = n->item > data ? this->setLeft : this->setRight;
                if(getFunc()) 
                    go(getFunc(), data);
                else 
                    setFunc(n, data);
            }
        };
        go(root, data);

    }
};