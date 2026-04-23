#include "binary_search_tree/mode.hpp"
#include <gtest/gtest.h>
#include "../utils.hpp"

namespace {

void expectModesUnordered(TreeNode* root, std::vector<int> expected) {
    std::vector<int> actual = findMode(root);
    std::sort(actual.begin(), actual.end());
    std::sort(expected.begin(), expected.end());
    EXPECT_EQ(actual, expected);
}

} // namespace

TEST(FindMode, EmptyTree_ReturnsEmptyVector) {
    TreeNode* root = nullptr;
    expectModesUnordered(root, {});
}

TEST(FindMode, SingleNode_ReturnsThatValue) {
    TreeNode* root = new TreeNode(42);

    expectModesUnordered(root, {42});

    deleteTree(root);
}

TEST(FindMode, OneClearMode) {
    //        2
    //       / \
    //      1   2
    //     /   / \
    //    1   2   3
    //
    // Frequencies:
    // 1 -> 2
    // 2 -> 3
    // 3 -> 1
    TreeNode* root = buildTree({
        2,
        1, 2,
        1, std::nullopt, 2, 3
    });

    expectModesUnordered(root, {2});

    deleteTree(root);
}

TEST(FindMode, TwoModes_ReturnsBothValues) {
    //        2
    //       / \
    //      1   2
    //     /     \
    //    1       3
    //             \
    //              3
    //
    // Frequencies:
    // 1 -> 2
    // 2 -> 2
    // 3 -> 2
    TreeNode* root = buildTree({
        2,
        1, 2,
        1, std::nullopt, std::nullopt, 3,
        std::nullopt, std::nullopt, std::nullopt, std::nullopt,
        std::nullopt, std::nullopt, std::nullopt, 3
    });

    expectModesUnordered(root, {1, 2, 3});

    deleteTree(root);
}

TEST(FindMode, AllValuesUnique_AllAreModes) {
    //      2
    //     / \
    //    1   3
    TreeNode* root = buildTree({2, 1, 3});

    expectModesUnordered(root, {1, 2, 3});

    deleteTree(root);
}

TEST(FindMode, HandlesNegativeValues) {
    //         -1
    //        /  \
    //      -2   -1
    //      /      \
    //    -2       -3
    //
    // Frequencies:
    // -2 -> 2
    // -1 -> 2
    // -3 -> 1
    TreeNode* root = buildTree({
        -1,
        -2, -1,
        -2, std::nullopt, std::nullopt, -3
    });

    expectModesUnordered(root, {-2, -1});

    deleteTree(root);
}

TEST(FindMode, LargerTree_OneModeAppearsMostOften) {
    //            5
    //          /   \
    //         3     8
    //        / \   / \
    //       3   4 8   9
    //      /       \
    //     3         8
    //
    // Frequencies:
    // 3 -> 3
    // 8 -> 3
    // 4 -> 1
    // 5 -> 1
    // 9 -> 1
    TreeNode* root = buildTree({
        5,
        3, 8,
        3, 4, 8, 9,
        3, std::nullopt, std::nullopt, std::nullopt, std::nullopt, 8
    });

    expectModesUnordered(root, {3, 8});

    deleteTree(root);
}

