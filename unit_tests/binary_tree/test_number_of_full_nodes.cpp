#include "binary_tree/number_of_full_nodes.hpp"
#include <gtest/gtest.h>
#include "../unit_tests/utils.hpp"


TEST(NumberOfFullNodes, PerfectBinaryTree) {
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

    int actual = nbOfFullNodes(root);

    EXPECT_EQ(actual,3);

    deleteTree(root);
}

TEST(NumberOfFullNodes, OnlyRoot) {
    //        4
    //      /   \

    TreeNode* root = buildTree({
        4
    });

    int actual = nbOfFullNodes(root);

    EXPECT_EQ(actual,0);

    deleteTree(root);
}