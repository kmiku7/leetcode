#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first_seg = 1;
        int max_product = INT_MIN;
        int curr_product = 1;
        for(auto val : nums) {
            curr_product *= val;
            max_product = max(max_product, curr_product);
            max_product = max(max_product, curr_product/first_seg);
            if(val==0) {
                first_seg = 1;
                curr_product = 1;
                continue;
            }
            if(val<0) {
                max_product = max(max_product, curr_product/first_seg);
                if(first_seg==1) first_seg = curr_product;
            }
        }
        return max_product;
    }
};


int main(int argc, char** argv) {

    vector<int> v = {2,3,-2,40};
    Solution s;
    cout << s.maxProduct(v) << endl;

    return 0;
}
