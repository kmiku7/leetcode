#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size()==0) return string();

        int upper_bound = strs[0].length();
        int count = strs.size();
        for(int i=1; i<count; ++i) {
            int str_len = strs[i].length();
            int idx=0;
            while(idx<upper_bound && idx<str_len && strs[0][idx]==strs[i][idx]) {
                ++idx;
            }
            upper_bound=idx;
        }

        return strs[0].substr(0, upper_bound);
    }
};
