#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()<=0) return false;
        int max_pos = 0;
        int nums_len = nums.size();
        for(int i=0; i<=max_pos && max_pos<nums_len-1; ++i) {
            max_pos = max(max_pos, i+nums[i]);
        }
        return max_pos>=nums_len-1;
    }
};

int main(int argc, char** argv) {
    return 0;
}
