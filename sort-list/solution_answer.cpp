
#include <cassert>

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //assert(head != NULL);

        int step = 1;
        int len = length(head);
        ListNode* sorted_list = NULL;
        ListNode** tail_holder = &sorted_list;
        while (step < len) {
            ListNode* left_head = NULL;
            ListNode* left_tail = NULL;
            ListNode* right_head = NULL;
            ListNode* right_tail = NULL;

            cutList(head, step, &left_head, &left_tail, &head);
            left_tail->next = NULL;
            if (head == NULL) {
                *tail_holder = left_head;
                goto NEXT_LOOP;
            }

            cutList(head, step, &right_head, &right_tail, &head);
            right_tail->next = NULL;
            *tail_holder = mergeList(left_head, right_head);
            //assert( (left_tail->next == NULL && right_tail->next != NULL)
            //        || (left_tail->next != NULL && right_tail->next == NULL));
            if (right_tail->next == NULL) {
                tail_holder = &(right_tail->next);
            } else {
                tail_holder = &(left_tail->next);
            }
NEXT_LOOP:
            if (head == NULL) {
                head = sorted_list;
                sorted_list = NULL;
                tail_holder = &sorted_list;
                step *= 2;
            }
        }
        return head;
    }


private:
    int length(ListNode* head) {
        int len = 0;
        while (head != NULL) {
            ++len;
            head = head->next;
        }
        return len;
    }
    void cutList(ListNode* head, int len, 
            ListNode** p_left_head, ListNode** p_left_tail, ListNode** p_right_head) {
        //assert(head != NULL);

        *p_left_head = head;
        *p_left_tail = head;
        *p_right_head = head->next;
        for (int i = 0; i < len && head != NULL; ++i) {
            *p_left_tail = head;
            *p_right_head = head->next;
            head = head->next;
        }
    }
    ListNode* mergeList(ListNode* left, ListNode* right) {
        //assert(left != NULL);
        //assert(right != NULL);

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
