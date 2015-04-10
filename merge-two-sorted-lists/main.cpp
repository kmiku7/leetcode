#include <iostream>
#include <cstddef>
#include "solution.h"

using namespace std;

void printList(ListNode* head) {
    while(head){
        cout << head->val << ", ";
        head = head->next;
    }
    cout << endl;
}

ListNode* build_list(int start, int step, int count){
    ListNode* head;
    ListNode** pNode = &head;

    for(int i=0; i<count; ++i){
        *pNode = new ListNode(start);
        pNode = &((*pNode)->next);
        start += step;
    }
    return head;
}

int main(int argc, char** argv) {

    ListNode* l1 = build_list(1, 2, 5);
    ListNode* l2 = build_list(2, 2, 10);

    printList(l1);
    printList(l2);

    Solution s;

    ListNode* l3 = s.mergeTwoLists(l1, l2);
    printList(l3);


    return 0;
}
