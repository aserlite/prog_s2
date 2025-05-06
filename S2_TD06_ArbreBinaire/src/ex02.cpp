#include "utils.hpp"
#include <numeric> // Pour std::accumulate

int main() {
    Node* root = create_node(5);
    root->insert(3);
    root->insert(7);
    root->insert(2);
    root->insert(4);
    root->insert(6);
    root->insert(8);
    root->insert(1);
    root->insert(9);
    root->insert(0);

    std::cout << "Infix display: ";
    root->display_infix();
    std::cout << std::endl;
    try {
        std::cout << "Minimum value in the tree: " << root->min(root) << std::endl;
        std::cout << "Maximum value in the tree: " << root->max(root) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    std::vector<Node const*> prefix_nodes = root->prefix();
    int sum = std::accumulate(prefix_nodes.begin(), prefix_nodes.end(), 0, 
        [](int acc, const Node* node) { return acc + node->value; });
    std::cout << "Sum of all node values (prefix order): " << sum << std::endl;

    std::cout << "Tree height: " << root->height() << std::endl;

    delete_tree(root);

    return 0;
}