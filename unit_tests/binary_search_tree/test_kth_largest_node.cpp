#include "binary_search_tree/kth_largest_node.hpp"
#include <gtest/gtest.h>
#include "../utils.hpp"

TEST(KthLargest, FirstLargest) {
    /*
          4
         / \
        2   6
       / \ / \
      1  3 5  7
    */
    TreeNode* root = buildTree({4, 2, 6, 1, 3, 5, 7});
    EXPECT_EQ(kthLargest(root, 1), 7);
    deleteTree(root);
}

TEST(KthLargest, SecondLargest) {
    TreeNode* root = buildTree({4, 2, 6, 1, 3, 5, 7});
    EXPECT_EQ(kthLargest(root, 2), 6);
    deleteTree(root);
}

TEST(KthLargest, ThirdLargest) {
    TreeNode* root = buildTree({4, 2, 6, 1, 3, 5, 7});
    EXPECT_EQ(kthLargest(root, 3), 5);
    deleteTree(root);
}

TEST(KthLargest, LastLargest) {
    TreeNode* root = buildTree({4, 2, 6, 1, 3, 5, 7});
    EXPECT_EQ(kthLargest(root, 7), 1);
    deleteTree(root);
}

TEST(KthLargest, SingleNode) {
    TreeNode* root = new TreeNode(42);
    EXPECT_EQ(kthLargest(root, 1), 42);
    deleteTree(root);
}

TEST(KthLargest, RightSkewed) {
    /*
        1
         \
          2
           \
            3
    */
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    EXPECT_EQ(kthLargest(root, 1), 3);
    EXPECT_EQ(kthLargest(root, 2), 2);
    deleteTree(root);
}

TEST(KthLargest, LeftSkewed) {
    /*
        3
       /
      2
     /
    1
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    EXPECT_EQ(kthLargest(root, 1), 3);
    EXPECT_EQ(kthLargest(root, 3), 1);
    deleteTree(root);
}