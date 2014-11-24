/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode* new_head = NULL;
        while (head!=NULL) {
            ListNode* tmp = head;
            head = head->next;
            tmp->next = NULL;
            ListNode** insert_pos = &new_head;
            while (*insert_pos) {
                if ((*insert_pos)->val > tmp->val) {
                    break;
                }
                insert_pos = &((*insert_pos)->next);
            }
            tmp->next = *insert_pos;
            *insert_pos = tmp;
        }
        return new_head;
    }
};
