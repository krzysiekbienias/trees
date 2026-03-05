#include <gtest/gtest.h>
#include "tree_node.hpp"
#include "../utils.hpp"


TEST(TreeBuilder, BuildsBiggerTree_LevelOrderWithNulls) {
 // Level-order representation:
 // index:  0  1  2  3   4  5   6   7  8  9 10 11  12  13 14 15  16  17  18 19  20  21  22
 // value: [1, 2, 3, 4,  5, n,  7,  8, n, n,10, n,  13, n,15,16,  n,  18, n,19,  n,  22, 23]
 // where n = nullopt

 TreeNode* root = buildTree({
     1,
     2, 3,
     4, 5, std::nullopt, 7,
     8, std::nullopt, std::nullopt, 10, std::nullopt, 13,
     std::nullopt, 15,16, std::nullopt, 18,std::nullopt,
     19, std::nullopt, 22, 23
 });
 /*
  *
  *              1
               /   \
              2     3
            /  \     \
           4    5     7
          /      \     \
         8        10    13
          \       /     /
          15     16    18
         /      /  \
        19     22  23


 */
 ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->m_val, 1);

    // level 1
    ASSERT_NE(root->left, nullptr);
    EXPECT_EQ(root->left->m_val, 2);

    ASSERT_NE(root->right, nullptr);
    EXPECT_EQ(root->right->m_val, 3);

    // node 2 -> 4,5
    ASSERT_NE(root->left->left, nullptr);
    EXPECT_EQ(root->left->left->m_val, 4);

    ASSERT_NE(root->left->right, nullptr);
    EXPECT_EQ(root->left->right->m_val, 5);

    // node 3 -> null,7
    EXPECT_EQ(root->right->left, nullptr);
    ASSERT_NE(root->right->right, nullptr);
    EXPECT_EQ(root->right->right->m_val, 7);

    // node 4 -> 8,null
    ASSERT_NE(root->left->left->left, nullptr);
    EXPECT_EQ(root->left->left->left->m_val, 8);
    EXPECT_EQ(root->left->left->right, nullptr);

    // node 5 -> null,10
    EXPECT_EQ(root->left->right->left, nullptr);
    ASSERT_NE(root->left->right->right, nullptr);
    EXPECT_EQ(root->left->right->right->m_val, 10);

    // node 7 -> null,13
    EXPECT_EQ(root->right->right->left, nullptr);
    ASSERT_NE(root->right->right->right, nullptr);
    EXPECT_EQ(root->right->right->right->m_val, 13);

    // node 13 -> 18,null
    ASSERT_NE(root->right->right->right->left, nullptr);
    EXPECT_EQ(root->right->right->right->left->m_val, 18);
    EXPECT_EQ(root->right->right->right->right, nullptr);

    // node 8 -> null,15
    EXPECT_EQ(root->left->left->left->left, nullptr);
    ASSERT_NE(root->left->left->left->right, nullptr);
    EXPECT_EQ(root->left->left->left->right->m_val, 15);

    // node 15 -> 19,null
    ASSERT_NE(root->left->left->left->right->left, nullptr);
    EXPECT_EQ(root->left->left->left->right->left->m_val, 19);
    EXPECT_EQ(root->left->left->left->right->right, nullptr);

    // node 10 -> 16,null
    ASSERT_NE(root->left->right->right->left, nullptr);
    EXPECT_EQ(root->left->right->right->left->m_val, 16);
    EXPECT_EQ(root->left->right->right->right, nullptr);

    // node 16 -> 22,23
    ASSERT_NE(root->left->right->right->left->left, nullptr);
    EXPECT_EQ(root->left->right->right->left->left->m_val, 22);

    ASSERT_NE(root->left->right->right->left->right, nullptr);
    EXPECT_EQ(root->left->right->right->left->right->m_val, 23);

    deleteTree(root);
}

// TreeBuilder basic shape tests (each case tested separately)

TEST(TreeBuilder, BuildsEmptyTree_ReturnsNullptr) {
    // 1) empty tree
    TreeNode* root = buildTree({});
    EXPECT_EQ(root, nullptr);
    // no deleteTree needed (nullptr ok, but safe either way)
    deleteTree(root);
}

TEST(TreeBuilder, BuildsOnlyRoot) {
    // 2) only root
    TreeNode* root = buildTree({1});

    ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->m_val, 1);
    EXPECT_EQ(root->left, nullptr);
    EXPECT_EQ(root->right, nullptr);

    deleteTree(root);
}

TEST(TreeBuilder, BuildsRootWithTwoChildren) {
    // 3) root and two children
    //     1
    //   /   \
    //  2     3
    TreeNode* root = buildTree({1, 2, 3});

    ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->m_val, 1);

    ASSERT_NE(root->left, nullptr);
    EXPECT_EQ(root->left->m_val, 2);
    EXPECT_EQ(root->left->left, nullptr);
    EXPECT_EQ(root->left->right, nullptr);

    ASSERT_NE(root->right, nullptr);
    EXPECT_EQ(root->right->m_val, 3);
    EXPECT_EQ(root->right->left, nullptr);
    EXPECT_EQ(root->right->right, nullptr);

    deleteTree(root);
}

TEST(TreeBuilder, BuildsSkewedLeft) {
    // 4) skewed left
    //
    //     1
    //    /
    //   2
    //  /
    // 3
    ///
    //4
    //
    // Indices (heap-style):
    // 1 at 0
    // 2 at 1
    // 3 at 3
    // 4 at 7
    //
    // vector size must be >= 8
    TreeNode* root = buildTree({
        1,                 // 0
        2, std::nullopt,   // 1,2
        3, std::nullopt,  // 3,4,5,6
        4,std::nullopt                  // 7
    });

    ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->m_val, 1);
    ASSERT_NE(root->left, nullptr);
    EXPECT_EQ(root->left->m_val, 2);
    EXPECT_EQ(root->right, nullptr);

    ASSERT_NE(root->left->left, nullptr);
    EXPECT_EQ(root->left->left->m_val, 3);
    EXPECT_EQ(root->left->right, nullptr);

    ASSERT_NE(root->left->left->left, nullptr);
    EXPECT_EQ(root->left->left->left->m_val, 4);

    // leaf
    EXPECT_EQ(root->left->left->left->left, nullptr);
    EXPECT_EQ(root->left->left->left->right, nullptr);

    deleteTree(root);
}

//Tree build with different function, using an array-index approach
TEST(TreeBuilder, BuildsSkewedRight) {
    // 5) skewed right
    // 1
    //  \
    //   2
    //    \
    //     3
    //      \
    //       4
    //
    // level-order with nulls to force "right only":
    // idx: 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14
    // val: 1, n, 2, n, n, n, 3, n, n, n, n, n, n, n, 4
    TreeNode* root = buildTreeIndexed({
        1,
        std::nullopt, 2,
        std::nullopt, std::nullopt, std::nullopt, 3,
        std::nullopt, std::nullopt, std::nullopt, std::nullopt,
        std::nullopt, std::nullopt, std::nullopt, 4
    });

    ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->m_val, 1);

    EXPECT_EQ(root->left, nullptr);
    ASSERT_NE(root->right, nullptr);
    EXPECT_EQ(root->right->m_val, 2);

    EXPECT_EQ(root->right->left, nullptr);
    ASSERT_NE(root->right->right, nullptr);
    EXPECT_EQ(root->right->right->m_val, 3);

    EXPECT_EQ(root->right->right->left, nullptr);
    ASSERT_NE(root->right->right->right, nullptr);
    EXPECT_EQ(root->right->right->right->m_val, 4);

    // leaf checks
    EXPECT_EQ(root->right->right->right->left, nullptr);
    EXPECT_EQ(root->right->right->right->right, nullptr);

    deleteTree(root);
}