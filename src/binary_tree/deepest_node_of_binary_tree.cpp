

#include "traversal/level_order.hpp"
#include "tree_node.hpp"


int deepestNode(TreeNode *root) {
    if (root==nullptr) {
        return -1;
    }
    int deepestNodeVal=levelOrder(root).back();
    return deepestNodeVal;
}
