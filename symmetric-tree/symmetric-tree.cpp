#include <iostream>
#include <deque>
#include <string>
#include <queue>
#include <climits>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>


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

    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        deque<TreeNode*> current_level;
        deque<TreeNode*> next_level;
        current_level.push_back(root);
        while(!current_level.empty()) {
            int begin = 0;
            int end = current_level.size() -1;
            while (begin < end) {
                auto begin_val = current_level[begin];
                auto end_val = current_level[end];
                if ((begin_val == NULL && end_val ==NULL) ||
                        (begin_val != NULL && end_val != NULL && begin_val->val == end_val->val)) {
                    ++begin;
                    --end;
                } else {
                    return false;
                }
            }
            for (auto iter = current_level.begin(); iter != current_level.end(); ++iter) {
                if (*iter) {
                    next_level.push_back((*iter)->left);
                    next_level.push_back((*iter)->right);
                }
            }
            current_level.clear();
            next_level.swap(current_level);
        }
        return true;
    }
};

vector<string> raw_case = {
        "1",
        "#",
        "1,#,2,3",
        "1,2,3,#,#,4,#,#,5",
        "1,2,2,3,4,4,3",
        "1,2,2,#,3,#,3",
};

void build_tree(TreeNode** p_head, const string& raw_str) {
    queue<TreeNode**> node_list;
    node_list.push(p_head);
    const char* serialized_data = raw_str.c_str();
    while (*serialized_data) {
        if (*serialized_data == '#') {
            TreeNode **p_node = node_list.front();
            node_list.pop();
            *p_node = NULL;
            ++serialized_data;
        } else if (*serialized_data == '-' || *serialized_data == '+' || isdigit(*serialized_data)) {
            const char* end_pos;
            errno = 0;
            long int val = strtol(serialized_data, const_cast<char**>(&end_pos), 0);
            assert(errno == 0);
            assert(val <= INT_MAX);
            serialized_data = end_pos;
            TreeNode** p_node = node_list.front();
            node_list.pop();
            *p_node = new TreeNode(val);
            node_list.push(&((*p_node)->left));
            node_list.push(&((*p_node)->right));
        } else {
            ++serialized_data;
        }
    }

    while(!node_list.empty()) {
        (*node_list.front()) = NULL;
        node_list.pop();
    }

    return;
 }

void print_tree_mid(TreeNode* head) {
    if (head == NULL) {
        return;
    }
    cout << head->val << "\t";
    print_tree_mid(head->left);
    print_tree_mid(head->right);
}

void print_tree_left(TreeNode* head) {
    if (head == NULL) {
        return;
    }
    print_tree_left(head->left);
    cout << head->val << "\t";
    print_tree_left(head->right);
}
void free_tree(TreeNode* head) {

}



int main(int argc, char** argv) {

    Solution ss;
    for (auto iter = raw_case.begin(); iter != raw_case.end(); ++iter) {
        cout << "----- ------ -----" << endl;
        TreeNode *head = NULL;
        build_tree(&head, *iter);
        print_tree_mid(head);
        cout << endl;
        print_tree_left(head);
        cout << endl;
        cout << ss.isSymmetric(head) << endl;
    }

    return 0;
}