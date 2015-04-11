#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define SOLUTION Solution_b

// Wrong
// Input:   "()(()"
// Output:  4
// Expected:    2
class Solution {
public:
    int longestValidParentheses(string s) {
        int left_unmatched = 0;
        int len = 0;
        int max_len = 0;
        for(int i=0; i<s.size(); ++i){
            left_unmatched += (s[i]==')') ? -1 : 1;
            len += 1;
            if(left_unmatched<0){
                left_unmatched = 0;
                len = 0;
            } else if(s[i]==')' && len-left_unmatched>max_len){
                max_len = len-left_unmatched;
            }
        }
        return max_len;       
    }
};


class Solution_a {
public:
    int longestValidParentheses(string s){
        vector<pair<int, int>> valid_interval;
        vector<int> begin_point;
        int max_len = 0;

        valid_interval.reserve(s.size()/2);
        begin_point.reserve(s.size());

        for(int i=0, ub=s.size(); i<ub; ++i){
            if(s[i]=='('){
                begin_point.push_back(i);
            } else {
                if(begin_point.empty()) continue;
                int bp = begin_point.back();
                begin_point.pop_back();
                valid_interval.push_back(make_pair(bp, i+1));
            }
        }

        int prev_begin = 0;
        int prev_end = 0;
        for(auto iter = valid_interval.rbegin(); iter != valid_interval.rend(); ++iter){
            int cur_begin = (*iter).first;;
            int cur_end = (*iter).second;
            if(cur_end<prev_begin || cur_begin>prev_end){
                prev_begin = cur_begin;
                prev_end = cur_end;
            } else {
                prev_begin = prev_begin < cur_begin ? prev_begin : cur_begin;
                prev_end = prev_end < cur_end ? cur_end : prev_end;
            }
            int cur_len = prev_end - prev_begin;
            if(cur_len>max_len) max_len = cur_len;
        }

        return max_len;
    }
};


class Solution_b {
public:
    int longestValidParentheses(string s){
        int max_len = 0;
        vector<const char*> begin_point;

        const char* str = s.c_str();
        for(const char* up = str + s.size(), *idx = str;
            idx < up;
            ++idx) {
            if(*idx == '('){
                begin_point.push_back(idx);
            } else {
                if(!begin_point.empty() && *(begin_point.back()) == '('){
                    begin_point.pop_back();
                    max_len = max(max_len, static_cast<int>(idx - (begin_point.empty()?(str-1):begin_point.back())));
                } else {
                    begin_point.push_back(idx);
                }
            }
        }
        return max_len;
    }
};


int main(int argc, char** argv){

    vector<string> cases = {
            "",
            "(",
            ")",
            "(()",
            "()",
            ")()())",
            ")()()(",
            "()(()",
            "()()()",
            "()(())"
    };
    SOLUTION s;
    for(auto iter=cases.begin(); iter!=cases.end(); ++iter){
        cout << *iter << endl;
        cout << s.longestValidParentheses(*iter) << endl << endl;
    }

    return 0;
}
