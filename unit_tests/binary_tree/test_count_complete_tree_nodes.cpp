#include "binary_tree/count_complete_tree_nodes.hpp"
#include <gtest/gtest.h>
#include "../unit_tests/utils.hpp"

TEST(NbNodesInCompleteTree,FromLeetCode) {

    /*
              1
           /     \
          2       3
         / \     / \
        4   5   6


*/  TreeNode* root = buildTree({1,2,3,4,5,6});
    //printTreeFancy(root);

    int actual=countNodesInComplete(root);
    EXPECT_EQ(actual,6);
}