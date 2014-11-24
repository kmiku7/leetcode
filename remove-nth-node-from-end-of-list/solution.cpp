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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode** prev = &head;
        ListNode** current = &head;
        for (int i = 0; i < n; ++i) {
            current = &((*current)->next);
        }
        while ((*current) != NULL) {
            prev = &((*prev)->next);
            current = &((*current)->next);
        }
        *prev = (*prev)->next;
        return head;
    }
};
