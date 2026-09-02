#include <string>
#include <vector>
#include "tree_node.hpp"


TreeNode* invertTree(TreeNode* root) {
    if (root==nullptr) {
        return nullptr;
    }
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* temp=q.front();
        q.pop();

        std::swap(temp->right,temp->left);
        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }
    return root;
}