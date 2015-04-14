#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        int begin = 0;
        int end = 0;
        int unique_count = 0;
        unordered_map<char, int> alpha_count;
        unordered_map<char, int> alpha_target;
        string result;

        for(auto c : T) {
            alpha_count[c] = 0;
            alpha_target[c] += 1;
        }
        int t_len = alpha_count.size();
        int idx = 0;
        while(idx<S.size() && alpha_count.find(S[idx]) == alpha_count.end()) {
             ++idx;
        }
        begin = idx;
        end = idx-1;
        while(begin<(int)S.size() && end<(int)S.size()) {
            if(unique_count<t_len) {
                // move end
                end += 1;
                while(end<S.size() && alpha_count.find(S[end]) == alpha_count.end()) ++end;
                if(end>=S.size()) continue;
                alpha_count[S[end]] += 1;
                if(alpha_count[S[end]] == alpha_target[S[end]]) {
                    unique_count += 1;
                }

            } else {
                // move begin
                if(unique_count == t_len && (result.size() == 0 || (end-begin+1) < result.size())) {
                    result = S.substr(begin, end-begin+1);
                }
                alpha_count[S[begin]] -= 1;
                if(alpha_count[S[begin]] == alpha_target[S[begin]]-1) {
                    unique_count -= 1;
                }
                begin += 1;
                while(begin<S.size() && alpha_count.find(S[begin]) == alpha_count.end()) ++begin;
            }
        }

        return result;
    }
};

int main(int argc, char** argv) {
    string S = "ADOBECODEBANC";
    string T = "ABC";

    string SA = "AAAAAAAAAAABB";
    string TA = "AAAAB";

    string SB = "abc";
    string TB = "b";

    Solution s;

    cout << s.minWindow(S, T) << endl;
    cout << s.minWindow(SA, TA) << endl;
    cout << s.minWindow(SB, TB) << endl;

    return 0;
}
