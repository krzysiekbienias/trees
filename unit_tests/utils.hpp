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