#include <iostream>
#include <cstddef>
#include "solution.h"


using namespace std;


ListNode* build_list(int start, int step, int count) {
    ListNode* head=NULL;
    ListNode** pNode = &head;
    while((count--)>0){
        *pNode = new ListNode(start);
        start += step;
        pNode = &((*pNode)->next);
    }
    return head;
}

void print_list(ListNode* node){
    while(node){
        cout << node->val << ", ";
        node = node->next;
    }
    cout << endl;
}

int main(int argc, char** argv) {


    ListNode* head = build_list(1, 1, 12);
    int k = 5;
    Solution s;

    print_list(head);
    ListNode* result = s.reverseKGroup(head, k);
    print_list(result);


    return 0;
}
