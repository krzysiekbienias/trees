
#include "binary_tree/node_depths.hpp"
#include <gtest/gtest.h>
#include "../utils.hpp"

TEST(NodeDepths, FromPlatform) {
    TreeNode* root = buildTree({1,
                                            2,3,
                                        4,5,6,7,
                                    8,9,std::nullopt,std::nullopt,std::nullopt,std::nullopt,std::nullopt,std::nullopt});
    EXPECT_EQ(nodeDepths(root), 16);
}


TEST(NodeDepths, NullTreeReturnsZero) {
    TreeNode* root = nullptr;
    EXPECT_EQ(nodeDepths(root), 0);
}

TEST(NodeDepths, SingleNodeReturnsZero) {
    TreeNode* root = buildTree({1});
    EXPECT_EQ(nodeDepths(root), 0);
}

TEST(NodeDepths, RootWithTwoChildren) {
    //      1
    //     / \
    //    2   3
    // depths: 0 + 1 + 1 = 2
    TreeNode* root = buildTree({1, 2, 3});
    EXPECT_EQ(nodeDepths(root), 2);
}

TEST(NodeDepths, PerfectTreeHeight2) {
    //          1
    //       /     \
    //      2       3
    //    /  \     / \
    //   4    5   6   7
    // depths: level0:1*0 + level1:2*1 + level2:4*2 = 0 + 2 + 8 = 10
    TreeNode* root = buildTree({1,2,3,4,5,6,7});
    EXPECT_EQ(nodeDepths(root), 10);
}

TEST(NodeDepths, LeftSkewedChain4Nodes) {
    //          1
    //         /
    //        2
    //       /
    //      3
    //     /
    //    4
    // depths: 0 + 1 + 2 + 3 = 6
    TreeNode* root = buildTree({1,
        2, std::nullopt,
        3, std::nullopt,
        4,std::nullopt});
    EXPECT_EQ(nodeDepths(root), 6);
}

TEST(NodeDepths, RightSkewedChain4Nodes) {
    // 1 -> 2 -> 3 -> 4 (all to the right)
    // depths: 0 + 1 + 2 + 3 = 6
    TreeNode* root = buildTree({1, std::nullopt, 2, std::nullopt, 3,std::nullopt,4});
    EXPECT_EQ(nodeDepths(root), 6);
}

TEST(NodeDepths, UnbalancedWithMissingChildren) {
    //          1
    //        /   \
    //       2     3
    //        \      \
    //         4      5
    //        /
    //       6
    //
    // depths:
    // 1:0
    // 2:1, 3:1
    // 4:2, 5:2
    // 6:3
    // sum = 0 + 1 + 1 + 2 + 2 + 3 = 9
    TreeNode* root = buildTree({
        1,
        2, 3,
        std::nullopt, 4, std::nullopt, 5,
        6
    });
    EXPECT_EQ(nodeDepths(root), 9);
}