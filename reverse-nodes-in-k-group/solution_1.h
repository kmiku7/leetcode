/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(k<=1) return head;

        ListNode* sub_head = head;
        ListNode** p_sub_head = &head;
        while(sub_head){
            for(int count = k-1; count>0; --count){
                ListNode* insert_pos = sub_head;
                int step = count;
                while(insert_pos && step>0){
                    insert_pos = insert_pos->next;
                    --step;
                }
                if(!insert_pos) break;
                ListNode* tmp_sub_head = sub_head->next;
                sub_head->next = insert_pos->next;
                insert_pos->next = sub_head;
                sub_head = tmp_sub_head;
            }
            *p_sub_head = sub_head;
            int step = k;
            while(sub_head && step>0){
                p_sub_head = &(sub_head->next);
                sub_head = sub_head->next;
                --step;
            }
        }
        return head;
    }
};
