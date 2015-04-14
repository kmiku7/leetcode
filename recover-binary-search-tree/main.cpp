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

// 根据其他人的解法、代码、提问可以确定的是： 只是交换了节点的值，
// 而不是整个节点对应的子树。
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode *root) {
        vector<TreeNode*> inorder_node;
        vector<int> inorder_val;

        vector<TreeNode*> stack;
        TreeNode* curr = root;
        while(curr || !stack.empty()) {
            if(!curr){
                curr = stack.back();
                stack.pop_back();
                inorder_node.push_back(curr);
                inorder_val.push_back(curr->val);
                curr = curr->right;
            } else {
                stack.push_back(curr);
                curr = curr->left;
            }
        }
        sort(inorder_val.begin(), inorder_val.end());
        for(int i=0; i<inorder_val.size(); ++i) {
            inorder_node[i]->val = inorder_val[i];
        }
    }

};

class Solution {
public:
    void recoverTree(TreeNode *root) {

    }
};
void print_tree(TreeNode* root) {
    if(root==NULL) return;
    print_tree(root->left);
    cout << root->val << ", ";
    print_tree(root->right);
}

int main(int argc, char** argv) {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution s;
    s.recoverTree(root);

    print_tree(root);
    cout << endl;

    return 0;
}

