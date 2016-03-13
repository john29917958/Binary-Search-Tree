#pragma once
#ifndef BINARA_SEARCH_TREE
#define BINARY_SEARCH_TREE

struct Node
{
    int key;
    int value;
    Node* parent;
    Node* left_child;
    Node* right_child;
};

class BinarySearchTree
{
    Node* _root_node;
    static Node* choice(Node*, Node*);
    void clear();
    Node* clone(Node*) const;
    static Node* create_new_node(int, int);
    Node* search(int key, Node*) const;
    void delete_node(Node* node) const;
    int size(Node*) const;
protected:
    BinarySearchTree(Node*);
public:
    BinarySearchTree();
    ~BinarySearchTree();
    bool add(int, int);
    BinarySearchTree* clone() const;
    bool contains_key(int) const;
    void remove(int);
    Node* search(int) const;
    int size() const;
};

#endif
