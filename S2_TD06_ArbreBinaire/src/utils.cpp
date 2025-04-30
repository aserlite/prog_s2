#include "utils.hpp"

Node *create_node(int value)
{
    return new Node{value};
}

bool Node::is_leaf() const
{
    return left == nullptr && right == nullptr;
}

void Node::insert(int value)
{
    if (value < this->value)
    {
        if (left == nullptr)
        {
            left = create_node(value);
        }
        else
        {
            left->insert(value);
        }
    }
    else
    {
        if (right == nullptr)
        {
            right = create_node(value);
        }
        else
        {
            right->insert(value);
        }
    }
}

int Node::height() const
{
    int left_height = left ? left->height() : 0;
    int right_height = right ? right->height() : 0;
    return 1 + std::max(left_height, right_height);
}

void Node::delete_children()
{
    if (left)
    {
        left->delete_children();
        delete left;
        left = nullptr;
    }
    if (right)
    {
        right->delete_children();
        delete right;
        right = nullptr;
    }
}

void Node::display_infix() const
{
    if (left)
    {
        left->display_infix();
    }
    std::cout << value << " ";
    if (right)
    {
        right->display_infix();
    }
}

std::vector<Node const *> Node::prefix() const
{
    std::vector<Node const *> result;
    result.push_back(this);
    if (left)
    {
        auto left_prefix = left->prefix();
        result.insert(result.end(), left_prefix.begin(), left_prefix.end());
    }
    if (right)
    {
        auto right_prefix = right->prefix();
        result.insert(result.end(), right_prefix.begin(), right_prefix.end());
    }
    return result;
}

Node *&most_left(Node *&node)
{
    if (node->left == nullptr)
    {
        return node;
    }
    return most_left(node->left);
}

bool remove(Node *&node, int value)
{
    if (node == nullptr)
    {
        return false;
    }

    if (value < node->value)
    {
        return remove(node->left, value);
    }
    else if (value > node->value)
    {
        return remove(node->right, value);
    }
    else
    {
        if (node->is_leaf())
        {
            delete node;
            node = nullptr;
            return true;
        }
        else if (node->left == nullptr)
        {
            Node *temp = node;
            node = node->right;
            delete temp;
            return true;
        }
        else if (node->right == nullptr)
        {
            Node *temp = node;
            node = node->left;
            delete temp;
            return true;
        }
        else
        {
            Node *&successor = most_left(node->right);
            node->value = successor->value;
            return remove(successor, successor->value);
        }
    }
}

void delete_tree(Node* node) {
    if (node == nullptr) {
        return;
    }

    delete_tree(node->left);
    delete_tree(node->right);

    delete node;
}

int Node::min(const Node* node) {
    if (node == nullptr) {
        throw std::runtime_error("Tree is empty, no minimum value.");
    }
    const Node* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current->value;
}

int Node::max(const Node* node) {
    if (node == nullptr) {
        throw std::runtime_error("Tree is empty, no maximum value.");
    }
    const Node* current = node;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current->value;
}