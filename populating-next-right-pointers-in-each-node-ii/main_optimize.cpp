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
            TreeLinkNode* prev_item = nullptr;
            while(item) {
                if(item->left) {
                    if(prev_item) {
                        prev_item->next = item->left;
                        prev_item = item->left;
                    }
                    else
                        next_level_head = prev_item = item->left;
                }
                if(item->right) {
                    if(prev_item) {
                        prev_item->next = item->right;
                        prev_item = item->right;
                    }
                    else
                        next_level_head = prev_item = item->right;
                }
                item = item->next;
            }
            level_head = next_level_head;
        }       
    }
};
