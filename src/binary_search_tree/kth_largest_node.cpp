#include <string>
#include <vector>
#include "tree_node.hpp"


static int helper(TreeNode* root,int k, int &counter) {
    if (root==nullptr) {
        return -1;
    }

    int rightResult=helper(root->right,k,counter);
    if (rightResult!=-1) {
        return rightResult;
    }
    //process current node
    counter++;
    if (counter==k) {
        return root->m_val;
    }
    return helper(root->left,k,counter);
}

int kthLargest(TreeNode *root, int k) {
    int counter=0;
    return helper(root, k,counter);

}