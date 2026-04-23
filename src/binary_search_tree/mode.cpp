#include <string>
#include <vector>
#include "tree_node.hpp"
#include "binary_search_tree/mode.hpp"
#include <stack>
#include <unordered_map>

#include "traversal/inorder.hpp"

std::vector<int> findMode(TreeNode *root) {
    std::vector<int> res;
    std::stack<int> st;
    std::vector<int> inOrder = inOrderRecursion(root);
    std::unordered_map<int, int> freq;
    for (int x: inOrder) {
        freq[x]++;
    }
    int maxFreq = 0;
    int maxFreqKey = 0;

    for (const auto &[k,v]: freq) {
        if (st.empty() || v >= maxFreq) {
            maxFreqKey = k;
            st.push(maxFreqKey);
        } else {
            st.pop();
        }
    }
    while (st.empty()) {
        int top = st.top();
        res.push_back(top);
        st.pop();
    }
    return res;
}
