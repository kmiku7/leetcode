#include <deque>
#include <unordered_map>
#include <cassert>

using namespace std;

class Solution {
private:
    int distance(const string& left, const string& right) {
        int dist = 0;
        for (int i = 0; i < left.size() && i < 2; ++i) {
            if (left[i] != right[i]) {
                ++dist;
            }
        }
        return dist;
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
    vector<vector<string>> build_result(const string& start, const string& end, unordered_map<string, unordered_set<string>>& prev_map) {
        deque<string>   path;
        vector<vector<string>> result;
        if (prev_map[start].size() <= 0) {
            return result;
        }
        __dfs_build_result(start, end, prev_map, path, result);
        return result;
    }

    void __dfs_build_result(const string& start, const string& end, unordered_map<string, unordered_set<string>>& prev_map, deque<string>& sub_path, vector<vector<string>>& result) {
        sub_path.push_back(start);
        if (start == end) {
            result.push_back(vector<string>(sub_path.begin(), sub_path.end()));
        } else {
            for (auto iter = prev_map[start].begin(); iter != prev_map[start].end(); ++iter) {
                __dfs_build_result(*iter, end, prev_map, sub_path, result);
            }
        }
        sub_path.pop_back();
    }
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> pop_from;
        unordered_set<string> push_to;
        //unordered_map<string, unordered_set<string>> adj_table;
        unordered_map<string, unordered_set<string>> prev_map;

        dict.insert(start);
        dict.insert(end);
        //build_adjacency_table(adj_table, start, dict);
        //adj_table[start].clear();

        for (auto iter = dict.begin(); iter != dict.end(); ++iter) {
            prev_map[*iter] = unordered_set<string>();
        }

        pop_from.insert(end);
        dict.erase(end);

        while (!pop_from.empty()) {
            for (auto iter = pop_from.begin(); iter != pop_from.end(); ++iter) {
                string next_cand = *iter;
                for (int i = 0; i < next_cand.size(); i++) {
                    string tmp = next_cand;
                    for (int j = 'a'; j <= 'z'; ++j) {
                        tmp[i] = j;
                        if (dict.count(tmp) > 0) {
                            push_to.insert(tmp);
                            prev_map[tmp].insert(next_cand);
                        }
                    }
                }
            }
            pop_from.clear();
            if (prev_map[start].size() > 0) {
                break;
            }
            for (auto iter = push_to.begin(); iter != push_to.end(); ++iter) {
                dict.erase(*iter);
            }
            pop_from.swap(push_to);
        }
        return build_result(start, end, prev_map);
    }
};
