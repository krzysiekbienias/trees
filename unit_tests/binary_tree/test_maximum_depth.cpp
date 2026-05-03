#include "binary_tree/maximum_depth.hpp"
#include <gtest/gtest.h>
#include "../unit_tests/utils.hpp"

TEST(MaximumDepth, FromLeetCode) {
    /*
              3
           /     \
          9       20
                  / \
                 15   7
    */
    TreeNode* root = buildTree({3, 9, 20, std::nullopt, std::nullopt, 15, 7});
    EXPECT_EQ(maxDepth(root), 3);
    deleteTree(root);
}

TEST(MaximumDepth, EmptyTree) {
    EXPECT_EQ(maxDepth(nullptr), 0);
}

TEST(MaximumDepth, SingleNode) {
    /*
        42
    */
    TreeNode* root = new TreeNode(42);
    EXPECT_EQ(maxDepth(root), 1);
    deleteTree(root);
}

TEST(MaximumDepth, LeftSkewedTree) {
    /*
        1
       /
      2
     /
    3
    */
    TreeNode* root = buildTree({1, 2, std::nullopt, 3});
    EXPECT_EQ(maxDepth(root), 3);
    deleteTree(root);
}

TEST(MaximumDepth, RightSkewedTree) {
    /*
    1
     \
      2
       \
        3
         \
          4
    */
    TreeNode* root = buildTree({1, std::nullopt, 2, std::nullopt, 3, std::nullopt, 4});
    EXPECT_EQ(maxDepth(root), 4);
    deleteTree(root);
}

TEST(MaximumDepth, LeftHeavy) {
    /*
            1
           / \
          2   3
         / \
        4   5
       /
      6
    */
    TreeNode* root = buildTree({1, 2, 3, 4, 5, std::nullopt, std::nullopt, 6});
    EXPECT_EQ(maxDepth(root), 4);
    deleteTree(root);
}

TEST(MaximumDepth, PerfectTree) {
    /*
           1
         /   \
        2     3
       / \   / \
      4   5 6   7
    */
    TreeNode* root = buildTree({1, 2, 3, 4, 5, 6, 7});
    EXPECT_EQ(maxDepth(root), 3);
    deleteTree(root);
}