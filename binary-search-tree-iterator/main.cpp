#include <iostream>
#include <vector>
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

class BSTIterator {
    vector<TreeNode*> successor;
    TreeNode* current;

public:
    BSTIterator(TreeNode *root) {
        current = root;
        if(!current) return;

        while(current->left) {
            successor.push_back(current);
            current = current->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return current!=NULL;
    }

    /** @return the next smallest number */
    int next() {
        int ret = current->val;
        if(current->right==NULL && !successor.empty()) {
            current = successor.back();
            successor.pop_back();
        } else if(current->right==NULL) {
            current = NULL;
        }else {
            current = current->right;
            while(current->left) {
                successor.push_back(current);
                current = current->left;
            }
        }
        return ret;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main(int argc, char** argv) {

    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);

    TreeNode* root = n3;
    root->left = n2;
    root->left->left = n1;
    root->right = n4;

    BSTIterator iter(root);
    while(iter.hasNext()) {
        cout << iter.next() << endl;
    }


    return 0;
}
