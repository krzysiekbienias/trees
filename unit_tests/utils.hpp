#include <vector>
#include <queue>
#include <optional>

// Your node
class TreeNode {
public:
    int m_val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode(int val) : m_val(val), left(nullptr), right(nullptr) {}
};

// Build from level-order array with nulls.
// Example:
//   buildTree({1, 2, 3, std::nullopt, 4, std::nullopt, 5});
TreeNode* buildTree(const std::vector<std::optional<int>>& levelOrder) {
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

// Clean-up helper (useful in unit tests)
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}