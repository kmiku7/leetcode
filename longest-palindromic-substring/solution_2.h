// Time Limit Exceeded

#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        vector<bool> mask_odd(s.length(), true);
        vector<bool> mask_even(s.length(), true);
        int result_pos=0;
        int result_len=1;
        int max_len = s.length()/2;

        // even
        for(int len=1; len<=max_len; ++len) {
            int count = 0;
            int upper_bound = s.length()-len-len+1;
            for(int start_pos=0; start_pos<upper_bound; ++start_pos) {
                int mid_pos = start_pos+len-1;
                int end_pos = mid_pos+len;
                mask_even[mid_pos] = (mask_even[mid_pos] && s[start_pos]==s[end_pos]);
                if(mask_even[mid_pos]){
                    result_pos = start_pos;
                    result_len = len+len;
                    ++count;
                }
            }
            if(count<=0)
                break;
        }
        // odd
        for(int len=1; len<=max_len; ++len) {
            int count = 0;
            int upper_bound = s.length()-len-len;
            for(int start_pos=0; start_pos<upper_bound; ++start_pos) {
                int mid_pos = start_pos+len;
                int end_pos = mid_pos+len;
                if(!mask_odd[mid_pos]) continue;
                if(s[start_pos]==s[end_pos]){
                    if(len+len+1>result_len){
                        result_pos=start_pos;
                        result_len=len+len+1;
                    }
                    ++count;
                } else {
                    mask_odd[mid_pos] = false;
                }
            }
            if(count<=0) break;
        }
        return s.substr(result_pos, result_len);
    }
};


