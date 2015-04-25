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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;
        do {
            fast = fast->next;
            slow = slow->next;
            fast = fast ? fast->next : nullptr;
        }while(fast && slow!=fast);
        
        if(!fast) return nullptr;
        
        fast = head;
        while(fast!=slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
