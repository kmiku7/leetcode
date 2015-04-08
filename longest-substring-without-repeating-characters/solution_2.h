// wrong
// aab, output: 3, expect: 2

#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        //unordered_map<char, int> prev_idx;
        int prev_idx[0xFF];
        int max_len = 0;
        int lower_bound = -1;

        for(int i=0; i<s.length(); ++i) {
            prev_idx[s[i]] = -1;
        }
        for(int i=0; i<s.length(); ++i) {

            int prev_pos = prev_idx[s[i]];
            if(prev_pos<lower_bound) {
                prev_pos = lower_bound;
            } else {
                lower_bound = prev_pos;
            }
            int len = i - prev_pos;
            max_len = len > max_len ? len : max_len;
            prev_idx[s[i]] = i;
        }

        return max_len;
    }
};
