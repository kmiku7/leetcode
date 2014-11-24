#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

#include "solution.cpp"

ListNode* build_list() {
    ListNode* head = NULL;
    for (int i = 0; i < 10; ++i) {
        ListNode* tmp = new ListNode(i);
        tmp->next = head;
        head = tmp;
    }
    return head;
}

void print_list(ListNode* head) {
    cout << "-----------" << endl;
    while (head) {
        cout << head->val << endl;
        head = head->next;
    }
}

int main(int argc, char** argv) {

    Solution ss;
    ListNode* head = build_list();
    ListNode* new_head = ss.insertionSortList(head);
    print_list(new_head);

    return 0;
}
