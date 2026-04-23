#include <string>
#include <vector>
#include "tree_node.hpp"


int rangeSumBST(TreeNode* root, int low, int high) {
    if (root==nullptr) {
        return 0;
    }
    if (root->m_val<low) {
        return rangeSumBST(root->right,low,high);
    }
    if (root->m_val>high) {
        return rangeSumBST(root->left,low,high);
    }

    return root->m_val+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);

}