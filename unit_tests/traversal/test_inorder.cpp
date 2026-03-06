#include "traversal/inorder.hpp"
#include <gtest/gtest.h>
#include "../unit_tests/utils.hpp"

// Assumes you already have:
// - TreeNode
// - buildTree(...)
// - buildTreeIndexed(...)
// - deleteTree(...)
// - inOrderDfs(...)
// - inOrderRecursion(...)

TEST(InOrderRecursion, EmptyTree_ReturnsEmptyVector) {
    TreeNode* root = nullptr;

    std::vector<int> actual = inOrderRecursion(root);

    EXPECT_TRUE(actual.empty());
}

TEST(InOrderRecursion, SingleNode_ReturnsSingleValue) {
    TreeNode* root = new TreeNode(42);

    std::vector<int> actual = inOrderRecursion(root);

    EXPECT_EQ(actual, std::vector<int>({42}));

    deleteTree(root);
}

TEST(InOrderRecursion, PerfectBinaryTree_ReturnsLeftRootRightOrder) {
    //        4
    //      /   \
    //     2     6
    //    / \   / \
    //   1   3 5   7
    TreeNode* root = buildTree({
        4,
        2, 6,
        1, 3, 5, 7
    });

    std::vector<int> actual = inOrderRecursion(root);

    EXPECT_EQ(actual, std::vector<int>({1, 2, 3, 4, 5, 6, 7}));

    deleteTree(root);
}

TEST(InOrderRecursion, LeftSkewedTree_ReturnsTopologicallySortedVisit) {
    //      4
    //     /
    //    3
    //   /
    //  2
    // /
    //1
    TreeNode* root = buildTreeIndexed({
        4,
        3, std::nullopt,
        2, std::nullopt, std::nullopt, std::nullopt,
        1
    });

    std::vector<int> actual = inOrderRecursion(root);

    EXPECT_EQ(actual, std::vector<int>({1, 2, 3, 4}));

    deleteTree(root);
}

TEST(InOrderRecursion, RightSkewedTree_ReturnsRootBeforeRightChainValues) {
    // 1
    //  \
    //   2
    //    \
    //     3
    //      \
    //       4
    TreeNode* root = buildTreeIndexed({
        1,
        std::nullopt, 2,
        std::nullopt, std::nullopt, std::nullopt, 3,
        std::nullopt, std::nullopt, std::nullopt, std::nullopt,
        std::nullopt, std::nullopt, std::nullopt, 4
    });

    std::vector<int> actual = inOrderRecursion(root);

    EXPECT_EQ(actual, std::vector<int>({1, 2, 3, 4}));

    deleteTree(root);
}

TEST(InOrderRecursion, TreeWithMissingChildren_StillTraversesCorrectly) {
    //        10
    //       /  \
    //      5    15
    //       \   /
    //        7 12
    TreeNode* root = buildTree({
        10,
        5, 15,
        std::nullopt, 7, 12, std::nullopt
    });

    std::vector<int> actual = inOrderRecursion(root);

    EXPECT_EQ(actual, std::vector<int>({5, 7, 10, 12, 15}));

    deleteTree(root);
}

TEST(InOrderRecursion, KeepsDuplicateValues) {
    //        2
    //       / \
    //      2   2
    TreeNode* root = buildTree({
        2,
        2, 2
    });

    std::vector<int> actual = inOrderRecursion(root);

    EXPECT_EQ(actual, std::vector<int>({2, 2, 2}));

    deleteTree(root);
}

TEST(InOrderRecursion, HandlesNegativeValues) {
    //         0
    //       /   \
    //     -3     5
    //     /     /
    //   -10    2
    TreeNode* root = buildTree({
        0,
        -3, 5,
        -10, std::nullopt, 2, std::nullopt
    });

    std::vector<int> actual = inOrderRecursion(root);

    EXPECT_EQ(actual, std::vector<int>({-10, -3, 0, 2, 5}));

    deleteTree(root);
}

TEST(InOrderDfs, AppendsIntoExistingVectorRatherThanClearingIt) {
    //      2
    //     / \
    //    1   3
    TreeNode* root = buildTree({2, 1, 3});

    std::vector<int> res = {99, 100};
    inOrderDfs(root, res);

    EXPECT_EQ(res, std::vector<int>({99, 100, 1, 2, 3}));

    deleteTree(root);
}

TEST(InOrderDfs, NullRoot_DoesNotModifyExistingVector) {
    TreeNode* root = nullptr;
    std::vector<int> res = {7, 8, 9};

    inOrderDfs(root, res);

    EXPECT_EQ(res, std::vector<int>({7, 8, 9}));
}