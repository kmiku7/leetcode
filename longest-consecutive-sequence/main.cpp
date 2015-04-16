#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> seg_len;
        int max_len = 0;
        for(auto val : num) {
            if(seg_len[val]!=0) continue;
            seg_len[val] = 1;

            int left_len = 0;
            int right_len = 0;
            if(val!=INT_MIN) {
                left_len = seg_len[val-1];
            }
            if(val!=INT_MAX) {
                right_len = seg_len[val+1];
            }
            seg_len[val-left_len] = seg_len[val+right_len] = left_len + 1 + right_len;           
            max_len = max(max_len, seg_len[val-left_len]);
        }
        return max_len;
    }
};

int main(int argc, char** argv) {

    Solution s;
    vector<int> v = {100, 4, 200, 1, 3, 2};
    vector<int> v1 = {1, 2, 0, 1};
    cout << s.longestConsecutive(v) << endl;
    cout << s.longestConsecutive(v1) << endl;
    return 0;
}
