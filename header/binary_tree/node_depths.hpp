#pragma once
#include <string>
#include <vector>
#include "tree_node.hpp"

void dfsNodeDepths(TreeNode* root,int currentDepth,int& accumulatedSum);

int nodeDepths(TreeNode* root);