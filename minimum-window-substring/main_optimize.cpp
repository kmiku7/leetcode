#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        int unique_count = 0;
        int unique_expect = 0;
        int alpha_count[256] = {0};
        int alpha_expect[256] = {0};
        for(auto c : T){
            alpha_expect[c] += 1;
            unique_expect += (alpha_expect[c]==1);
        }

        const char *s_begin = S.c_str();
        const char *s_guard = s_begin + S.size();
        const char *s_end = NULL;

        const char *min_start = NULL;
        int min_len = INT_MAX;

        while(s_begin<s_guard && alpha_expect[*s_begin]==0) ++s_begin;

        s_end = s_begin - 1;
        while(s_begin<s_guard && s_end<s_guard) {
            if(unique_expect == unique_count) {
                if(s_end-s_begin+1<min_len) {
                    min_start = s_begin;
                    min_len = s_end-s_begin+1;
                }
                if(alpha_count[*s_begin] == alpha_expect[*s_begin]) --unique_count;
                alpha_count[*s_begin] -= 1;
                ++s_begin;
                while(s_begin<s_guard && alpha_expect[*s_begin]==0) ++s_begin;
            } else {
                ++s_end;
                while(s_end<s_guard && alpha_expect[*s_end]==0) ++s_end;
                if(s_end>=s_guard) continue;
                alpha_count[*s_end] += 1;
                if(alpha_expect[*s_end] == alpha_count[*s_end]) unique_count += 1;
            }
        }

        if(min_start==NULL) return "";
        return string(min_start, min_start+min_len);
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
