// http://articles.leetcode.com/2010/10/binary-tree-post-order-traversal.html


#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> output;
        vector<TreeNode*> stack;
        stack.push_back(root);

        while(!stack.empty()) {
            TreeNode* node = stack.back();
            stack.pop_back();
            if(!node) continue;
            output.push_back(node->val);
            stack.push_back(node->left);
            stack.push_back(node->right);
        }
        reverse(output.begin(), output.end());
        return output;
    }
};

class Solution_b {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> output;
        if(!root) return output;

        vector<TreeNode*> stack;
        stack.push_back(root);

        while(!stack.empty()) {
            TreeNode* node = stack.back();
            stack.pop_back();
            output.push_back(node->val);
            if(node->left) stack.push_back(node->left);
            if(node->right) stack.push_back(node->right);
        }
        reverse(output.begin(), output.end());
        return output;
    }
};

int main(int argc, char** argv) {

    return 0;
}
