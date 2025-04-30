#include "utils.hpp"

int main() {
    Node* root = create_node(10);
    root->insert(5);
    root->insert(15);
    root->insert(3);
    root->insert(7);

    std::cout << "Infix display: ";
    root->display_infix();
    std::cout << std::endl;

    std::cout << "Tree height: " << root->height() << std::endl;

    Node*& leftmost = most_left(root);
    if (leftmost) {
        std::cout << "Leftmost node value: " << leftmost->value << std::endl;
    }

    int value_to_remove = 5;
    if (remove(root, value_to_remove)) {
        std::cout << "Value " << value_to_remove << " removed successfully." << std::endl;
    } else {
        std::cout << "Value " << value_to_remove << " not found in the tree." << std::endl;
    }

    std::cout << "Infix display: ";
    root->display_infix();
    std::cout << std::endl;
    
    try {
        std::cout << "Minimum value in the tree: " << root->min(root) << std::endl;
        std::cout << "Maximum value in the tree: " << root->max(root) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    delete_tree(root);
    return 0;
}