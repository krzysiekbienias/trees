#include "tree_node.hpp"


bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr){
        return false;
    }
    TreeNode* runner=root;
    if(runner->left==nullptr && runner->right==nullptr){
        return runner->m_val==targetSum;
    }
    targetSum-=runner->m_val;
    return hasPathSum(runner->left,targetSum) ||hasPathSum(runner->right,targetSum);

}
