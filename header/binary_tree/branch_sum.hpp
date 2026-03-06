#pragma once
#include <string>
#include <vector>
#include "tree_node.hpp"

std::vector<int> branchSums(TreeNode* root);
void dfsBranchSum(TreeNode * root, int runningSum, std::vector<int> &results);



