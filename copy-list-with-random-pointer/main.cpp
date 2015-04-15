/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

#include <unordered_map>
#include <iostream>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;

        RandomListNode* copy_head = NULL;
        RandomListNode** p_copy_head = &copy_head;
        unordered_map<RandomListNode*, int> origin_addr_idx;
        unordered_map<int, RandomListNode*> copy_addr_idx;

        int count = 0;
        for(RandomListNode* origin_iter = head; origin_iter!=NULL; origin_iter = origin_iter->next) {
            *p_copy_head = new RandomListNode(origin_iter->label);
            origin_addr_idx[origin_iter] = count;
            copy_addr_idx[count] = *p_copy_head;
            p_copy_head = &((*p_copy_head)->next);
            count++;
        }

        for(RandomListNode* origin_iter = head, *copy_iter = copy_head;
            origin_iter!=NULL; ) {

            if(origin_iter->random!=NULL) {
                int idx = origin_addr_idx[origin_iter->random];
                copy_iter->random = copy_addr_idx[idx];
            }
            copy_iter = copy_iter->next;
            origin_iter = origin_iter->next;
        }
        return copy_head;
    }
};



class Solution_a {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;

        RandomListNode *curr;
        RandomListNode *next;

        curr = head;
        while(curr) {
            next = curr->next;
            curr->next = new RandomListNode(curr->label);
            curr->next->next = next;
            curr = next;
        }

        curr = head;
        while(curr) {
            next = curr->next;
            if(curr->random) {
                next->random = curr->random->next;
            }
            curr = next->next;
        }

        RandomListNode* copy_head = NULL;
        RandomListNode** p_copy_head = &copy_head;
        curr = head;
        while(curr) {
            next = curr->next;
            *p_copy_head = next;
            p_copy_head = &(next->next);
            curr->next = next->next;
            curr = next->next;
        }
        return copy_head;
    }
};


int main(int argc, char** argv) {
    Solution s;
    Solution_a sa;

    RandomListNode* n1 = new RandomListNode(-1);
    RandomListNode* n2 = new RandomListNode(-2);
    n1 -> next = n2;

    n1 -> random = n1;
    n2 -> random = n1;

    RandomListNode* cc = n1;
    while(cc) {
        cout << cc->label << endl;
        if(cc->random) cout << "random: " << cc->random->label << endl;
        cc = cc->next;
    }
    cout << " ---- " << endl;

    cc = s.copyRandomList(n1);

    while(cc) {
        cout << cc->label << endl;
        if(cc->random) cout << "random: " << cc->random->label << endl;
        cc = cc->next;
    }

    cout << " ---- " << endl;

    cc = sa.copyRandomList(n1);

    while(cc) {
        cout << cc->label << endl;
        if(cc->random) cout << "random: " << cc->random->label << endl;
        cc = cc->next;
    }



    return 1;


}
