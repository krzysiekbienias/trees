#include "binary_tree/node_depths.hpp"

#include <string>
#include <vector>
#include "tree_node.hpp"


int nodeDepths(TreeNode* root) {
    int accumulatedSum=0;
    dfsNodeDepths(root, 0,accumulatedSum);
    return accumulatedSum;
}

void dfsNodeDepths(TreeNode *root, int currentDepth, int &accumulatedSum) {
    if (!root) return ; //equivalent if(root==nullptr)
    accumulatedSum+=currentDepth;
    dfsNodeDepths(root->left,currentDepth+1,accumulatedSum);
    dfsNodeDepths(root->right,currentDepth+1,accumulatedSum);
}

