#include "binary_tree/count_complete_tree_nodes.hpp"
#include <gtest/gtest.h>
#include "../unit_tests/utils.hpp"

TEST(NbNodesInCompleteTree, FromLeetCode) {
    /*
              1
           /     \
          2       3
         / \     /
        4   5   6
    */
    TreeNode* root = buildTree({1,2,3,4,5,6});
    EXPECT_EQ(countNodesInComplete(root), 6);
    deleteTree(root);
}

TEST(NbNodesInCompleteTree, EmptyTree) {
    EXPECT_EQ(countNodesInComplete(nullptr), 0);
}

TEST(NbNodesInCompleteTree, SingleNode) {
    TreeNode* root = new TreeNode(1);
    EXPECT_EQ(countNodesInComplete(root), 1);
    deleteTree(root);
}

TEST(NbNodesInCompleteTree, PerfectTree) {
    /*
              1
           /     \
          2       3
         / \     / \
        4   5   6   7
    */
    TreeNode* root = buildTree({1,2,3,4,5,6,7});
    EXPECT_EQ(countNodesInComplete(root), 7);
    deleteTree(root);
}

TEST(NbNodesInCompleteTree, TwoLevelsFullLeft) {
    /*
        1
       / \
      2   3
    */
    TreeNode* root = buildTree({1,2,3});
    EXPECT_EQ(countNodesInComplete(root), 3);
    deleteTree(root);
}

TEST(NbNodesInCompleteTree, LastLevelOneNode) {
    /*
            1
           / \
          2   3
         /
        4
    */
    TreeNode* root = buildTree({1,2,3,4});
    EXPECT_EQ(countNodesInComplete(root), 4);
    deleteTree(root);
}

TEST(NbNodesInCompleteTree, LastLevelAlmostFull) {
    /*
              1
           /     \
          2       3
         / \     / \
        4   5   6   7
       /
      8
    */
    TreeNode* root = buildTree({1,2,3,4,5,6,7,8});
    EXPECT_EQ(countNodesInComplete(root), 8);
    deleteTree(root);
}