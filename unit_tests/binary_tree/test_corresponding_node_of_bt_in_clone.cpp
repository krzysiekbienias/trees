#include "binary_tree/corresponding_node_of_bt_in_clone.hpp"
#include <gtest/gtest.h>
#include "../unit_tests/utils.hpp"

// Helper: build a deep-copy (clone) of a tree
static TreeNode* cloneTree(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* node = new TreeNode(root->m_val);
    node->left  = cloneTree(root->left);
    node->right = cloneTree(root->right);
    return node;
}

TEST(CorrespondingNodeInClone, TargetIsRoot) {
    /*
        1
       / \
      2   3
    */
    TreeNode* original = buildTree({1, 2, 3});
    TreeNode* cloned   = cloneTree(original);

    TreeNode* result = getTargetCopy(original, cloned, original);
    EXPECT_EQ(result->m_val, 1);
    EXPECT_NE(result, original);   // must be from clone, not original
    EXPECT_EQ(result, cloned);

    deleteTree(original);
    deleteTree(cloned);
}

TEST(CorrespondingNodeInClone, TargetIsLeftLeaf) {
    /*
        1
       / \
      2   3
    */
    TreeNode* original = buildTree({1, 2, 3});
    TreeNode* cloned   = cloneTree(original);

    TreeNode* target = original->left;   // node with value 2
    TreeNode* result = getTargetCopy(original, cloned, target);

    EXPECT_EQ(result->m_val, 2);
    EXPECT_NE(result, target);           // different pointer
    EXPECT_EQ(result, cloned->left);

    deleteTree(original);
    deleteTree(cloned);
}

TEST(CorrespondingNodeInClone, TargetIsRightLeaf) {
    /*
        1
       / \
      2   3
    */
    TreeNode* original = buildTree({1, 2, 3});
    TreeNode* cloned   = cloneTree(original);

    TreeNode* target = original->right;  // node with value 3
    TreeNode* result = getTargetCopy(original, cloned, target);

    EXPECT_EQ(result->m_val, 3);
    EXPECT_NE(result, target);
    EXPECT_EQ(result, cloned->right);

    deleteTree(original);
    deleteTree(cloned);
}

TEST(CorrespondingNodeInClone, TargetIsDeepNode) {
    /*
            1
           / \
          2   3
         / \
        4   5
    */
    TreeNode* original = buildTree({1, 2, 3, 4, 5});
    TreeNode* cloned   = cloneTree(original);

    TreeNode* target = original->left->right;  // node with value 5
    TreeNode* result = getTargetCopy(original, cloned, target);

    EXPECT_EQ(result->m_val, 5);
    EXPECT_NE(result, target);
    EXPECT_EQ(result, cloned->left->right);

    deleteTree(original);
    deleteTree(cloned);
}

TEST(CorrespondingNodeInClone, TargetIsInternalNode) {
    /*
            1
           / \
          2   3
         /
        4
    */
    TreeNode* original = buildTree({1, 2, 3, 4});
    TreeNode* cloned   = cloneTree(original);

    TreeNode* target = original->left;   // node with value 2 (internal, not a leaf)
    TreeNode* result = getTargetCopy(original, cloned, target);

    EXPECT_EQ(result->m_val, 2);
    EXPECT_NE(result, target);
    EXPECT_EQ(result, cloned->left);

    deleteTree(original);
    deleteTree(cloned);
}

TEST(CorrespondingNodeInClone, SingleNodeTree) {
    TreeNode* original = new TreeNode(42);
    TreeNode* cloned   = cloneTree(original);

    TreeNode* result = getTargetCopy(original, cloned, original);

    EXPECT_EQ(result->m_val, 42);
    EXPECT_EQ(result, cloned);

    deleteTree(original);
    deleteTree(cloned);
}

TEST(CorrespondingNodeInClone, EmptyTree) {
    TreeNode* result = getTargetCopy(nullptr, nullptr, nullptr);
    EXPECT_EQ(result, nullptr);
}