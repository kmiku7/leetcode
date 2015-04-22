#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <climits>

using namespace std;


class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        unordered_map<size_t, vector<size_t>> prev;
        int max_len = INT_MIN;
        int min_len = INT_MAX;
        for(auto& item : wordDict) {
            max_len = max(max_len, (int)item.size());
            min_len = min(min_len, (int)item.size());
        }
        prev[0].size();
        for(int i=0; i<s.size(); ++i) {
            for(int len=min_len; len<=max_len && i+len<=s.size(); ++len) {
                if(prev.find(i)==prev.end()) continue;
                string sub(s.c_str()+i, len);
                if(wordDict.find(sub)!=wordDict.end()) prev[i+len].push_back(i);
            }
        }
        vector<string> result;
        build_result(prev, result, s, s.size(), "");
        return result;
    }
private:
    void build_result(unordered_map<size_t, vector<size_t>>& prev, vector<string>& result, string& s, size_t begin_pos, string prev_sub) {
        for(auto prev_pos : prev[begin_pos]) {
            string curr_sub = s.substr(prev_pos, begin_pos-prev_pos) + (prev_sub.size()==0?"":" ") + prev_sub;
            if(prev_pos==0)
                result.push_back(curr_sub);
            else
                build_result(prev, result, s, prev_pos, curr_sub);
        }
        
    }
};

int main(int argc ,char** argv) {

    string str_0 = "catsanddog";
    unordered_set<string> dict_0({"cat", "cats", "and", "sand", "dog"});

    string str = "baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    unordered_set<string> dict({"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"});

    Solution ss;
    auto result = ss.wordBreak(str, dict);
    for(auto item : result) {
        cout << "|" << item << "|" << endl;
    }
    auto result_0 = ss.wordBreak(str_0, dict_0);
    for(auto item : result_0) {
        cout << "|" << item << "|" << endl;
    }

    return 0;
}
