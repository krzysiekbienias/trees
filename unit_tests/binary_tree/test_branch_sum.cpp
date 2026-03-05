#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>

// If TreeNode / branchSums are in headers, include them instead.
#include "tree_node.hpp"
#include "binary_tree/branch_sum.hpp"
#include "../utils.hpp"

using ::testing::ElementsAre;
using ::testing::UnorderedElementsAre;

namespace {

// Optional: helper to free the tree (recommended if TreeNode has no destructor)


TreeNode* buildExampleTree() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    return root;
}

} // namespace

TEST(BranchSums, NullRoot_ReturnsEmpty) {
    std::vector<int> sums = branchSums(nullptr);
    EXPECT_TRUE(sums.empty());
}

TEST(BranchSums, SingleNode_ReturnsRootValue) {
    TreeNode* root = new TreeNode(42);

    std::vector<int> sums = branchSums(root);
    EXPECT_THAT(sums, ElementsAre(42));

    deleteTree(root);
}

TEST(BranchSums, TwoLevelTree_LeftAndRightLeaves) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // Leaves: 1->2 sum=3, 1->3 sum=4
    std::vector<int> sums = branchSums(root);
    EXPECT_THAT(sums, ElementsAre(3, 4)); // left-to-right DFS

    deleteTree(root);
}

TEST(BranchSums, ExampleTree_DfsLeftToRightOrder) {
    TreeNode* root = buildExampleTree();

    // Leaves are:
    // 1-2-4-8  -> 15
    // 1-2-4-9  -> 16
    // 1-2-5-10 -> 18
    // 1-3-6    -> 10
    // 1-3-7    -> 11
    std::vector<int> sums = branchSums(root);

    EXPECT_THAT(sums, ElementsAre(15, 16, 18, 10, 11));

    deleteTree(root);
}

TEST(BranchSums, ExampleTree_AsSetIfOrderDoesNotMatter) {
    TreeNode* root = buildExampleTree();

    std::vector<int> sums = branchSums(root);

    // Same values, but order-agnostic check (sometimes useful).
    EXPECT_THAT(sums, UnorderedElementsAre(15, 16, 18, 10, 11));

    deleteTree(root);
}

TEST(BranchSums, NegativeValues_WorkCorrectly) {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(-2);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(-3);

    // Leaves:
    // 5 -> -2 -> -3 = 0
    // 5 -> 1         = 6
    std::vector<int> sums = branchSums(root);
    EXPECT_THAT(sums, ElementsAre(0, 6));

    deleteTree(root);
}

TEST(BranchSums, SkewedTree_AllRightChildren) {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    // Only one root-to-leaf path: 1+2+3+4=10
    std::vector<int> sums = branchSums(root);
    EXPECT_THAT(sums, ElementsAre(10));

    deleteTree(root);
}

