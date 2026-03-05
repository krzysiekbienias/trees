#pragma once

class  TreeNode {
public:
    int m_val;
    TreeNode* left=nullptr;
    TreeNode* right=nullptr;

    TreeNode(int val):m_val(val),left(nullptr),right(nullptr){};
};

