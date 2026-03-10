#include "traversal/preorder.hpp"
#include <gtest/gtest.h>
#include "../unit_tests/utils.hpp"


TEST(PreOrderRecursion, PerfectBinaryTree_ReturnsRootLeftRightOrder) {
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

    std::vector<int> actual = preOrderIterative(root);

    EXPECT_EQ(actual, std::vector<int>({4,2,1,3,6,5,7}));

    deleteTree(root);
}