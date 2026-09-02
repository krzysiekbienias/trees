#include "binary_tree/symmetrical_tree.hpp"

#include <string>
#include <vector>
#include <tree_node.hpp>

bool isMirror(TreeNode* left,TreeNode* right) {
    if (left==nullptr && right==nullptr) {
        return true;
    }
    if ((left!=nullptr && right==nullptr) || (left==nullptr && right!=nullptr)) {
        return false;
    }

    return (left->m_val==right->m_val &&
        isMirror(left->right,right->left) &&
        isMirror(left->left,right->right));
}


bool isSymmetric(TreeNode* root) {
    if (root==nullptr) {
        return true;
    }
    return isMirror(root->left,root->right);
}