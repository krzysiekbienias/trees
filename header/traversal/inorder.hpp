#pragma once
#include <string>
#include <vector>
#include "tree_node.hpp"


void inOrderDfs(TreeNode* root, std::vector<int> & res);

std::vector<int> inOrderRecursion(TreeNode* root);