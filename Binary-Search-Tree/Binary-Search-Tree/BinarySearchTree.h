#pragma once
#ifndef BINARA_SEARCH_TREE
#define BINARY_SEARCH_TREE

struct Node
{
    int value;
    Node* left_child;
    Node* right_child;
};

class BinarySearchTree
{
private:
    Node* _root_node;
    void clear();
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void add(int);
    BinarySearchTree* clone();
    bool contains_key();
    void remove(int);
    int size();
};

#endif
