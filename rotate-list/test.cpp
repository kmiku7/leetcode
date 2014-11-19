#include <iostream>
#include <list>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#include "solution.cpp"

ListNode* build_list(int* arr, int len) {
    ListNode* head = NULL;
    ListNode** target = &head;
    for (int i = 0; i < len; ++i) {
        *target = new ListNode(arr[i]);
        target = &(*target)->next;
    }
    return head;
}

void print_list(ListNode* list) {
    while (list != NULL) {
        cout << "\t" << list->val << endl;
        list = list->next;
    }
}

int main(int argc, char** argv) {

    int raw_list[] = {1,2,3,4,5};
    int k = 2;

    ListNode* head = build_list(raw_list, sizeof(raw_list)/sizeof(int));
    Solution ss;

    print_list(head);
    cout << "-------------" << endl;

    ListNode* new_head = ss.rotateRight(head, k);
    print_list(new_head);

    return 0;
}
