#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//#include "solution_answer.cpp"
#include "solution.cpp"
#include "case_b.cpp"

ListNode* buildList(int* array, int len) {
    cout << "len:" << len << endl;
    ListNode* head = NULL;
    ListNode** pp_node = &head;
    for(int i = 0; i < len; ++i) {
        *pp_node = new ListNode(array[i]);
        pp_node = &((*pp_node)->next);
    }
    return head;
}

void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val << endl;
        head = head->next;
    }
}

int main(int argc, char** argv) {

    Solution ss;
    int case_a[] = {9,7,5,3,1,8,6,4,2,0};

    //ListNode* head = buildList(case_b, sizeof(case_b)/sizeof(int));
    ListNode* head = buildList(case_a, sizeof(case_a)/sizeof(int));
    printList(head);
    cout << "---------------" << endl;
    ListNode* sorted = ss.sortList(head);
    printList(sorted);
    return 0;
}






