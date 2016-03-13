#include <exception>
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
    _root_node = nullptr;
}

BinarySearchTree::BinarySearchTree(Node* root_node)
{
    _root_node = root_node;
}

BinarySearchTree::~BinarySearchTree()
{
    clear();
    _root_node = nullptr;
}

bool BinarySearchTree::add(int key, int value)
{
    if (_root_node == nullptr)
    {
        _root_node = create_new_node(key, value);
        return true;
    }

    Node* current_node = _root_node;

    while (true)
    {
        if (current_node->key == key)
        {
            return false;
        }

        if (key < current_node->key)
        {
            if (current_node->left_child == nullptr)
            {
                current_node->left_child = create_new_node(key, value);
                current_node->left_child->parent = current_node;
                return true;
            }

            current_node = current_node->left_child;
        }

        if (key > current_node->key)
        {
            if (current_node->right_child == nullptr)
            {
                current_node->right_child = create_new_node(key, value);
                current_node->right_child->parent = current_node;
                return true;
            }

            current_node = current_node->right_child;
        }
    }
}

Node* BinarySearchTree::choice(Node* first_node, Node* second_node)
{
    if (first_node != nullptr)
    {
        return first_node;
    }

    return second_node;
}


void BinarySearchTree::clear()
{
    delete_node(_root_node);
    _root_node = nullptr;
}

BinarySearchTree* BinarySearchTree::clone() const
{
    Node* new_root_node = clone(_root_node);

    return new BinarySearchTree(new_root_node);
}

Node* BinarySearchTree::clone(Node* node) const
{
    if (node == nullptr)
    {
        return nullptr;
    }

    Node* cloned_node = create_new_node(node->key, node->value);
    
    if (node->left_child != nullptr)
    {
        cloned_node->left_child = clone(node->left_child);
    }

    if (node->right_child != nullptr)
    {
        cloned_node->right_child = clone(node->right_child);
    }

    return cloned_node;
}

bool BinarySearchTree::contains_key(int key) const
{
    return search(key, _root_node) != nullptr;
}

Node* BinarySearchTree::search(int key, Node* node) const
{
    Node* result = nullptr;

    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->key == key)
    {
        return node;
    }

    return choice(search(key, node->left_child), search(key, node->right_child));
}

Node* BinarySearchTree::create_new_node(int key, int value)
{
    Node* node = new Node;

    node->parent = nullptr;
    node->left_child = nullptr;
    node->right_child = nullptr;
    node->key = key;
    node->value = value;

    return node;
}

void BinarySearchTree::delete_node(Node* node) const
{
    if (node != nullptr)
    {
        delete_node(node->left_child);
        delete_node(node->right_child);

        node->left_child = nullptr;
        node->right_child = nullptr;

        delete node;
    }
}

void BinarySearchTree::remove(int key)
{
    Node* node = search(key);

    if (node != nullptr)
    {
        
    }
}

int BinarySearchTree::size() const
{
    return size(_root_node);
}

Node* BinarySearchTree::search(int key) const
{
    return search(key, _root_node);
}


int BinarySearchTree::size(Node* node) const
{
    int counter = 0;

    if (node == nullptr)
    {
        return 0;
    }

    if (node->left_child != nullptr)
    {
        counter = size(node->left_child) + 1;
    }

    if (node->right_child != nullptr)
    {
        counter = size(node->right_child) + 1;
    }

    return counter;
}
