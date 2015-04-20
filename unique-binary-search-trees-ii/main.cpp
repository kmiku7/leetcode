#include <iostream>
#include <vector>

// 对比
// http://fisherlei.blogspot.com/2013/03/leetcode-unique-binary-search-trees-ii.html

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
    vector<TreeNode *> generateTrees(int n) {
        vector<vector<TreeNode*>> subtree;

        // n = 0
        subtree.push_back(vector<TreeNode*>());
        subtree.back().push_back(NULL);

        // n = 1
        subtree.push_back(vector<TreeNode*>());
        subtree.back().push_back(new TreeNode(0));

        for(int in=2; in<=n; ++in) {
            subtree.resize(subtree.size()+1);
            for(int left=0; left<in; ++left) {
                int right = in-left-1;
                auto &left_cands = subtree[left];
                auto &right_cands = subtree[right];
                for(auto left_node : left_cands){
                    for(auto right_node : right_cands) {
                        TreeNode* tree = new TreeNode(0);
                        tree->left = left_node;
                        tree->right = right_node;
                        subtree.back().push_back(tree);
                    }
                }
            }

        }
        // fill and set
        vector<TreeNode*> result;
        result.reserve(subtree[n].size());
        for(auto root : subtree[n]) {
            TreeNode* temp = NULL;
            int next_value = 1;
            copy_and_set(temp, root, next_value);
            result.push_back(temp);
        }
        return result;
    }

    void copy_and_set(TreeNode*& root, TreeNode* template_tree, int& next_value) {
        if(template_tree==NULL) return;
        root = new TreeNode(0);
        copy_and_set(root->left, template_tree->left, next_value);
        root->val = next_value++;
        copy_and_set(root->right, template_tree->right, next_value);
    }
};

void print_preorder(TreeNode* root) {
    if(!root) return;
    cout << root->val << ", ";
    print_preorder(root->left);
    print_preorder(root->right);
}

int main(int argc, char** argv) {

    Solution s;
    auto result = s.generateTrees(0);
    cout << result.size() << endl;

    for(auto root : result) {
        print_preorder(root);
        cout << endl;
    }

    return 0;
}
