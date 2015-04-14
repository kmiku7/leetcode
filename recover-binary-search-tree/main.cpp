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

// https://leetcode.com/discuss/7319/an-elegent-time-complexity-and-space-complexity-algorithm
// https://leetcode.com/discuss/13034/no-fancy-algorithm-just-simple-and-powerful-order-traversal
//
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

// 这个解法有两个点需要注意：
//  1： morris遍历，类似于线索二叉树
//  2： 他是如何确定交换的是连续的两个数和不连续的两个数的。
//      即：1,2,3,4,5,6,7,
//      交换2，3，和交换2，6都能识别出来。
class Solution_b {
public:
    void recoverTree(TreeNode *root) {
        TreeNode* current = root;
        TreeNode* prev = NULL;
        TreeNode* miss_first = NULL;
        TreeNode* miss_second = NULL;

        while(current) {
            if(current->left==NULL) {
                if(prev && prev->val > current->val) {
                    if(!miss_first) miss_first = prev;
                    miss_second = current;
                }
                prev = current;
                current = current->right;
            } else {
                TreeNode* left_child = current->left;
                while(left_child->right != NULL && left_child->right != current) {
                    left_child = left_child->right;
                }
                if(left_child->right == NULL) {
                    left_child->right = current;
                    //prev = current;
                    current = current->left;
                } else {
                    if(prev && prev->val > current->val) {
                        if(!miss_first) miss_first = prev;
                        miss_second = current;
                    }
                    prev->right = NULL;
                    prev = current;
                    current = current->right;
                }
            }
        }
        if(miss_first) {
            int temp = miss_first->val;
            miss_first->val = miss_second->val;
            miss_second->val = temp;
        }
    }
};
void print_tree(TreeNode* root) {
    if(root==NULL) return;
    print_tree(root->left);
    cout << root->val << ", ";
    print_tree(root->right);
}

int main(int argc, char** argv) {

/*
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
*/
    TreeNode* root = new TreeNode(3);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(2);

    Solution_b s;
    s.recoverTree(root);

    print_tree(root);
    cout << endl;

    return 0;
}

