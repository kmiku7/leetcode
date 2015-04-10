#include "TreeNode.h"
#include "solution.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>


TreeNode* build_case(){

    //       1
    //   2       3
    // 1   5        5
    //  4

    TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode* node = NULL;

    left = NULL;
    right = new TreeNode(4);
    node = new TreeNode(1);
    node->right = right;

    left = node;
    right = new TreeNode(5);
    node = new TreeNode(2);
    node->left = left;
    node->right = right;

    left = node;

    right = new TreeNode(3);
    right->right = new TreeNode(5);

    node = new TreeNode(1);
    node->left = left;
    node->right = right;

    return node;
}

int main(int argc, char** argv) {


    Solution s;
    TreeNode* root = build_case();

    auto result = s.rightSideView(root);
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
