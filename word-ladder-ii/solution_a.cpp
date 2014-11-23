#include <deque>

using namespace std;

class Solution {
private:
    vector<vector<string>> result_find(deque<deque<string>>& cands, const string& target) {
        vector<vector<string>> result;
        for (deque<deque<string>>::iterator iter = cands.begin();
                iter != cands.end();
                ++iter) {
            if (distance((*iter).back(), target) <= 1) {
                result.push_back(vector<string>());
                for (deque<string>::iterator node = (*iter).begin();
                        node != (*iter).end();
                        ++node) {
                    result.back().push_back(*node);
                }
                result.back().push_back(target);
            }
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
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        deque<deque<string>> pop_from;
        deque<deque<string>> push_to;

        deque<string> next_cand;
        next_cand.push_back(start);
        pop_from.push_back(next_cand);

        while (!pop_from.empty()) {
            while (!pop_from.empty()) {
                deque<string>& next_cand = pop_from.front();
                string& prev_str = next_cand.back();
                int dist = distance(prev_str, end);
                if (dist <= 1) {
                    return result_find(pop_from, end);
                }
                for (int i = 0; i < prev_str.size(); i++) {
                    string tmp = prev_str;
                    for (int j = 'a'; j <= 'z'; ++j) {
                        tmp[i] = j;
                        if (dict.count(tmp) > 0) {
                            deque<string> tmp_cand(next_cand);
                            tmp_cand.push_back(tmp);
                            push_to.push_back(tmp_cand);
                        }
                    }
                }
                pop_from.pop_front();
            }
            for (deque<deque<string>>::iterator iter = push_to.begin();
                    iter != push_to.end();
                    ++iter) {
                dict.erase((*iter).back());
            }
            pop_from.swap(push_to);
        }
        return vector<vector<string>>();
    }
};
