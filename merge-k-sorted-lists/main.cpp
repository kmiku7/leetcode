#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <cstdlib>
#include <iterator>

using namespace std;

#define SOLUTION Solution_b

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


bool ListNodeCompare(ListNode* left, ListNode* right) {
    return left->val < right->val;
}
bool ListNodeCompareHeap(ListNode* left, ListNode* right) {
    return left->val >= right->val;
}

void print_list(ListNode* left) {
    int count = 0;
    while(left){
        cout << left->val << ", ";
        left = left->next;
        ++count;
    }
    cout << endl;
    cout << "count: " << count << endl;;

}

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty()) return NULL;

        ListNode* head=NULL;
        ListNode** pHead = &head;

        for(int i=0; i<lists.size(); ) {
            if(lists[i]==NULL) lists.erase(lists.begin()+i);
            else ++i;
        }

        while(lists.size()>1){
            sort(lists.begin(), lists.end(), ListNodeCompare);
            *pHead = lists[0];
            pHead = &(*pHead)->next;
            lists[0] = lists[0]->next;
            if(lists[0]==NULL) lists.erase(lists.begin());
        }
        *pHead = lists[0];

        return head;
    }
};

class Solution_a {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty()) return NULL;

        ListNode* head=NULL;
        ListNode** pHead = &head;

        // Last executed input: [{},{}]
        for(int i=0; i<lists.size(); ) {
            if(lists[i]==NULL) lists.erase(lists.begin()+i);
            else ++i;
        }

        make_heap(lists.begin(), lists.end(), ListNodeCompareHeap);
        while(lists.size()>1){
            pop_heap(lists.begin(), lists.end(), ListNodeCompareHeap);
            *pHead = lists.back();
            pHead = &(*pHead)->next;
            lists.back() = lists.back()->next;
            if(lists.back()==NULL) lists.pop_back();
            else push_heap(lists.begin(), lists.end(), ListNodeCompareHeap);
        }
        *pHead = lists[0];

        return head;
    }
};


class Solution_b {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty()) return NULL;

        ListNode* head=NULL;
        ListNode** pHead = &head;

        // Last executed input: [{},{}]
        for(int i=0; i<lists.size(); ) {
            if(lists[i]==NULL) lists.erase(lists.begin()+i);
            else ++i;
        }

        make_heap(lists.begin(), lists.end(), ListNodeCompareHeap);
        while(lists.size()>1){
            *pHead = lists.front();
            pHead = &(*pHead)->next;
            lists.front() = lists.front()->next;
            if(lists.front()==NULL){
                lists.front() = lists.back();
                lists.pop_back();
            }
            // shift down
            int count = lists.size();
            int parent_idx = 0;
            int left_child = 1;
            ListNode* current_value = lists[0];
            while(left_child < count){
                if(left_child + 1 < count && lists[left_child]->val > lists[left_child+1]->val) {
                    left_child += 1;
                }
                if(current_value->val <= lists[left_child]->val) {
                    break;
                }
                lists[parent_idx] = lists[left_child];
                parent_idx = left_child;
                left_child = (parent_idx<<1)+1;
            }
            lists[parent_idx] = current_value;
        }
        *pHead = lists[0];

        return head;
    }
};


int main(int argc, char** argv) {

    int count = 10000;
    vector<int> one_array;
    vector<ListNode*> cases;

    srandom(time(NULL));

    for(int i=0; i<count; ++i){
        one_array.clear();
        for(int j=0; j<1; ++j){
            one_array.push_back(random()%10);
        }
        sort(one_array.begin(), one_array.end());
        reverse(one_array.begin(), one_array.end());

        ListNode* head = NULL;
        ListNode* node = NULL;
        for(auto &val : one_array) {
            node = new ListNode(val);
            node->next = head;
            head = node;
        }
        cases.push_back(head);
        print_list(head);
    }

    SOLUTION s;
    ListNode* result = s.mergeKLists(cases);
    print_list(result);


    return 0;
}
