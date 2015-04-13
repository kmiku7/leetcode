#include <iostream>
#include <climits>

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

// wrong:
// Input:   {1,2,3}
// Output:  4
// Expected:    6
// 没有不能跨左右分支的限制。
class Solution_w1 {
public:
    int maxPathSum(TreeNode *root) {
        return maxPathSum(root, 0, INT_MIN);   
    }
    int maxPathSum(TreeNode *node, int current_sum, int current_max) {
        if(node==NULL) return current_max;

        current_sum += node->val;
        current_max = max(current_sum, current_max);
        current_sum = max(current_sum, 0);
        current_max = max(current_max, maxPathSum(node->left, current_sum, current_max));
        current_max = max(current_max, maxPathSum(node->right, current_sum, current_max));

        return current_max;
    }
};


class Solution {
public:
    int maxPathSum(TreeNode *root) {
        if(root==NULL) return 0;

        int max_value = INT_MIN;
        traverseNode(root, max_value);
        return max_value;
    }
    // return continuous len from leaf, must end in this node.
    int traverseNode(TreeNode* node, int& max_value) {
        if(node==NULL) return INT_MIN;

        int left_sum = traverseNode(node->left, max_value);
        //max_value = max(max_value, left_sum);
        left_sum = max(left_sum, 0);

        int right_sum = traverseNode(node->right, max_value);
        //max_value = max(max_value, right_sum);
        right_sum = max(right_sum, 0);

        max_value = max(max_value, left_sum + right_sum + node->val);

        return node->val + max(left_sum, right_sum);
    }
};

int main(int argc, char** argv) {
    return 0;
}
