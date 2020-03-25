#pragma once 

#include "binarytree.h"

template <typename T> 
class SearchNode : public Node<T>
{
public:
    SearchNode(T item, Node<T>* left, Node<T>* right)
        : Node<T>(item, left, right)
    {
    }
    ~SearchNode()
    {
    }

    int getFactor(void)
    {
        int factor = 0;
        if(this->isLeaf())
            factor = 0;
        else
        {
            int leftH = -1;
            int rightH = -1;
            if(this->left)
                leftH = this->left->height();
            if(this->right)
                rightH = this->right->height();
            factor = leftH - rightH;
        }
        return factor;
    }
};

template <typename T>
class BinarySearchTree : public BinaryTree<SearchNode, T>
{
public:
    BinarySearchTree() {}
    BinarySearchTree(T data) : BinaryTree<SearchNode, T>(data) {}
    BinarySearchTree(SearchNode<T>* subRoot) : BinaryTree<SearchNode, T>(subRoot) {}
    ~BinarySearchTree() {}

    void insert(T data)
    {
        if(!this->root) {
            this->root = new SearchNode<T>(data, nullptr, nullptr);
            return ;
        }

        std::function<void(SearchNode<T>* n, T data)> go;
        go = [this, &go](SearchNode<T>* n, T data) -> void
        {
            if(n->isLeaf())
            {
                n->item > data ? this->setLeft(n, data) : this->setRight(n, data);
            }
            else {
                SearchNode<T>* get = static_cast<SearchNode<T>*>(n->item > data ? n->left : n->right);
                if(get) 
                    go(get, data);
                else 
                    n->item > data ? this->setLeft(n, data) : this->setRight(n, data);
            }
        };
        go(this->root, data);
        this->root = balancing(this->root);
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
        go(this->root, data);
    }
    SearchNode<T>* balancing(SearchNode<T>* root)
    {
        if(root == nullptr)
            return nullptr;

        root->left = balancing(castToNode(root->left));
        root->right = balancing(castToNode(root->right));
        int factor = root->getFactor();
        if(-2 < factor && factor < 2)
            return root;
        // Left Rotation 
        else if(2 <= factor) 
            return castToNode(root->left)->getFactor() > 0 ? rotateLL(root) : rotateLR(root);
        // Right Rotation
        else if(factor <= -2)
            return castToNode(root->right)->getFactor() < 0 ? rotateRR(root) : rotateRL(root);
        return root;
    }

    static SearchNode<T>* rotateLL(SearchNode<T>* parent)
    {
        auto child = castToNode(parent->left);
        parent->left = child->right;
        child->right = parent;
        return child;
    }
    static SearchNode<T>* rotateRR(SearchNode<T>* parent)
    {
        auto child = castToNode(parent->right);
        parent->right = child->left;
        child->left = parent;
        return child;
    }
    static SearchNode<T>* rotateLR(SearchNode<T>* parent)
    {
        auto child = castToNode(parent->left);
        parent->left = rotateRR(child);
        return rotateLL(parent);
    }
    static SearchNode<T>* rotateRL(SearchNode<T>* parent)
    {
        auto child = castToNode(parent->right);
        parent->right = rotateLL(child);
        return rotateRR(parent);
    }
public:
    static SearchNode<T>* castToNode(Node<T>* n)
    {
        return static_cast<SearchNode<T>*>(n);
    }
};