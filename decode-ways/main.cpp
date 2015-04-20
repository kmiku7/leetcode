#include <iostream>
#include <string>

using namespace std;


// 字符串的hash， "1" "01" 注意需要区分。
//
// https://leetcode.com/discuss/28644/c-5ms-o-n-time-and-o-1-space-without-dp-hashtable-recursive
// 直接代码判断。
class Solution {
public:
    int numDecodings(string s) {
        if(s.size()==0) return 0;

        unsigned hash_map[110] = {0};
        for(int i=1; i<10; ++i) {
            hash_map[i] = ~0;
        }
        for(int i=10; i<=26; ++i) {
            hash_map[i+10] = ~0;
        }
        int prev_prev_count = 1;
        int prev_count = hash_map[s[0]-'0']?1:0;
        for(int i=1; i<s.size() && prev_count; ++i) {
            int p_key = s[i]-'0';
            int pp_key = (s[i-1]-'0'+1)*10 + p_key;
            //int curr_count = prev_prev_count&hash_map[pp_key] + prev_count&hash_map[p_key];
            int curr_count = (prev_prev_count&hash_map[pp_key]) + (prev_count&hash_map[p_key]);
            prev_prev_count = prev_count;
            prev_count = curr_count;
        }
        return prev_count;
    }
};

int main(int argc, char** argv) {

    Solution s;
    cout << s.numDecodings("1262662") << endl;
    cout << s.numDecodings("0") << endl;
    cout << s.numDecodings("12") << endl;
    cout << s.numDecodings("1260662") << endl;
    cout << s.numDecodings("101") << endl;
    cout << s.numDecodings("99") << endl;

    return 0;
}

