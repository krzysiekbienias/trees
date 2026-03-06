#include <string>
#include <vector>
#include "tree_node.hpp"
#include "binary_search_tree/find_closest_value.hpp"

int dfsClosestValue(TreeNode* root,int target, int bestSoFar) {
    TreeNode* runner= root;
    while (runner!=nullptr) {
        int runnerVal=runner->m_val;
        if ((abs(target-bestSoFar)>abs(target-runnerVal))) {
            bestSoFar=runnerVal;
        }
        if (runnerVal<target) {
            runner=runner->right;
        }
        else if (runnerVal<target) {
            runner=runner->left;
        }
        else break;
    }
    return bestSoFar;
}

int closestValue(TreeNode* root,int target) {
    dfsClosestValue(root,target,root->m_val);
}




