#include "binary_search_tree/next_greater_number.hpp"
#include <gtest/gtest.h>
#include "../unit_tests/utils.hpp"


TEST(NextGreaterNumberTest, ReturnsNullForEmptyTree) {
    TreeNode* root = nullptr;

    TreeNode* result = nextGreaterNumber(root, 10);

    EXPECT_EQ(result, nullptr);
}

TEST(NextGreaterNumberTest, ReturnsRootWhenRootIsNextGreater) {
    TreeNode* root = buildTree({
        10
    });

    TreeNode* result = nextGreaterNumber(root, 5);

    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result->m_val, 10);

    deleteTree(root);
}

TEST(NextGreaterNumberTest, ReturnsNullWhenTargetEqualsOnlyNode) {
    TreeNode* root = buildTree({
        10
    });

    TreeNode* result = nextGreaterNumber(root, 10);

    EXPECT_EQ(result, nullptr);

    deleteTree(root);
}

TEST(NextGreaterNumberTest, ReturnsNullWhenTargetIsGreaterThanOnlyNode) {
    TreeNode* root = buildTree({
        10
    });

    TreeNode* result = nextGreaterNumber(root, 20);

    EXPECT_EQ(result, nullptr);

    deleteTree(root);
}

TEST(NextGreaterNumberTest, FindsNextGreaterInBalancedBST) {
    //        10
    //       /  \
    //      5    15
    //     / \   / \
    //    2   7 12 20
    TreeNode* root = buildTree({
        10,
        5, 15,
        2, 7, 12, 20
    });

    TreeNode* result = nextGreaterNumber(root, 11);

    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result->m_val, 12);

    deleteTree(root);
}

TEST(NextGreaterNumberTest, FindsImmediateSuccessorWhenTargetExists) {
    // Inorder: 2, 5, 7, 10, 12, 15, 20
    TreeNode* root = buildTree({
        10,
        5, 15,
        2, 7, 12, 20
    });

    TreeNode* result = nextGreaterNumber(root, 10);

    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result->m_val, 12);

    deleteTree(root);
}

TEST(NextGreaterNumberTest, ReturnsSmallestValueGreaterThanTarget) {
    // Inorder: 2, 5, 7, 10, 12, 15, 20
    TreeNode* root = buildTree({
        10,
        5, 15,
        2, 7, 12, 20
    });

    TreeNode* result = nextGreaterNumber(root, 6);

    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result->m_val, 7);

    deleteTree(root);
}

TEST(NextGreaterNumberTest, ReturnsNullWhenTargetIsLargestValue) {
    TreeNode* root = buildTree({
        10,
        5, 15,
        2, 7, 12, 20
    });

    TreeNode* result = nextGreaterNumber(root, 20);

    EXPECT_EQ(result, nullptr);

    deleteTree(root);
}

TEST(NextGreaterNumberTest, ReturnsNullWhenTargetExceedsLargestValue) {
    TreeNode* root = buildTree({
        10,
        5, 15,
        2, 7, 12, 20
    });

    TreeNode* result = nextGreaterNumber(root, 100);

    EXPECT_EQ(result, nullptr);

    deleteTree(root);
}

TEST(NextGreaterNumberTest, WorksForLeftSkewedTree) {
    //      10
    //     /
    //    8
    //   /
    //  6
    // /
    //4
    TreeNode* root = buildTree({
        10,
        8, std::nullopt,
        6, std::nullopt,
        4
    });

    TreeNode* result = nextGreaterNumber(root, 5);

    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result->m_val, 6);

    deleteTree(root);
}

TEST(NextGreaterNumberTest, WorksForRightSkewedTree) {
    // 1
    //  \
    //   3
    //    \
    //     5
    //      \
    //       7
    TreeNode* root = buildTreeIndexed({
        1,
        std::nullopt, 3,
        std::nullopt, std::nullopt, std::nullopt, 5,
        std::nullopt, std::nullopt, std::nullopt, std::nullopt,
        std::nullopt, std::nullopt, std::nullopt, 7
    });

    TreeNode* result = nextGreaterNumber(root, 5);

    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result->m_val, 7);

    deleteTree(root);
}

TEST(NextGreaterNumberTest, ReturnsClosestAncestorAsCandidate) {
    //         20
    //        /
    //      10
    //        \
    //         15
    //           \
    //            17
    TreeNode* root = buildTree({
        20,
        10, std::nullopt,
        std::nullopt, 15,
        std::nullopt, 17
    });

    TreeNode* result = nextGreaterNumber(root, 17);

    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result->m_val, 20);

    deleteTree(root);
}

TEST(NextGreaterNumberTest, ReturnsMinimumWhenTargetIsSmallerThanAllValues) {
    TreeNode* root = buildTree({
        8,
        4, 12,
        2, 6, 10, 14
    });

    TreeNode* result = nextGreaterNumber(root, -100);

    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result->m_val, 2);

    deleteTree(root);
}