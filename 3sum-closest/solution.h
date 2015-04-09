#include <algorithm>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;



class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {

        // assert(num.size()>=3);

        int result = INT_MAX;
        int distance = INT_MAX;

        sort(num.begin(), num.end());

        for(auto iter = num.begin(), upper_bound = num.end()-2; iter < upper_bound; ++iter) {
            auto sub_begin = iter+1;
            auto sub_end = num.end()-1;
            while(sub_begin<sub_end){
                int sub_sum = *sub_begin + *sub_end + *iter;
                int sub_distance = abs(sub_sum-target);
                if(sub_distance==0) return target;
                if(sub_distance<distance){

                    distance = sub_distance;
                    result = sub_sum;
                }
                if(sub_sum < target) {
                    ++sub_begin;
                    while(sub_begin < sub_end && *sub_begin == *(sub_begin-1)) ++sub_begin;
                } else {
                    --sub_end;
                    while(sub_begin < sub_end && *sub_end == *(sub_end+1)) --sub_end;
                }
                while(iter<upper_bound && *iter == *(iter+1))++iter;
            }
        }

        return result;
    }
};
