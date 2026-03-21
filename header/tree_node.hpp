#pragma once

class  TreeNode {
public:
    int m_val;
    TreeNode* left=nullptr;
    TreeNode* right=nullptr;

    explicit TreeNode();
    explicit TreeNode(int val):m_val(val),left(nullptr),right(nullptr){};
};

class  TreeNodeWithParent {
public:
    int m_val;
    TreeNode* left=nullptr;
    TreeNode* right=nullptr;
    TreeNode* parent=nullptr;

    explicit TreeNodeWithParent();
    explicit TreeNodeWithParent(int val):m_val(val),left(nullptr),right(nullptr),parent(nullptr){};
};



