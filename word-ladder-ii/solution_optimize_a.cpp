#include <deque>
#include <cassert>

using namespace std;

struct Node {
    string val;
    Node* next;
    int ref_count;
    
    Node(const string& v, Node* n) : val(v), next(n), ref_count(0) {
        if (next) {
            ++(*next).ref_count;
        }
    }
    ~Node() {
        assert(ref_count == 0);
        if (next) {
            --(*next).ref_count;
            if ((*next).ref_count == 0) {
                delete next;
            }
        }
    }
};

class Solution {
private:
    vector<vector<string>> result_find(deque<Node*>& cands, const string& target) {
        vector<vector<string>> result;
        for (auto iter = cands.begin(); iter != cands.end(); ++iter) {
            if (distance((*iter)->val, target) <= 1) {
                result.push_back(vector<string>());
                build_result(result.back(), *iter);
                result.back().push_back(target);
            }
            delete *iter;
        }
        return result;
    }
    int distance(const string& left, const string& right) {
        int dist = 0;
        for (int i = 0; i < left.size(); ++i) {
            if (left[i] != right[i]) {
                ++dist;
            }
        }
        return dist;
    }
    void build_result(vector<string>& container, Node* list) {
        if (list == NULL) {
            return;
        }
        build_result(container, list->next);
        container.push_back(list->val);
    }
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        deque<Node*> pop_from;
        deque<Node*> push_to;

        Node* next_cand = new Node(start, NULL);
        pop_from.push_back(next_cand);

        while (!pop_from.empty()) {
            while (!pop_from.empty()) {
                next_cand = pop_from.front();
                string& prev_str = next_cand->val;
                int dist = distance(prev_str, end);
                if (dist <= 1) {
                    // release mem in push_to
                    return result_find(pop_from, end);
                }
                pop_from.pop_front();
                for (int i = 0; i < prev_str.size(); i++) {
                    string tmp = prev_str;
                    for (int j = 'a'; j <= 'z'; ++j) {
                        tmp[i] = j;
                        if (dict.count(tmp) > 0) {
                            Node* tmp_cand = new Node(tmp, next_cand);
                            push_to.push_back(tmp_cand);
                        }
                    }
                }
                if (next_cand->ref_count <= 0) {
                    delete next_cand;
                }
            }
            for (auto iter = push_to.begin(); iter != push_to.end(); ++iter) {
                dict.erase((*iter)->val);
            }
            pop_from.swap(push_to);
        }
        return vector<vector<string>>();
    }
};
