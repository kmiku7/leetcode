#include <string>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        string result;
        for(int len=1; len<s.length(); ++len) {
            for(int start_pos=0; start_pos+len<=s.length(); ++start_pos) {
                int str_head = start_pos;
                int str_tail = start_pos+len-1;
                while(str_head < str_tail){
                    if(s[str_head]!=s[str_tail]){
                        break;
                    } else {
                        ++str_head;
                        --str_tail;
                    }
                }
                if(str_head>=str_tail) result = s.substr(start_pos, len);
            }
        }
        return result;
    }
};


