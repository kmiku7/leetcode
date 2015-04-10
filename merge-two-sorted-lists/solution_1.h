/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <cstddef>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode* head = NULL;
        ListNode** pNode = &head;

        while(l1 && l2){
            if(l1->val < l2->val){
                *pNode = l1;
                pNode = &(l1->next);
                l1 = l1->next;
            } else {
                *pNode = l2;
                pNode = &(l2->next);
                l2=l2->next;
            }
        }
        *pNode = l1 ? l1 : l2;
        return head;
    }
};
