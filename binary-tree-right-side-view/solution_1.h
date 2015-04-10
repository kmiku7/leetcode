/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>
#include "TreeNode.h"
#include <cstddef>

using namespace std;


class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;   
    }

    void dfs(TreeNode* node, int level, vector<int>& result){
        if(node==NULL) return;
        if(level<result.size()){
            result[level] = node->val;
        } else {
            result.push_back(node->val);
        }
        dfs(node->left, level+1, result);
        dfs(node->right, level+1, result);
    }
};
