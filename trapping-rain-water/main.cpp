#include <iostream>
#include <vector>
#include <climits>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> min_idx;
        min_idx.reserve(height.size());
        int total_sum = 0;
        int i = 0;
        while(i<height.size()) {
            if(min_idx.empty() || height[i]<height[min_idx.back()]) {
                min_idx.push_back(i);
                ++i;
            } else {
                int back_idx = min_idx.back();
                min_idx.pop_back();
                int left_pos = min_idx.empty() ? back_idx : min_idx.back();
                total_sum += (min(height[i], height[left_pos]) - height[back_idx]) * (i - left_pos - 1);
            }
        }
        return total_sum;
    }
};

class Solution_a {
public:
    int trap(vector<int>& num) {
        if(num.size()<=2) return 0;
        vector<int> water(num.size(), INT_MAX);
        int wall = 0;
        for(int i=0; i<num.size(); ++i) {
            if(num[i] > wall) wall = num[i];
            water[i] = min(water[i], wall-num[i]);

        }
        wall = 0;
        for(int i=num.size()-1; i>=0; --i) {
            if(num[i]>wall) wall = num[i];
            water[i] = min(water[i], wall-num[i]);
        }
        int total_sum = 0;
        for(auto val : water) {
            total_sum += val;
        }
        return total_sum;
    }
};


class Solution_b {
public:
    int trap(vector<int>& height) {
        if(height.size()<=2) return 0;

        int total_sum = 0;
        int left_wall = 0;
        int right_wall = 0;
        int left_pos = 0;
        int right_pos = height.size()-1;
        while(left_pos<=right_pos) {
            if(left_wall < right_wall) {
                left_wall = max(height[left_pos], left_wall);
                total_sum += left_wall - height[left_pos++];
            } else {
                right_wall =max(height[right_pos], right_wall);
                total_sum += right_wall - height[right_pos--];
            }

        }
        return total_sum;
    }
};

int main(int argc, char** argv) {

    vector<int> nums = {
            0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    Solution s;
    Solution_a sa;
    Solution_b sb;
    cout << s.trap(nums) << endl;
    cout << sa.trap(nums) << endl;
    cout << sb.trap(nums) << endl;

    return 0;
}
