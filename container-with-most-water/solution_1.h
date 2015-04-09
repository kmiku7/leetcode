#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int max = 0;
        int left = 0;
        int right = height.size()-1;
        int next_line = 0;
        while(left<right){
            if(height[left]<height[right]){
                int area = (right-left)*height[left];
                if(area>max) max = area;
                next_line = left+1;
                while(next_line<right && height[next_line]<=height[left])++next_line;
                left = next_line;
            } else {
                int area = (right-left)*height[right];
                if(area>max) max = area;
                next_line = right-1;
                while(next_line>left && height[next_line]<=height[right])--next_line;
                right=next_line;
            }
        }
        return max;
    }
};
