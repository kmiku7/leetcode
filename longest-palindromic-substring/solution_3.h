#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n==0) return "";
        int result_start = 0;
        int result_len = 1;

        for(int i=0; i<n-1; ++i) {
            int len = expandFromCenter(s, i, i);
            if(len+len+1>result_len){
                result_start = i - len;
                result_len = len+len+1;
            }

            len = expandFromCenter(s, i, i+1);
            if(len+len+2>result_len){
                result_start = i - len;
                result_len = len + len + 2;
            }
        }
        return s.substr(result_start, result_len);
    }

    // return the left - left_start + 1;
    int expandFromCenter(string& s, int left, int right){
        int l = left;
        int r = right;
        int n = s.length();

        while(l>=0 && r<n && s[l]==s[r]){
            --l;
            ++r;
        }
        return left-l-1;
    }
};


