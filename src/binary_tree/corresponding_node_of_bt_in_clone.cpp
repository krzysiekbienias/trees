#include <string>
#include <vector>
#include "tree_node.hpp"


TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original==nullptr || cloned==nullptr) {
                return nullptr;
        }

        std::queue<std::pair<TreeNode*,TreeNode*>> q;
        q.push({original,cloned});
        while (!q.empty()) {
                //structured bindings
                //⚠️ tutaj nie rob const&
                auto [curr_ori,curr_cl]=q.front();
                q.pop();
                if (curr_ori==target) {
                        return curr_cl;
                }
                if (curr_ori->left){
                        q.push({curr_ori->left,curr_cl->left});
                }
                if (curr_ori->right){
                        q.push({curr_ori->right,curr_cl->right});
                }

        }
        return nullptr;
}