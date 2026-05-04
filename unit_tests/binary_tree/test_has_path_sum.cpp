#include "binary_tree/has_path_sum.hpp"
#include <gtest/gtest.h>
#include "../unit_tests/utils.hpp"

TEST(PathSum, ClassicTest) {
    /*
                5
             /     \
            4       8
           /       / \
          11      13  4
         /  \          \
        7    2          1
    */
    TreeNode* root = buildTree({5,4,8,11,std::nullopt,13,4,7,2,std::nullopt,std::nullopt,std::nullopt,1});
    EXPECT_TRUE(hasPathSum(root, 22));
    deleteTree(root);
}

TEST(PathSum, EmptyTree) {
    EXPECT_FALSE(hasPathSum(nullptr, 0));
}

TEST(PathSum, SingleNodeMatch) {
    TreeNode* root = new TreeNode(5);
    EXPECT_TRUE(hasPathSum(root, 5));
    deleteTree(root);
}

TEST(PathSum, SingleNodeNoMatch) {
    TreeNode* root = new TreeNode(5);
    EXPECT_FALSE(hasPathSum(root, 10));
    deleteTree(root);
}

TEST(PathSum, PathExistsOnRightSide) {
    /*
        1
       / \
      2   3
    */
    TreeNode* root = buildTree({1, 2, 3});
    EXPECT_TRUE(hasPathSum(root, 4));   // 1->3
    deleteTree(root);
}

TEST(PathSum, NoValidPath) {
    /*
        1
       / \
      2   3
    */
    TreeNode* root = buildTree({1, 2, 3});
    EXPECT_FALSE(hasPathSum(root, 10));
    deleteTree(root);
}

TEST(PathSum, NegativeValues) {
    /*
        -2
          \
          -3
    */
    TreeNode* root = new TreeNode(-2);
    root->right = new TreeNode(-3);
    EXPECT_TRUE(hasPathSum(root, -5));
    deleteTree(root);
}

TEST(PathSum, SumReachedButNotAtLeaf) {
    /*
        5
       /
      3
       \
        2
    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    EXPECT_FALSE(hasPathSum(root, 8));  // 5+3=8 but node 3 is not a leaf
    EXPECT_TRUE(hasPathSum(root, 10)); // 5+3+2=10, valid path
    deleteTree(root);
}