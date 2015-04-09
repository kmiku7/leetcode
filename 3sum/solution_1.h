
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;

        if(num.size()<3) return result;
        sort(num.begin(), num.end());
        int num_count = num.size();

        for(auto last_num_iter = num.rbegin(), upper_bound = num.rend()-2; 
                last_num_iter < upper_bound; ++last_num_iter) {
            int target = *last_num_iter;
            if((target+*(last_num_iter+1)+*(last_num_iter+2))<0) {
                continue;
            }
            auto tmp_result = twoSum(last_num_iter+1, num.rend(), -target);
            for(auto iter = tmp_result.begin(); iter!=tmp_result.end(); ++iter) {
                (*iter).push_back(*last_num_iter);
                if(find(result.begin(), result.end(), *iter)==result.end()){
                    result.push_back(*iter);
                }
            }
            while(last_num_iter < upper_bound && *last_num_iter==*(last_num_iter+1)) ++last_num_iter;
        }
        return result;   
    }

    vector<vector<int> > twoSum(vector<int>::reverse_iterator begin, vector<int>::reverse_iterator end, int target) {
        --end;
        vector<vector<int> > result;
        while(begin<end) {
            int sum = *begin + *end;
            if(sum==target){
                result.push_back({*end, *begin});
                ++begin;
                --end;
            } else if(sum>target) {
                ++begin;
            } else {
                --end;
            }
        }
        return result;
    }
};
