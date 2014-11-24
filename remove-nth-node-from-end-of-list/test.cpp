#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

#include "solution.cpp"

int case_a[] = {1,2,3,4,5};
int n = 2;

ListNode* build_list() {

    ListNode* head = NULL;
    ListNode** current = &head;
    for (int i = 0; i < sizeof(case_a)/sizeof(int); ++i) {
        *current = new ListNode(case_a[i]);
        (*current)->next = NULL;
        current = &((*current)->next);
    }

    return head;
}

void print_list(ListNode* head) {
    cout << "----------" << endl;
    while (head) {
        cout << head->val << endl;
        head = head->next;
    }
}

int main(int argc, char** argv) {

    ListNode* head = build_list();
    print_list(head);
    Solution ss;
    ListNode* new_head = ss.removeNthFromEnd(head, n);
    print_list(new_head);

    return 0;
}

