#include <string>
#include <vector>
#include "tree_node.hpp"


void branchSumHelper(TreeNode * root, int runningSum, std::vector<int> &results) {
    if (root == nullptr) {
        return;
    }
    const int newSum=runningSum+root->m_val;
    if (root->left==nullptr && root->right==nullptr) {
        results.push_back(newSum);
    }
    branchSumHelper(root->left,newSum,results);
    branchSumHelper(root->right,newSum,results);
}

std::vector<int> branchSums(TreeNode* root) {
    std::vector<int> results;
    branchSumHelper(root,0,results);
    return results;
}