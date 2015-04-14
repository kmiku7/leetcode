#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.size()==0) return INT_MIN;
        if(num.size()==1) return num[0];
        if(num.size()==2) return min(num[0], num[1]);

        int begin = 0;
        int end = num.size()-1;

        while(end-begin>1) {
            int mid = (begin+end)/2;
            //if(num[begin] < num[mid] && num[mid]<num[end]) {
            //    return num[begin];
            //} else if(num[mid] < num[end]) {
            if(num[mid] < num[end]) {
                end = mid;
            } else {
                begin = mid;
            }
        }
        return min(num[begin], num[end]);
    }
};


int main(int argc, char** argv) {
    
    vector<int> nums;
    for(int i=0; i<30; ++i)
        nums.push_back(i);

    Solution s;
    for(int i=0; i<3; ++i) {
        rotate(nums.begin(), nums.begin()+30, nums.end());
        cout << s.findMin(nums) << endl;
    }
    return 0;

}
