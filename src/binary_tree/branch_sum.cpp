#include <string>
#include <vector>
#include "tree_node.hpp"


void dfsBranchSum(TreeNode * root, int runningSum, std::vector<int> &results) {
    if (root == nullptr) {
        return;
    }
    const int newSum=runningSum+root->m_val;
    if (root->left==nullptr && root->right==nullptr) {
        results.push_back(newSum);
    }
    dfsBranchSum(root->left,newSum,results);
    dfsBranchSum(root->right,newSum,results);
}

std::vector<int> branchSums(TreeNode* root) {
    std::vector<int> results;
    dfsBranchSum(root,0,results);
    return results;
}