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

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        int left_right = false;
        vector<TreeNode*> curr;
        vector<TreeNode*> next;
        vector<vector<int>> result;

        if(root) next.push_back(root);

        while(!next.empty()){
            curr.swap(next);
            result.resize(result.size()+1);
            left_right = !left_right;
            for(auto iter = curr.rbegin(); iter != curr.rend(); ++iter) {
                result.back().push_back((*iter)->val);
                if(left_right) {
                    if((*iter)->left) next.push_back((*iter)->left);
                    if((*iter)->right) next.push_back((*iter)->right);
                } else {
                    if((*iter)->right) next.push_back((*iter)->right);
                    if((*iter)->left) next.push_back((*iter)->left);
                }
            }
            curr.clear();
        }
        return result;
    }
};

int main(int argc, char** argv) {

    return 0;
}
