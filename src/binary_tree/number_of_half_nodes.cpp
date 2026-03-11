#include <string>
#include <vector>
#include "tree_node.hpp"
#include <stack>

int countHalf(TreeNode *root) {
    int res =0;
    if (root == nullptr) {
        return res;
    }

    std::stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* tempTree =st.top();
        st.pop();
        if ((tempTree->right && !tempTree->left)||(!tempTree->right && tempTree->left)) {
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