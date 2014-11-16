/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 **/

#include <list>
#include <deque>

using namespace std;

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        deque<ListNode*> queue;
        ListNode* iter = head;
        ListNode* next = NULL;
        while (iter != NULL) {
            queue.push_back(iter);
            next = iter->next;
            iter->next = NULL;
            iter = next;
        }
        while (queue.size() >= 2) {
            iter = queue.front();
            queue.pop_front();
            next = queue.front();
            queue.pop_front();
            queue.push_back(mergeList(iter, next));
        }
        return queue.front();   
    }

private:
    ListNode* mergeList(ListNode* left, ListNode* right) {
        ListNode* merged_list = NULL;
        ListNode** next_holder = &merged_list;
        ListNode* selected_node = NULL;
        while(left != NULL && right != NULL) {
            if (left->val <= right->val) {
                selected_node = left;
                left = left->next;
            } else {
                selected_node = right;
                right = right->next;
            }
            selected_node->next = NULL;
            *next_holder = selected_node;
            next_holder = &(selected_node->next);
        }
        *next_holder = left ? left : right;
        return merged_list;
    }
};

