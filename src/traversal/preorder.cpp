#include <string>
#include <vector>
#include "tree_node.hpp"
#include <stack>


std::vector<int> preOrderIterative(TreeNode* root) {
    std::vector<int> res;
    if (root==nullptr) {
        return res;
    }

    std::stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* tempTree=st.top();
        st.pop();
        res.push_back(tempTree->m_val);
        if (tempTree->right) {
            st.push(tempTree->right);
        }
        if (tempTree->left) {
            st.push(tempTree->left);
        }
    }
    return res;
}