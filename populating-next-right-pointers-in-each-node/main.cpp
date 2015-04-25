/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* level_head = root;
        while(level_head) {
            TreeLinkNode* item = level_head;
            while(item) {
                TreeLinkNode* left = item->left;
                TreeLinkNode* right = item->right;
                // while(left && right) {
                while(left) {
                    left->next = right;
                    left = left->right;
                    right = right->left;
                }
                item = item->next;
            }
            level_head = level_head->left;
        }
    }
};
