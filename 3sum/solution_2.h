
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
            auto sub_begin = last_num_iter+1;
            auto sub_end = num.rend()-1;
            while(sub_begin < sub_end) {
                int sum = -(*sub_begin + *sub_end);
                if(sum==target) {
                    vector<int> tmp_result = {*sub_end, *sub_begin, target};
                    //if(find(result.begin(), result.end(), tmp_result)==result.end()){
                        result.push_back(tmp_result);
                    //}
                    ++sub_begin;
                    --sub_end;
                    while(*sub_begin==*(sub_begin-1))++sub_begin;
                    while(*sub_end==*(sub_end+1))--sub_end;
                } else if(sum<target) {
                    ++sub_begin;

                } else {
                    --sub_end;

                }
            }
            while(last_num_iter < upper_bound && *last_num_iter==*(last_num_iter+1)) ++last_num_iter;
        }
        return result;   
    }
};
