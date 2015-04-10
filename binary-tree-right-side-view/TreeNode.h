#ifndef __TREENODE_H__
#define __TREENODE_H__

#include <cstddef>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif // __TREENODE_H__
