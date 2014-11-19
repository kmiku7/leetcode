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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) {
            return head;
        }
        ListNode** pTailNext = NULL;
        ListNode** pMidd = &head;
        ListNode*  newHead = NULL;
        int len = length(&head, &pTailNext);
        k = k % len;
        if (k == 0) {
            return head;
        }
        k = len - k;
        while (k > 1) {
            pMidd = &((*pMidd)->next);
            --k;
        }
        newHead = (*pMidd)->next;
        (*pMidd)->next = NULL;
        *pTailNext  = head;
        return newHead;
    }
private:
    int length(ListNode **head, ListNode ***pTail) {
        int len = 0;
        *pTail = head;
        while (**pTail != NULL) {
            ++len;
            *pTail = &((**pTail)->next);
        }
        return len;
    }
};
