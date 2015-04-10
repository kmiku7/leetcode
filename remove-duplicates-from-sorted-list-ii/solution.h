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
    ListNode *deleteDuplicates(ListNode *head) {

        if(head==NULL) return NULL;

        ListNode** ppNext = &head;
        ListNode* pNext = head;
        //head = NULL;
        int count = 1;
        while(pNext->next){
            if(pNext->next->val == pNext->val){
                count++;
            } else {
                if(count==1){
                    *ppNext = pNext;
                    ppNext = &(pNext->next);
                }
                count = 1;
            }
            pNext = pNext->next;
        }
        if(count==1){
            *ppNext = pNext;
            ppNext = &(pNext->next);
        }
        *ppNext = NULL;
        return head;
    }
};
