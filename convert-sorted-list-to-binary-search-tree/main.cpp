#include <iostream>
#include <climits>
#include <cstddef>

using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    TreeNode *sortedListToBST(ListNode *head) {
        if(head==NULL) return NULL;


        TreeNode* root = NULL;
        int list_len = 0;
        ListNode* curr = head;
        while(curr){
            list_len += 1;
            curr = curr->next;
        }

        root = build_threaded_tree(0, list_len);

        TreeNode* tree_curr = root;
        curr = head;
        while(tree_curr) {
            if(tree_curr->left==NULL) {
                tree_curr->val = curr->val;
                curr = curr->next;
                tree_curr = tree_curr->right;
            } else {
                TreeNode* precursor = tree_curr->left;
                while(precursor->right!=NULL && precursor->right!=tree_curr) {
                    precursor = precursor->right;
                }
                if(precursor->right==NULL){
                    precursor->right=tree_curr;
                    tree_curr = tree_curr->left;
                } else {
                    tree_curr->val = curr->val;
                    curr = curr->next;
                    precursor->right = NULL;
                    tree_curr = tree_curr->right;
                }
            }
        }
        return root;
    }

    TreeNode* build_threaded_tree(int idx, int idx_ub) {
        // assert(idx<idx_ub);
        TreeNode* root = new TreeNode(idx);

        // left child
        int child_idx = idx*2 + 1;
        if(child_idx<idx_ub) {
            root->left = build_threaded_tree(child_idx, idx_ub);
        }

        // right child
        child_idx += 1;
        if(child_idx<idx_ub) {
            root->right = build_threaded_tree(child_idx, idx_ub);
        }

        return root;
    }

};

void print_tree_pre(TreeNode* root) {
    if(!root) return;
    cout << root->val << ", " << endl;
    print_tree_pre(root->left);
    print_tree_pre(root->right);
}
void print_tree_in(TreeNode* root) {
    if(!root) return;
    print_tree_in(root->left);
    cout << root->val << ", " << endl;
    print_tree_in(root->right);
}

int main(int argc, char** argv) {


    ListNode* root = NULL;
    for(int i=10; i>=0; i--) {
        ListNode* temp = new ListNode(i);
        temp->next = root;
        root = temp;
    }

    Solution s;
    TreeNode* tree = s.sortedListToBST(root);

    print_tree_in(tree);
    cout << endl;
    print_tree_pre(tree);
    cout << endl;
    return 0;
}
