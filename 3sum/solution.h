// timeout

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        int num_count = num.size();
        vector<vector<int> > result;
        for(int i=0; i<num_count; ++i) {
            for(int j=i+2; j<num_count; ++j) {
                int target = -(num[i]+num[j]);
                if(target<num[i+1] || target>num[j-1]) continue;
                auto target_iter = find(num.begin()+i, num.begin()+j, target);
                if(target_iter == num.begin()+j) continue;
                vector<int> one_result = {num[i], *target_iter, num[j]};
                if(find(result.begin(), result.end(), one_result)==result.end()){
                    result.push_back({num[i], *target_iter, num[j]});
                }
            }
        }
        return result;   
    }
};
