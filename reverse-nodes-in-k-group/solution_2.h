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

        int len = 0;
        ListNode* left = head;
        while(left){
            ++len;
            left = left->next;
        }

        int group_count = len / k;
        ListNode** pHead;
        ListNode** pTail;

        left = head;
        head = NULL;
        pTail = &head;
        while(group_count-->0){
            pHead = pTail;
            pTail = &(left->next);
            int count = k;
            while(count-->0){
                ListNode* temp_node = left;
                left = left->next;
                temp_node->next = *pHead;
                *pHead = temp_node;
            }
        }
        *pTail = left;

        return head;
    }
};
