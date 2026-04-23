#include <string>
#include <vector>
#include "tree_node.hpp"

int countNodesInComplete(TreeNode* root) {
    if (root==nullptr) return 0;

    int lh=0;
    int rh=0;

   //dwoch zwiadowcow 🥷
    TreeNode *currL=root;
    TreeNode *currR=root;

    while (currL!=nullptr) {
        currL=currL->left;
        lh++;
    }
    while (currR!=nullptr) {
        currR=currR->right;
        rh++;
    }
    if (rh==lh) {
        return (1<<lh)-1; //sum 1+2+4+8+16
    }
    return 1+countNodesInComplete(root->left)+countNodesInComplete(root->right);
}