#pragma once
#include <string>
#include <vector>
#include "tree_node.hpp"


class TreeAncestor {
public:
    std::vector<std::vector<int>> up;

    TreeAncestor(int n, std::vector<int>& parent);

    int getKthAncestor(int node, int k);
};