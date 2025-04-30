#pragma once
#include <vector>
#include <iostream>

struct Node
{
    int value;
    Node *left{nullptr};
    Node *right{nullptr};

    // Méthodes
    bool is_leaf() const;
    void insert(int value);
    int height() const;
    void delete_children();
    void display_infix() const;
    std::vector<Node const *> prefix() const;
    int min(const Node* node);
    int max(const Node* node);
};

Node *create_node(int value);
bool remove(Node *&node, int value);
Node *&most_left(Node *&node);
void delete_tree(Node* node);