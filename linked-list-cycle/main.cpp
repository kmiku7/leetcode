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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        
        ListNode* dbl = head->next;
        while(head && dbl && head!=dbl) {
            dbl = dbl->next;
            head = head->next;
            dbl = dbl ? dbl->next : nullptr;
        }
        
        return dbl && dbl==head;
        
    }
};
