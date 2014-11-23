#include <deque>
#include <unordered_map>
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
            //delete *iter;
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

    void build_adjacency_table(unordered_map<string, unordered_set<string>>& adj_table, const string& start, const unordered_set<string>& dict) {
        for (auto iter = dict.begin(); iter != dict.end(); ++iter) {
            adj_table[*iter] = unordered_set<string>();
            for (int i = 0; i < (*iter).size(); ++i) {
                string tmp_str = *iter;
                for (int j = 'a'; j <= 'z'; ++j) {
                    if ((*iter)[i] == j) {
                        continue;
                    }
                    tmp_str[i] = j;
                    if (dict.count(tmp_str) >= 1) {
                        adj_table[*iter].insert(tmp_str);
                    }
                }
            }
        }
    }
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        deque<Node*> pop_from;
        deque<Node*> push_to;
        unordered_map<string, unordered_set<string>> adj_table;

        dict.insert(start);
        build_adjacency_table(adj_table, start, dict);

        Node* next_cand = new Node(start, NULL);
        pop_from.push_back(next_cand);
        dict.erase(start);

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
                for (auto iter = adj_table[prev_str].begin(); iter != adj_table[prev_str].end(); ++iter) {
                    if (dict.count(*iter) >= 1) {
                        Node* tmp_node = new Node(*iter, next_cand);
                        push_to.push_back(tmp_node);
                    }
                }
                //if (next_cand->ref_count <= 0) {
                //    delete next_cand;
                //}
            }
            for (auto iter = push_to.begin(); iter != push_to.end(); ++iter) {
                dict.erase((*iter)->val);
            }
            pop_from.swap(push_to);
        }
        return vector<vector<string>>();
    }
};
