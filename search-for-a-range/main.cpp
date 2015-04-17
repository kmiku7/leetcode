#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return vector<int>{-1, -1};
        // find >=
        int begin = 0;
        int end = nums.size();
        while(begin<end) {
            int mid = (begin+end)/2;
            if(nums[mid] < target)
                begin = mid+1;
            else
                end = mid;
        }
        if(begin>=nums.size() || nums[begin]!=target) return vector<int>{-1, -1};
        int pos_begin = begin;
        begin = 0;
        end = nums.size();
        while(begin<end) {
            int mid = (begin+end)/2;
            if(nums[mid] <= target)
                begin = mid+1;
            else end = mid;
        }
        return vector<int>{pos_begin, begin-1};
    }
};


int main(int argc, char** argv) {

    vector<int> nums = {5, 7, 7, 8, 8, 10};
    Solution s;
    auto result = s.searchRange(nums, 7);
    cout << result.size() << endl;
    cout << result[0] << endl;
    cout << result[1] << endl;

    return 0;
}
