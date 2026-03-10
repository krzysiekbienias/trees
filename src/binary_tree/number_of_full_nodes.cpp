#include <string>
#include <vector>
#include "tree_node.hpp"
#include <stack>


int nbOfFullNodes(TreeNode* root) {
    int res=0;
    if (root==nullptr) {
        return res;
    }

    std::stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* tempTree=st.top();
        st.pop();
        if (tempTree->left && tempTree->right) {
            res++;

        }
        if (tempTree->right) {
            st.push(tempTree->right);
        }
        if (tempTree->left) {
            st.push(tempTree->left);
        }

    }
    return res;
}