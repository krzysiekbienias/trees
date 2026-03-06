#include <string>
#include <vector>
#include "tree_node.hpp"

TreeNode* nextGreaterNumber(TreeNode* root, int target) {
    TreeNode * runner=root;
    TreeNode * candidate=nullptr;

    while (runner!=nullptr) {
        int currentVal=runner->m_val;
        if (target<currentVal) {
            candidate=runner;
            runner=runner->left;
        }
        else
            runner=runner->right;
    }
    return candidate;
}