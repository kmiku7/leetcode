// wrong
// aab, output: 3, expect: 2

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> prev_idx;
        int max_len = 0;

        for(int i=0; i<s.length(); ++i) {
            prev_idx[s[i]] = -1;
        }
        for(int i=0; i<s.length(); ++i) {
            int len = i - prev_idx[s[i]];
            prev_idx[s[i]] = i;
            max_len = len > max_len ? len : max_len;
        }

        return max_len;
    }
};
