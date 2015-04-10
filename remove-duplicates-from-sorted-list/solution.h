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
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==NULL) return head;
        ListNode* pNext = head;
        while(pNext->next){
            if(pNext->val == pNext->next->val){
                pNext->next = pNext->next->next;
            } else {
                pNext = pNext->next;
            }
        }
        return head;
    }
};
