#include <string>
#include <vector>
#include "tree_node.hpp"
#include "traversal/inorder.hpp"


bool isValidBST(TreeNode* root) {
    std::vector<int> inOrder= inOrderRecursion(root);
    for (int i = 1; i < inOrder.size(); ++i) {
        if (inOrder[i-1]>=inOrder[i]) return false;
    }
    return true;
}
