#include <vector>
#include <queue>
#include <optional>
#include "tree_node.hpp"


// Build from level-order array with nulls.
// Example:
//   buildTree({1, 2, 3, std::nullopt, 4, std::nullopt, 5});
inline TreeNode* buildTree(const std::vector<std::optional<int>>& levelOrder) {
    if (levelOrder.empty() || !levelOrder[0].has_value()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(*levelOrder[0]);
    std::queue<TreeNode*> q;
    q.push(root);

    std::size_t i = 1;
    while (!q.empty() && i < levelOrder.size()) {
        TreeNode* parent = q.front();
        q.pop();

        // left child
        if (i < levelOrder.size() && levelOrder[i].has_value()) {
            parent->left = new TreeNode(*levelOrder[i]);
            q.push(parent->left);
        }
        ++i;

        // right child
        if (i < levelOrder.size() && levelOrder[i].has_value()) {
            parent->right = new TreeNode(*levelOrder[i]);
            q.push(parent->right);
        }
        ++i;
    }

    return root;
}

inline TreeNode* buildTreeIndexed(const std::vector<std::optional<int>>& a, std::size_t i = 0) {
    if (i >= a.size() || !a[i].has_value()) return nullptr;

    TreeNode* root = new TreeNode(a[i].value());
    root->left  = buildTreeIndexed(a, 2 * i + 1);
    root->right = buildTreeIndexed(a, 2 * i + 2);
    return root;
}

// Clean-up helper (useful in unit tests)
inline void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}


inline void dumpTree(TreeNode* root, std::string prefix = "") {
    if (!root) {
        std::cout << prefix << "nullptr" << std::endl;
        return;
    }
    std::cout << prefix << root->m_val << std::endl;
    dumpTree(root->left, prefix + "   L:  ");
    dumpTree(root->right, prefix + "   R:  ");
}

inline void printTreeFancy(TreeNode* node, std::string prefix = "", bool isLeft = false, bool isRoot = true) {
    if (!node) return;

    std::cout << prefix;
    if (!isRoot) {
        std::cout << (isLeft ? "├── " : "└── ");
    }
    std::cout << node->m_val << std::endl;

    // Obliczamy wcięcie dla kolejnego poziomu
    std::string nextPrefix = prefix + (isRoot ? "" : (isLeft ? "│   " : "    "));

    // Rysujemy dzieci tylko, jeśli istnieje chociaż jedno
    if (node->left || node->right) {
        if (node->left) {
            printTreeFancy(node->left, nextPrefix, true, false);
        } else {
            // Wypisujemy pusty lewy węzeł, żeby pokazać "dziurę"
            std::cout << nextPrefix << "├── [null]" << std::endl;
        }

        if (node->right) {
            printTreeFancy(node->right, nextPrefix, false, false);
        } else {
            // Wypisujemy pusty prawy węzeł
            std::cout << nextPrefix << "└── [null]" << std::endl;
        }
    }
}