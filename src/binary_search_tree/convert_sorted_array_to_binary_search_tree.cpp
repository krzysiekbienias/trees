#include <string>
#include <vector>
#include "tree_node.hpp"


static TreeNode* buildTree(const std::vector<int>& nums, int low, int heigh) {
    if (low>heigh) {
        return nullptr;
    }

    //mid
    int mid=low+(heigh-low)/2;
    TreeNode* node = new TreeNode(nums[mid]);
    node->left=buildTree(nums,low,mid-1);
    node->left=buildTree(nums,mid+1,heigh);
    return node;
}

TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    return buildTree(nums,0,nums.size()-1);

}