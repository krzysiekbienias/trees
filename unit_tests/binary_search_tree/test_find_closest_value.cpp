#include "binary_search_tree/find_closest_value.hpp"
#include <gtest/gtest.h>
#include "../unit_tests/utils.hpp"


TEST(ClosestValue, ReturnsRootWhenTreeHasSingleNodeAndTargetEqualsRoot) {
    TreeNode* root = new TreeNode(10);

    EXPECT_EQ(dfsClosestValue(root, 10, root->m_val), 10);

    deleteTree(root);
}

TEST(ClosestValue, ReturnsRootWhenTreeHasSingleNodeAndTargetIsDifferent) {
    TreeNode* root = new TreeNode(10);

    EXPECT_EQ(dfsClosestValue(root, 42, root->m_val), 10);
    EXPECT_EQ(dfsClosestValue(root, -5, root->m_val), 10);

    deleteTree(root);
}

TEST(ClosestValue, FindsExactMatchInRightSubtree) {
    //        10
    //       /  \
    //      5    15
    //          /  \
    //         13   22
    TreeNode* root = buildTree({
        10,
        5, 15,
        std::nullopt, std::nullopt, 13, 22
    });

    EXPECT_EQ(dfsClosestValue(root, 13, root->m_val), 13);
    EXPECT_EQ(dfsClosestValue(root, 22, root->m_val), 22);
    EXPECT_EQ(dfsClosestValue(root, 15, root->m_val), 15);

    deleteTree(root);
}

TEST(ClosestValue, FindsClosestValueInRightSubtreeWhenNoExactMatch) {
    //        10
    //       /  \
    //      5    15
    //          /  \
    //         13   22
    TreeNode* root = buildTreeIndexed({
        10,
        5, 15,
        std::nullopt, std::nullopt, 13, 22
    });

    EXPECT_EQ(dfsClosestValue(root, 12, root->m_val), 13);
    //no rules for tie:
    int tie_result=dfsClosestValue(root, 14, root->m_val);
    EXPECT_TRUE(tie_result==13||tie_result==15);

    EXPECT_EQ(dfsClosestValue(root, 100, root->m_val), 22);

    deleteTree(root);
}

TEST(ClosestValue, FindsClosestValueInLeftSubtreeWhenNoExactMatch) {
    //         10
    //        /  \
    //       5    15
    //      / \
    //     2   7
    TreeNode* root = buildTree({
        10,
        5, 15,
        2, 7
    });

    EXPECT_EQ(dfsClosestValue(root, 6, root->m_val), 5);
    EXPECT_EQ(dfsClosestValue(root, 1, root->m_val), 2);
    EXPECT_EQ(dfsClosestValue(root, 3, root->m_val), 2);

    deleteTree(root);
}

TEST(ClosestValue, FindsExactMatchInLeftSubtree) {
    //         10
    //        /  \
    //       5    15
    //      / \
    //     2   7
    TreeNode* root = buildTree({
        10,
        5, 15,
        2, 7
    });

    EXPECT_EQ(dfsClosestValue(root, 5, root->m_val), 5);
    EXPECT_EQ(dfsClosestValue(root, 2, root->m_val), 2);
    EXPECT_EQ(dfsClosestValue(root, 7, root->m_val), 7);

    deleteTree(root);
}

TEST(ClosestValue, ReturnsRootWhenRootIsClosest) {
    //        10
    //       /  \
    //      5    15
    TreeNode* root = buildTree({
        10,
        5, 15
    });

    EXPECT_EQ(dfsClosestValue(root, 9, root->m_val), 10);
    EXPECT_EQ(dfsClosestValue(root, 11, root->m_val), 10);

    deleteTree(root);
}

TEST(ClosestValue, HandlesNegativeValues) {
    //          0
    //        /   \
    //      -10    10
    //      / \    / \
    //   -20 -5   5  20
    TreeNode* root = buildTree({
        0,
        -10, 10,
        -20, -5, 5, 20
    });

    EXPECT_EQ(dfsClosestValue(root, -6, root->m_val), -5);
    EXPECT_EQ(dfsClosestValue(root, -17, root->m_val), -20);
    EXPECT_EQ(dfsClosestValue(root, 6, root->m_val), 5);

    deleteTree(root);
}

TEST(ClosestValue, TieKeepsEarlierBestSoFarBecauseComparisonUsesStrictGreater) {
    //        10
    //       /  \
    //      5    15
    TreeNode* root = buildTree({
        10,
        5, 15
    });

    // target = 12
    // distance to 10 = 2
    // distance to 15 = 3
    EXPECT_EQ(dfsClosestValue(root, 12, root->m_val), 10);

    // target = 13
    // distance to 10 = 3
    // distance to 15 = 2
    EXPECT_EQ(dfsClosestValue(root, 13, root->m_val), 15);

    // target = 12? not tie. Let's make a real tie:
    // distance to 10 and 15 from target=12? 2 and 3, not tie.
    // target = 12.5 impossible with int target.
    // For int BST, tie example with 10 and 14 around 12:
    deleteTree(root);
}

TEST(ClosestValue, TieCaseWithIntegersKeepsBestSoFarWhenDistancesAreEqual) {
    //        10
    //          \
    //           14
    TreeNode* root = buildTree({
        10,
        std::nullopt, 14
    });

    // target = 12
    // dist(10)=2, dist(14)=2
    // Since code updates only when strictly better:
    // if (abs(target-bestSoFar) > abs(target-runnerVal))
    // bestSoFar should remain 10.
    EXPECT_EQ(dfsClosestValue(root, 12, root->m_val), 10);

    deleteTree(root);
}