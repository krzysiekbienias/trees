#pragma once
#include <string>
#include <vector>
#include "tree_node.hpp"

std::vector<int> branchSums(TreeNode* root);
void branchSumHelper(TreeNode * root, int runningSum, std::vector<int> &results);

