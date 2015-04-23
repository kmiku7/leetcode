#include <cstddef>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <climits>
#include <cassert>

using namespace std;

// hasher for const char*
size_t str_hash(const char* str, int len) {
    size_t h = 0;
    while(len-->0) {
        h = 5*h + *str;
        ++str;
    }
    return h;
}

const size_t AVLTREE_MAX_HEIGHT = 62;

struct AVLTreeNode {
    AVLTreeNode* left;
    AVLTreeNode* right;
    int height;
    size_t key;
    int value;
    AVLTreeNode(size_t k=0, int v=0) : left(nullptr), right(nullptr), height(1), key(k), value(v) {}
};

int avl_height(AVLTreeNode* root) {
    return root?root->height:0;
}

int avl_height_update(AVLTreeNode* root) {
    // assert(root!=NULL);
    return (root->height = std::max(avl_height(root->left), avl_height(root->right)) + 1);
}

int avl_balance_factor(AVLTreeNode* root) {
    // assert(root!=NULL);
    return avl_height(root->left) - avl_height(root->right);
}

AVLTreeNode* avl_rotate_left(AVLTreeNode* root) {
    // assert(root!=nullptr);
    AVLTreeNode* right = root->right;
    // assert(right!=nullptr);
    root->right= right->left;
    right->left = root;
    avl_height_update(root);
    avl_height_update(right);
    return right;
}

AVLTreeNode* avl_rotate_right(AVLTreeNode* root) {
    // assert(root!=nullptr);
    AVLTreeNode* left = root->left;
    // assert(right!=nullptr);
    root->left = left->right;
    left->right = root;
    avl_height_update(root);
    avl_height_update(left);
    return left;
}

// true:    insert;
// false:   update;
bool avl_insert(AVLTreeNode*& root, size_t key, int value) {
    AVLTreeNode* path[AVLTREE_MAX_HEIGHT] = {nullptr};
    int top_pos = 1;
    AVLTreeNode* curr = root;
    while(curr!=NULL) {
        path[top_pos++] = curr;
        if(curr->key>key) {
            curr = curr->left;
        } else if(curr->key<key) {
            curr = curr->right;
        } else {
            curr->value = value;
            return false;
        }
    }

    curr = new AVLTreeNode(key, value);
    AVLTreeNode* parent = path[--top_pos];
    if(parent==nullptr) root = curr;
    else if(parent->key<key) parent->right = curr;
    else parent->left = curr;

    while(parent!=nullptr) {
        int parent_balance_factor = avl_balance_factor(parent);
        int curr_balance_factor = avl_balance_factor(curr);
        if(parent_balance_factor==2) {
            if(curr_balance_factor==-1) {
                curr = avl_rotate_left(curr);
                parent->left = curr;
            }

            AVLTreeNode** p_parent_parent = nullptr;
            if(path[top_pos-1]==nullptr)
                p_parent_parent = &root;
            else if(path[top_pos-1]->left == parent)
                p_parent_parent = &path[top_pos-1]->left;
            else
                p_parent_parent = &path[top_pos-1]->right;

            parent = avl_rotate_right(parent);
            *p_parent_parent = parent;
            break;
        } else if(parent_balance_factor==-2) {
            if(curr_balance_factor==1) {
                curr = avl_rotate_right(curr);
                parent->right = curr;
            }


            AVLTreeNode** p_parent_parent = nullptr;
            if(path[top_pos-1]==nullptr)
                p_parent_parent = &root;
            else if(path[top_pos-1]->left == parent)
                p_parent_parent = &path[top_pos-1]->left;
            else
                p_parent_parent = &path[top_pos-1]->right;

            parent = avl_rotate_left(parent);
            *p_parent_parent = parent;
            break;
        } else if(parent_balance_factor==0) {
            // origin: left - right = -1
            // now: left = left + 1
            break;
        }
        avl_height_update(parent);
        curr = parent;
        parent = path[--top_pos];

    }

    return true;
}


bool avl_search(AVLTreeNode* const root, size_t key, int* value) {
    AVLTreeNode* temp = root;
    while(temp) {
        if(temp->key==key) {
            if(value) *value = temp->value;
            return true;
        }
        if(temp->key < key) {
            temp = temp->right;
        } else {
            temp = temp->left;
        }
    }
    return false;
}

bool avl_delete(AVLTreeNode*& root, size_t key, int* value) {
    AVLTreeNode* path[AVLTREE_MAX_HEIGHT] = {nullptr};
    int top_pos = 1;
    AVLTreeNode* curr = root;
    AVLTreeNode* remove = nullptr;
    while(curr!=NULL) {
        if(curr->key==key)
            break;
        path[top_pos++] = curr;
        if(curr->key>key)
            curr = curr->left;
        else 
            curr =curr->right;
    }
    if(curr==nullptr)
        return false;

    remove = curr;
    if(curr->left!=nullptr && curr->right!=nullptr)
    {
        remove = curr->left;
        path[top_pos++] = curr;
        while(remove->right) {
            path[top_pos++] = remove;
            remove = remove->right;
        }
    }

    AVLTreeNode* parent = path[--top_pos];
    if(parent==nullptr) {
        // assert(remove==curr);
        root = remove->left ? remove->left : remove->right;
        delete(remove);
        return true;
    }

    if(remove!=curr) {
        curr->key = remove->key;
        curr->value = remove->value;
    }
    curr = remove->left ? remove->left : remove->right;
    if(remove==parent->left)
        parent->left = curr;
    else
        parent->right = curr;

    delete(remove);

    while(parent!=nullptr) {
        parent->height = avl_height_update(parent);
        int parent_balance_factor = avl_balance_factor(parent);
        if(parent_balance_factor==2) {
            int curr_balance_factor = avl_balance_factor(parent->left);
            if(curr_balance_factor==-1)
                parent->left = avl_rotate_left(parent->left);
            
            AVLTreeNode** p_parent_parent = nullptr;
            if(path[top_pos-1]==nullptr)
                p_parent_parent = &root;
            else if(path[top_pos-1]->left == parent)
                p_parent_parent = &path[top_pos-1]->left;
            else
                p_parent_parent = &path[top_pos-1]->right;

            parent = avl_rotate_right(parent);
            *p_parent_parent = parent;
            break;
        } else if(parent_balance_factor==-2) {
            int curr_balance_factor = avl_balance_factor(parent->right);
            if(curr_balance_factor==1)
                parent->right = avl_rotate_right(parent->right);

            AVLTreeNode** p_parent_parent = nullptr;
            if(path[top_pos-1]==nullptr)
                p_parent_parent = &root;
            else if(path[top_pos-1]->left == parent)
                p_parent_parent = &path[top_pos-1]->left;
            else
                p_parent_parent = &path[top_pos-1]->right;

            parent = avl_rotate_left(parent);
            *p_parent_parent = parent;
            break;
        } else if(parent_balance_factor == 1 || parent_balance_factor == -1) {
            break;
        }
        //curr = parent;
        avl_height_update(parent);
        parent = path[--top_pos];
    }
    return true;
}

void print_tree_inorder(AVLTreeNode* root, int level = 0) {
    if(!root) return;
    if(!level) cout << "----------" << endl;
    print_tree_inorder(root->left, level+1);
    cout << "(" << root->key << "," << root->value << "," << level << "," << root->height << "), ";
    print_tree_inorder(root->right, level+1);
    if(!level) cout << endl;
}


class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        AVLTreeNode* head = nullptr;
        int sum = 0;
        for(auto item: num) {
            int value = 0;
            bool ret = avl_search(head, item, &value);
            avl_insert(head, item, value+1);
        }
        vector<vector<int>> result;
        vector<int> buffer;
        buffer.reserve(num.size()/2);

        print_tree_inorder(head);

        // 先将二叉树转成线索二叉树，然后再转换回来。
        // trans to threaded thee;
        AVLTreeNode* curr = head;
        AVLTreeNode* thread_head = nullptr;
        while(curr) {
            if(curr->left==nullptr) {
                if(thread_head==nullptr) thread_head = curr;
                curr = curr->right;
                continue;
            }

            AVLTreeNode* left = curr->left;
            while(left->right && left->right!=curr) left = left->right;
            if(left->right == nullptr) {
                left->right = curr;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        // print threaded tree
        curr = thread_head;
        while(curr) {
            cout << "(" << curr->key << "," << curr->value << ")";
            curr = curr->right;
        }
        cout << endl;

        dfs(thread_head, target, buffer, result);
        
        // unthread
        curr = thread_head;
        while(curr) {
            if(curr->left == nullptr) {
                curr = curr->right;
                continue;
            }
            AVLTreeNode* left = curr->left;
            while(left->right && left->right!=curr) left = left->right;
            if(left->right == curr) {
                left->right = nullptr;
                curr = curr->right;
            } else {
                assert(false && "should not here");
                curr = curr->left;
            }
        }
        return result;
    }
private:
    void dfs(AVLTreeNode* head, int target, vector<int>& tpl, vector<vector<int>>& result) {
        if(head==nullptr) return;
        int num = head->key;
        int i = 0;

        AVLTreeNode* next = head->right;
        AVLTreeNode* left = next ? next->left : nullptr;
        if(left) {
            while(left->right && left->right!=next) left = left->right;
            if(left != head) {
                while(next->left) next = next->left;
            }
        }

        do {
            if(target==0) result.push_back(tpl);
            else if(target>num) dfs(next, target, tpl, result);

            ++i;
            tpl.push_back(num);
            target -= num;

        }while(i<=head->value && target >=0);
        tpl.resize(tpl.size()-i);
    }
};

int main(int argc, char** argv) {

//    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
//    int target = 8;
    vector<int> nums = {4,4,2,1,4,2,2,1,3};
    int target = 6;
    Solution s;

    auto result = s.combinationSum2(nums, target);
    cout << result.size() << endl;

    for(auto& item : result) {
        cout << "size(" << item.size() << ") ";
        for(auto val : item) {
            cout << val << ", ";
        }
        cout << endl;
    }
    return 0;
}
