#include "queries/kth_ancestor_of_tree_node.hpp"

#include <string>
#include <vector>
#include "tree_node.hpp"


TreeAncestor::TreeAncestor(int n, std::vector<int> &parent):up(n,std::vector<int>(16,-1)) {
    //the precomputing phase is happening in the constructor
    for (int i = 0; i < n; ++i) {
        up[i][0]=parent[i];
    }
    //15 because of problem constraints defined in leedcode
    for (int j = 1; j < 16; ++j) {
        for (int i = 0; i < n; ++i) {
            if (up[i][j-1]!=-1) {
                up[i][j]=up[up[i][j-1]][j-1];
            }
        }
    }
};

int TreeAncestor::getKthAncestor(int node, int k) {
    for (int i = 15; i >=0;  --i) {
        if (k>=(1<<i)) {
            node=up[node][i];
            k-=(1<<i);
            if (node==-1) {
                break;
            }
        }

    }
    return node;
}
