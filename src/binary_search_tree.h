#pragma once 

#include "binarytree.h"

template <typename T> 
class SearchNode : public Node<T>
{
public:
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
            int leftH = -1;
            int rightH = -1;
            if(left)
                leftH = left->height();
            if(right)
                rightH = right->height();
            factor = leftH - rightH;
        }
    }

public:
    // balanced factor
    int factor;
};

template <typename T>
class BinarySearchTree : public BinaryTree<SearchNode, T>
{
public:
    BinarySearchTree() {}
    BinarySearchTree(T data) : BinaryTree(data) {}
    BinarySearchTree(SearchNode<T>* subRoot) : BinaryTree(subRoot) {}
    ~BinarySearchTree() {}

    void insert(T data)
    {
        if(!root) {
            root = new SearchNode<T>(data, nullptr, nullptr);
            return ;
        }

        std::function<void(SearchNode<T>* n, T data)> go;
        go = [this, &go](SearchNode<T>* n, T data) -> void
        {
            if(n->isLeaf())
            {
                n->item > data ? setLeft(n, data) : setRight(n, data);
            }
            else {
                SearchNode<T>* get = static_cast<SearchNode<T>*>(n->item > data ? n->left : n->right);
                if(get) 
                    go(get, data);
                else 
                    n->item > data ? setLeft(n, data) : setRight(n, data);
            }
        };
        go(root, data);
        updateFactors();
        auto inbNode = findInbalance();
        if(!inbNode)
            return;
        if(1 < inbNode->factor)
        {
            // llRotation(inbNode);
        }
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
    void updateFactors(void)
    {
        std::function<void(SearchNode<T>* n)> go;
        go = [&go](SearchNode<T>* n) -> void
        {
            n->balancing();
            if(n->left)
                castToNode(n->left)->balancing();
            if(n->right)
                castToNode(n->right)->balancing();
        };
        go(castToNode(root));
    }
    SearchNode<T>* findInbalance(void)
    {
        std::function<SearchNode<T>* (SearchNode<T>* n)> go;
        go = [&go](SearchNode<T>* n) -> SearchNode<T>* 
        {
            if(n->factor < -1 || 1 < n->factor)
                return n;

            SearchNode<T>* l=castToNode(n->left);
            SearchNode<T>* r=castToNode(n->right);
            SearchNode<T>* leftRes = nullptr;
            SearchNode<T>* rightRes = nullptr;
            if(l)
                leftRes = go(l);
            if(r)
                rightRes = go(r);
            return leftRes ? leftRes : rightRes;
        };
        return go(castToNode(root));
    }
public:
    static SearchNode<T>* castToNode(Node<T>* n)
    {
        return static_cast<SearchNode<T>*>(n);
    }
};