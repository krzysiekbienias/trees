#include "binary_tree/diameter.hpp"


int calculateHeight(TreeNode* node,int & maxDiameter) {
    int lh=0;
    int rh=0;
    int localDiameter=0;
    if (node==nullptr) {
        return 0;
    }
    lh=calculateHeight(node->left,maxDiameter);
    rh=calculateHeight(node->right,maxDiameter);
    localDiameter=lh+rh+1;
    maxDiameter=std::max(maxDiameter,localDiameter);
    return std::max(lh,rh)+1;
}

int binaryTreeDiameter(TreeNode* root) {
    int maxDiameter=0;
    calculateHeight(root,maxDiameter);
    return maxDiameter;

}