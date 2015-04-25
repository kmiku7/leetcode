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
            TreeLinkNode* next_level_head = nullptr;
            TreeLinkNode** prev_item = &next_level_head;
            TreeLinkNode* item = level_head;
            while(item) {
                if(item->left) {
                    *prev_item = item->left;
                    prev_item = &(item->left->next);
                }
                if(item->right) {
                    *prev_item = item->right;
                    prev_item = &(item->right->next);
                }
                item = item->next;
            }
            level_head = next_level_head;
        }
    }
};
