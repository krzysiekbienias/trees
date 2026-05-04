#include "binary_tree/deepest_node_of_binary_tree.hpp"
#include <gtest/gtest.h>
#include "../unit_tests/utils.hpp"

TEST(DeepestNode, EmptyTree) {
    EXPECT_EQ(deepestNode(nullptr), -1);
}

TEST(DeepestNode, SingleNode) {
    TreeNode* root = new TreeNode(42);
    EXPECT_EQ(deepestNode(root), 42);
    deleteTree(root);
}

TEST(DeepestNode, RightmostOnDeepestLevel) {
    /*
            1
           / \
          2   3
         / \
        4   5
    */
    TreeNode* root = buildTree({1, 2, 3, 4, 5});
    EXPECT_EQ(deepestNode(root), 5);
    deleteTree(root);
}

TEST(DeepestNode, DeepestIsRightChild) {
    /*
        1
       / \
      2   3
    */
    TreeNode* root = buildTree({1, 2, 3});
    EXPECT_EQ(deepestNode(root), 3);
    deleteTree(root);
}

TEST(DeepestNode, OnlyLeftChildren) {
    /*
        1
       /
      2
     /
    3
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    EXPECT_EQ(deepestNode(root), 3);
    deleteTree(root);
}

TEST(DeepestNode, BalancedTree) {
    /*
              1
           /     \
          2       3
         / \     / \
        4   5   6   7
    */
    TreeNode* root = buildTree({1, 2, 3, 4, 5, 6, 7});
    EXPECT_EQ(deepestNode(root), 7);
    deleteTree(root);
}

TEST(DeepestNode, LastLevelPartiallyFilled) {
    /*
              1
           /     \
          2       3
         / \     /
        4   5   6
    */
    TreeNode* root = buildTree({1, 2, 3, 4, 5, 6});
    EXPECT_EQ(deepestNode(root), 6);
    deleteTree(root);
}
